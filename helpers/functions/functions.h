#ifndef _FUNCTIONS_
#define _FUNCTIONS_
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include "../constants/nonPlayerSprites.h"
#include "../constants/rawStrings.h"
#include "../../NonPlayer/NonPlayer.h"
#include "../../Player/Player.h"

using namespace std;

namespace helperFunctions {
	void displayString(string input);
	void exitProgramWithError(const vector<string> &errorMessages);
	vector<int> useMainArgs(int argc, char* argv[]);
	bool isPositive(int number);
	vector<NonPlayer> generateRandomXYPos(const Player &player, const vector<stringMatrix2d> &nonPlayerSprites, int count, int xSize, int ySize);
	bool calcIntersectPlayer(int pos, int playerPos, int playerSpriteSize);
	bool calcIntersectScreen(int pos, int size, int spriteSize);
	void changeConsoleBlink(bool display);
	string findSpecialBuilding(const vector<NonPlayer> &buildings);
}

#endif
