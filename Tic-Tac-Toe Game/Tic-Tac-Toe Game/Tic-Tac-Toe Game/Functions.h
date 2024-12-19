#pragma once
#include "Players.h"
#include "Board.h"

int menu(profile& player, profile& Ai, std::map<int, char>& emblem_collection);
void multiplayer_game(profile& player1, profile& player2, std::map<int, char>& emblem_collection);
void singleplayer_game(profile& player, profile& Ai, std::map<int, char>& emblem_collection);
void freeze_screen();
char rematch();



