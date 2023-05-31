#include "PathSearcher.h"

void PathSearcher::parseCells(Cell* startCell, Cell* endCell)
{
	if (!startCell->isWalkable())
		throw invalid_argument("Start cell is not walkable. Choose another cell");
	else if (!endCell->isWalkable())
		throw invalid_argument("End cell is not walkable. Choose another cell");
}

bool PathSearcher::isInList(Cell* cell, vector<Cell*>& array)
{
	for (Cell *presentCell : array)
	{
		if (presentCell->getX() == cell->getX() && presentCell->getY() == cell->getY())
			return true;
	}
	return false;
}

int PathSearcher::heuristic(Cell* cellA, Cell* cellB)
{
	return fabs(cellA->getX() - cellB->getX()) + fabs(cellA->getY() - cellB->getY());
}

void PathSearcher::retracePath(vector<Cell*>& closedList, vector<Cell*>& path, Cell* startCell, Cell* endCell)
{
	Cell *current = endCell;
	while (current != startCell)
	{
		path.insert(path.begin(), current);
		current = current->getParent();
	}
	path.insert(path.begin(), current);
}

void PathSearcher::showPath(Maze& maze, vector<Cell*>& path)
{
	int rows = maze.getRows();
	int cols = maze.getCols();

	char solvedMaze[rows][cols];

	for (vector<Cell*>& row : maze.getCells())
	{
		for (Cell* cell : row)
		{
			if (!cell->isWalkable())
				solvedMaze[cell->getY()][cell->getX()] = 'X';
			else if (!isInList(cell, path))
				solvedMaze[cell->getY()][cell->getX()] = ' ';
		}

		for (int i = 0; i < path.size(); i++)
		{
			Cell *curr = path[i];
			char asciiValue;
			if (i < 9)
				asciiValue = 49 + i;
			else
				asciiValue = 88 + i;

			solvedMaze[path[i]->getY()][path[i]->getX()] = asciiValue;
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << solvedMaze[i][j] << ' ';
		}
		cout << endl;
	}
}

void PathSearcher::findPath(Maze& maze, Cell* startCell, Cell* endCell)
{
	parseCells(startCell, endCell);
	PriorityQueue openList(5);
	vector<Cell*> closedList;
	vector<Cell*> path;
	Cell* currentCell;

	openList.enqueue(startCell);

	while (!openList.isEmpty())
	{
		// get the cell with the lowest f_cost, remove it from open list and add it to closed list
		currentCell = openList.dequeue();
		closedList.push_back(currentCell);

		// if current cell is a target, we found the path
		if (currentCell->getX() == endCell->getX() && currentCell->getY() == endCell->getY())
		{
			retracePath(closedList, path, startCell, endCell);
			showPath(maze, path);
			return;
		}

		// find the neighbour with the lowest f_cost and add it to open list
		for (Cell* neigbour : maze.getCellNeighbours(currentCell))
		{
			if (!neigbour->isWalkable() || isInList(neigbour, closedList))
				continue;

			int newCost = currentCell->getGCost() + 1;

			if (newCost < neigbour->getGCost() || !isInList(neigbour, closedList))
			{
				neigbour->setGCost(currentCell->getGCost() + 1);
				neigbour->setHCost(heuristic(neigbour, endCell));
				neigbour->setParent(currentCell);

				if (!isInList(neigbour, closedList))
					openList.enqueue(neigbour);
			}
		}
	}
}