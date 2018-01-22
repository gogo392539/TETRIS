#include "game.h"

const int arBlocks[7][4][4][4] = {
	{
		{
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ BLOCK, BLOCK, BLOCK, BLOCK },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ EMPTY, BLOCK, EMPTY, EMPTY }
		},
		{
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ BLOCK, BLOCK, BLOCK, BLOCK },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ EMPTY, BLOCK, EMPTY, EMPTY }
		},
	},
	{
		{
			{ BLOCK, EMPTY, EMPTY, EMPTY },
			{ BLOCK, BLOCK, BLOCK, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ BLOCK, BLOCK, BLOCK, EMPTY },
			{ EMPTY, EMPTY, BLOCK, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ BLOCK, EMPTY, EMPTY, EMPTY },
			{ BLOCK, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
	},
	{
		{
			{ EMPTY, EMPTY, BLOCK, EMPTY },
			{ BLOCK, BLOCK, BLOCK, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ BLOCK, BLOCK, BLOCK, EMPTY },
			{ BLOCK, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ BLOCK, EMPTY, EMPTY, EMPTY },
			{ BLOCK, EMPTY, EMPTY, EMPTY },
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
	},
	{
		{
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
	},
	{
		{
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ EMPTY, BLOCK, BLOCK, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ BLOCK, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ EMPTY, BLOCK, BLOCK, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ BLOCK, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
	},
	{
		{
			{ EMPTY, BLOCK, BLOCK, EMPTY },
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ BLOCK, EMPTY, EMPTY, EMPTY },
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ EMPTY, BLOCK, BLOCK, EMPTY },
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ BLOCK, EMPTY, EMPTY, EMPTY },
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
	},
	{
		{
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ BLOCK, BLOCK, BLOCK, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ BLOCK, BLOCK, BLOCK, EMPTY },
			{ EMPTY, BLOCK, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
		{
			{ BLOCK, EMPTY, EMPTY, EMPTY },
			{ BLOCK, BLOCK, EMPTY, EMPTY },
			{ BLOCK, EMPTY, EMPTY, EMPTY },
			{ EMPTY, EMPTY, EMPTY, EMPTY }
		},
	}
};
int arBlock[4][4] = { 0 };
int arGameMap[MAPHEIGHT][MAPWIDTH] = { 0 };
int arPostBlockMap[PREMAPSIZE][PREMAPSIZE] = { 0 };

int nBlockType = 0;
int nBlockRot = 0;

int nPosX = 0;
int nPosY = 0;

int nIdxX = 0;
int nIdxY = 0;

void initGameScene() {
	//game map
	for (int i = 0; i < MAPHEIGHT; i++) {
		for (int j = 0; j < MAPWIDTH; j++) {
			arGameMap[i][j] = EMPTY;
		}
	}
	for (int i = 0; i < MAPHEIGHT; i++) {
		arGameMap[i][0] = BLOCK;
		arGameMap[i][MAPWIDTH - 1] = BLOCK;
	}
	for (int i = 1; i < MAPWIDTH - 1; i++) {
		arGameMap[0][i] = BLOCK;
		arGameMap[MAPHEIGHT - 1][i] = BLOCK;
	}
	//pre game map
	for (int i = 0; i < PREMAPSIZE; i++) {
		for (int j = 0; j < PREMAPSIZE; j++) {
			arPostBlockMap[i][j] = EMPTY;
		}
	}
	for (int i = 0; i < PREMAPSIZE; i++) {
		arPostBlockMap[i][0] = BLOCK;
		arPostBlockMap[i][PREMAPSIZE - 1] = BLOCK;
	}
	for (int i = 1; i < PREMAPSIZE - 1; i++) {
		arPostBlockMap[0][i] = BLOCK;
		arPostBlockMap[PREMAPSIZE - 1][i] = BLOCK;
	}
}

void initBlockPosition() {
	nPosX = 16;
	nPosY = 3;
	nIdxX = 0;
	nIdxY = 0;
}

void showGameScene() {
	system("cls");
	gotoxy(7, 1);
	printf("Score : ");
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

	gotoxy(40, 1);
	printf("<Next>");
	for (int i = 0; i < PREMAPSIZE; i++) {
		for (int j = 0; j < PREMAPSIZE; j++) {
			gotoxy(40 + j * 2, 2 + i);
			if (arPostBlockMap[i][j] == BLOCK) {
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

//void showPostMap() {
//	for (int i = 0; i < PREMAPSIZE; i++) {
//		for (int j = 0; j < PREMAPSIZE; j++) {
//			gotoxy(40 + j * 2, 2 + i);
//			if (arPostBlockMap[i][j] == BLOCK) {
//				printf("%s", MAPBLOCK);
//			}
//			else {
//				printf("%s", MAPEMPTY);
//			}
//		}
//		printf("\n");
//	}
//}

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

void showPostBlock() {
	for (int i = 0; i < BLOCKSIZE; i++) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			gotoxy(42 + j * 2, 3 + i);
			if (arBlocks[nBlockType][nBlockRot][i][j] == BLOCK) {
				printf("%s", MAPBLOCK);
			}
			else {
				printf("%s", MAPEMPTY);
			}
		}
		printf("\n");
	}
}

void showGameBlock() {
	for (int i = 0; i < BLOCKSIZE; i++) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			gotoxy(nPosX + j * 2, nPosY + i);
			if (arBlocks[nBlockType][nBlockRot][i][j] == BLOCK) {
				printf("%s", MAPBLOCK);
			}
		}
		printf("\n");
	}
}

void eraseGameBlock() {
	for (int i = 0; i < BLOCKSIZE; i++) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			gotoxy(nPosX + j * 2, nPosY + i);
			if (arBlocks[nBlockType][nBlockRot][i][j] == BLOCK) {
				printf("%s", MAPEMPTY);
			}
		}
		printf("\n");
	}
}

void randomBlock() {
	srand((unsigned int)time(NULL));
	nBlockType = rand() % 7;
	nBlockRot = rand() % 4;
}

void setBlockIdx() {
	nIdxX = (nPosX - 6) / 2;
	nIdxY = (nPosY - 2);
}

BOOL downBlock() {
	if (!blockCrushCheck(0, 1, nBlockRot)) {
		return FALSE;
	}
	eraseGameBlock();
	downArrow();
	showGameBlock();
	return TRUE;
}

void settingBlock() {
	memcpy(arBlock, arBlocks[nBlockType][nBlockType], sizeof(arBlock));
}

BOOL blockCrushCheck(int nX, int nY, int nRot) {
	BOOL bCheck = FALSE;
	int nTmpIdxX = 0;
	int nTmpIdxY = 0;

	nTmpIdxX = ((nPosX - 6) / 2) + nX;
	nTmpIdxY = (nPosY - 2) + nY;
	for (int i = 0; i < BLOCKSIZE; i++) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			if (arBlocks[nBlockType][nRot][i][j] == BLOCK && arGameMap[nTmpIdxY + i][nTmpIdxX + j] == BLOCK) {
				return bCheck;
			}
		}
	}

	return TRUE;
}

