#include "Square.h"



Square::Square()
{
	value = 1;
	freeFieldIndex = 0;
	targetDistance = -1;
}

Square::Square(int par)
{
	value = par;
	freeFieldIndex = 0;
	targetDistance = -1;
}


Square::~Square()
{
}

int Square::getValue()
{
	return value;
}

int Square::setValue(int par)
{
	value = par;
	return 0;
}

int Square::getFreeFieldIndex()
{
	return freeFieldIndex;
}

int Square::updateFreeFieldIndex()
{
	if (value == 2) {
		freeFieldIndex = 5;
	}
	else {
		freeFieldIndex = 0;

		for (int i = 0; i < 4; i++) {
			if (neighbours[i]) {
				if (neighbours[i]->getValue() == 1) {
					freeFieldIndex++;
				}
			}
		}
	}
	return 0;
}

int Square::addNeighbour(direction dir, Square *square)
{
	neighbours[dir] = square;
	return 0;
}

Square * Square::getNeighbour(direction dir)
{
	return neighbours[dir];
}

int Square::getTargetDistance()
{
	return targetDistance;
}

int Square::setTargetDistance(int param)
{
	targetDistance = param;
	return 0;
}
