#ifndef _GRID_
#define _GRID_
#include <string>
#include "../Player/Player.h"

using namespace std;

struct Grid {
	int xSize;
	int ySize;
	string sprite;
	void clearScreen();
	void render(const Player &player);
	string renderBorder(int, int);
};

#endif