void fixBlock() {
	setBlockIdx();
	for (int i = 0; i < BLOCKSIZE; i++) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			if (arBlocks[nBlockType][nBlockRot][i][j] == BLOCK) {
				arGameMap[nIdxY + i][nIdxX + j] = BLOCK;
			}
		}
	}
	showGameMap();
}

void inputArrowKey() {
	int nSelect = 0;

	if (_kbhit()) {
		nSelect = _getch();
		if (nSelect == 224) {
			nSelect = _getch();
			switch (nSelect)
			{
			case UP:
				if (blockCrushCheck(0, 0, (nBlockRot + 1) % 4)) {
					eraseGameBlock();
					upArrow();
					showGameBlock();
				}
				break;
			case DOWN:
				if (blockCrushCheck(0, 1, nBlockRot)) {
					eraseGameBlock();
					downArrow();
					showGameBlock();
				}
				break;
			case LEFT:
				if (blockCrushCheck(-1, 0, nBlockRot)) {
					eraseGameBlock();
					leftArrow();
					showGameBlock();
				}
				break;
			case RIGHT:
				if (blockCrushCheck(1, 0, nBlockRot)) {
					eraseGameBlock();
					rightArrow();
					showGameBlock();
				}
				break;
			}
		}
	}
	else {
		//Sleep(100);
	}

	while (_kbhit()) {
		_getch();
	}
}

void leftArrow() {
	nPosX -= 2;
}

void rightArrow() {
	nPosX += 2;
}

void upArrow() {
	/*int arTmpBlock[4][4] = { 0 };
	memcpy(arTmpBlock, arBlock, sizeof(arTmpBlock));
	int nY = 0;
	int nTmpIdxX = 0;

	nY = 3;
	for (int i = 0; i < BLOCKSIZE; i++) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			arBlock[i][j] = arTmpBlock[j][nY - i];
		}
	}*/
	nBlockRot = (nBlockRot + 1) % 4;

}

void downArrow() {
	nPosY += 1;
}
