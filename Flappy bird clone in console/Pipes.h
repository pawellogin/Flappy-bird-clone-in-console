#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "Map.h"


class Pipes {
	std::vector<std::vector<int>>* matrix;
	Map* map;
	int WIDTH;
	int HEIGHT;
	int pipePosition;
	int pipeSize;

public:
	/*Pipes(std::vector<std::vector<int>>* m) : matrix(m) {	
		pipePosition = (*matrix)[0].size() -1;
		Map* map;
	}*/

	Pipes(Map* m) : map(m) {
		WIDTH = map->WIDTH;
		HEIGHT = map->HEIGHT;

		pipePosition = WIDTH-1;
		pipeSize = 3;
	}

	void makePipes() {
		std::random_device rd;
		std::mt19937 gen(rd());

		// Define the range for the random numbers (0 to 99 in this case)
		std::uniform_int_distribution<int> distribution(0.3*WIDTH, 0.7*WIDTH);

		std::cout << distribution(gen);

		// od 0.3 widh do 0.3 width, gap = 0.2 width 
		int gap;
		for(int i = pipePosition ; i > pipePosition - pipeSize; i--){
			for (int k = 0; k < HEIGHT; k++) {
				map->placePixel(i, k, 44);
					}
		}
		pipePosition -= 1;
		if (pipePosition -2 < 0) {
			pipePosition = WIDTH-1;
		}
	}
};
