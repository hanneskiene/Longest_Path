#pragma once

#include "Square.h"
#include <vector>

class Head
{
public:
	Head();
	~Head();

	int setCurrentSquare(Square *);

	int move(Square::direction);

	int moveBack();

	int getStepCount();

	int markStartAndEnd();

private:
	Square *currentSquare;
	std::vector<Square*> path;

	int modifyEnvironment();
};

