#pragma once

#ifndef Direction

enum Direction { LEFT, RIGHT, UP, DOWN };

#endif


class Coord
{
	int x : 8;
	int	y : 8;
	bool isHard;
public:
	//##############################//
	// ctors
	Coord() : Coord(0,0,false){}
	Coord(int x, int y, bool isHard);

	//##############################//
	// Operators
	Coord& operator + (Direction dir);
	
	Coord& operator - () = delete;

	bool operator == (const Coord& other);	

	bool operator != (const Coord& other);
	
	//##############################//
	// Set - get 

	inline void setX(int x) { this->x = x; }

	inline void setY(int y) { this->y = y; }

	inline int getX() const { return x; }

	inline int getY() const { return y; }

	~Coord() {}
};

