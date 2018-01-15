#pragma once

#include "main.h"

extern int arBlocks[7][4][4];
extern int arGameMap[MAPHEIGHT][MAPWIDTH];
extern int arGamePreMap[PREMAPSIZE][PREMAPSIZE];
extern int arBlock[4][4];
extern int nPosX;
extern int nPosY;
extern int nIdxX;
extern int nIdxY;
//extern int arStartIdx[2];
//extern int arBlockIdx[2];

void initMap();
void printingMap();

int getBlockIdx();
void initPreMap();
void showPreBlock(int nBlockIdx);

void showGameBlock(int nBlockIdx);
void showGameMap();

BOOL checkCrush(int nKey);
void checkMoveKey(int nBlockIdx);
void rotationBlock(int nRotCount);
void moveBlock(int nKey);