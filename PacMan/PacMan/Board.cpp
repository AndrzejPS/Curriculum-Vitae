#include "Board.h"
#include "Useful_functions.h"
#include <iostream>

BoardParameters choose_board_size(BoardParameters &board_size)
{
	while (true)
	{
		std::cout << "\033[H\033[J";
		std::cout << "Choose the board size (numbers of rows and columns, both greater than 4).\nNumber of rows: ";
		std::cin >> board_size.rows_number;
		std::cout << "Number of columns: ";
		std::cin>> board_size.columns_number;

		if(!validate_int(board_size.rows_number)) continue;
		if (!validate_int(board_size.columns_number)) continue;
		
		if (board_size.rows_number> 4 && board_size.columns_number >4) return board_size;

		std::cout << "\033[H\033[J";
		std::cerr << "The parameters of the board must be greater than 4!";
		freeze_screen();
	}
}

std::vector<std::vector<char>> create_board(const BoardParameters& board_size)
{
	std::vector<std::vector<char>> board(board_size.rows_number);

	for (std::vector<char> &row : board)
	{
		row.resize(board_size.columns_number);
	}

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1)
			{
				board[i][j] = '#';
			}
			else
			{
				board[i][j] = '*';
			}
		}
	}
	return board;
}

void draw_board(const std::vector<std::vector<char>> board)
{
	for (auto& row : board)
	{
		for (const char& field : row)
		{
			std::cout << field<<" ";
		}
		std::cout << std::endl;
	}
}