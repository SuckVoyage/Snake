#include "MemoryManager.h"
#include "stdexcept"



MemoryManager::MemoryManager(size_t n) : counter(n)
{
	buffer = ::operator new(sizeof(Coord) * n);
	if (!buffer) 
	{
		throw std::runtime_error("not allocated memory");
	}
	memoryPointer = static_cast<bool*>(buffer);
}


void MemoryManager::printAdressPool() {
	for (int i = 0; i < counter * sizeof(Coord); i++) 
	{
		std::cout << i << "-" << &memoryPointer[i] << std::endl;
 	}
}

void* MemoryManager::alloc(int n)
{
	bool* tmp = memoryPointer;
	//printAdressPool();
	int count = 0;
	for (int i = (counter * sizeof(Coord)) - 1; i >= 0; i--) {
		if (&memoryPointer[i] == tmp )
		{
			break;
		}
		count++;
	}
	if (count - n > 0) 
	{
		memoryPointer += n;
		//std::cout << memoryPointer << std::endl;
		return tmp;
	}
	return nullptr;
}



