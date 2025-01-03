#include "Board.h"
#include "Useful_functions.h"
#include <iostream>

BoardParameters chooseBoardSize(BoardParameters &board_size)
{
	while (true)
	{
		std::cout << "\033[H\033[J";
		std::cout << "Choose the board size (numbers of rows and columns, both greater than 2).\nNumber of rows: ";
		std::cin >> board_size.rows_number;
		std::cout << "Number of columns: ";
		std::cin>> board_size.columns_number;

		if(!validateInt(board_size.rows_number)) continue;
		if (!validateInt(board_size.columns_number)) continue;
		
		if (board_size.rows_number> 2 && board_size.columns_number >2) return board_size;

		std::cout << "\033[H\033[J";
		std::cerr << "The parameters of the board must be greater than 2!";
		freezeScreen();
	}
}

std::vector<std::vector<char>> createBoard(const BoardParameters& board_sizes)
{
	std::vector<std::vector<char>> board(board_sizes.rows_number+2); //+2 to make board eages

	for (std::vector<char> &row : board)
	{
		row.resize(board_sizes.columns_number+2);
	}

	//create map with walls and points
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1)
			{
				board[i][j] = board_sizes.building_elements[0]; //wall symbol
			}
			else
			{
				board[i][j] = board_sizes.building_elements[2]; // point symbol
			}
		}
	}
	return board;
}

void generateObstacle(BoardParameters &board_sizes, std::vector<std::vector<char>>&board)
{
	int fields_number = board_sizes.board_surface_area, obstacle_number = std::ceil((double) fields_number/10.0);

	while (obstacle_number-- > 0)
	{
		//create a new obstacle
		while (true)
		{
			int x = generateRandomInt(1, board_sizes.rows_number - 1);
			int y = generateRandomInt(1, board_sizes.columns_number - 1);
			if (board[x][y] != board_sizes.building_elements[1]) //obstacle symbol
			{
				board[x][y] = board_sizes.building_elements[1];  
				break;
			}
		}
		board_sizes.number_of_obstacles++;
	}
} 

void drawBoard(const std::vector<std::vector<char>> board)
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