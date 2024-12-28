#include "Board.h"
#include <iostream>

int main()
{
	BoardParameters board_size;
	draw_board(create_board(choose_board_size(board_size)));
}


