#include "menu.h"

int PrintingMainMenu()
{
	system("cls");
	int nSelect = 0;
	BOOL bSelect = TRUE;
	char cSelect = '\0';

	system("mode con cols=80 lines=40");	//console 크기 설정

	gotoxy(0, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	printf("===============================================================================\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGRAY);
	printf("====================================TETRIS=====================================\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
	printf("===============================================================================\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTBLUE);
	printf("\n");
	printf("                   1. Game Start ('s')\n");
	printf("                   2. Ranking	 ('r')\n");
	printf("                   3. Exit	 ('e')\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTRED);
	gotoxy(65, 30);
	printf("made by Junk\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTGRAY);
	cSelect = getch();
	switch (cSelect)
	{
	case 's':
		nSelect = START;
		bSelect = FALSE;
		break;
	case 'r':
		nSelect = RANK;
		bSelect = FALSE;
		break;
	case 'e':
		nSelect = EXIT;
		bSelect = FALSE;
		break;
	default:
		break;
	}
	return nSelect;
}
