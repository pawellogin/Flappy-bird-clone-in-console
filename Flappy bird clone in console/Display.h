#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <chrono>
#include <string>
#include "Map.h"

class Display {
	std::string output;
	Map* map;

public:
	Display(Map* m) : map(m)   {
		std::cout << "\033[?25l";
	}

	void displayClear() {
		output.clear();
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD cursorPos;

		cursorPos.X = 0;
		cursorPos.Y = 0;
		SetConsoleCursorPosition(hConsole, cursorPos);
	}

	void displayPrint() {
		for (int i = 0; i < map->HEIGHT - 1; i++) {
			for (int j = 0; j< map->WIDTH - 1; j++) {
				output += map->getPixelString(i, j);
			}
			output += "\033[40m\n";
		}
		std::cout << output;
		std::cout << "\033[40m";
	}
};