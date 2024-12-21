#include "Board.h"
#include "Functions.h"

int choose_board_size()
{
	int size;

	while (true)
	{
		system("cls");
		std::cout << "Choose the board size (type a length of the side of the board): ";
		std::cin >> size;
		if (size < 3)
		{
			system("cls");
			std::cout << "The length of the side must be higher than 3! Pls, try again.";
			freeze_screen();
			continue;
		}
		break;
	}

	return size;
}

std::vector<std::vector<char>> create_board(const int& board_size)
{
	std::vector<std::vector<char>> board(board_size);

	for (std::vector<char>& value : board)
	{
		value.resize(board_size);
		for (char& board_field : value)
		{
			board_field = ' ';
		}
	}
	return board;
}

void write_board(std::vector<std::vector<char>>& board, const int& board_size)
{
	system("cls");
	for (int i = 0; i < board_size; i++)
	{
		//columns
		for (int j = 0; j < board_size; j++)
		{
			std::cout << board[i][j];
			if (j < board_size - 1) std::cout << " | ";
		}
		std::cout << std::endl;

		if (i < board_size - 1)
		{
			//rows
			for (int c = 0; c < board_size; c++) std::cout << "---";

			//extra prints for rows to even a higher numbered sides of board
			for (int x = 0; x < board_size - 3; x++)std::cout << "-";
		}
		std::cout << std::endl;
	}
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

