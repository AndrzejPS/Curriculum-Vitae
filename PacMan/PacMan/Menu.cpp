#include "Menu.h"
#include <iostream>
#include <chrono>

void showInGameTime(std::chrono::time_point<std::chrono::steady_clock>& start_time)
{
	auto actual_time = std::chrono::steady_clock::now() - start_time;

	std::cout << std::chrono::duration_cast<std::chrono::minutes>(actual_time).count()
		<< ":" << std::chrono::duration_cast<std::chrono::seconds>(actual_time).count()%60
		<< ":" << std::chrono::duration_cast<std::chrono::milliseconds>(actual_time).count()%1000;
}