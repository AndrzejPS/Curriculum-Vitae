#pragma once
#include <iostream>
#include <vector>

int choose_board_size();
std::vector<std::vector<char>> create_board(const int& board_size);
void write_board(std::vector<std::vector<char>>& board, const int& board_size);
void clear_board(std::vector<std::vector<char>>& board);