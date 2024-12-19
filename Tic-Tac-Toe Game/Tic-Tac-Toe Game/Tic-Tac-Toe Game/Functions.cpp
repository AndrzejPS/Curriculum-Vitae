#include "Functions.h"
#include <iostream>

void write_menu()
{

}


char rematch()
{
	system("cls");
	std::cout << "Do you want to play once more?[Y/N]\n";
	char choice;
	
	while(true)
	{
		std::cin >> choice;
		choice = toupper(choice);
		if (choice != 'Y' && choice != 'N')
		{
			std::cout << "You've chosen a wrong letter! Pls, try again: ";
			continue;
		}

		break;
	}

	return choice;
}

void freeze_screen()
{
	std::cin.get();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}