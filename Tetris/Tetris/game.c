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
int arLineCheck[24] = { 0 };
int arGameMap[MAPHEIGHT][MAPWIDTH] = { 0 };
int arPostBlockMap[PREMAPSIZE][PREMAPSIZE] = { 0 };

int nScore = 0;

int nBlockType = 0;
int nBlockRot = 0;

int nBlockPostType = 0;
int nBlockPostRot = 0;

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
	showScore(0);
	showGameMap();

	gotoxy(40, 1);
	printf("<Next>");
	showPostMap();

	gotoxy(40, 5 + PREMAPSIZE);
	printf("Left	 : ← \n");
	gotoxy(40, 6 + PREMAPSIZE);
	printf("Right	 : → \n");
	gotoxy(40, 7 + PREMAPSIZE);
	printf("Rotation : ↑ \n");

	gotoxy(40, 1 + MAPHEIGHT);
	printf("Exit	 : 't'\n");
}

void showPostMap() {
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

void showPostBlock() {
	for (int i = 0; i < BLOCKSIZE; i++) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			gotoxy(42 + j * 2, 3 + i);
			if (arBlocks[nBlockPostType][nBlockPostRot][i][j] == BLOCK) {
				printf("%s", MAPBLOCK);
			}
			else {
				printf("%s", MAPEMPTY);
			}
		}
		printf("\n");
	}
}

BOOL showGameBlock() {
	for (int i = 0; i < BLOCKSIZE; i++) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			gotoxy(nPosX + j * 2, nPosY + i);
			if (arBlocks[nBlockType][nBlockRot][i][j] == BLOCK) {
				printf("%s", MAPBLOCK);
			}
		}
		printf("\n");
	}

	setBlockIdx();
	for (int i = 0; i < BLOCKSIZE; i++) {
		for (int j = 0; j < BLOCKSIZE; j++) {
			if (arBlocks[nBlockType][nBlockRot][i][j] == BLOCK && arGameMap[nIdxY][nIdxX] == BLOCK) {
				return FALSE;
			}
		}
	}
	return TRUE;
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

void setRandomBlock() {
	srand((unsigned int)time(NULL));
	nBlockPostType = rand() % 7;
	nBlockPostRot = rand() % 4;
}

void setGameBlock() {
	nBlockType = nBlockPostType;
	nBlockRot = nBlockPostRot;
}

void setBlockIdx() {
	nIdxX = (nPosX - 6) / 2;
	nIdxY = (nPosY - 2);
}

BOOL downBlock() {
	if (!CheckblockCrush(0, 1, nBlockRot)) {
		return FALSE;
	}
	eraseGameBlock();
	downArrow();
	showGameBlock();
	return TRUE;
}

BOOL CheckblockCrush(int nX, int nY, int nRot) {
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
	lineCheck();
	showGameMap();
}

void lineCheck() {
	BOOL bCheck = FALSE;
	int nCountDeleteLine = 0;
	int nStartDeleteLine = 0;

	for (int i = 1; i < MAPHEIGHT - 1; i++) {
		for (int j = 1; j < MAPWIDTH - 1; j++) {
			if (arGameMap[i][j] != BLOCK) {
				bCheck = TRUE;
				break;
			}
		}
		if (!bCheck) {
			arLineCheck[i - 1] = 1;
			nStartDeleteLine = i;
		}
		else {
			bCheck = FALSE;
		}
	}

	for (int i = 0; i < 24; i++) {
		if (arLineCheck[i] == 1) {
			nCountDeleteLine++;
		}
	}

	for (int i = 0; i < nCountDeleteLine; i++) {
		for (int j = 1; j < MAPWIDTH - 1; j++) {
			arGameMap[nStartDeleteLine - i][j] = EMPTY;
		}
	}

	for (int i = nStartDeleteLine; i - nCountDeleteLine > 1 ; i--) {
		for (int j = 1; j < MAPWIDTH - 1; j++) {
			arGameMap[i][j] = arGameMap[i - nCountDeleteLine][j];
			arGameMap[i - nCountDeleteLine][j] = EMPTY;
		}
	}

	for (int i = 0; i < 24; i++) {
		arLineCheck[i] = 0;
	}

	countScore(nCountDeleteLine);
}

void countScore(int nCountDeleteLine) {
	float fScore = 0.0f;

	for (int i = 0; i < nCountDeleteLine; i++) {
		if (i == 0) {
			fScore += 5.0f;
		}
		else {
			fScore += 5.0f;
			fScore *= 1.2f;
		}
	}
	showScore((int)fScore);
}

void showScore(int nInput) {
	nScore += nInput;
	gotoxy(7, 1);
	printf("Score : %d", nScore);
}

BOOL exitGame() {
	char cSelect = 0;
	gotoxy(40, 15);
	printf("게임을 그만두시겠습니까?(y/n)");

	cSelect = _getch();
	if (cSelect == 'y' || cSelect == 'Y') {
		return FALSE;
	}
	showGameScene();
	return TRUE;
}

BOOL dieGame() {
	for (int i = 1; i < MAPWIDTH - 1; i++) {
		if (arGameMap[1][i] == BLOCK) {
			return FALSE;
		}
	}
	return TRUE;
}

int getGameScore() {
	return nScore;
}

BOOL inputEventKey() {
	int nSelect = 0;

	if (_kbhit()) {
		nSelect = _getch();
		if (nSelect == 224) {
			nSelect = _getch();
			switch (nSelect)
			{
			case UP:
				if (CheckblockCrush(0, 0, (nBlockRot + 1) % 4)) {
					eraseGameBlock();
					upArrow();
					showGameBlock();
				}
				break;
			case DOWN:
				if (CheckblockCrush(0, 1, nBlockRot)) {
					eraseGameBlock();
					downArrow();
					showGameBlock();
				}
				break;
			case LEFT:
				if (CheckblockCrush(-1, 0, nBlockRot)) {
					eraseGameBlock();
					leftArrow();
					showGameBlock();
				}
				break;
			case RIGHT:
				if (CheckblockCrush(1, 0, nBlockRot)) {
					eraseGameBlock();
					rightArrow();
					showGameBlock();
				}
				break;
			}
		}
		else if (nSelect == 116) {
			if (!exitGame()) {
				return FALSE;
			}
		}
	}
	else {
		//Sleep(100);
	}

	while (_kbhit()) {
		_getch();
	}

	return TRUE;
}

void leftArrow() {
	nPosX -= 2;
}

void rightArrow() {
	nPosX += 2;
}

void upArrow() {
	nBlockRot = (nBlockRot + 1) % 4;
}

void downArrow() {
	nPosY += 1;
}
