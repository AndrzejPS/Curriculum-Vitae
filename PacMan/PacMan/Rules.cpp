#include "Rules.h"

bool chechWinCondtition(const int& score, const int& board_fields)
{
	
	return score == (board_fields -1);
}