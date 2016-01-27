#pragma once

#include <vector>
#include <iostream>
#include "Square.h"
#include "Head.h"

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

	Square* getSquareAt(int , int);

	int getBoardIndex();

	int placeRandomBlocks(int);

	int consoleValuesOut();

	int consoleDrawOut();

	int consoleEnvOut();

	Head * getHead();


private:
	int sizeX, sizeY;

	std::vector< std::vector<Square> > squares;

	Head head;
	
};

