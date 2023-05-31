#include "MazeReader.h"

void MazeReader::parseFileData(const vector<vector<char>> &fileData, const int rowNum, const int colNum, const string &fName)
{
	if (fileData.empty())
		throw invalid_argument("File " + fName + " is empty");

	if (rowNum < 2)
		throw invalid_argument("File " + fName + " has a maze of an invalid format. It must have at least two rows");

	if (colNum < 2)
		throw invalid_argument("File " + fName + " has a maze of an invalid format. It must have at least two columns");

	for (const vector<char> &row : fileData)
	{
		if (row.size() != colNum)
			throw invalid_argument("File " + fName + " has a maze of an invalid format. All rows must have the equal number of columns");
		for (const char rowElem : row)
		{
			if (rowElem != ' ' && rowElem != 'X')
				throw invalid_argument("File " + fName + " has a maze of an invalid format. Only ' ' and 'X' characters are allowed");
		}
	}
}

Maze MazeReader::readMaze(const fs::path &fpath)
{
	vector<vector<Cell>> cells;
	vector<vector<char>> fileData;
	int rowNum, colNum;

	fileData = readFile(fpath);
	rowNum = fileData.size();
	colNum = fileData[0].size();

	parseFileData(fileData, rowNum, colNum, fpath.filename().string());

	cells.resize(rowNum);

	for (int yCoord = 0; yCoord < rowNum; yCoord++)
	{
		for (int xCoord = 0; xCoord < colNum; xCoord++)
		{
			bool isWalkable = fileData[yCoord][xCoord] == 'X' ? false : true;
			cells[yCoord].push_back(Cell(xCoord, yCoord, isWalkable));
		}
	}
	Maze maze(cells);

	return maze;
}
