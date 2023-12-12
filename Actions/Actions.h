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

struct Actions {
	void movePlayer(Player &player, char input);
	void standPlayer(Player &player, Grid &grid, mutex &mut, char input);
	vector<vector<string>> calcNextPlayerSprite(
		Player &player,
		const vector<PlayerSprite> &playerSprites
	);
};

#endif
