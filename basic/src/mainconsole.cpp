#include <mecacell/mecacell.h>
#include "core/scenario.hpp"
#include "core/cell.h"

int main(int argc, char *argv[]) {
	Scenario<Cell> sc;
	sc.init(argc, argv);
	while (!sc.finished()) sc.loop();
	sc.terminate();
	return 0;
}