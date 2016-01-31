#pragma once
#include <memory>
#include <vector>
class Square
{
public:
	Square();
	Square(int par);
	int initialize();
	~Square();

	enum direction { LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3 };

	int getValue();
	int setValue(int);

	int getFreeFieldIndex();
	int updateFreeFieldIndex();
	int addNeighbour(direction , std::shared_ptr<Square>);
	std::shared_ptr<Square> getNeighbour(direction);

	int getTargetDistance();
	int setTargetDistance(int);

	std::vector<int> getProbability();

	int getProbability(direction);
	int setProbability(direction, int);

	int updateProbabilityDist(int param);

	int setLastDir(direction);

	int getLastDir();

private:
	int value;
	int freeFieldIndex;
	int targetDistance;

	std::shared_ptr<Square> neighbours[4] = {};

	std::vector<int> probability;
	int lastDir = -1;
};

