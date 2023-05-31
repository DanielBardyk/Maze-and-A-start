#pragma once
#include <iostream>
using namespace std;

#include "Cell.h"

class PriorityQueue {
	Cell **queue;
	int top;
	int rear; 
	int size;
	int capacity; 

	bool isLoaded();
	void resize();

public:
	PriorityQueue(int _capacity);
	~PriorityQueue();
	
	void enqueue(Cell *value);
	Cell *dequeue();
	bool isEmpty();
	int getSize();
};