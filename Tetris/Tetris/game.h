#pragma once

#include "main.h"

extern const int arBlocks[7][4][4][4];
extern int arBlock[4][4];
extern int arGameMap[MAPHEIGHT][MAPWIDTH];
extern int arPostBlockMap[PREMAPSIZE][PREMAPSIZE];

extern int nBlockType;
extern int nBlockRot;

extern int nPosX;
extern int nPosY;
extern int nIdxX;
extern int nIdxY;

void initGameScene();
void initBlockPosition();

void showGameScene();
//void showPostMap();
void showGameMap();
void showPostBlock();
void showGameBlock();
void eraseGameBlock();

void randomBlock();
void setBlockIdx();
BOOL downBlock();
void settingBlock();
BOOL blockCrushCheck(int nX, int nY, int nRot);
void fixBlock();

void inputArrowKey();
void leftArrow();
void rightArrow();
void upArrow();
void downArrow();