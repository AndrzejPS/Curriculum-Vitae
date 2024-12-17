#pragma once
#include <vector>
#include <string>
#include <map>
#include <random>

struct player
{
	std::string players_name; 
	char emblem = ' ';
};

std::vector<std::vector<char>> create_board(const int& board_size);
void write_board(std::vector<std::vector<char>> &board, const int& board_size);
void players_turn(std::vector<std::vector<char>>& board, const int& board_size, player& profile);
int AI_move_generator(int low, int high);
void AI_turn(std::vector<std::vector<char>>& board, const int& board_size);
bool win_conditions(std::vector<std::vector<char>>& board, const int& board_size, player &profile);
int check_game_results();
bool free_spaces(std::vector<std::vector<char>>& board);
void write_menu(std::map<int, char>& emblem_collection, player& profile);
void freeze_screen();
void clear_board(std::vector<std::vector<char>>& board);
char rematch();