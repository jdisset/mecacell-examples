#include "scenario.hpp"

int main(int, char **) {
	Scenario sc;
	while (!sc.finished()) sc.loop();
	return 0;
}
