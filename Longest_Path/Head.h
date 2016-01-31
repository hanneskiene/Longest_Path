#pragma once

#include "Square.h"
#include <vector>

class Head
{
public:
	Head();
	~Head();

	int setCurrentSquare(std::shared_ptr<Square>);

	int move(Square::direction);

	int moveBack();

	int getStepCount();

	std::shared_ptr<Square> getCurrentSquare();

	int markStartAndEnd();

private:
	std::shared_ptr<Square> currentSquare;
	std::vector<std::shared_ptr<Square>> path;

	int modifyEnvironment();
};

