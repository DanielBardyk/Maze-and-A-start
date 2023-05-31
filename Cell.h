#pragma once

class Cell {
	int x, y;
	bool walkable;
	double gCost = 0;
	double hCost = 0;
	Cell *parent = nullptr;
public:
	Cell();
	Cell(int _x, int _y, bool _walkable);
	Cell(const Cell& other);

	bool operator!=(const Cell& other);

	void setGCost(double _gCost);

	void setHCost(double _hCost);

	void setParent(Cell *_parent);

	int getX();

	int getY();

	double getGCost();

	double getHCost();

	double getFCost();

	Cell *getParent();

	bool isWalkable();
};