#include "main.h"
#include "game.h"
#include "menu.h"

int main(void) {
	int nSelect = 0;
	int nPreBlockIdx = 0;
	int nGameBlockIdx = 0;
	int nBlockIdx = 0;

	nSelect = PrintingMainMenu();
	if (nSelect = START) {
		initGameScene();
		showGameScene();
		//randomBlock();
		showPostBlock();
		Sleep(1000);
		while (1) {
			randomBlock();
			initBlockPosition();
			showGameBlock();
			while (1) {
				for (int i = 0; i < 5; i++) {
					inputArrowKey();
					Sleep(100);
				}
				if (!downBlock()) {
					fixBlock();
					break;
				}
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