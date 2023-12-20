#ifndef _GRID_
#define _GRID_
#include <string>
#include <iostream>
#include <cmath>
#include "../Player/Player.h"
#include "../helpers/constants/constants.h"
#include "../helpers/constants/enums.h"
#include "../helpers/constants/interfaces.h"
#include "../helpers/functions/functions.h"

using namespace std;

struct Grid {
	int xSize;
	int ySize;
	string sprite;
	int xScreen {1};
	int yScreen {1};
	void clearScreen();
	void render(const Player &player, bool playerStand = false);
	string renderBorder(int col, int row);
	IShouldBoundaryUpdate shouldBoundaryUpdate(int playerXPos, int playerYPos);
	Directions checkShouldBoundaryUpdate(int playerPos, int screen, int size, const Directions &dir1, const Directions &dir2);
	void calcBoundaryUpdate(const Directions &direction);
	void ignoreScreenZero(int &screen, int update);
	int calcSpriteDimension(int index, int playerPos, int screen, int size);
};

#endif
