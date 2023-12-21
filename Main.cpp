#include <iostream>
#include "BattleshipGame.h"

int main()
{
	BattleshipGame game;

	game.placeShips();

	game.printAllGrids();

	return 0;
}