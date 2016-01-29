#pragma once
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
	int addNeighbour(direction , Square*);
	Square *getNeighbour(direction);

	int getTargetDistance();
	int setTargetDistance(int);

private:
	int value;
	int freeFieldIndex;
	int targetDistance;

	Square *neighbours[4] = {};
};

