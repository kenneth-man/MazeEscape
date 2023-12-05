#include "./Actions.h"

void Actions::movePlayer(Player &player, char input) {
	switch(input) {
		case helperConstants::inputUp:
			player.yPos -= 1;
			player.sprite = Actions::calcNextPlayerSprite(
				player,
				helperConstants::playerUpMoveInitial,
				helperConstants::playerUpMoveFinal
			);
			break;
		case helperConstants::inputLeft:
			player.xPos -= 1;
			player.sprite = Actions::calcNextPlayerSprite(
				player,
				helperConstants::playerLeftMoveInitial,
				helperConstants::playerLeftMoveFinal
			);
			break;
		case helperConstants::inputDown:
			player.yPos += 1;
			player.sprite = Actions::calcNextPlayerSprite(
				player,
				helperConstants::playerDownMoveInitial,
				helperConstants::playerDownMoveFinal
			);
			break;
		case helperConstants::inputRight:
			player.xPos += 1;
			player.sprite = Actions::calcNextPlayerSprite(
				player,
				helperConstants::playerRightMoveInitial,
				helperConstants::playerRightMoveFinal
			);
			break;
		default:
			break;
	}
}

vector<vector<string>> Actions::calcNextPlayerSprite(
	Player &player,
	vector<vector<string>> initialSprite,
	vector<vector<string>> finalSprite
) {
	return player.sprite == initialSprite ? finalSprite : initialSprite;
}
