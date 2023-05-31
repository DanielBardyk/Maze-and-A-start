#pragma once
#include <iostream>
#include <vector>
#include <cmath>

#include "Cell.h"
#include "Maze.h"
#include "PriorityQueue.h"

using namespace std;

class PathSearcher
{
	void parseCells(Cell* startCell, Cell* endCell);

	bool isInList(Cell* cell, vector<Cell*>& array);

	int heuristic(Cell* cellA, Cell* cellB);

	void retracePath(vector<Cell*>& closedList, vector<Cell*>& path, Cell* startCell, Cell* endCell);

	void showPath(Maze& maze, vector<Cell*>& path);

public:
	void findPath(Maze& maze, Cell* startCell, Cell* endCell);
};