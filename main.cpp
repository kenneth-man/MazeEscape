#include <thread>
#include <mutex>
#include <iostream>
#include <conio.h>
#include "./Grid/Grid.h"
#include "./Actions/Actions.h"
#include "./TitleScreen/TitleScreen.h"
#include "./helpers/constants/constants.h"
#include "./helpers/constants/playerSprites.h"
#include "./helpers/functions/functions.h"

using namespace std;

int main(int argc, char* argv[]) {
	const vector<int> MainArgs = helperFunctions::useMainArgs(argc, argv);
	// single quotes for `char`, double quotes for `std::string`
	char input { helperConstants::defaultInput };
	bool gameStart { false };
	mutex m;

    Grid grid { MainArgs[0], MainArgs[1], helperConstants::defaultTerrain };
	Player player { 2, 4, playerSprites::standDown };
	Actions actions {};
	TitleScreen titleScreen {};
	
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
// game screen boundary checking (outside area) e.g. if past x position 120, then update player position to n - 120 ?
// random generation (coords) of walls, structures; figure out how to display things at defined coordinates e.g. structure at position 320, 40
// randomized dirt terrain with different floor character map
// collision detection of walls, structures
// player starting position refactor
// INVESTIGATION: why failing compile when putting `const vector<string> invalidArguments` into `helperConstants`?
// INVESTIGATION: why cannot use `std::optional`?

// BUG: sometimes the player gets reset to standing for less than a second if spamming the movement keys
// detect if windows, mac or linux os, and use the appropriate `SetConsoleCursorPosition`-like function for windows so `clearScreen` is compatible
// enemies chasing if get too close (on a timer? updates per second without needing player input?)
// raw string puzzles
// player attack; enemy health; to kill takes a certain amount of attacks
// player lives; display on screen
// player block
