#include "Cell.h"

Cell::Cell() {};

Cell::Cell(int _x, int _y, bool _walkable)
: x(_x), y(_y), walkable(_walkable) {}

Cell::Cell(const Cell& other)
: x(other.x), y(other.y), walkable(other.walkable), gCost(other.gCost), hCost(other.hCost)
{
	if(other.parent != nullptr)
		setParent(other.parent);
	else
		parent = nullptr;
}

bool Cell::operator!=(const Cell& other)
{ return (x != other.x && y != other.y); }

void Cell::setGCost(double _gCost)
{ gCost = _gCost; }

void Cell::setHCost(double _hCost)
{ hCost = _hCost; }

void Cell::setParent(Cell *_parent)
{ parent = _parent; }

int Cell::getX()
{ return x; }

int Cell::getY() 
{ return y; }

double Cell::getGCost() 
{ return gCost; }

double Cell::getHCost() 
{ return hCost; }

double Cell::getFCost() 
{ return gCost + hCost; }

Cell* Cell::getParent() 
{ return parent; }

bool Cell::isWalkable() 
{ return walkable; }