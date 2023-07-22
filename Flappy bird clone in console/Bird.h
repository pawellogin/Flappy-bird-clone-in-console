#define NOMIMAX
#pragma once
#include <Windows.h>
#include <chrono>
#include <thread>

class Bird {
	std::vector<std::vector<int>>* matrix;
	
	std::chrono::time_point<std::chrono::high_resolution_clock> timeStart;

	float velocity;
	float MAX_VELOCITY = 1;
	bool isSpacePressed;
	
public:
	float x;
	float y;

	Bird(std::vector<std::vector<int>>* m) : matrix(m) {
		velocity = 0;
		isSpacePressed = 0;
		x = 5;
		y = 5;

		timeStart = std::chrono::high_resolution_clock::now();
	}

	void fall() {
		if (velocity < MAX_VELOCITY) {
			velocity += 0.1;
		}
		if (velocity > MAX_VELOCITY) {
			velocity = MAX_VELOCITY;
		}
		if (velocity < -MAX_VELOCITY) {
			velocity = -MAX_VELOCITY;
		}

		if (y < (*matrix).size() - 1) {
			y += velocity;
		}
		if (y > (*matrix).size() - 2) {
			y = (*matrix).size() - 3;
		}
		if (y < 0) {
			y = 0;
		}
	}

	void fly() {
		std::cout << velocity << "\n" << x << " " << y;
		isSpacePressed = GetAsyncKeyState(VK_SPACE) & 0x8000;

		auto currentTime = std::chrono::high_resolution_clock::now();
		auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - timeStart).count();

		if (deltaTime >= 100) {
				if (isSpacePressed && y > 6) {
					velocity -= 3;
				}

			timeStart = currentTime;
			return;
		}		
	}
};