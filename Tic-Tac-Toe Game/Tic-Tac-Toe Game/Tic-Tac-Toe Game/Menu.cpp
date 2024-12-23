#include "Menu.h"

int menu(profile& player1, profile& player2, std::map<int, char>& emblem_collection, int& gamemode)
{
	int chosen_option;
	
	while (true)
	{
		system("cls");
		std::cout << "The (Un)Classic Tic-Tac-Toe Game\n\n";
		std::cout << "Choose an option:\n1. New singleplayer game (PvE)\n2. New multiplayer game (PvP)\n3. Leaderboard\n4. Game information\n5. Exit game" << std::endl;

		if(!type_validation_int(chosen_option)) continue;
		system("cls");

		switch (chosen_option)
		{
			case 1: singleplayer_game(player1, player2, emblem_collection, gamemode, make_leaderboard()); return 1;
			case 2: multiplayer_game(player1, player2, emblem_collection, gamemode, make_leaderboard()); return 2;
			case 3: show_leaderboard(make_leaderboard()); break;
			case 4: game_information(); break;
			case 5: std::cout << "Bye,bye!\n"; return 5;
			default: std::cout << "There is no such an option! Pls, try again."; freeze_screen();
		}

	}
}

void singleplayer_game(profile& player, profile& Ai, std::map<int, char>& emblem_collection, int& gamemode, std::vector<std::pair<std::string, int>> leaderboard)
{
	gamemode = gamemode_decision();
	system("cls");
	std::cout << "Type your nickname: ";
	std::cin >> player.profile_name;

	for (auto& score_info : leaderboard)
	{
		if (player.profile_name == score_info.first)
		{
			player.score = score_info.second;
			break;
		}
	}

	Ai.profile_name = "Computer";
	random_emblem_for_bot(Ai, emblem_collection, emblem_choice(emblem_collection, player));
}

