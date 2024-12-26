#include "Useful_functions.h"
#include <iostream>

void freeze_screen(const std::string& error_message)
{
	system("cls");
	std::cerr << error_message;
	std::cin.get();
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool validate_int(int& input)
{
		if (std::typeof(input) == typeof(int)) return true;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		freeze_screen("You entered the wrong data type! Try again.");
		return false;
}