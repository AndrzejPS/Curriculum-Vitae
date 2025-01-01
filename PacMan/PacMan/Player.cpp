#include "PLayer.h"
#include "Useful_functions.h"
#include <iostream>
#include "Board.h"
#include <conio.h>


void spawnPlayer(std::vector<std::vector<char>>& board, const BoardParameters &board_size, PlayerProfile& player)
{
	while (true)
	{
		//1 and -1 to make sure the player won't be spawned on the eadges of the board or on obstacles
		player.coordinate_x = generateRandomInt(1, board_size.rows_number - 1);
		player.coordinate_y = generateRandomInt(1, board_size.columns_number - 1);
		if (board[player.coordinate_x][player.coordinate_y] != '#')
		{
			board[player.coordinate_x][player.coordinate_y] = 'C';
			break;
		}
	}
	
}

char getPlayerMovement()
{
	char move = _getch();
	move = tolower(move);
	return move;
}

void movePlayer(std::vector<std::vector<char>>& board, PlayerProfile& player, char move)
{
	switch (move)
	{
	case 'w': checkMovementResult(board, player, -1, 0); break; //up
	case 'a': checkMovementResult(board, player, 0, -1); break; //left
	case 's': checkMovementResult(board, player, 1, 0);  break; //down
	case 'd': checkMovementResult(board, player, 0, 1);  break; //right
	default:;
	}
}

void checkMovementResult(std::vector<std::vector<char>>& board, PlayerProfile& player, int distance_x,int distance_y)
{
	if (board[player.coordinate_x + distance_x][player.coordinate_y + distance_y] != '#')
	{
		//getting a point by a player
		if (board[player.coordinate_x + distance_x][player.coordinate_y + distance_y] == '*')
		{
			addPointToPlayer(player.score);
			board[player.coordinate_x + distance_x][player.coordinate_y + distance_y] = ' ';
		}

		std::swap(board[player.coordinate_x][player.coordinate_y], board[player.coordinate_x + distance_x][player.coordinate_y + distance_y]);

		player.coordinate_x = player.coordinate_x + distance_x;
		player.coordinate_y = player.coordinate_y + distance_y;
	}
}

void addPointToPlayer(int& score)
{
	score++;
}