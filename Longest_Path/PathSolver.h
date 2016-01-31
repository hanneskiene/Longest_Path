#pragma once

#include "Board.h"

class PathSolver
{
public:
	PathSolver();
	~PathSolver();

	int setBoard(std::shared_ptr<Board>);
	int solveBoard();


private:
	std::shared_ptr<Board> board;

	int solveStep();
	int solveStepDist();
	int solveStepProb();
};

