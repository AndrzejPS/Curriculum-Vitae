#include <iostream>
#include "MazeLogic.h"
#include "Engine.h"

int main()
{
    //due to a lot of conditions with generating, it is advised to generate at least 13x13 maze
    //the parameters of maze must be odd numbers!
    Engine game_engine(15, 15);

    while (game_engine.isRunning())
    {
        game_engine.renderGame();
    }

}

