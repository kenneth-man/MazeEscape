#ifndef _GRID_
#define _GRID_
#include <string>
#include <iostream>
#include "../Player/Player.h"

using namespace std;

struct Grid {
	int xSize;
	int ySize;
	string sprite;
	void clearScreen() const;
	void render(const Player &player) const;
	string renderBorder(int col, int row) const;
};

#endif
