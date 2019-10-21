#pragma once
#include <chrono>
#include <iostream>



class Timer{
	public:
		Timer(){
			startTime = std::chrono::high_resolution_clock::now();
		}
		~Timer(){stop();}
		void stop(){
			auto eTime = std::chrono::high_resolution_clock::now();
			auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTime).time_since_epoch().count();
			auto end = std::chrono::time_point_cast<std::chrono::microseconds>(eTime).time_since_epoch().count();
			auto duration = end - start;
			double miliseconds = duration * 0.001;
			std::cout << "Time in miliseconds -> " << miliseconds << std::endl;
		}
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

};
