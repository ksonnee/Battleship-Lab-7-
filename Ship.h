#ifndef SHIP_H
#define SHIP_H

#include <string>

class Ship
{
public:
	Ship();
	Ship(int hp, int length, int xLoc, int yLoc, bool isHorizontal, std::string name);

	int getHp();
	int getLength();
	int getXLoc();
	int getYLoc();
	bool getIsHorizontal();
	bool isSunk();
	bool isHit();
	std::string getName();

	void setHp(int hp);
	void setLength(int length);
	void setXLoc(int xLoc);
	void setYLoc(int yLoc);
	void setIsHorizontal(bool isHorizontal);
	void isSunk(bool isSunk_);
	void isHit(bool isHit_);
	void setName(std::string name);

private:
	int hp;
	int length;
	int xLoc;
	int yLoc;
	bool isHorizontal;
	std::string name;
};

#endif // !SHIP_H


