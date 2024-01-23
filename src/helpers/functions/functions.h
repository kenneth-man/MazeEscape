#ifndef _FUNCTIONS_
#define _FUNCTIONS_
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include "../constants/nonPlayerSprites.h"
#include "../constants/rawStrings.h"
#include "../constants/types.h"
#include "../../NonPlayer/NonPlayer.h"
#include "../../Player/Player.h"
#include "../../Grid/Grid.h"

class Grid;
class Player;
class NonPlayer;

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
	vector<coord> calcNonPlayerCoords(const vector<NonPlayer> &np);
	map<NonPlayer, coord> calcNonPlayerMap(const vector<NonPlayer> &np);
	map<NonPlayer, coord> someRendered(const map<NonPlayer, coord> &npMap, const Grid &grid);
	void checkSomeRendered(const map<NonPlayer, coord> &npMap, map<NonPlayer, coord> &someRendered, const Grid &grid, bool &boundaryUpdated);
	coord calcSpriteMaxCoord(const pair<stringMatrix2d, coord> &spritePair);
}

#endif
