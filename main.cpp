#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>

#include "MazeReader.h"
#include "Maze.h"
#include "Cell.h"
#include "PathSearcher.h"

namespace fs = std::filesystem;

int main(int argc, char **argv)
{
	/* if(argc != 2)
	{
		std::cerr << "You need to supply one argument to this program." << std::endl;
		return 1;
	} */

	// std::string filename = argv[1];
	std::string filename = "maze.txt";

	try
	{
		fs::path filepath = ".\\" + filename;

		MazeReader mazeReader;
		Maze maze = mazeReader.readMaze(filepath);

		Cell* startCell = maze.getCellByCoordinates(1, 5);
		Cell* endCell = maze.getCellByCoordinates(6, 1);

		PathSearcher search;
		search.findPath(maze, startCell, endCell);
	}
	catch(const invalid_argument& e)
	{
		cerr << e.what() << endl;
	}
	catch(const runtime_error& e)
	{
		cerr << e.what() << endl;
	}
	
	return 0;
}