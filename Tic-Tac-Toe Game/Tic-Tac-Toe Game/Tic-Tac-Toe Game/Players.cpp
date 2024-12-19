#include "Players.h"
#include "Functions.h"
#include <iostream>

void players_turn(std::vector<std::vector<char>>& board, const int& board_size, profile& player)
{
	int row_number, column_number;
	bool move_correct, taken_field;

	do
	{
		do
		{

			std::cout << "Type the number of row (1-" << board_size << "): ";
			std::cin >> row_number;
			std::cout << "Type the number of column(1-" << board_size << "): ";
			std::cin >> column_number;

			if (row_number > 0 && row_number <= board_size && column_number > 0 && column_number <= board_size)
			{
				move_correct = true;
			}
			else
			{
				move_correct = false;
				std::cout << "Your move is incorrect! Pls, try again.\n";
			}

		} while (!move_correct);

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

		for (const std::pair<int, char>& emblem : emblem_collection)
		{
			std::cout << emblem.first << ". " << emblem.second << std::endl;
		}


		int decision;

		std::cin >> decision;
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