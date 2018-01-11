#include "main.h"
#include "game.h"
#include "menu.h"

int main(void) {
	int nSelect = 0;
	int nPreBlockIdx = 0;
	int nGameBlockIdx = 0;

	nSelect = PrintingMainMenu();
	if (nSelect = START) {
		initMap();
		printingMap();
		for (int i = 0; i < 5; i++) {
			nPreBlockIdx = getBlockIdx();
			nGameBlockIdx = setPreBlock(nPreBlockIdx);
			showPreBlock(nPreBlockIdx);
			Sleep(1000);
			setInitBlock(nGameBlockIdx);
			while (1) {
				moveBlock(nGameBlockIdx);
			}
		}
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