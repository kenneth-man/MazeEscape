#ifndef _GRID_
#define _GRID_
#include <string>
#include "../Player/Player.h"

using namespace std;

struct Grid {
	int xSize;
	int ySize;
	string sprite;
	void render(const Player &player);
	bool renderBorder(int, int);
};

#endif
