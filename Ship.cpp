#include "Ship.h"

Ship::Ship()
{
	hp = -1;
	length = -1;
	xLoc = -1;
	yLoc = -1;
	isHorizontal = false;
	name = "";
}

Ship::Ship(int hp, int length, int xLoc, int yLoc, bool isHorizontal, std::string name) :
	hp(hp), length(length), xLoc(xLoc), yLoc(yLoc), isHorizontal(isHorizontal), name(name)
{
}

int Ship::getHp()
{
	return hp;
}

int Ship::getLength()
{
	return length;
}

int Ship::getXLoc()
{
	return xLoc;
}

int Ship::getYLoc()
{
	return yLoc;
}

bool Ship::getIsHorizontal()
{
	return isHorizontal;
}

bool Ship::isSunk()
{
	return false;
}

bool Ship::isHit()
{
	return false;
}

std::string Ship::getName()
{
	return name;
}

void Ship::setHp(int hp_)
{
	hp = hp_;
}

void Ship::setLength(int length_)
{
	length = length_;
}

void Ship::setXLoc(int xLoc_)
{
	xLoc = xLoc_;
}

void Ship::setYLoc(int yLoc_)
{
	yLoc = yLoc_;
}

void Ship::setIsHorizontal(bool isHorizontal_)
{
	isHorizontal = isHorizontal_;
}

void Ship::setName(std::string name_)
{
	name = name_;
}