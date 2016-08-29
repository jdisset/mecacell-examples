#include <mecacell/mecacell.h>
#include <mecacell/viewer/viewer.h>
#include "core/scenario.hpp"
#include "core/cell.h"

int main(int argc, char *argv[]) {
	MecacellViewer::Viewer<Scenario<Cell>> v(argc, argv);
	return v.exec();
}