#include "Functions.h"

void freeze_screen()
{
	std::cin.get();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool type_validation_int(int& input)
{
	if (!(std::cin >> input))
	{
		system("cls");
		std::cerr << "Entered wrong data type! Pls try again.\n";

		//clearing stream
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//freezing screen
		std::cin.get();
		return false;
	}

	return true;
}
