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

	void placePixel(int widthId, int heightId, int color) {
		if (widthId > WIDTH || heightId > HEIGHT || widthId < 0 || heightId < 0) {
			return;
		}
		for (int i = widthId * 2; i < widthId * 2 + 2; i++) {
			matrix[heightId][i] = color;
		}
	}

	std::string getPixelString(int heightId,int widthId) {
		std::string output = "";

		if (widthId > WIDTH || heightId > HEIGHT || widthId < 0 || heightId < 0) {
			return output;
		}
		for (int j = widthId * 2; j < widthId * 2 + 2; j++) {
			if (matrix[heightId][j] != 0) {
				output += "\033[";
				output += std::to_string(matrix[heightId][j]);
				output += "m ";
			}
			else {
				output += "\033[40m ";
			}
		}

		return output;
	}

	void clear() {
		matrix.assign(HEIGHT,std::vector<int>(WIDTH *2,104));
	}

	int getData(int heightId,int widthId) {
		return matrix[heightId][widthId*2];
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