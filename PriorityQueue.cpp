#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int _capacity)
{
	capacity = _capacity;
	queue = new Cell*[capacity];

	top = -1;
	rear = -1;
	size = 0;
}

PriorityQueue::~PriorityQueue()
{
	for (int i=0; i < capacity; i++)
		delete queue[i];
	delete[] queue;
	queue = nullptr;
}

void PriorityQueue::enqueue(Cell *value)
{
	if (isLoaded())
		resize();

	rear++;
	size++;
	int index = -1;
	Cell *next_value;

	if (size == 1)
	{
		top = 0;
		queue[top] = value;
	}
	if (size > 1)
	{
		for (int i = top; i < rear; i++)
		{
			if (value->getFCost() < queue[i]->getFCost() 
				|| value->getFCost() == queue[i]->getFCost()
				&& value->getGCost() > queue[i]->getGCost())
			{
				next_value = queue[i];
				queue[i] = value;

				index = i;
				break;
			}
		}
		if (index != -1)
		{
			for (int i = rear; i > index + 1; i--)
				queue[i] = queue[i - 1];

			queue[index + 1] = next_value;
		}
		else
			queue[rear] = value;
	}
}

Cell *PriorityQueue::dequeue()
{
	Cell *value;
	if (!size)
		throw runtime_error("Underflow of priority queue, cannot perform dequeue");
	else
	{
		value = queue[top++];
		size--;

		if (!size) 
		{
			top = -1;
			rear = -1;
		}

		return value;
	}
}

bool PriorityQueue::isLoaded()
{ return (size / (capacity * 1.0) > 0.75); }

void PriorityQueue::resize()
{
	Cell **array_tmp = new Cell*[2 * size];

	for (int i = 0; i < size; i++)
		array_tmp[i] = queue[i];

	delete[] queue;

	queue = array_tmp;
	size *= 2;
}

int PriorityQueue::getSize()
{ return size; }

bool PriorityQueue::isEmpty()
{ return size == 0; }