#include <mecacell/mecacell.h>
#include <chrono>
#include <iostream>
#include <mecacell/springbody.hpp>
#include <random>

// We need to define a Cell class. This class must inherit from one of the base MecaCell
// cells classes (or implement all of their basics methods). In doing so, it must also
// provide a "body implementation". A cell body is a class that handles the physics of
// cellular interactions (both cell-cell and cell-world) as well as provide storage and
// access to physics-related state variable for each cell. For example, in the very
// simple SpringBody model, such variables are the cell's center position, velocity,
// orientation, stiffness and radius.
// MecaCell's base cell classes use the CRTP programing idiom (where the base class is
// templated with the inheriting one) and require a body implementation class as second
// template argument (default is SpringBody).
// Here we use the MecaCell::ConnectableCell base class (which just maintains a list of
// connected cells) with the default SpringBody.
class Cell : public MecaCell::ConnectableCell<Cell, MecaCell::SpringBody> {
 public:
	using parent = MecaCell::ConnectableCell<Cell, MecaCell::SpringBody>;
	using parent::parent;  // Constructor inheritance

	// A MecaCell::World (the environment which contains the cells) require each agent (each
	// cell) to provide an implementation of updateBehavior. This methods takes a reference
	// to the world itself (here we already know that the W typename is going to be
	// MecaCell::World<Cell>) and is, by default, called at every world update for each
	// cell.
	template <typename W> void updateBehavior(W&) {
		// we can do whatever we want here... such as making the cell divide
	}

	// SpringBody (and most other body implementations in MecaCell) requires that the cells
	// define a getAdhesionWith method that, for a given cell pointer and orientation
	// vector, returns a real value proportional to the desired adhesion intensity with the
	// given cell. Usually the final adhesion value between two given cell is defined as the
	// minimum getAdhesionWith value for the two cells (but this depends on the body
	// implementation you chose, so you should check)
	double getAdhesionWith(Cell*, const MecaCell::Vector3D&) {
		// here we just return 0 (no adhesion, only collisions between cells)
		return 0;
	}
};

// A scenario class is a useful wrapper for our simulation,
// and a requirement for using MecaCellViewer
class Scenario {
	using World = MecaCell::World<Cell>;
	using V = MecaCell::Vector3D;

 protected:
	const double SIM_DURATION = 10.0;
	World w;             // Our scenario contains an instance of a MecaCell World
	double simTime = 0;  // Just to keep track of simulated time
	std::chrono::time_point<std::chrono::system_clock> start;  // keep track of real time

 public:
	Scenario() {
		start = std::chrono::system_clock::now();

		// MecaCell puts a strong emphasis on being deterministic. It however uses
		// psudo-random functions, mostly for geometry methods (such as
		// Vector3D::randomUnit()).  See mecacell/geometry/ files for lots of geometry related
		// methods and helpers. Here we seed the globalRand engine to get some variations at
		// each program run. Default seed is 0.
		MecaCell::Config::globalRand().seed(std::random_device{}());

		// We add two cells at the "center of the world"
		// The MecaCell::World will take ownership of the given pointer and handle all memory
		// and object lifetime related questions. A
		w.addCell(new Cell(V(-30, 0, 0)));
		w.addCell(new Cell(V(30, 0, 0)));

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
		std::cerr << nlohmann::json(w.getExport()).dump(2) << std::endl;

		w.update();
	}

	World& getWorld() { return w; }  // required by the viewer

	// Convenience function : returns true when the scenario is finished. (Here we also
	// print out the time it took)
	bool finished() {
		if (simTime >= SIM_DURATION) {
			std::chrono::duration<double> diff = std::chrono::system_clock::now() - start;
			std::cout << w.getNbUpdates() << " updates in " << diff.count() << " seconds."
			          << std::endl;
			return true;
		};
		return false;
	}
};
