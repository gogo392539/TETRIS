#pragma once

#include "main.h"

char arBlocks[7][4][4];

void InitMap(char (*arGameMap)[MAPWIDTH], char (*arGamePreMap)[PREMAPSIZE]);
void PrintingMap(char (*arGameMap)[MAPWIDTH], char (*arGamePreMap)[PREMAPSIZE]);