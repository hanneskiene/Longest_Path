// Longest_Path.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>

#include "Board.h"
#include "PathSolver.h"
 

const int SIZEX = 13, SIZEY = 13;

Board *board;

int output();
int arrayOut();

int main()
{
	board = new Board(SIZEX, SIZEY);

	board->getHead()->setCurrentSquare(board->getSquareAt(1, 1));

	PathSolver solver;
	solver.setBoard(board);

	if (solver.solveBoard())
		output();
	else
		std::cout << "Failed" << std::endl;

	arrayOut();

	std::cin.get();

    return 0;
}

int output() 
{
	//board->consoleValuesOut();
	//std::cout << std::endl;
	//board->consoleEnvOut();
	//std::cout << std::endl;
	board->consoleDrawOut();

	std::cout << "Board Index: " << board->getBoardIndex() << std::endl;

	return 0;
}

int arrayOut() 
{
	std::ofstream data("output_data.txt");
	if (data.is_open()) {
		data << "case 28:" << std::endl;
		data << "map = [";
		board->getHead()->markStartAndEnd();
		for (int i = 0; i < board->getSizeX(); i++) {
			data << ",[";
			for (int z = 0; z < board->getSizeY(); z++) {
				if (board->getValueAt(i, z) == 2)
					data << "1" << ",";
				else if (board->getValueAt(i, z) == 1)
					data << "0" << ",";
				else
					data << board->getValueAt(i, z) << ",";
			}
			data << "]";
		}
		data << "];" << std::endl;

		data << "dimensionx = " << board->getSizeX() << ";" << std::endl;
		data << "dimensiony = " << board->getSizeY() << ";" << std::endl;
		data << "break;" << std::endl;
	}
	return true;
}

