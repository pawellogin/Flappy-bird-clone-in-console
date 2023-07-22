#pragma once
#include <Windows.h>
#include <chrono>
#include <thread>
#include "Map.h"

class Bird {
	Map* map;
	
	std::chrono::time_point<std::chrono::high_resolution_clock> timeStart;

	float velocity;
	float MAX_VELOCITY;
	bool isSpacePressed;
	float fallAcceleration;
	float jumpPower;
	int jumpDelay; //in ms
	
public:
	float x;
	float y;

	Bird(Map* m) : map(m) {
		MAX_VELOCITY = 1;
		fallAcceleration = 0.2;
		jumpPower = 5;
		jumpDelay = 100;

		x = 5;
		y = 5;
		velocity = 0;
		isSpacePressed = 0;

		timeStart = std::chrono::high_resolution_clock::now();
	}

	bool fall() {
		if (velocity < MAX_VELOCITY) {
			velocity += fallAcceleration;
		}

		if (velocity > MAX_VELOCITY) {
			velocity = MAX_VELOCITY;
		}

		if (velocity < -MAX_VELOCITY) {
			velocity = -MAX_VELOCITY;
		}

			y += velocity;
	
		if (y > map->HEIGHT - 2) {
			return 0;
		}

		if (y < 0) {
			return 0;
		}

		return 1;
	}

	bool fly() {
		isSpacePressed = GetAsyncKeyState(VK_SPACE) & 0x8000;

		auto currentTime = std::chrono::high_resolution_clock::now();
		auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - timeStart).count();

		if (deltaTime >= jumpDelay) {
				if (isSpacePressed) {
					velocity -= jumpPower;
				}

			timeStart = currentTime;
			
			if (y <= 0) {
				return 0;
			}

		}
		return 1;
	}
};