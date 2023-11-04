#include "./Actions.h"

void Actions::movePlayer(char playerInput, Player &player) {
	switch(playerInput) {
		case 'w':
			player.yPos -= 1;
			break;
		case 'a':
			player.xPos -= 1;
			break;
		case 's':
			player.yPos += 1;
			break;
		case 'd':
			player.xPos += 1;
			break;
		default:
			break;
	}
}
