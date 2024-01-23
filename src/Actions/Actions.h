#ifndef _ACTIONS_
#define _ACTIONS_
#include <chrono>
#include <thread>
#include <mutex>
#include "../Player/Player.h"
#include "../Grid/Grid.h"
#include "../helpers/constants/constants.h"
#include "../helpers/constants/playerSprites.h"
#include "../helpers/constants/enums.h"
#include "../helpers/constants/types.h"

struct Actions {
	void movePlayer(Player &player, char input);
	void standPlayer(Player &player, Grid &grid, mutex &mut, char input);
	stringMatrix2d calcNextPlayerSprite(
		const Player &player,
		const vector<stringMatrix2d> &playerSprites
	);
};

#endif
