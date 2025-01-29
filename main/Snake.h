#pragma once
#include "MemoryManager.h"
#include <ctime>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

class Snake
{
	MemoryManager manager;
	int maxSize;
	Coord* snake;
	Coord* absorbed;
	int absorbedFreePointer, absorbedNowPointer;
	Coord newCoord;
	int snakePointer;
	Direction direction;
	bool isGrow;

public:
	Snake(int);
	void print();
	
	void randCoord();

	void forward();

	// сменить направление движения
	void changeDirection(char symbol, int& result);
	
	char printOnMap(int x, int y);

	void pauseMenu();

	void grow();

	void absorb();
	
};

