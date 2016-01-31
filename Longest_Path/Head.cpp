#include "Head.h"
#include <iostream>


Head::Head()
{
}


Head::~Head()
{
	std::cout << "Head Destroyed" << std::endl;
}

int Head::setCurrentSquare(std::shared_ptr<Square> par)
{
	currentSquare = par;
	currentSquare->setValue(2);
	path.push_back(currentSquare);

	modifyEnvironment();
	return 0;
}

int Head::modifyEnvironment()
{
	currentSquare->updateFreeFieldIndex();

	for (int i = 0; i < 4; i++) {
		currentSquare->getNeighbour(Square::direction(i))->updateFreeFieldIndex();
	}
	return 0;
}

int Head::couldMove(Square::direction dir)
{
	if (currentSquare && currentSquare->getNeighbour(dir)->getValue() == 1 && currentSquare->getNeighbour(dir)->getFreeFieldIndex() > 0)
		return true;
	else
		return false;
}

int Head::move(Square::direction dir)
{
	if (currentSquare && currentSquare->getNeighbour(dir)->getValue() == 1 && currentSquare->getNeighbour(dir)->getFreeFieldIndex() > 0) {
		currentSquare = currentSquare->getNeighbour(dir);
		currentSquare->setValue(2);
		currentSquare->setLastDir(dir);
		path.push_back(currentSquare);

		modifyEnvironment();
		return true;
	}
	else {
		return false;
	}
}

int Head::moveBack()
{
	currentSquare->setValue(1);
	modifyEnvironment();

	path.pop_back();
	currentSquare = path.back();

	return 0;
}

int Head::getStepCount()
{
	return path.size();
}

std::shared_ptr<Square> Head::getCurrentSquare()
{
	return currentSquare;
}

int Head::markStartAndEnd() 
{
	path.at(0)->setValue(3);
	path.back()->setValue(4);
	return true;
}

int Head::updatePathProb()
{
	if (path.size() < 1) return false;
	for (int i = path.size() - 1; i > 0; i--) {
		path.at(i)->updateProbabilityDist(path.size() - i);
	}
}
