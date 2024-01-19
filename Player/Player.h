#ifndef _PLAYER_
#define _PLAYER_
#include <string>
#include <vector>
#include <map>
#include "../NonPlayer/NonPlayer.h"
#include "../helpers/constants/types.h"
#include "../helpers/functions/functions.h"

using namespace std;

struct Player {
	int xPos;
	int yPos;
	stringMatrix2d sprite;
	void checkWouldCollide(const map<NonPlayer, coord> &npMap, bool &playerWouldCollide);

	// if using list initialization, don't need to define the below to initialize members as C++ provides a default constructor
	// Player(int x, int y, string s): xPos{x}, yPos{y}, sprite{s} {};
};

#endif
