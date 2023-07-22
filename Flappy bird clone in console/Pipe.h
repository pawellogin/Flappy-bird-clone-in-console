#pragma once
#include "Pipes.h"

class Pipe {
	Map* map;
	int WIDTH;
	int HEIGHT;
	int pipePosition;
	int pipeSize;
	int gap;
	float genOffset;

public:
	Pipe(Map* m) : map(m) {
		genOffset = 0.2;
		WIDTH = map->WIDTH;
		HEIGHT = map->HEIGHT;

		std::random_device rd;
		std::mt19937 gen(rd());

		std::uniform_int_distribution<int> distribution(genOffset * HEIGHT, (1-genOffset) * HEIGHT);

		gap = distribution(gen);

		pipePosition = WIDTH - 1;
		pipeSize = 3;
	}

	~Pipe(){
		
	}

	bool pipeMove() {
		for (int i = pipePosition; i > pipePosition - pipeSize; i--) {
			for (int k = 0; k < HEIGHT; k++) {
				if (!((k >= gap-0.1*HEIGHT) && (k<= gap+0.1*HEIGHT))) {
					map->placePixel(i, k, 102);
				}
			}
		}
		pipePosition -= 1;
		if (pipePosition - 2 < 0) {
			pipePosition = WIDTH - 1;
			return 0;
		}
		return 1;
	}

	int returnPosition() {
		return pipePosition;
	}
};
