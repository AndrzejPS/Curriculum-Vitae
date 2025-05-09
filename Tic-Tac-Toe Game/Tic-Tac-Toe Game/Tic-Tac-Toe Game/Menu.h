#pragma once
#include "Players.h"
#include "Board.h"
#include "Functions.h"
#include <map>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>

int menu(profile& player, profile& Ai, std::map<int, char>& emblem_collection, int& gamemode);
void singleplayer_game(profile& player, profile& Ai, std::map<int, char>& emblem_collection, int& gamemode, std::vector<std::pair<std::string, int>> leaderboard);
void multiplayer_game(profile& player1, profile& player2, std::map<int, char>& emblem_collection, int& gamemode, std::vector<std::pair<std::string, int>> leaderboard);
int gamemode_decision();
void crazy_mode(std::vector<std::vector<char>> &board, const int& board_size);
void show_leaderboard(const std::vector<std::pair<std::string, int>>&leaderboard);
std::vector<std::pair<std::string, int>> make_leaderboard();
void game_information();
void save_score_decision(std::vector<std::pair<std::string, int>> leaderboard, const profile& winner);
bool save_score(std::vector<std::pair<std::string, int>>& leaderboard);
char rematch();




