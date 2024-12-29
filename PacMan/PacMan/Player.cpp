#include "PLayer.h"
#include "Useful_functions.h"
#include "Board.h"

void spawnPlayer(std::vector<std::vector<char>>& board, const BoardParameters &board_size, PlayerProfile& player)
{
	player.coordinate_x = generateRandomInt(1, board_size.rows_number-1);
	player.coordinate_y = generateRandomInt(1, board_size.columns_number - 1);

	board[player.coordinate_x][player.coordinate_y] = 'C';
}