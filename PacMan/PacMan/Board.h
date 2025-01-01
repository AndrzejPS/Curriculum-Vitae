#pragma once
#include <vector>

struct BoardParameters
{
	int rows_number = 0, columns_number = 0;
	int number_of_obstacles = 0;
	int board_surface_area = 0;
};

BoardParameters chooseBoardSize(BoardParameters &board_size);
std::vector<std::vector<char>> createBoard(const BoardParameters& board_size);
void generateObstacle(BoardParameters& board_sizes, std::vector<std::vector<char>>& board);
void drawBoard(const std::vector<std::vector<char>> board);


