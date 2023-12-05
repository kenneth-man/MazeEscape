#ifndef _ACTIONS_
#define _ACTIONS_
#include "../Player/Player.h"
#include "../helpers/constants/constants.h"

struct Actions {
	void movePlayer(Player &player, char input);
	vector<vector<string>> calcNextPlayerSprite(
		Player &player,
		vector<vector<string>> initialSprite,
		vector<vector<string>> finalSprite
	);
};

#endif
