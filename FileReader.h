#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <sstream>
#include <exception>

using namespace std;
namespace fs = std::filesystem;

class FileReader {
	vector<char> splitLine(const string& line);
public:
	vector<vector<char>> readFile(const fs::path& fpath);
};