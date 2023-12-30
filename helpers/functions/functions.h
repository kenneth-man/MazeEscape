#ifndef _FUNCTIONS_
#define _FUNCTIONS_
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include "../constants/nonPlayerSprites.h"
#include "../constants/rawStrings.h"
#include "../constants/types.h"
#include "../../NonPlayer/NonPlayer.h"
#include "../../Player/Player.h"
#include "../../Grid/Grid.h"

using namespace std;

namespace helperFunctions {
	void displayString(string input);
	void exitProgramWithError(const vector<string> &errorMessages);
	vector<int> useMainArgs(int argc, char* argv[]);
	vector<NonPlayer> generateRandomXYPos(const Player &player, const vector<stringMatrix2d> &nonPlayerSprites, int count, int xSize, int ySize);
	bool calcIntersectPlayer(int pos, int playerPos, int playerSpriteSize);
	bool calcIntersectScreen(int pos, int size, int spriteSize);
	void changeConsoleBlink(bool display);
	string findSpecialBuilding(const vector<NonPlayer> &buildings);
	vector<coord> calcBuildingsCoords(const vector<NonPlayer> &buildings);
	bool someRendered(const vector<coord> &coords, const Grid &grid);
	void checkSomeRendered(const vector<coord> &coords, const Grid &grid, bool &boundaryUpdated, bool &someRendered);
}

#endif
