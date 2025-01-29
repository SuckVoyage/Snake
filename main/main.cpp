// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRTDBG_MAP_ALLOC_
#include <stdlib.h>
#include <crtdbg.h>
#include "Snake.h"

void ClearScreen(HANDLE console) {
	// Получаем размеры консоли
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(console, &csbi);

	// Рассчитываем количество символов в буфере консоли
	DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Создаем буфер заполненный пробелами
	COORD coord = { 0, 0 };
	DWORD charsWritten;
	FillConsoleOutputCharacter(console, ' ', consoleSize, coord, &charsWritten);

	// Сбрасываем курсор в (0, 0)
	SetConsoleCursorPosition(console, coord);
}

void print(Snake& snake)
{
	std::cout << "\n\n\n\n\t\t\t";
	for (int i = 0; i < 22; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
	for (int i = 0; i < 20; i++)
	{
		std::cout << "\t\t\t#";
		for (int j = 0; j < 20; j++)
		{
			std::cout << snake.printOnMap(j, i);
		}
		std::cout << "#" << std::endl;
	}
	std::cout << "\t\t\t";
	for (int i = 0; i < 22; i++)
	{
		std::cout << "#";
	}
}

int main()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	try {
		int re;

		char ch;
		Snake a(400);
		int speed = 30, count = 0;
		while(1){
			/*if ((count++) % 20 == 0) 
			{
				speed -= 3;
				if (speed < 30) { speed = 30; }
				
			}*/
			a.forward();
			print(a);
			std::cout << std::endl << count << " speed - " << speed;
			Sleep(speed);
			ClearScreen(console);
			
			if (_kbhit()) 
			{
				ch = _getch();
				if (ch == 27)
					break;
				a.changeDirection(ch, re);
			}

			
		}
		print(a);
	}
	catch(std::exception& ex)
	{
		std::cerr << ex.what();
		std::cout << "ERROR";
	}
	std::cout << _CrtDumpMemoryLeaks();
}