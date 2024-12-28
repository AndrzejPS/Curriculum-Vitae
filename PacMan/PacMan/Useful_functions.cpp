#include "Useful_functions.h"
#include <iostream>

void freeze_screen()
{
	std::cin.get();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool validate_int(int& input)
{
	if (!std::cin.fail()) return true;

	system("cls");
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cerr << "You entered the wrong data type! Try again.";
	std::cin.get();
	return false;
}