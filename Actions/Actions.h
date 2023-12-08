#ifndef _ACTIONS_
#define _ACTIONS_
#include <chrono>
#include <thread>
#include <mutex>
#include "../Player/Player.h"
#include "../Grid/Grid.h"
#include "../helpers/constants/constants.h"

struct Actions {
	void movePlayer(Player &player, char input);
	void standPlayer(Player &player, Grid &grid, mutex &m);
	vector<vector<string>> calcNextPlayerSprite(
		Player &player,
		vector<vector<string>> initialSprite,
		vector<vector<string>> finalSprite
	);
};

#endif
