#ifndef _GRID_
#define _GRID_
#include <string>
#include <iostream>
#include "../Player/Player.h"
#include "../helpers/constants/constants.h"
#include "../helpers/constants/enums.h"
#include "../helpers/constants/interfaces.h"

using namespace std;

struct Grid {
	int xSize;
	int ySize;
	string sprite;
	int xSizeMin {0};
	int ySizeMin {0};
	int xScreen {0};
	int yScreen {0};
	void clearScreen();
	void render(const Player &player);
	string renderBorder(int col, int row);
	IShouldBoundaryUpdate shouldBoundaryUpdate(int playerXPos, int playerYPos);
	void calcBoundaryUpdate(const Directions &updateDirection);
	void ignoreScreenZero(int &screen, int update);
};

#endif
