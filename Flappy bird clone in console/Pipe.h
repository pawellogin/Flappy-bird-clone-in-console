#pragma once
#include "Pipes.h"

class Pipe {
	Map* map;

	int WIDTH;
	int HEIGHT;

	int* score;

	float pipePosition;
	int pipeSize;
	float pipeSpeed;

	int gapPosition;
	int gapSizeHalf;

	float genOffset;

public:
	Pipe(Map* m,int pSize,int* s,float speed =0.5,int halfGapSize =3) : map(m), pipeSize(pSize),score(s), pipeSpeed(speed),gapSizeHalf(halfGapSize) {

		genOffset = 0.2;
		WIDTH = map->WIDTH;
		HEIGHT = map->HEIGHT;

		std::random_device rd;
		std::mt19937 gen(rd());

		std::uniform_int_distribution<int> distribution(genOffset * HEIGHT, (1-genOffset) * HEIGHT);

		gapPosition = distribution(gen);
		gapSizeHalf = 3;

		pipePosition = WIDTH - 1;
	}

	~Pipe(){
		(*score)+=1;
	}

	bool pipeMove() {
		for (int i = pipePosition; i > pipePosition - pipeSize; i--) {
			for (int k = 0; k < HEIGHT; k++) {
				if (!((k >= gapPosition-gapSizeHalf) && (k<= gapPosition+gapSizeHalf))) {
					map->placePixel(i, k, 102);
				}
			}
		}
		pipePosition -= pipeSpeed;
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
