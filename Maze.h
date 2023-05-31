#pragma once
#include <iostream>
#include <vector>

#include "Cell.h"

using namespace std;

class Maze
{
	vector<vector<Cell>> cells;
public:
	Maze(vector<vector<Cell>> &_cells);

	vector<Cell*> getCellNeighbours(Cell *cell);

	vector<vector<Cell*>> getCells();
	
	int getRows();

	int getCols();

	Cell* getCellByCoordinates(int _x, int _y);
};