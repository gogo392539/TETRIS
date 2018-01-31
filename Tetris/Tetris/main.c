#include "main.h"
#include "game.h"
#include "menu.h"

int main(void) {
	int nSelect = 0;
	int nScore = 0;
	BOOL bGameCheck = FALSE;

	readFileRanking();
	nSelect = PrintingMainMenu();
	while (1) {

		if (nSelect == START) {
			nScore = 0;
			bGameCheck = TRUE;
			initGameScene();
			showGameScene();
			setRandomBlock();
			showPostBlock();
			Sleep(1000);
			while (bGameCheck) {
				initBlockPosition();
				setGameBlock();
				if (!showGameBlock()) {
					break;
				}
				setRandomBlock();
				showPostBlock();
				while (1) {
					for (int i = 0; i < 5; i++) {
						if (!inputEventKey()) {
							gameOver(-1);
							bGameCheck = FALSE;
							break;
						}
						Sleep(100);
					}

					if (!bGameCheck)
						break;

					if (!downBlock()) {
						fixBlock();
						if (!dieGame()) {
							nScore = getGameScore();
							gameOver(nScore);
							bGameCheck = FALSE;
						}
						break;
					}
				} //end while
			} //end while
			writeFileranking();
			nSelect = PrintingMainMenu();
		}
		else if (nSelect == RANK) {
			showRanking();



			nSelect = PrintingMainMenu();
		}
		else if (nSelect == EXIT) {
			if (finishGame()) {
				break;
			}
			nSelect = PrintingMainMenu();
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