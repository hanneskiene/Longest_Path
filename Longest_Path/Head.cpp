#include "Head.h"



Head::Head()
{
}


Head::~Head()
{
}

int Head::setCurrentSquare(Square* par)
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

int Head::move(Square::direction dir)
{
	if (currentSquare && currentSquare->getNeighbour(dir)->getValue() == 1) {
		currentSquare = currentSquare->getNeighbour(dir);
		currentSquare->setValue(2);
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

int Head::markStartAndEnd() {
	path.at(0)->setValue(3);
	path.back()->setValue(4);
	return true;
}
