#include "./Actions.h"

using namespace std;

void Actions::movePlayer(Player &player, char input) {
	switch(input) {
		case helperConstants::inputUp:
			player.yPos -= 1;
			player.sprite = Actions::calcNextPlayerSprite(
				player,
				playerSprites::move[Directions::UP]
			);
			break;
		case helperConstants::inputLeft:
			player.xPos -= 1;
			player.sprite = Actions::calcNextPlayerSprite(
				player,
				playerSprites::move[Directions::LEFT]
			);
			break;
		case helperConstants::inputDown:
			player.yPos += 1;
			player.sprite = Actions::calcNextPlayerSprite(
				player,
				playerSprites::move[Directions::DOWN]
			);
			break;
		case helperConstants::inputRight:
			player.xPos += 1;
			player.sprite = Actions::calcNextPlayerSprite(
				player,
				playerSprites::move[Directions::RIGHT]
			);
			break;
		default:
			break;
	}
}

void Actions::standPlayer(Player &player, Grid &grid, mutex &mut, char input) {
	// `mut.try_lock()` attempts to lock the mutex, if another thread has locked the mutex already, do nothing
	if(mut.try_lock()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		switch(input) {
			case helperConstants::inputUp:
				player.sprite = playerSprites::stand[Directions::UP];
				break;
			case helperConstants::inputLeft:
				player.sprite = playerSprites::stand[Directions::LEFT];
				break;
			case helperConstants::inputDown:
				player.sprite = playerSprites::stand[Directions::DOWN];
				break;
			case helperConstants::inputRight:
				player.sprite = playerSprites::stand[Directions::RIGHT];
				break;
			default:
				break;
		}

		grid.render(player);

		mut.unlock();
	}
}

vector<vector<string>> Actions::calcNextPlayerSprite(
	Player &player,
	const vector<PlayerSprite> &playerSprites
) {
	return player.sprite == playerSprites[0] ? playerSprites[1] : playerSprites[0];
}
