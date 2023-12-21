#include "BattleshipGame.h"
#include <iostream>
#include <cstdlib>  
#include <ctime>    

int i = 0;
int playerFleet = 5;
int computerFleet = 5;

BattleshipGame::BattleshipGame()
{
    initializeFleet(playerFleet);
    initializeFleet(computerFleet);
}

void BattleshipGame::placeShips()
{
    std::cout << "Player, place your ships:";

    std::cout << "Computer is placing its ships...";
}

void BattleshipGame::placePlayerShips()//input section for player to place ships
{
    for (i = 0; i < 5; ++i)
    {
        std::cout << "Place " << playerFleet[i].getName() << std::endl;
        std::cout << "Enter direction (0 = vertical, 1 = horizontal): ";
        int direction;
        std::cin >> direction;
        std::cout << "Enter starting coordinates (x, y): ";
        int x, y;
        std::cin >> x >> y;

        playerFleet[i].setXLoc(x);
        playerFleet[i].setYLoc(y);
        playerFleet[i].setIsHorizontal(static_cast<bool>(direction));

        gameGrid.placeShips(playerFleet[i].getXLoc(), playerFleet[i].getYLoc(), playerFleet[i].getLength(),
            playerFleet[i].getIsHorizontal());
    }
}

void BattleshipGame::placeComputerShips()//randomly placing computers ships
{
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    for (i = 0; i < 5; ++i)
    {
        int direction = rand() % 2; // 0 for vertical, 1 for horizontal
        int x = rand() % 10;
        int y = rand() % 10;

        computerFleet[i].setXLoc(x);
        computerFleet[i].setYLoc(y);
        computerFleet[i].setIsHorizontal(static_cast<bool>(direction));

        gameGrid.placeShips(computerFleet[i].getXLoc(), computerFleet[i].getYLoc(), computerFleet[i].getLength(),
            computerFleet[i].getIsHorizontal());
    }
}

void BattleshipGame::shootAtPlayer()//computers turn
{
    int x, y;
    std::cout << "Computer's turn to shoot.Enter target coordinates (x, y): ";
    x = rand() % 10;
    y = rand() % 10;

    BattleshipGame::shoot(playerFleet, x, y);
}

void BattleshipGame::shootAtComputer()//players turn
{
    int x, y;
    std::cout << "Player's turn to shoot.Enter target coordinates (x, y): ";
    std::cin >> x >> y;

    shoot(computerFleet, x, y);
}

void BattleshipGame::shoot(Ship fleet[5], int x, int y)
{
    // Check if the coordinates are within the grid
    if (x >= 0 && x < 10 && y >= 0 && y < 10)
    {
        // Check if there is a ship at the target coordinates
        if (gameGrid.hasShip(x, y))
        {
            std::cout << "Hit!";
            // Update ship's HP
            for (int i = 0; i < 5; ++i)
            {
                if (fleet[i].isHit(x, y))
                {
                    std::cout << fleet[i].getName() << " is hit!";
                    if (fleet[i].isSunk())
                    {
                        std::cout << fleet[i].getName() << " is sunk!";
                    }
                    break;
                }
            }
        }
        else
        {
            std::cout << "Miss!";
        }
    }
    else
    {
        std::cout << "Invalid coordinates. Please enter coordinates within the grid.";
    }
}

void BattleshipGame::printAllGrids()
{
    gameGrid.printAllGrids();
}

void BattleshipGame::initializeFleet(Ship fleet[5]) //initializing the fleet
{
    fleet[0].setName("Carrier");
    fleet[0].setHp(5);
    fleet[0].setLength(5);

    fleet[1].setName("Battleship");
    fleet[1].setHp(4);
    fleet[1].setLength(4);

    fleet[2].setName("Cruiser");
    fleet[2].setHp(3);
    fleet[2].setLength(3);

    fleet[3].setName("Submarine");
    fleet[3].setHp(3);
    fleet[3].setLength(3);

    fleet[4].setName("Destroyer");
    fleet[4].setHp(2);
    fleet[4].setLength(2);
}

bool BattleshipGame::checkPlayerWin()
{
    for (int i = 0; i < 5; ++i)
    {
        if (!computerFleet[i].isSunk())
        {
            return false; // At least one ship is not sunk, player has not won yet
        }
    }
    return true; // All computer ships are sunk, player wins
}

void BattleshipGame::playGame()
{
    placeShips(); 

    while (true)
    {
        // Player's turn
        shootAtComputer();
        printAllGrids();

        // Check if player has won
        if (checkPlayerWin())
        {
            std::cout << "Congratulations! You have sunk all computer ships. You win!";
            break;
        }

        // Computer's turn
        shootAtPlayer();
        printAllGrids();

        // Check if computer has won
        if (checkComputerWin())
        {
            std::cout << "Game over! Computer has sunk all your ships. You lose!";
            break;
        }
    }
}

bool BattleshipGame::checkComputerWin()
{
    for (int i = 0; i < 5; ++i)
    {
        if (!playerFleet[i].isSunk())
        {
            return false; // At least one ship is not sunk, computer has not won yet
        }
    }
    return true; // All player ships are sunk, computer wins
}
