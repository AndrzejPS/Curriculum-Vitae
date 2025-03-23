#include "Engine.h"

int main()
{
	Engine game;

	while (game.checkRunningCondition())
	{

		game.renderGame();
	}

}
