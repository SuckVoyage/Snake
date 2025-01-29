#include "Snake.h"

Snake::Snake(int maxSize) : manager(maxSize * 2), maxSize(maxSize)
{
	snake = static_cast<Coord*>(manager.alloc(maxSize));
	absorbed = static_cast<Coord*>(manager.alloc(maxSize));
	std::cout << sizeof(snake) << std::endl << sizeof(manager) << std::endl;
	snakePointer = 0;
	absorbedFreePointer = 0;
	absorbedNowPointer = 0;
	int x = 5, y = 5;
	while (snakePointer < 3)
	{
		new(&snake[snakePointer++]) Coord(x++, y, false);
	}
	randCoord();
	isGrow = false;
	direction = LEFT;
}

void Snake::print()
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << std::endl << snake[i].getX() << " - " << snake[i].getY() << std::endl;
	}
	std::cout << "NEW\n" << newCoord.getX() << " - " << newCoord.getY() << std::endl;
}


void Snake::randCoord()
{
	srand(time(0));
	bool created = false, sucsess = true;
	int x = rand() % 20;
	int y = rand() % 20;
	while (!created) {
		for (int i = 0; i < snakePointer; i++) 
		{
			if (snake[i].getX() == x && snake[i].getY() == y)
			{
				sucsess = false;
				x += 3;
				if (x > 19)
				{
					x = 0;
					y += 3;
					if (y > 19) { y = 0; }
				}
				break;
			}
			sucsess = true;
		}
		if (!sucsess) { continue; }
		created = true;
		newCoord.setX(x);
		newCoord.setY(y);
	}
}

void Snake::forward()
{
	if (isGrow) 
	{
		grow();
	}
	for (int i = snakePointer - 1; i >= 0; i--) 
	{
		if (i > 0)
			snake[i] = snake[i - 1];
		else
			snake[i] = snake[i] + direction;
	}
	if (snake[snakePointer - 1] == absorbed[absorbedNowPointer]) { isGrow = true; }
	absorb();
}

void Snake::changeDirection(char symbol, int& result) {
	switch (symbol)
	{
	case 'w':
	case 'W':
		if (direction != Direction::DOWN)
			direction = Direction::UP;
		break;
	case 's':
	case 'S':
		if (direction != Direction::UP)
			direction = Direction::DOWN;
		break;
	case 'a':
	case 'A':
		if (direction != Direction::RIGHT)
			direction = Direction::LEFT;
		break;
	case 'd':
	case 'D':
		if (direction != Direction::LEFT)
			direction = Direction::RIGHT;
		break;
	case' ':
		system("cls");
		pauseMenu();
		std::cin >> result;
		break;
	default:
		break;
	}
}

char Snake::printOnMap(int x, int y)
{
	if (newCoord.getX() == x && newCoord.getY() == y) { return '*'; }
	for (int i = 0; i < snakePointer; i++) 
	{
		if (snake[i].getX() == x && snake[i].getY() == y) 
		{
			for (int i = absorbedNowPointer; i < absorbedFreePointer; i++) 
			{
				if (absorbed[i].getX() == x && absorbed[i].getY() == y) 
				{
					return 'O';
				}
			}
			return 'o';
		}
	}
	return ' ';
}

void Snake::pauseMenu()
{
	std::cout <<
		R"(
        Pause
----------------------
| Continue   - 1     |
----------------------
| Restart    - 2     |
----------------------
| Exit       - 0     |
----------------------)" << std::endl << "- ";
}

void Snake::grow()
{
	new(&snake[snakePointer++]) Coord(absorbed[absorbedNowPointer].getX(), absorbed[absorbedNowPointer].getY(), false);
	absorbedNowPointer++;
	isGrow = false;
}

void Snake::absorb()
{
	if (snake[0] == newCoord) 
	{
		new(&absorbed[absorbedFreePointer++]) Coord(newCoord.getX(), newCoord.getY(), false);
		randCoord();
	}
}

