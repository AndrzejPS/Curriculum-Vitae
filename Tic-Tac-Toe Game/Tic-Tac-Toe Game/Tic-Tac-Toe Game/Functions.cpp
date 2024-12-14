#include "Functions.h"
#include <iostream>
#include <vector>

std::vector<std::vector<char>> create_board(const int& board_size)
{
	std::vector<std::vector<char>> board(board_size);
	
	for (std::vector<char> &value : board)
	{
		value.resize(board_size);
		for (char& board_field : value)
		{
			board_field = '1';
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

void players_turn(std::vector<std::vector<char>>& board, const int& board_size)
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

		if (board[row_number - 1][column_number - 1] != '1')
		{
			taken_field = true;
			std::cout << "This field is already taken! Pls, try again.\n";
		}
		else
		{
			taken_field = false;
			board[row_number - 1][column_number - 1] = 'X';
		}

	} while (taken_field);	
}

