#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <chrono>
#include <string>

class Display {
	std::string output;
	std::vector<std::vector<int>>* matrix;

public:
	Display(std::vector<std::vector<int>> *m) : matrix(m)   {
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
		for (int i = 0; i < (*matrix).size(); i++) {
			for (int j = 0; j < (*matrix)[0].size(); j++) {
				if ((*matrix)[i][j] != 0) {
					output += "\033[";
					output += std::to_string((*matrix)[i][j]);
					output += "m ";
				}
				else {
					output += "\033[40m " ;
				}
			}
			output += "\033[40m\n";
		}

		std::cout << output;
		std::cout << "\033[40m";
	}

};