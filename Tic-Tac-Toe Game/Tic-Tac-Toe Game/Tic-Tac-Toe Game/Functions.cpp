#include "Functions.h"
#include <iostream>

void menu(profile& player, profile& Ai, std::map<int, char>& emblem_collection)
{
	int chosen_option;

	while (true)
	{
		std::cout << "The (Un)Classic Tic-Tac-Toe Game\n\n";
		std::cout << "Choose an option:\n1. New singleplayer game (PvE)\n2. New multiplayer game (PvP)\n3. High score table\n4. Game information\n5. Exit game" << std::endl;

		std::cin >> chosen_option;
		switch (chosen_option)
		{
			case 1: singleplayer_game(player, Ai, emblem_collection); break;
			case 2:
			case 3: 
			case 4:
			case 5: exit (0);
			default: std::cout << "There is no such an option! Pls, try again."; freeze_screen(); continue;
		}
		break;
	}
}

void singleplayer_game(profile& player, profile& Ai, std::map<int, char>& emblem_collection)
{
	system("cls");
	std::cout << "Type your nickname: ";
	std::cin >> player.profile_name;
	Ai.profile_name = "Computer";
	random_emblem_for_bot(Ai, emblem_collection, emblem_choice(emblem_collection, player));
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