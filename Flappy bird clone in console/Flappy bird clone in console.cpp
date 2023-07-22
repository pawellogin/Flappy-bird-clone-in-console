#include "Display.h"
#include "Bird.h"
#include "Map.h"
#include "Fps.h"
#include "Pipes.h"
#include <thread>

int main() {
	const int HEIGHT = 30;
	const int WIDTH = 50;

	Map map(HEIGHT, WIDTH);
	Display display(map.returnPointerMap());
	Bird bird(map.returnPointerMap());
	Fps fps;

	//Pipes pipes(map.returnPointerMap());
	Pipes pipes(&map);

	while (1) {
		fps.displayFpsMonitor();
		fps.limitFps(60);

		bird.fall();
		bird.fly();
		pipes.makePipes();
		map.placePixel(bird.x, bird.y, 45);

		//map.display();
		std::cout << "\n";
		display.displayPrint();
		display.displayClear();

		map.clear();
	}

	return 0;
}