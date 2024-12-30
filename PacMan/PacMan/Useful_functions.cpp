#include "Useful_functions.h"
#include <string>
#include <iostream>
#include <random>

void freeze_screen()
{
	std::cin.get();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool validate_int(int& input)
{
	if (!std::cin.fail()) return true;

	std::cout << "\033[H\033[J";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cerr << "You entered the wrong data type! Try again.";
	std::cin.get();
	return false;
}

int generateRandomInt(int low, int high)
{
	static std::default_random_engine re{ std::random_device{}() };

	using Dist = std::uniform_int_distribution<int>;
	static Dist uid{};
	return uid(re, Dist::param_type{ low,high });
}