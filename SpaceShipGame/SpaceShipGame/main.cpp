#include "Engine.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	Engine game;

	while (game.checkRunningCondition())
	{
		
		game.renderGame();

	}

}
