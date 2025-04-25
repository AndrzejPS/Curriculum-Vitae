#include "Engine.h"

int main()
{
	Engine silnik(12,12);

	while (silnik.isGameRunning())
	{

		silnik.renderGame();
	}
}