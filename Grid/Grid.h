#ifndef _GRID_
#define _GRID_
#include <string>
#include "../Player/Player.h"

using namespace std;

struct Grid {
	int xSize;
	int ySize;
	string sprite;
	void render(Player player);
};

#endif
