#ifndef BATTLESHIPGAME_H
#define BATTLESHIPGAME_H

#include "Grid.h"
#include "Ship.h"

class BattleshipGame
{
public:
	BattleshipGame();

	void placeShips();

	void placePlayerShips();

	void placeComputerShips();

	void shootAtPlayer();

	void shootAtComputer();

	void printAllGrids();

private:
	Grid gameGrid;
	Ship playerFleet[5];
	Ship computerFleet[5];

	void initializeFleet(Ship fleet[5]);
	bool checkPlayerWin();
	void playGame();
	bool checkComputerWin();
};

#endif // !BATTLESHIPGAME_H

