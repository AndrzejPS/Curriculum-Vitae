#include "Functions.h"
#include <iostream>
#include <fstream>

int menu(profile& player1, profile& player2, std::map<int, char>& emblem_collection)
{
	int chosen_option;
	

	while (true)
	{
		system("cls");
		std::cout << "The (Un)Classic Tic-Tac-Toe Game\n\n";
		std::cout << "Choose an option:\n1. New singleplayer game (PvE)\n2. New multiplayer game (PvP)\n3. High score table\n4. Game information\n5. Exit game" << std::endl;

		std::cin >> chosen_option;
		system("cls");

		switch (chosen_option)
		{
			case 1: singleplayer_game(player1, player2, emblem_collection); return 1;
			case 2: multiplayer_game(player1, player2, emblem_collection); return 2;
			case 3: high_score_table(); break;
			case 4: game_information(); break;
			case 5: std::cout << "Bye,bye!"; return 5;
			default: std::cout << "There is no such an option! Pls, try again."; freeze_screen();
		}

	}
}

void singleplayer_game(profile& player, profile& Ai, std::map<int, char>& emblem_collection)
{
	std::cout << "Type your nickname: ";
	std::cin >> player.profile_name;
	Ai.profile_name = "Computer";
	random_emblem_for_bot(Ai, emblem_collection, emblem_choice(emblem_collection, player));
}

void multiplayer_game(profile& player1, profile& player2, std::map<int, char>& emblem_collection)
{
	std::cout << "Type nickname for the first player: ";
	std::cin >> player1.profile_name;
	int taken_emblem = emblem_choice(emblem_collection, player1);

	system("cls");
	std::cout << "Type nickname for the second player: ";
	std::cin >> player2.profile_name;

	while(true)
	{
		if (taken_emblem == emblem_choice(emblem_collection, player2))
		{
			system("cls");
			std::cout << "This emblem is already taken! Pls, choose other emblem.";
			freeze_screen();
			continue;
		}
		break;
	}
}

void high_score_table()
{
	std::fstream scores_file("Table of high scores.txt");
	std::string personal_high_score;

	if (!scores_file.good())
	{
		std::cout << "Coudn't load the the high score table. Error: code(2)!";
		freeze_screen();
		return;
	}

	while(getline(scores_file, personal_high_score))
	{
		std::cout << personal_high_score << std::endl;
	}

	scores_file.close();
	freeze_screen();
}

void game_information()
{
	std::fstream info_file("Information.txt");
	std::string line;

	if(!info_file.good())
	{
		std::cout << "Coudn't load the file. Error: code(3)!";
		freeze_screen();
		return;
	}

	while (getline(info_file, line))
	{
		std::cout << line << std::endl;
	}

	info_file.close();
	freeze_screen();
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