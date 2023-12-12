#include <thread>
#include <mutex>
#include <iostream>
#include <conio.h>
#include "./Grid/Grid.h"
#include "./Actions/Actions.h"
#include "./TitleScreen/TitleScreen.h"
#include "./helpers/constants/constants.h"
#include "./helpers/constants/playerSprites.h"

using namespace std;

int main() {
    Grid grid { 120, 20, helperConstants::terrain };
	Player player { 2, 4, playerSprites::standDown };
	Actions actions {};
	TitleScreen titleScreen {};
	// single quotes for `char`, double quotes for `std::string`
	char input { helperConstants::defaultInput };
	bool gameStart { false };
	mutex m;
	
	while (input != helperConstants::inputQuit) {
		if (!gameStart) {
			titleScreen.render();

			input = getch();

			if (input == helperConstants::inputSpace) {
				gameStart = true;
			}

			// clear entire terminal to make sure instructions aren't shown during gameplay
			// because instructions have a larger height than the grid
			system("CLS");

			continue;
		}

		thread t1(&Actions::standPlayer, &actions, ref(player), ref(grid), ref(m), input);
		t1.detach();

		grid.render(player);

		input = getch();

		actions.movePlayer(player, input);
	}

    return 0;
}



// TODO:
// BUG: sometimes the player gets reset to standing for less than a second if spamming the movement keys

// detect if windows, mac or linux os, and use the appropriate `SetConsoleCursorPosition`-like function for windows so `clearScreen` is compatible
// collision detection (walls, structures)
// boundaries checking (outside area) e.g. if past x position 120, then update player position to n - 120 ?
// figure out how to display things at defined coordinates e.g. structure at position 320,40
// different terrain character map
// player starting position refactor
// enemies chasing (timer? updates without needing player input?)
// raw string puzzles
// player attack
// player lives; display on screen



// COMPLETE:
// add border to game window
// create struct for while loop movement
// title screen and instructions (ensure chcp 65001 to choose UTF-8 encoding and terminal font is Cascadia mono)
// prevent `displayString` displaying `R""`
// improve player sprite