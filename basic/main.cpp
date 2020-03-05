#include "scenario.hpp"

int main(int, char **) {
	Scenario sc;

	while (!sc.finished()) {
		sc.loop();
		std::cout<< "Frame " << sc.w.getNbUpdates() << " : " << sc.w.cells.size() << " cells"
		          << std::endl;
	}
	return 0;
}
