#include "PathSolver.h"

#include <ctime>

//#define debug


PathSolver::PathSolver()
{
	std::srand(std::time(0));
}


PathSolver::~PathSolver()
{
}

int PathSolver::setBoard(std::shared_ptr<Board> par)
{
	board = par;
	return 0;
}

int PathSolver::solveBoard()
{
	int backSteps = 1;
	int highestIndex = 0;


	for (int i = 0; i < 100000; i++) {
#ifdef debug
		system("cls");
		board->consoleDrawOut();
		//std::cin.get();
#endif
		if (!solveStepProb()) {
			//std::cin.get();
			board->getHead()->updatePathProb();
			for (int i = 0; i < backSteps; i++)
				board->getHead()->moveBack();
			backSteps++;
			if (backSteps >= board->getHead()->getStepCount() - 1) {
				backSteps = 1;
			}
		}
		int currentIndex = board->getBoardIndex();
		if (currentIndex > (board->getSizeX() - 2)*(board->getSizeX() - 2)* 4.1 ) {
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
	int highestDistance = 0;

	std::vector<Square::direction> possibleSteps;

	//Move into each direction once
	for (int i = 0; i < 4; i++) {
		if (board->getHead()->move(Square::direction(i))) {
			int thisIndex = board->getBoardIndex();

			if (thisIndex == currentHighestBoardIndex) {
				possibleSteps.push_back(Square::direction(i));
			}else if (thisIndex > currentHighestBoardIndex) {
				currentHighestBoardIndex = thisIndex;
				if(possibleSteps.size() > 0)
					possibleSteps.pop_back();
				possibleSteps.push_back(Square::direction(i));
			}
			//Reset the Step
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

int PathSolver::solveStepDist() 
{
	int highestDistance = 0;

	std::vector<Square::direction> possibleSteps;

	//Move into each direction once
	for (int i = 0; i < 4; i++) {
		if (board->getHead()->move(Square::direction(i))) {
			int currentDist = board->getHead()->getCurrentSquare()->getTargetDistance();

			if (currentDist == highestDistance) {
				possibleSteps.push_back(Square::direction(i));
			}
			else if (currentDist > highestDistance) {
				highestDistance = currentDist;
				if (possibleSteps.size() > 0)
					possibleSteps.pop_back();
				possibleSteps.push_back(Square::direction(i));
			}
			//Reset the Step
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

int PathSolver::solveStepProb()
{
	auto head = board->getHead();

	int total = 0;
	std::vector<int> possibleSteps = {};
	std::vector<int> probability = {};

	//Move into each direction once
	for (int i = 0; i < 4; i++) {
		if (head->couldMove(Square::direction(i))) {
			total += head->getCurrentSquare()->getProbability(Square::direction(i));
			probability.push_back(head->getCurrentSquare()->getProbability(Square::direction(i)));
			possibleSteps.push_back(i);
		}
	}
	if (possibleSteps.size() > 0) {
		int rand = (int)(std::rand() % total);
		for (int i = 0; i < possibleSteps.size(); i++) {
			int lower = 0;
			for (int z = 0; z < i; z++) {
				lower += probability.at(z);
			}
			if (rand > lower && rand < lower + probability.at(i)) {
				head->move(Square::direction(possibleSteps.at(i)));
			}
		}
	}
	else {
		return false;
	}


}
