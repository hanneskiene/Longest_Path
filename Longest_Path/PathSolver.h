#pragma once

#include "Board.h"

class PathSolver
{
public:
	PathSolver();
	~PathSolver();

	int setBoard(Board *);
	int solveBoard();


private:
	Board *board;

	int solveStep();
};

