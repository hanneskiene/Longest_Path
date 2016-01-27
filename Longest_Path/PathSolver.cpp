#include "PathSolver.h"

#include <ctime>


PathSolver::PathSolver()
{
	std::srand(std::time(0));
}


PathSolver::~PathSolver()
{
}

int PathSolver::setBoard(Board *par)
{
	board = par;
	return 0;
}

int PathSolver::solveBoard()
{
	int backSteps = 1;
	int highestIndex = 0;


	for (int i = 0; i < 100000; i++) {
		board->consoleDrawOut();
		//std::cin.get();
		system("cls");
		if (!solveStep()) {
			for (int i = 0; i < backSteps; i++)
				board->getHead()->moveBack();
			backSteps++;
			if (backSteps >= board->getHead()->getStepCount() - 1) {
				backSteps = 1;
			}
		}
		int currentIndex = board->getBoardIndex();
		if (currentIndex > (board->getSizeX() - 2)*(board->getSizeX() - 2)* 4.5 ) {
		//if(currentIndex > 520){
			return true;
		}
		if (currentIndex > highestIndex) {
			highestIndex = currentIndex;
			//std::cout << "Step: " << i << " Index: " << highestIndex << std::endl;
			//board->consoleDrawOut();
		}
	}
	return false;
}

int PathSolver::solveStep()
{
	int currentHighestBoardIndex = 2;

	std::vector<Square::direction> possibleSteps;

	for (int i = 0; i < 4; i++) {
		if (board->getHead()->move(Square::direction(i))) {
			int thisIndex = board->getBoardIndex();
			if (thisIndex >= currentHighestBoardIndex) {
				currentHighestBoardIndex = thisIndex;
				possibleSteps.push_back(Square::direction(i));
			}
			//possibleSteps.push_back(Square::direction(i));
			board->getHead()->moveBack();
		}
	}
	if (possibleSteps.size() > 0) {
		int dir = possibleSteps.at(((int)(std::rand() % possibleSteps.size())));
		board->getHead()->move(Square::direction(dir));
		return true;
	}
	else {
		return false;
	}

	
}
