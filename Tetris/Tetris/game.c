#include "game.h"

int arBlocks[7][4][4] = {
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

int arGameMap[MAPHEIGHT][MAPWIDTH];
int arGamePreMap[PREMAPSIZE][PREMAPSIZE];

int arStartIdx[2] = { 1, 4 };
int arBlockIdx[2] = { 0, 0 };

void initMap() {
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

void printingMap() {
	system("cls");
	gotoxy(7, 1);
	printf("Score : ");
	for (int i = 0; i < MAPHEIGHT; i++) {
		for (int j = 0; j < MAPWIDTH; j++) {
			gotoxy(6 + j*2, 2 + i);
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

int getBlockIdx() {
	int nBlockIdx = 0;
	srand((unsigned int)time(NULL));
	nBlockIdx = rand() % 7;
	return nBlockIdx;
}

int setPreBlock(int nBlockIdx) {
	int nBlockY = 0;
	int nBlockX = 0;
	
	for (int i = 1; i < PREMAPSIZE - 1; i++) {
		nBlockX = 0;
		for (int j = 1; j < PREMAPSIZE - 1; j++) {
			arGamePreMap[i][j] = arBlocks[nBlockIdx][nBlockY][nBlockX];
			nBlockX++;
		}
		nBlockY++;
	}
	return nBlockIdx;
}

void showPreBlock(int nBlockIdx) {
	gotoxy(42, 3);
	for (int i = 0; i < BLOCKSIZE; i++) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			gotoxy(42 + j * 2, 3 + i);
			if (arBlocks[nBlockIdx][i][j] == BLOCK) {
				printf("%s", MAPBLOCK);
			}
			else {
				printf("%s", MAPEMPTY);
			}
		}
		printf("\n");
	}
}

void setInitBlock(int nBlockIdx) {
	for (int i = 0; i < BLOCKSIZE; i++) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			gotoxy(16 + j * 2, 3 + i);
			if (arBlocks[nBlockIdx][i][j] == BLOCK) {
				printf("%s", MAPBLOCK);
			}
			else {
				printf("%s", MAPEMPTY);
			}
		}
		printf("\n");
	}
}

void showGameMap() {
	for (int i = 0; i < MAPHEIGHT; i++) {
		for (int j = 0; j < MAPWIDTH; j++) {
			gotoxy(6 + j * 2, 2 + i);
			if (arGameMap[i][j] == BLOCK) {
				printf("%s", MAPBLOCK);
			}
			else {
				printf("%s", MAPEMPTY);
			}

		}
		printf("\n");
	}
}

void setGameBlock(int nBlockIdx) {

}

void moveBlock(int nBlockIdx) {
	int nSelect = 0;
	int nLeft = 0;
	int nright = 0;

	
	nSelect = _getch();
	if (nSelect == 224) {
		nSelect = _getch();
		switch (nSelect)
		{
		case UP:
			//
			break;
		case DOWN:
			//
			break;
		case LEFT:
			showGameMap();
			arBlockIdx[1] -= 2;
			for (int i = 0; i < BLOCKSIZE; i++) {
				for (int j = 0; j < BLOCKSIZE; j++) {
					gotoxy(16 + j * 2 + arBlockIdx[1], 3 + i);
					if (arBlocks[nBlockIdx][i][j] == BLOCK) {
						printf("%s", MAPBLOCK);
					}
					else {
						printf("%s", MAPEMPTY);
					}
				}
				printf("\n");
			}
			break;
		case RIGHT:
			showGameMap();
			arBlockIdx[1] += 2;
			for (int i = 0; i < BLOCKSIZE; i++) {
				for (int j = 0; j < BLOCKSIZE; j++) {
					gotoxy(16 + j * 2 + arBlockIdx[1], 3 + i);
					if (arBlocks[nBlockIdx][i][j] == BLOCK) {
						printf("%s", MAPBLOCK);
					}
					else {
						printf("%s", MAPEMPTY);
					}
				}
				printf("\n");
			}
			break;
		default:
			break;
		}
	}
}