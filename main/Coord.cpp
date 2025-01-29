#include "Coord.h"


//##############################//
// ctors
Coord::Coord(int x, int y, bool isHard) : x(x), y(y), isHard(isHard)
{
	if (x < -128 || x > 127) 
	{
		this->x = 0;
	}
	if (y < -128 || y > 127)
	{
		this->y = 0;
	}
	if (this->x > 19 || this->x < 0) 
	{
		this->x = 0;
	}
	if (this->y > 19 || this->y < 0)
	{
		this->y = 0;
	}
}

//##############################//
// Operators
Coord& Coord::operator+(Direction dir)
{
	if (dir == LEFT) { x -= 1; }
	else if (dir == RIGHT) { x += 1; }
	else if (dir == DOWN) { y += 1; }
	else { y -= 1; }
	if (!isHard) {
		if (x < 0) { x = 19; }
		if (x > 19) { x = 0; }
		if (y < 0) { y = 19; }
		if (y > 19) { y = 0; }
	}
	return *this;
}

bool Coord::operator==(const Coord& other)
{
	if (this->x == other.x && this->y == other.y)
	{
		return true;
	}
	return false;
}

bool Coord::operator!=(const Coord& other)
{
	if (*this == other)
	{
		return false;
	}
	return true;
}
