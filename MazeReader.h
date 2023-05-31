#pragma once
#include <iostream>
#include <vector>
#include <exception>

#include "Cell.h"
#include "Maze.h"
#include "FileReader.h"

using namespace std;
namespace fs = std::filesystem;

class MazeReader : public FileReader
{
	void parseFileData(const vector<vector<char>> &fileData, const int rowNum, const int colNum, const string &fName);
public:
	Maze readMaze(const fs::path &fpath);
};