#pragma once

#include <vector>
#include <iostream>
#include "Square.h"
#include "Head.h"
#include  <memory>

class Board
{
public:
	Board();
	Board(int parX, int parY);
	~Board();

	int initialize();

	int getSizeX();
	int getSizeY();

	int getValueAt(int, int);

	std::shared_ptr<Square> getSquareAt(int , int);

	int getBoardIndex();

	int placeRandomBlocks(int);

	int placeRandomTarget();

	int consoleValuesOut();

	int consoleDrawOut();

	int consoleEnvOut();

	int consoleDistOut();

	Head * getHead();


private:
	int sizeX, sizeY;

	std::vector< std::vector<std::shared_ptr<Square>> > squares;

	Head head;
	
};

