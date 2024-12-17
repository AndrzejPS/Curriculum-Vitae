#include "Functions.h"
#include <iostream>



std::vector<std::vector<char>> create_board(const int& board_size)
{
	std::vector<std::vector<char>> board(board_size);
	
	for (std::vector<char> &value : board)
	{
		value.resize(board_size);
		for (char& board_field : value)
		{
			board_field = ' ';
		}
	}
	return board;
}

void write_board(std::vector<std::vector<char>> &board, const int& board_size)
{
	system("cls");
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			std::cout << board[i][j];
			if (j < board_size - 1) std::cout << " | ";
		}

		std::cout << std::endl;
		if(i< board_size-1) for(int c = 0; c < board_size; c++) std::cout << "---";
		std::cout << std::endl;
	}
}

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

		} while(!move_correct);

		if (board[row_number-1][column_number-1] != ' ')
		{
			taken_field = true;
			std::cout << "This field is already taken! Pls, try again.\n";
		}
		else
		{
			taken_field = false;
			board[row_number-1][column_number-1] = player.emblem;
		}

	} while (taken_field);

}

void AI_turn(std::vector<std::vector<char>>& board, const int& board_size,profile& bot)
{
	int row_number, column_number;

	do
	{
		row_number = AI_move_generator(1, board_size);
		column_number = AI_move_generator(1, board_size);

	} while (board[row_number-1][column_number-1] != ' ');

	board[row_number-1][column_number-1] = bot.emblem;
}

int AI_move_generator(int low, int high)
{
	static std::default_random_engine re{ std::random_device{}() };

	using Dist = std::uniform_int_distribution<int>;
	static Dist uid{};
	return uid(re, Dist::param_type{ low,high });
}

bool win_conditions(std::vector<std::vector<char>>& board, const int& board_size, profile& player)
{
	int counter = 0;
	
	//horizontally
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 1; j < board_size; j++)
		{
			if (board[i][j - 1] == board[i][j] && board[i][j] != ' ') counter++;
			else break;
		}
		if (counter == board_size-1)  return true;
		else counter = 0;
	}

	//vertically
	for (int j = 0; j < board_size; j++)
	{
		for (int i = 1; i < board_size; i++)
		{
			if (board[i-1][j] == board[i][j] && board[i][j] != ' ') counter++;
			else break;
		}
		if (counter == board_size-1)  return true;
		else counter = 0;
	}

	//diagonally up-down
	for (int i = 1; i < board_size; i++)
	{ 
		int j = i;
		if (board[i-1][j-1] == board[i][j] && board[i][j] != ' ') counter++;
	}
	if (counter == board_size - 1) return true;
	else counter = 0;

	//diagonally down-up
	for (int i = board_size - 1; i > 0; i--)
	{
		int j = board_size -1 - i;
		if (board[i-1][j+1] == board[i][j] && board[i][j] != ' ') counter++;
	}
	if (counter == board_size - 1)  return true;
	
	return false;
}

int check_game_results()
{
	if (win_conditions) return 0;
	else if (!free_spaces) return 1;
	
	return 2;
}

bool free_spaces(std::vector<std::vector<char>>& board)
{
	for (std::vector<char> &fields : board)
	{
		for (char& freespaces : fields)
		{
			if (freespaces == ' ') return true;
		}
	}

	return false;
}

int emblem_choice(std::map<int, char> &emblem_collection, profile& player)
{
	while (true)
	{
		system("cls");
		std::cout<<"Choose your emblem: \n";

		for (const std::pair<int,char> &emblem : emblem_collection)
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

void freeze_screen()
{
	std::cin.get();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void clear_board(std::vector<std::vector<char>>& board)
{
	for (std::vector<char>& rows_and_columns : board)
	{
		for (char& fullfilled_fields : rows_and_columns)
		{
			fullfilled_fields = ' ';
		}
	}
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

void random_emblem_for_bot(profile& bot, std::map<int, char>& emblem_collection, int emblem_taken)
{
	int bot_emblem;
	do
	{
		bot_emblem = AI_move_generator(1, emblem_collection.size());

	} while (bot_emblem == emblem_taken);

	bot.emblem = emblem_collection[bot_emblem];
}