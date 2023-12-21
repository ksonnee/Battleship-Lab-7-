#include "Grid.h"
#include <iostream>

Grid::Grid()
{
	initializeGrid(playerShipGrid);
	initializeGrid(playerShotGrid);
	initializeGrid(computerShipGrid);
	initializeGrid(computerShotGrid);
}

void Grid::placeShips(int x, int y, int size, bool isHorizontal)
{
	if (isHorizontal)
	{
		for (int j = 0; j < size; ++j)
		{
			playerShipGrid[x][y + j] = '#';
		}
	}
	else
	{
		for (int j = 0; j < size; ++j)
		{
			playerShipGrid[x + j][y] = '#';
		}
	}
}

void Grid::printAllGrids()
{
	std::cout << "Player Ship Grid" << std::endl;
	printGrid(playerShipGrid);
	std::cout << std::endl;

	std::cout << "Player Shot Grid" << std::endl;
	printGrid(playerShotGrid);
	std::cout << std::endl;

	std::cout << "Computer Ship Grid" << std::endl;
	printGrid(computerShipGrid);
	std::cout << std::endl;

	std::cout << "Computer Shot Grid" << std::endl;
	printGrid(computerShotGrid);
	std::cout << std::endl;
}

void Grid::printGrid(char grid[10][10])
{
	std::cout << "  ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " ";
		for (int j = 0; j < 10; j++)
		{
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Grid::initializeGrid(char grid[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			grid[i][j] = '~';
		}
	}
}
