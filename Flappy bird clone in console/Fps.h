#pragma once
#include <thread>
#include <chrono>

class Fps {

	std::chrono::system_clock::time_point pointA;
	std::chrono::system_clock::time_point pointB;

	int frameCount;
	double fps;
	std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

public:
	Fps() {
		pointA = std::chrono::system_clock::now();
		pointB = std::chrono::system_clock::now();
		fps = 0;
		frameCount = 0;
	}

	void limitFps(float ms) {

		pointA = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> work_time = pointA - pointB;

		if (work_time.count() < ms)
		{
			std::chrono::duration<double, std::milli> delta_ms(ms - work_time.count());
			auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
			std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
		}

		pointB = std::chrono::system_clock::now();
		std::chrono::duration<double, std::milli> sleep_time = pointB - pointA;
	}

	void displayFpsMonitor() {
		frameCount++;
		auto currentTime = std::chrono::high_resolution_clock::now();
		auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count();

		if (deltaTime >= 1000) {
			fps = static_cast<double>(frameCount) / deltaTime * 1000;
			std::string title = "FPS: " + std::to_string(fps);

			int len = MultiByteToWideChar(CP_UTF8, 0, title.c_str(), -1, NULL, 0);
			wchar_t* wideStr = new wchar_t[len];
			MultiByteToWideChar(CP_UTF8, 0, title.c_str(), -1, wideStr, len);
			SetConsoleTitle(wideStr);

			frameCount = 0;
			startTime = currentTime;
		}
	}
};
