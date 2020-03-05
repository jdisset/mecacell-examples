#include <mecacell/mecacell.h>
#include <mecacell/pbdbody.hpp>
#include <chrono>

using body_t = MecaCell::PBDBody_singleParticle;

struct Cell {
	static const constexpr double BASE_LENGTH = 1.0;
	static const constexpr double GROWTH_SPEED = 1.0;

	size_t id;  // required by world
	double divisionProgress = 0;

	void updateSize(body_t& b) {
		double currentLength = BASE_LENGTH * (1.0 + divisionProgress);
		b.setLength(currentLength);
	}

	template <typename W, typename B> void divide(W& w, B& body, size_t threadId) {
		// we create the daughter cell and its body
		B b(body.getPosition());  // we place the new body at the same position
		Cell c(*this);            // we use the default copy constructor

		divisionProgress = 0;  // we reset division progress
		c.divisionProgress = 0;

		updateSize(body);
		c.updateSize(b);

		// we need to very slightly nudge the two middle nodes (as they are still confounded)
		const double NUDGE_MAGNITUDE = 0.0001;
		auto v = MecaCell::Vec::randomUnit();
		b.particles[0].position += v * NUDGE_MAGNITUDE;

		body.resetProjections();
		b.resetProjections();

		w.addCell(std::move(c), std::move(b), threadId);
	}

	// A MecaCell::World (the environment which contains the cells) require each agent (each
	// cell) to provide an implementation of updateBehavior. This methods takes a reference
	// to the world itself (here we already know that the W typename is going to be
	// MecaCell::World<Cell>) and is, by default, called at every world update for each
	// cell.
	template <typename W> void updateBehavior(W& w, body_t& b, size_t threadId) {
		// we can do whatever we want here... such as making the cell divide
		// grow & divide
		if (divisionProgress < 1) {  // grow
			divisionProgress += GROWTH_SPEED * w.getDt();
			updateSize(b);
		} else {
			divide(w, b, threadId);
		}
	}
};

// A scenario class is a useful wrapper for our simulation,
// and a requirement for using MecaCellViewer
struct Scenario {
	using World = MecaCell::World<Cell, body_t>;
	using V = MecaCell::Vector3D;

	const double SIM_DURATION = 12.2;
	World w;             // Our scenario contains an instance of a MecaCell World
	double simTime = 0;  // Just to keep track of simulated time
	std::chrono::time_point<std::chrono::system_clock> start;  // keep track of real time

	Scenario() {
		start = std::chrono::system_clock::now();

		// MecaCell puts a strong emphasis on being deterministic. It however uses
		// psudo-random functions, mostly for geometry methods (such as
		// Vector3D::randomUnit()).  See mecacell/geometry/ files for lots of geometry related
		// methods and helpers. Here we seed the globalRand engine to get some variations at
		// each program run. Default seed is 0.
		MecaCell::Config::globalRand().seed(std::random_device{}());

		// Adding cells require both a Cell object (the controller and high level methods) and
		// a body object (the physics implementation and representation of that cell)
		w.addCell(Cell(), body_t(V(0, 0, 0)));

		// When we add cells to the world (using addCell), they are actually stored in a
		// buffer, and thus are not immediately accessible in World::cells (the cell
		// container)
		w.addNewCells();
	}

	// A loop method is required for MecaCellViewer, and is the recommended way to
	// encapsulate MecaCell::world updates.
	// Events or calculations on the populations can happen there, but for anything bigger
	// than a few lines of code, the clean/portable/recommended way to add events, stats or
	// anything that should be regularly run is through the use of plugins (or direclty in
	// the cell's updateBehavior methods for anything local). See plugin examples
	void loop() {
		simTime += w.getDt();

		// ...
		// you could loop over w.cells to do some calculations or trigger some events here,
		// but it would be cleaner to use a plugin and/or the updateBehavior of each cell
		// ...
		//
		// std::cerr << nlohmann::json(w.getExport()).dump(2) << std::endl;

		w.update();
	}

	// Convenience function : returns true when the scenario is finished. (Here we also
	// print out the time it took)
	bool finished() {
		if (simTime >= SIM_DURATION) {
			std::chrono::duration<double> diff = std::chrono::system_clock::now() - start;
			std::cout << w.getNbUpdates() << " updates in " << diff.count() << " seconds."
			          << std::endl;
			std::cout<<"Simulation reached "<<w.cells.size()<<" cells"<<std::endl;
			return true;
		};
		return false;
	}
};
