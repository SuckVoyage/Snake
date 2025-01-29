#pragma once
#include <iostream>
#include "Coord.h"


class MemoryManager
{
	void* buffer;
	bool* memoryPointer;
	size_t counter;
public:
	MemoryManager(size_t n);
	
	void* alloc(int);

	void printAdressPool();

	~MemoryManager() 
	{
		::operator delete(buffer, sizeof(Coord) * counter);
	}
};
