#include "./Player.h"

void Player::checkWouldCollide(
	const map<NonPlayer, coord> &npMap,
	bool &playerWouldCollide
) {
	const coord playerMaxCoord {helperFunctions::calcSpriteMaxCoord(
		make_pair(Player::sprite, make_pair(Player::xPos, Player::yPos))
	)};
	const coord playerMinCoord {make_pair(Player::xPos, Player::yPos)};

	for(const pair<NonPlayer, coord> &p : npMap) {
		const coord maxCoord {helperFunctions::calcSpriteMaxCoord(
			make_pair(p.first.sprite, p.second)
		)};
		const coord minCoord {p.second};

		// if rectangle has area 0, no overlap
		if (
			playerMinCoord.first == playerMaxCoord.first ||
			playerMinCoord.second == playerMaxCoord.second ||
			maxCoord.first == minCoord.first ||
			minCoord.second == maxCoord.second
		) {
			continue;
		}

		// If one rectangle is on left side of other
		if (playerMinCoord.first > maxCoord.first || minCoord.first > playerMaxCoord.first) {
			continue;
		}

		// If one rectangle is above other
		if (playerMaxCoord.second > minCoord.second || maxCoord.second > playerMinCoord.second) {
			continue;
		}

		playerWouldCollide = true;
	}
}