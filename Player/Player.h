#ifndef _PLAYER_
#define _PLAYER_
#include <string>
#include <vector>

using namespace std;

struct Player {
	int xPos;
	int yPos;
	vector<vector<string>> sprite;

	// if using list initialization, don't need to define the below to initialize members
	// as C++ provides a default constructor
	// 
	// Player(int x, int y, string s): xPos{x}, yPos{y}, sprite{s} {};
};

#endif
