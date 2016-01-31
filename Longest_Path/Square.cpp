#include "Square.h"
#include <iostream>


Square::Square()
{
	value = 1;
	initialize();
}

Square::Square(int par)
{
	value = par;
	initialize();
}
int Square::initialize()
{
	freeFieldIndex = 0;
	targetDistance = -1;
	for (int i = 0; i < 4; i++) {
		probability.push_back(100);
	}
	return true;
}


Square::~Square()
{
	std::cout << "Square Destroyed" << std::endl;
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

int Square::addNeighbour(direction dir, std::shared_ptr<Square> square)
{
	neighbours[dir] = square;
	return 0;
}

std::shared_ptr<Square> Square::getNeighbour(direction dir)
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
	return true;
}

std::vector<int> Square::getProbability()
{
	return probability;
}

int Square::getProbability(direction dir)
{
	return probability[dir];
}

int Square::setProbability(direction dir, int param)
{
	probability[dir] = param;
	return true;
}

int Square::updateProbabilityDist(int param)
{
	probability[lastDir] = (int) (probability[lastDir] * std::pow(0.9, param));
	return true;
}

int Square::setLastDir(direction dir) 
{
	lastDir = dir;
	return true;
}

int Square::getLastDir() 
{
	return lastDir;
}
