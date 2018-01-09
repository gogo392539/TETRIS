#include "game.h"

arBlocks[7][4][4] = {
	{
		{ EMPTY, EMPTY, EMPTY, EMPTY },
		{ BLOCK, BLOCK, BLOCK, BLOCK },
		{ EMPTY, EMPTY, EMPTY, EMPTY },
		{ EMPTY, EMPTY, EMPTY, EMPTY }
	},
	{
		{ EMPTY, EMPTY, EMPTY, EMPTY },
		{ BLOCK, EMPTY, EMPTY, EMPTY },
		{ BLOCK, BLOCK, BLOCK, EMPTY },
		{ EMPTY, EMPTY, EMPTY, EMPTY }
	},
	{
		{ EMPTY, EMPTY, EMPTY, EMPTY },
		{ EMPTY, EMPTY, BLOCK, EMPTY },
		{ BLOCK, BLOCK, BLOCK, EMPTY },
		{ EMPTY, EMPTY, EMPTY, EMPTY }
	},
	{
		{ EMPTY, EMPTY, EMPTY, EMPTY },
		{ EMPTY, BLOCK, BLOCK, EMPTY },
		{ EMPTY, BLOCK, BLOCK, EMPTY },
		{ EMPTY, EMPTY, EMPTY, EMPTY }
	},
	{
		{ EMPTY, EMPTY, EMPTY, EMPTY },
		{ EMPTY, BLOCK, BLOCK, EMPTY },
		{ BLOCK, BLOCK, EMPTY, EMPTY },
		{ EMPTY, EMPTY, EMPTY, EMPTY }
	},
	{
		{ EMPTY, EMPTY, EMPTY, EMPTY },
		{ BLOCK, BLOCK, EMPTY, EMPTY },
		{ EMPTY, BLOCK, BLOCK, EMPTY },
		{ EMPTY, EMPTY, EMPTY, EMPTY }
	},
	{
		{ EMPTY, EMPTY, EMPTY, EMPTY },
		{ EMPTY, BLOCK, EMPTY, EMPTY },
		{ BLOCK, BLOCK, BLOCK, EMPTY },
		{ EMPTY, EMPTY, EMPTY, EMPTY }
	}
};

void InitMap(char (*arGameMap)[MAPWIDTH], char (*arGamePreMap)[PREMAPSIZE]) {
	for (int i = 0; i < MAPHEIGHT; i++) {
		for (int j = 0; j < MAPWIDTH; j++) {
			arGameMap[i][j] = EMPTY;
		}
	}
	for (int i = 0; i < MAPHEIGHT; i++) {
		arGameMap[i][0] = BLOCK;
		arGameMap[i][MAPWIDTH- 1] = BLOCK;
	}
	for (int i = 1; i < MAPWIDTH - 1; i++) {
		arGameMap[0][i] = BLOCK;
		arGameMap[MAPHEIGHT- 1][i] = BLOCK;
	}

	for (int i = 0; i < PREMAPSIZE; i++) {
		for (int j = 0; j < PREMAPSIZE; j++) {
			arGamePreMap[i][j] = EMPTY;
		}
	}
	for (int i = 0; i < PREMAPSIZE; i++) {
		arGamePreMap[i][0] = BLOCK;
		arGamePreMap[i][PREMAPSIZE - 1] = BLOCK;
	}
	for (int i = 1; i < PREMAPSIZE - 1; i++) {
		arGamePreMap[0][i] = BLOCK;
		arGamePreMap[PREMAPSIZE - 1][i] = BLOCK;
	}
}

void PrintingMap(char (*arGameMap)[MAPWIDTH], char (*arGamePreMap)[PREMAPSIZE]) {
	system("cls");
	gotoxy(5, 1);
	printf("Score : ");
	for (int i = 0; i < MAPHEIGHT; i++) {
		for (int j = 0; j < MAPWIDTH; j++) {
			gotoxy(5 + j*2, 2 + i);
			if (arGameMap[i][j] == BLOCK) {
				printf("%s", MAPBLOCK);
			}
			else {
				printf("%s", MAPEMPTY);
			}
			
		}
		printf("\n");
	}

	gotoxy(40, 1);
	printf("<Next>");
	for (int i = 0; i < PREMAPSIZE; i++) {
		for (int j = 0; j < PREMAPSIZE; j++) {
			gotoxy(40 + j * 2, 2 + i);
			if (arGamePreMap[i][j] == BLOCK) {
				printf("%s", MAPBLOCK);
			}
			else {
				printf("%s", MAPEMPTY);
			}
		}
		printf("\n");
	}

	gotoxy(40, 5 + PREMAPSIZE);
	printf("Left	 : ¡ç \n");
	gotoxy(40, 6 + PREMAPSIZE);
	printf("Right	 : ¡æ \n");
	gotoxy(40, 7 + PREMAPSIZE);
	printf("Rotation : ¡è \n");

	gotoxy(40, 1 + MAPHEIGHT);
	printf("Exit	 : 't'\n");
}