void multiplayer_game(profile& player1, profile& player2, std::map<int, char>& emblem_collection, int& gamemode, std::vector<std::pair<std::string, int>> leaderboard)
{
	gamemode = gamemode_decision();
	system("cls");
	std::cout << "Type nickname for the first player: ";
	std::cin >> player1.profile_name;
	for (auto& score_info : leaderboard)
	{
		if (player1.profile_name == score_info.first)
		{
			player1.score = score_info.second;
			break;
		}
	}
	int taken_emblem = emblem_choice(emblem_collection, player1);

	while (true)
	{
		system("cls");
		std::cout << "Type nickname for the second player: ";
		std::cin >> player2.profile_name;
		if (player2.profile_name != player1.profile_name) break;

		system("cls");
		std::cerr << "This name is already taken. Pls, enter another one.";
		freeze_screen();
	}
	
	for (auto& score_info : leaderboard)
	{
		if (player2.profile_name == score_info.first)
		{
			player1.score = score_info.second;
			break;
		}
	}

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

int gamemode_decision()
{
	while (true)
	{
		system("cls");
		std::cout << "Which gamemod do you want to play?\n1. Classic mode\n2. Crazy mode\n";

		int decision;
		if(!type_validation_int(decision))continue;
		else if (decision == 1 || decision == 2) return decision;

		system("cls");
		std::cout << "There is no such an option! Pls, try again.";
		freeze_screen();
	}
}

void crazy_mode(std::vector<std::vector<char>> &board, const int& board_size)
{
	int row_number, column_number;

	row_number = AI_move_generator(0, board_size-1);
	column_number = AI_move_generator(0, board_size-1);
	board[row_number][column_number] = ' ';
	write_board(board, board_size);
	std::cout << "The field [" << row_number+1 << "][" << column_number+1 << "] was cleared.";
	freeze_screen();
}

void show_leaderboard(const std::vector<std::pair<std::string, int>> &leaderboard)
{
	if (leaderboard.empty())
	{
		std::cerr << "Couldn't load the leaderboard or the leaderboard does not exist. Error: code(2)!";
		freeze_screen();
		return;
	}

	std::cout << "~~The leaderboard~~\n\n";
	int counter = 1;

	for (auto& player_info : leaderboard)
	{
		std::cout << counter++ << ". ";
		std::cout << player_info.first<< " - " << player_info.second <<" points"<< std::endl;
	}
	freeze_screen();
}

void game_information()
{
	std::fstream info_file("Information.txt");
	std::string line;

	if(!info_file.good())
	{
		std::cerr << "Coudn't load the file. Error: code(3)!";
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
	char choice;

	while (true)
	{
		system("cls");
		std::cout << "Do you want to play once more?[Y/N]\n";
	
		std::cin >> choice;
		choice = toupper(choice);

		if (choice != 'Y' && choice != 'N')
		{
			system("cls");
			std::cout << "You've chosen a wrong letter! Pls, try again: ";
			freeze_screen();
			continue;
		}
		break;
	}

	return choice;
}

std::vector<std::pair<std::string,int>> make_leaderboard()
{
		std::vector<std::pair<std::string, int>> leaderboard;
		std::fstream scores_file("Leaderboard.txt");

		if (!scores_file.good())
		{
			return leaderboard;
		}

		std::string scores_data_buffer;

		//clearing the first line
		getline(scores_file, scores_data_buffer);

		while (getline(scores_file, scores_data_buffer))
		{
			std::stringstream score_data(scores_data_buffer);
			std::pair<std::string, int> score;
			std::string punctuation_marks;

			score_data >> score.first >> punctuation_marks >> score.second;
			leaderboard.push_back(score);
		}
		scores_file.close();

		//sorting numerically and alphabetically
		for (int i = 0; i < leaderboard.size(); i++)
		{
			for (int j = 1; j < leaderboard.size(); j++)
			{
				if (leaderboard[j - 1].second < leaderboard[j].second) swap(leaderboard[j - 1], leaderboard[j]);
				else if (leaderboard[j - 1].second == leaderboard[j].second)
				{
					if(leaderboard[j - 1].first < leaderboard[j].first) swap(leaderboard[j - 1], leaderboard[j]);
				}
			}
		}

		return leaderboard;	
}

void save_score_decision(std::vector<std::pair<std::string, int>> leaderboard,const profile &winner)
{
	char save_score_decision;

	while (true)
	{
		system("cls");
		std::cout << "Would you like (the winner) to save/update your score in the high score table?[Y/N]" << std::endl;

		std::cin >> save_score_decision;
		save_score_decision = toupper(save_score_decision);

		switch (save_score_decision)
		{
			case 'Y':
			{
				for (auto& winners_data : leaderboard)
				{
					//update existing score
					if (winners_data.first == winner.profile_name)
					{
						winners_data.second = winner.score;
						if (!save_score(leaderboard)) return;
						system("cls");
						std::cout << "The score has been updated\n";
						freeze_screen();
						return;
					}
				}

				//saving a new score;
				std::pair<std::string, int> new_high_score = { winner.profile_name,winner.score };
				leaderboard.push_back(new_high_score);
				if (!save_score(leaderboard)) return;
				system("cls");
				std::cout << "The score has been saved\n";
				freeze_screen();
				return;
			}
			case 'N': return;
			default: system("cls"); std::cout << "You've chosen a wrong letter! Pls, try again."; freeze_screen();
		}
	}
}

bool save_score(std::vector<std::pair<std::string, int>>& leaderboard)
{
	std::ofstream score_file("Leaderboard.txt");

	if (!score_file.good())
	{
		std::cerr << "Can't save the score. Code: error(4)";
		return false;
	}

	score_file << "Leaderboard\n";
	for (auto& winners_data : leaderboard)
	{
		score_file << winners_data.first << " - " << winners_data.second << '\n';
	}
	return true;

	score_file.close();
}

