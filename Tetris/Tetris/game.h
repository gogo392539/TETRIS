#pragma once

#include "main.h"

extern const int arBlocks[7][4][4][4];
extern int arLineCheck[24];
extern int arGameMap[MAPHEIGHT][MAPWIDTH];
extern int arPostBlockMap[PREMAPSIZE][PREMAPSIZE];

extern int nScore;

extern int nBlockType;
extern int nBlockRot;

extern int nBlockPostType;
extern int nBlockPostRot;

extern int nPosX;
extern int nPosY;
extern int nIdxX;
extern int nIdxY;

void initGameScene();
void initBlockPosition();

void showGameScene();
void showPostMap();
void showGameMap();
void showPostBlock();
BOOL showGameBlock();
void eraseGameBlock();

void setRandomBlock();
void setGameBlock();
void setBlockIdx();
BOOL downBlock();
BOOL CheckblockCrush(int nX, int nY, int nRot);
void fixBlock();
void lineCheck();
void countScore(int nCountDeleteLine);
void showScore(int nInput);

BOOL exitGame();
BOOL dieGame();
int getGameScore();

BOOL inputEventKey();
void leftArrow();
void rightArrow();
void upArrow();
void downArrow();