#include "menu.h"

//char* arGameScore[10] = { 0 };
int arGameScore[10] = { 0 };

int PrintingMainMenu()
{
	system("cls");
	int nSelect = 0;
	BOOL bSelect = TRUE;
	char cSelect = '\0';

	system("mode con cols=80 lines=40");	//console 크기 설정

	gotoxy(0, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("===============================================================================\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("====================================TETRIS=====================================\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("===============================================================================\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printf("\n");
	printf("                   1. Game Start ('s')\n");
	printf("                   2. Ranking	 ('r')\n");
	printf("                   3. Exit	 ('e')\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	gotoxy(65, 30);
	printf("made by Junk\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	while (bSelect) {
		if (_kbhit()) {
			cSelect = _getch();
			switch (cSelect)
			{
			case 's':
			case 'S':
				nSelect = START;
				bSelect = FALSE;
				break;
			case 'r':
			case 'R':
				nSelect = RANK;
				bSelect = FALSE;
				break;
			case 'e':
			case 'E':
				nSelect = EXIT;
				bSelect = FALSE;
				break;
			default:
				break;
			}
		}
	}
	
	return nSelect;
}

void setGameScore(int nInput) {
	int nScoreIdx = 0;
	int nTmpScore = 0;
	int nScore = 0;

	nScore = nInput;
	for (int i = 0; i < 10; i++) {
		if (nScore > arGameScore[i]) {
			nScoreIdx = i;
		}
	}

	for (int i = nScoreIdx; i < 10; i++) {
		nTmpScore = arGameScore[i];
		arGameScore[i] = nScore;
		nScore = nTmpScore;
	}

}

void showRanking() {
	system("cls");

	system("mode con cols=40 lines=20");

	int nRank = 0;
	char cSelect = '\0';

	printf("\n");
	printf("  Ranking Top10! \n");
	printf("\n");

	nRank = 1;
	for (int i = 0; i < 10; i++) {
		if (arGameScore[i] == 0) {
			printf(" %d.		BLANK \n", nRank);
		}
		else {
			printf(" %d.		%d \n", nRank, arGameScore[i]);
		}
		nRank++;
	}


	gotoxy(2, 15);
	printf("Back 	 : 'b' \n ");
	
	while (1) {
		cSelect = _getch();
		if (cSelect == 'b' || cSelect == 'B') {
			break;
		}
	}
}

BOOL finishGame()
{
	char cSelect = 0;
	gotoxy(20, 15);
	printf("게임을 종료하시겠습니까?(y/n)\n");

	cSelect = _getch();
	if (cSelect == 'N' || cSelect == 'n')
		return FALSE;

	return TRUE;
}
