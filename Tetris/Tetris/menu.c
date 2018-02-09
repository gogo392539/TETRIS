#include "menu.h"

S_Ranking sRanking[10] = { 0 };

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

void sortGameRanking(char* sUserName, int nScore, int nRankingIdx)
{
	for (int i = 9; i >= 0; i--) {
		if (nRankingIdx == i) {
			if (nRankingIdx != 9) {
				sRanking[i + 1].nScore = sRanking[i].nScore;
				strcpy_s(sRanking[i + 1].sUserName, 256, sRanking[i].sUserName);
			}
			sRanking[i].nScore = nScore;
			strcpy_s(sRanking[i].sUserName, 256, sUserName);
			break;
		}
		else {
			if (i + 1 <= 9) {
				sRanking[i + 1].nScore = sRanking[i].nScore;
				strcpy_s(sRanking[i + 1].sUserName, 256, sRanking[i].sUserName);
			}
		}
	}
}

void showRanking()
{
	system("cls");

	system("mode con cols=40 lines=20");

	int nRank = 0;
	char cSelect = '\0';

	printf("\n");
	printf("  Ranking Top10! \n");
	printf("\n");

	nRank = 1;
	for (int i = 0; i < 10; i++) {
		if (sRanking[i].sUserName == "BLANK") {
			printf(" %2d. BLANK \n", nRank);
		}
		else {
			printf(" %2d. %s		 %d \n", nRank, sRanking[i].sUserName, sRanking[i].nScore);
		}
		nRank++;
	}


	gotoxy(2, 15);
	printf("main 	 : 'm' \n ");

	while (1) {
		cSelect = _getch();
		if (cSelect == 'm' || cSelect == 'M') {
			break;
		}
	}
}

void gameOver(int nScore)
{
	char sUserName[256] = { 0 };
	int nRankingIdx = 0;
	BOOL bRankingCheck = FALSE;
	char cSelect = '\0';
	system("mode con cols=80 lines=20");	//console 크기 설정

	gotoxy(0, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("===============================================================================\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("===================================GAME OVER===================================\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("===============================================================================\n");

	if (nScore != -1) {
		saveRanking(nScore);
	}
	else {
		Sleep(3000);
	}
}

void saveRanking(int nScore)
{
	char sUserName[256] = { 0 };
	int nRankingIdx = 0;
	BOOL bRankingCheck = FALSE;

	for (int i = 0; i < 10; i++) {
		if (nScore >= sRanking[i].nScore) {
			bRankingCheck = TRUE;
			nRankingIdx = i;
			break;
		}
	}

	if (bRankingCheck) {
		printf("Game Score : %d \n", nScore);
		printf("User Name  : ");
		scanf_s("%s", sUserName, 256);
		sortGameRanking(sUserName, nScore, nRankingIdx);
	}
	Sleep(300);
	showRanking();
}

void readFileRanking()
{
	FILE* fp = NULL;
	errno_t err;
	int nIndex = 0;
	char strBlank[] = "BLANK";

	err = fopen_s(&fp, "./ranking/ranking.txt", "rt");
	if (err != 0) {
		printf("file read error! \n");
	}

	while (!feof(fp)) {
		fscanf_s(fp, "%s %d", sRanking[nIndex].sUserName, 256, &sRanking[nIndex].nScore);
		nIndex++;
	}

	while (nIndex < 10) {
		sRanking[nIndex].nScore = 0;
		strcpy_s(sRanking[nIndex].sUserName, sizeof(strBlank), strBlank);
		nIndex++;
	}

	fclose(fp);
}

void writeFileranking()
{
	FILE* fp = NULL;
	errno_t err;
	int nIndex = 0;

	err = fopen_s(&fp, "./ranking/ranking.txt", "wt");
	if (err != 0) {
		printf("file write error! \n");
	}

	while (nIndex < 10) {
		fprintf_s(fp, "%s %d\n", sRanking[nIndex].sUserName, sRanking[nIndex].nScore);
		nIndex++;
	}

	fclose(fp);
}

BOOL finishGame()
{
	BOOL bFinishCheck = FALSE;
	char cSelect = 0;
	gotoxy(20, 15);
	printf("게임을 종료하시겠습니까?(y/n)\n");

	while (1) {
		cSelect = _getch();
		if (cSelect == 'N' || cSelect == 'n') {
			bFinishCheck = FALSE;
			break;
		}
		else if (cSelect == 'Y' || cSelect == 'y') {
			bFinishCheck = TRUE;
			break;
		}
	}
	
	return bFinishCheck;
}
