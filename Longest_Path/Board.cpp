#include "Board.h"
#include <ctime>


Board::Board()
{
	sizeX = 10;
	sizeY = 10;
	initialize();
}

Board::Board(int parX, int parY)
{
	sizeX = parX;
	sizeY = parY;
	initialize();
}


Board::~Board()
{
}

int Board::initialize()
{
	//Initialize Squares
	for (int i = 0; i < sizeX; i++) {
		squares.push_back(*new std::vector<Square>);
		for (int z = 0; z < sizeY; z++) {
			squares.at(i).push_back(*new Square);
			if (i == 0 || i == sizeX - 1 || z == 0 || z == sizeY - 1)
				squares.at(i).at(z).setValue(0);
		}
	}

	placeRandomBlocks((int)(sqrt(sizeX * sizeY)/2));

	for (int i = 1; i < sizeX - 1; i++) {
		for (int z = 1; z < sizeY - 1; z++) {
			squares.at(i).at(z).addNeighbour(Square::LEFT, &squares.at(i).at(z - 1));
			squares.at(i).at(z).addNeighbour(Square::UP, &squares.at(i - 1).at(z));
			squares.at(i).at(z).addNeighbour(Square::RIGHT, &squares.at(i).at(z + 1));
			squares.at(i).at(z).addNeighbour(Square::DOWN, &squares.at(i + 1).at(z));

			squares.at(i).at(z).updateFreeFieldIndex();
		}
	}

	return 0;
}

int Board::getSizeX()
{
	return sizeX;
}

int Board::getSizeY()
{
	return sizeY;
}

int Board::getValueAt(int parX, int parY)
{
	return squares.at(parX).at(parY).getValue();
}

Square* Board::getSquareAt(int parX, int parY)
{
	return &squares.at(parX).at(parY);
}

int Board::getBoardIndex()
{
	int boardIndex = 0;
	for (int i = 1; i < sizeX - 1; i++) {
		for (int z = 1; z < sizeY - 1; z++) {
			boardIndex += squares.at(i).at(z).getFreeFieldIndex();
		}
	}
	return boardIndex;
}

int Board::placeRandomBlocks(int parC) 
{
	std::srand(std::time(0));
	for (int i = 0; i < parC; i++) {
		squares.at((std::rand() % sizeX - 1) + 1).at((std::rand() % sizeX - 1) + 1).setValue(0);
	}
	return true;
}

int Board::consoleValuesOut()
{
	std::cout << "Board Values" << std::endl;
	for (int i = 0; i < sizeX; i++) {
		for (int z = 0; z < sizeY; z++) {
		std::cout << getValueAt(i, z) << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

int Board::consoleDrawOut()
{
	std::cout << "Board Values" << std::endl;
	for (int i = 0; i < sizeX; i++) {
		for (int z = 0; z < sizeY; z++) {
			if(getValueAt(i, z) == 2)
				std::cout << "8" << " ";
			else if (getValueAt(i, z) == 0)
				std::cout << "+" << " ";
			else
				std::cout << " " << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

int Board::consoleEnvOut()
{
	std::cout << "Free Neighbours" << std::endl;
	for (int i = 0; i < sizeX; i++) {
		for (int z = 0; z < sizeY; z++) {
			std::cout << getSquareAt(i, z)->getFreeFieldIndex() << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}


Head * Board::getHead()
{
	return &head;
}
