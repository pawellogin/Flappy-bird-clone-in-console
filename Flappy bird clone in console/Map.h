#pragma once
#include <vector>

class Map {
	std::vector<std::vector<int>> matrix;
public:
	const int HEIGHT;
	const int WIDTH;

	Map(const int HEIGHT, const int WIDTH) : HEIGHT(HEIGHT), WIDTH(WIDTH) {
		matrix.resize(HEIGHT, std::vector<int>(WIDTH * 2, 104));
	}

	std::vector<std::vector<int>>* returnPointerMap() {
		return &matrix;
	}

	void placePixel(int width, int height, int color) {
		if (width > WIDTH || height > HEIGHT) {
			return;
		}
		for (int i = width * 2; i < width * 2 + 2; i++) {
			matrix[height][i] = color;
		}
	}

	void clear() {
		matrix.assign(HEIGHT,std::vector<int>(WIDTH *2,104));
	}

	void display() {
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				std::cout << matrix[i][j]<<"  ";
			}
			std::cout << "\n";
		}
		
	}
};