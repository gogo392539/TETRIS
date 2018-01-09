#include "main.h"
#include "game.h"
#include "menu.h"

int main(void) {
	int nSelect = 0;
	char arGameMap[MAPHEIGHT][MAPWIDTH];
	char arGamePreMap[PREMAPSIZE][PREMAPSIZE];

	nSelect = PrintingMainMenu();
	if (nSelect = START) {
		InitMap(arGameMap, arGamePreMap);
		PrintingMap(arGameMap, arGamePreMap);
	}

	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

char getKey()
{
	if (kbhit()) {
		return getch();
	}
	return '\0';
}
