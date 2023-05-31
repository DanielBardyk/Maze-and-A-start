#include "Maze.h"

Maze::Maze(vector<vector<Cell>>& _cells)
{ cells = _cells; }

vector<Cell*> Maze::getCellNeighbours(Cell *cell)
{
	vector<Cell*> neighbours;
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};

	for (int i = 0; i < 4; i++)
	{
		int checkX = cell->getX() + dx[i];
		int checkY = cell->getY() + dy[i];

		if (checkX >= 0 && checkX < getCols() && checkY >= 0 && checkY < getRows())
		{
			Cell *neigbour;
			neigbour = getCellByCoordinates(checkX, checkY);
			neighbours.push_back(neigbour);
		}
	}

	return neighbours;
}

vector<vector<Cell*>> Maze::getCells()
{
	int rowNum = getRows();
	int colNum = getCols();
	vector<vector<Cell*>> cell_ptrs;

	cell_ptrs.resize(rowNum, vector<Cell*>(colNum));
	
	for (int i=0; i < rowNum; i++)
	{
		for(int j=0; j < colNum; j++)
		{
			Cell *cellptr = &cells[i][j];
			cell_ptrs[i][j] = cellptr;
		}
	}
	return cell_ptrs;
}

int Maze::getRows()
{ return cells.size(); }

int Maze::getCols()
{ return cells[0].size(); }

Cell* Maze::getCellByCoordinates(int _x, int _y)
{
	for (vector<Cell>& row : cells)
	{
		for (Cell& cell : row)
		{
			if (cell.getX() == _x && cell.getY() == _y)
			{
				Cell *cellptr = &cell;
				return cellptr;
			}
		}
	}
	throw invalid_argument("Maze doesn't have Cell with this coordinates");
}
