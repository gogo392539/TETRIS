#include "game.h"

int arBlocks[7][4][4] = {
	{
		{ EMPTY, BLOCK, EMPTY, EMPTY },
		{ EMPTY, BLOCK, EMPTY, EMPTY },
		{ EMPTY, BLOCK, EMPTY, EMPTY },
		{ EMPTY, BLOCK, EMPTY, EMPTY }
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

int arGameMap[MAPHEIGHT][MAPWIDTH] = { 0 };
int arGamePreMap[PREMAPSIZE][PREMAPSIZE] = { 0 };
int arBlock[4][4] = { 0 };

int nPosX = 16;
int nPosY = 3;
int nIdxX = 5;
int nIdxY = 1;

//int arStartIdx[2] = { 1, 5 };
//int arBlockIdx[2] = { 0, 0 };

void initMap() {
	//game map
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
	//pre game map
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

void initPreMap() {
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

void showPreBlock(int nBlockIdx) {
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

/////////////////////////////////////////////////////////

void showGameBlock(int nBlockIdx) {

	memcpy(arBlock, arBlocks[nBlockIdx], sizeof(arBlock));

	for (int i = 0; i < BLOCKSIZE; i++) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			gotoxy(nPosX + j * 2, nPosY + i);
			if (arBlock[i][j] == BLOCK) {
				printf("%s", MAPBLOCK);
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

//////////////////////////////////////////////////////////////////////

BOOL checkCrush(int nKey)
{
	BOOL bCheck = FALSE;

	switch (nKey)
	{
	case UP:

		break;
	case DOWN:
		//
		break;
	case LEFT:
		for (int i = 0; i < BLOCKSIZE; i++) {
			for (int j = 0; j < BLOCKSIZE; j++) {
				if (arBlock[i][j] == BLOCK && arGameMap[nIdxY + i][nIdxX + j - 1] == BLOCK) {
					return bCheck;
				}
			}
		}
		break;
	case RIGHT:
		for (int i = 0; i < BLOCKSIZE; i++) {
			for (int j = 0; j < BLOCKSIZE; j++) {
				if (arBlock[i][j] == BLOCK && arGameMap[nIdxY + i][nIdxX + j + 1] == BLOCK) {
					return bCheck;
				}
			}
		}
		break;
	}

	return TRUE;
}

void checkMoveKey(int nBlockIdx) {
	int nSelect = 0;
	int nRotCount = 0;
	int arTmpBlock[4][4] = { 0 };

	if (_kbhit()) {
		nSelect = _getch();
		if (nSelect == 224) {
			nSelect = _getch();
			switch (nSelect)
			{
			case UP:
				memcpy(arTmpBlock, arBlock, sizeof(arTmpBlock));
				nRotCount++;
				nRotCount = nRotCount % 4;
				for (int i = 0; i < BLOCKSIZE; i++) {
					for (int j = 0; j < BLOCKSIZE; j++) {
						gotoxy(nPosX + j * 2, nPosY + i);
						if (arBlock[i][j] == BLOCK) {
							printf("%s", MAPEMPTY);
						}
					}
					printf("\n");
				}
				rotationBlock(nRotCount);
				for (int i = 0; i < BLOCKSIZE; i++) {
					for (int j = 0; j < BLOCKSIZE; j++) {
						gotoxy(nPosX + j * 2, nPosY + i);
						if (arBlock[i][j] == BLOCK) {
							printf("%s", MAPBLOCK);
						}
					}
					printf("\n");
				}
				break;
			case DOWN:
				//
				break;
			case LEFT:
				if (checkCrush(LEFT)) {
					for (int i = 0; i < BLOCKSIZE; i++) {
						for (int j = 0; j < BLOCKSIZE; j++) {
							gotoxy(nPosX + j * 2, nPosY + i);
							if (arBlock[i][j] == BLOCK) {
								printf("%s", MAPEMPTY);
							}
						}
						printf("\n");
					}
					nPosX -= 2;
					nIdxX--;
					for (int i = 0; i < BLOCKSIZE; i++) {
						for (int j = 0; j < BLOCKSIZE; j++) {
							gotoxy(nPosX + j * 2, nPosY + i);
							if (arBlock[i][j] == BLOCK) {
								printf("%s", MAPBLOCK);
							}
						}
						printf("\n");
					}
				}
				break;
			case RIGHT:
				if (checkCrush(RIGHT)) {
					for (int i = 0; i < BLOCKSIZE; i++) {
						for (int j = 0; j < BLOCKSIZE; j++) {
							gotoxy(nPosX + j * 2, nPosY + i);
							if (arBlock[i][j] == BLOCK) {
								printf("%s", MAPEMPTY);
							}
						}
						printf("\n");
					}
					nPosX += 2;
					nIdxX++;
					for (int i = 0; i < BLOCKSIZE; i++) {
						for (int j = 0; j < BLOCKSIZE; j++) {
							gotoxy(nPosX + j * 2, nPosY + i);
							if (arBlock[i][j] == BLOCK) {
								printf("%s", MAPBLOCK);
							}
						}
						printf("\n");
					}
				}
				break;
			}
		}
	}
}

void rotationBlock(int nRotCount) {
	int arTmpBlock[4][4] = { 0 };
	memcpy(arTmpBlock, arBlock, sizeof(arTmpBlock));
	int nY = 0;
	int nCount = 0;

	nY = 3;
	for (int i = 0; i < BLOCKSIZE; i++) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			arBlock[i][j] = arTmpBlock[j][nY - i];
		}
	}

	for(int j = 0; j < 2; j++) {
		for (int i = 0; i < BLOCKSIZE; i++) {
			if (arGameMap[nIdxY + i][nIdxX] == BLOCK && arBlock[i][0] == BLOCK) {
				nPosX += 2;
				nIdxX++;
			}
		}
	}
	
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < BLOCKSIZE; i++) {
			if (arGameMap[nIdxY + i][nIdxX + 3] == BLOCK && arBlock[i][3] == BLOCK) {
				nPosX -= 2;
				nIdxX--;
			}
		}
	}
}

void downBlock() {
	Sleep(300);
	int nMapX = 0;
	int nMapY = 0;
	BOOL bCheckk = FALSE;

	for (int i = BLOCKSIZE - 1; i >= 0 ; i--) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			if (arBlock[i][j] == BLOCK && arGameMap[nIdxY + i + 1][nIdxX + j] == BLOCK) {
				bCheckk = TRUE;
				break;
			}
		}
		if (bCheckk)
			break;
	}

	if (bCheckk) {
		for (int i = 0; i < BLOCKSIZE; i++) {
			for (int j = 0; j < BLOCKSIZE; j++) {
				if (arBlock[i][j] == BLOCK) {
					arGameMap[nIdxY + i][nIdxX + j] = BLOCK;
				}
			}
		}
	}
	else {
		for (int i = 0; i < BLOCKSIZE; i++) {
			for (int j = 0; j < BLOCKSIZE; j++) {
				gotoxy(nPosX + j * 2, nPosY + i);
				if (arBlock[i][j] == BLOCK) {
					printf("%s", MAPEMPTY);
				}
			}
			printf("\n");
		}
		nPosY += 1;
		nIdxY++;
		for (int i = 0; i < BLOCKSIZE; i++) {
			for (int j = 0; j < BLOCKSIZE; j++) {
				gotoxy(nPosX + j * 2, nPosY + i);
				if (arBlock[i][j] == BLOCK) {
					printf("%s", MAPBLOCK);
				}
			}
			printf("\n");
		}
	}
}