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

		nPreBlockIdx = getBlockIdx();
		//nPreBlockIdx = 0;
		showPreBlock(nPreBlockIdx);
		showGameBlock(nPreBlockIdx);
		while (1) {
			for (int i = 0; i < 5; i++) {
				Sleep(100);
				checkMoveKey(nPreBlockIdx);
			}
			downBlock();
			
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