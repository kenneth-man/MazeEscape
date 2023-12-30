#ifndef _PLAYER_
#define _PLAYER_
#include <string>
#include <vector>
#include "../NonPlayer/NonPlayer.h"
#include "../helpers/constants/types.h"

using namespace std;

struct Player {
	int xPos;
	int yPos;
	stringMatrix2d sprite;
	// bool isColliding(const vector<NonPlayer> &nonPlayers);

	// if using list initialization, don't need to define the below to initialize members
	// as C++ provides a default constructor
	// 
	// Player(int x, int y, string s): xPos{x}, yPos{y}, sprite{s} {};
};

#endif
