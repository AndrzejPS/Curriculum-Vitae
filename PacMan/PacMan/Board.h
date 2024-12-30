#pragma once
#include <vector>

struct BoardParameters
{
	int rows_number=0, columns_number=0;
};

BoardParameters choose_board_size(BoardParameters &board_size);
std::vector<std::vector<char>> create_board(const BoardParameters& board_size);
void draw_board(const std::vector<std::vector<char>> board);

