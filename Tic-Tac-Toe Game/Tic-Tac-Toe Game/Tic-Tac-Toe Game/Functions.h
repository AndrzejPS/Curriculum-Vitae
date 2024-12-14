#pragma once
#include <vector>

std::vector<std::vector<char>> create_board(const int& board_size);
void write_board(std::vector<std::vector<char>> &board, const int& board_size);
void players_turn(std::vector<std::vector<char>>& board, const int& board_size);