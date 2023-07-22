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
	int pipeSize;
	int* score;

	std::vector<Pipe*> pipes;

public:

	Pipes(Map* m,int* s) : map(m),score(s) {
		WIDTH = map->WIDTH;
		HEIGHT = map->HEIGHT;

		pipeSize = 3;
	}

	void makePipes() {

		if (pipes.empty()) {
			pipes.push_back(new Pipe(map,pipeSize,score));
		}

		if (pipes[pipes.size() - 1]->returnPosition() < WIDTH - pipeSize*6) {
			pipes.push_back(new Pipe(map,pipeSize,score));
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
	}

	~Pipes() {
		for (Pipe* pipe : pipes) {
			delete pipe;
		}
		pipes.clear();
	}
};
