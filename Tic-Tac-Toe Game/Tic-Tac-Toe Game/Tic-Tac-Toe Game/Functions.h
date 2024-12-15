#pragma once
#include <vector>
#include <string>

struct player
{
	std::string players_name;
	bool victory = false; 
	char emblem = ' ';
};

std::vector<std::vector<char>> create_board(const int& board_size);
void write_board(std::vector<std::vector<char>> &board, const int& board_size);
void players_turn(std::vector<std::vector<char>>& board, const int& board_size);
int AI_move_generator(int low, int high);
void AI_turn(std::vector<std::vector<char>>& board, const int& board_size);
bool win_condition(std::vector<std::vector<char>>& board, const int& board_size, player &profile);