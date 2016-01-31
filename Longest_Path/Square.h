#pragma once
#include <memory>
class Square
{
public:
	Square();
	Square(int par);
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

	int getProbability(direction);
	int setProbability(direction, int);

private:
	int value;
	int freeFieldIndex;
	int targetDistance;

	std::shared_ptr<Square> neighbours[4] = {};

	int probability[4] = {};
};

