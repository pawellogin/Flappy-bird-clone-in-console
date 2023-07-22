#include "Display.h"
#include "Bird.h"
#include "Map.h"
#include "Fps.h"
#include "Pipes.h"
#include <thread>

int main() {
	const int HEIGHT = 30;
	const int WIDTH = 50;

	int score = 0;

	Map map(HEIGHT, WIDTH);
	Display display(&map);
	Bird bird(&map);
	Fps fps;

	Pipes pipes(&map,&score);

	while (1) {
		fps.displayFpsMonitor();
		fps.limitFps(60); //in ms 

		if (!bird.fall() || !bird.fly()) {
			return 0;
		}

		pipes.makePipes();
		if (!map.isPixelClear(bird.y, bird.x)) {
			return 0;
		}
		map.placePixel(bird.x, bird.y, 43);

		std::cout <<"Score: "<< score<<"\n";
		display.displayPrint();
		display.displayClear();

		map.clear();
	}

	return 0;
}