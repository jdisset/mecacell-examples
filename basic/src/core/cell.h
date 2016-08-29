#ifndef CELL_HPP
#define CELL_HPP

#include <mecacell/mecacell.h>

class Cell : public MecaCell::ConnectableCell<Cell> {
	using Base = MecaCell::ConnectableCell<Cell>;

 public:
	Cell(const MecaCell::Vec& p) : Base(p) {}
	double getAdhesionWith(const Cell*, const MecaCell::Vec&) const { return 1.0; }

	template <class W> void updateBehavior(W&) {}
};

#endif
