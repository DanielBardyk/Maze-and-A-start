#include "fileReader.h"

vector<char> FileReader::splitLine(const string &line)
{
	vector<char> lineElems;
	for (int i = 0; i < line.length(); i += 2)
		lineElems.push_back(line[i]);

	return lineElems;
}

vector<vector<char>> FileReader::readFile(const fs::path &fpath)
{
	string line;
	vector<vector<char>> filesData;

	ifstream inputFile(fpath);

	if (!inputFile.is_open())
		throw runtime_error("Cannot open " + fpath.filename().string());

	while (getline(inputFile, line))
	{
		vector<char> splitedLine = splitLine(line);
		filesData.push_back(splitedLine);
	}
	inputFile.close();

	return filesData;
};