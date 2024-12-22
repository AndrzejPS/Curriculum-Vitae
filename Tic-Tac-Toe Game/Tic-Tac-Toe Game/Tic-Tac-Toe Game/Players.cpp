#include "Players.h"
#include "Menu.h"



void players_turn(std::vector<std::vector<char>>& board, const int& board_size, profile& player)
{
	int row_number, column_number;
	bool taken_field;

	do
	{
		while(true)
		{
			write_board(board, board_size);
			std::cout << "Type the number of row (1-" << board_size << "): ";
			if (!type_validation_int(row_number)) continue;
			std::cout << "Type the number of column(1-" << board_size << "): ";
			if (!type_validation_int(column_number)) continue;

			if (row_number > 0 && row_number <= board_size && column_number > 0 && column_number <= board_size)
			{
				break;
			}
			else
			{
				system("cls");
				std::cout << "Your move is incorrect! Pls, try again.\n";
				freeze_screen();
				continue;
			}
		}

		if (board[row_number - 1][column_number - 1] != ' ')
		{
			taken_field = true;
			std::cout << "This field is already taken! Pls, try again.\n";
		}
		else
		{
			taken_field = false;
			board[row_number - 1][column_number - 1] = player.emblem;
		}

	} while (taken_field);

}

int emblem_choice(std::map<int, char>& emblem_collection, profile& player)
{
	while (true)
	{
		system("cls");
		std::cout << "Choose your emblem: \n";

		//printing available emblems
		for (const std::pair<int, char>& emblem : emblem_collection)
		{
			std::cout << emblem.first << ". " << emblem.second << std::endl;
		}


		int decision;
		if (!type_validation_int(decision)) continue;

		if (!emblem_collection.contains(decision))
		{
			system("cls");
			std::cout << "Chosen a wrong number! Pls, try again.";
			freeze_screen();
			continue;
		}
		player.emblem = emblem_collection[decision];
		return decision;
	}

}

void AI_turn(std::vector<std::vector<char>>& board, const int& board_size, profile& bot)
{
	int row_number, column_number;

	do
	{
		row_number = AI_move_generator(1, board_size);
		column_number = AI_move_generator(1, board_size);

	} while (board[row_number - 1][column_number - 1] != ' ');

	board[row_number - 1][column_number - 1] = bot.emblem;
}

int AI_move_generator(int low, int high)
{
	static std::default_random_engine re{ std::random_device{}() };

	using Dist = std::uniform_int_distribution<int>;
	static Dist uid{};
	return uid(re, Dist::param_type{ low,high });
}

void random_emblem_for_bot(profile& bot, std::map<int, char>& emblem_collection, int emblem_taken)
{
	int bot_emblem;
	do
	{
		bot_emblem = AI_move_generator(1, emblem_collection.size());

	} while (bot_emblem == emblem_taken);

	bot.emblem = emblem_collection[bot_emblem];
}

