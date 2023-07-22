#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "Map.h"
#include "Pipe.h"


class Pipes {
	Map* map;
	int WIDTH;
	int HEIGHT;
	int pipePosition;
	int pipeSize;

	bool isPipe;

	Pipe* pipe;

	std::vector<Pipe*> pipes;



public:

	Pipes(Map* m) : map(m) {
		WIDTH = map->WIDTH;
		HEIGHT = map->HEIGHT;

		pipePosition = WIDTH-1;
		pipeSize = 3;
		isPipe = 0;
		pipe = NULL;
	}

	void makePipes() {

		if (pipes.empty()) {
			pipes.push_back(new Pipe(map));
		}

		if (pipes[pipes.size() - 1]->returnPosition() < WIDTH - pipeSize*6) {
			pipes.push_back(new Pipe(map));
		}

		for (int i = 0; i < pipes.size();) {

			if (!pipes[i]->pipeMove()) {
				delete pipes[i];
				pipes.erase(pipes.begin() + i);
			}
			else {
				++i;
			}
		}




		/*if (pipe == NULL) {
			pipe = new Pipe(map);
		}
		else {
			if (!pipe->pipeMove()) {
				delete pipe;
				pipe = nullptr;
				pipe = new Pipe(map);
			}
		}*/

	}

	~Pipes() {
		for (Pipe* pipe : pipes) {
			delete pipe;
		}
		pipes.clear();
	}
};
