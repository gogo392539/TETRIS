#pragma once

#include "main.h"

extern int arBlocks[7][4][4];
extern int arGameMap[MAPHEIGHT][MAPWIDTH];
extern int arGamePreMap[PREMAPSIZE][PREMAPSIZE];
extern int arStartIdx[2];
extern int arBlockIdx[2];

void initMap();
void printingMap();

int getBlockIdx();
int setPreBlock(int nBlockIdx);
void showPreBlock(int nBlockIdx);

void setInitBlock(int nBlockIdx);
void showGameMap();
void setGameBlock(int nBlockIdx);
void moveBlock(int nBlockIdx);