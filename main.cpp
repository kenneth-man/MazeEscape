#include <thread>
#include <mutex>
#include <iostream>
#include <conio.h>
#include "./Grid/Grid.h"
#include "./Actions/Actions.h"
#include "./TitleScreen/TitleScreen.h"
#include "./NonPlayer/NonPlayer.h"
#include "./helpers/constants/constants.h"
#include "./helpers/constants/playerSprites.h"
#include "./helpers/constants/nonPlayerSprites.h"
#include "./helpers/functions/functions.h"

using namespace std;

int main(int argc, char* argv[]) {
	const vector<int> MainArgs{helperFunctions::useMainArgs(argc, argv)};
	char input {helperConstants::defaultInput};
	bool gameStart {false};
	mutex m;
    Grid grid {MainArgs[0], MainArgs[1], helperConstants::defaultTerrain};
	Player player {MainArgs[0] / 2, MainArgs[1] / 2, playerSprites::standDown};
	Actions actions {};
	TitleScreen titleScreen {};
	vector<NonPlayer> buildings {
		helperFunctions::generateRandomXYPos(
			player,
			helperConstants::buildingsSprites,
			helperConstants::buildingsCount,
			grid.xSize,
			grid.ySize
		)
	};
	
	while (input != helperConstants::inputQuit) {
		for (NonPlayer b : buildings) {
			cout << b.xPos << " " << b.yPos << '\n';
		}
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

		// thread t1(&Actions::standPlayer, &actions, ref(player), ref(grid), ref(m), input);
		// t1.detach();

		grid.render(player, buildings);

		cout << "xPos " << player.xPos << endl;
		cout << "yPos " << player.yPos << endl;
		cout << "xScreen " << grid.xScreen << endl;
		cout << "yScreen " << grid.yScreen << endl;

		input = getch();

		actions.movePlayer(player, input);
	}

    return 0;
}



// (TODO)
// # - random generation (coords) of walls, structures
//		- fix buildings getting cut out at border (render the rest on next screen or make sure they render certain distance 'X' away from the border?)
//		- check if need '</=' and '>/=' for line 217 in `Grid\Grid.cpp` (border number calc?)
//		- try to get operator overloading to work with std::find... line 15 in `NonPlayer\NonPlayer.h`, line 88, 89, 94 in `helpers\functions\functions.cpp`
// - hud with game info and good looking ascii
// - randomized dirt terrain with different floor character map
// - collision detection of walls, structures
// - player starting position refactor
// - detect if windows, mac or linux os, and use the appropriate `SetConsoleCursorPosition`-like function for windows so `clearScreen` is compatible
// - enemies chasing if get too close (on a timer? updates per second without needing player input?)
// - raw string puzzles
// - player attack; enemy health; to kill takes a certain amount of attacks
// - player lives; display on screen
// - player block

// (BUGS/INVESTIGATIONS)
// # ??? INVESTIGATION: why cout shows trailing digit from previous couts? e.g. xPos, yPos, xScreen, yScreen...
// # !!! BUG: Actions::standPlayer causing a render bug if holding down the movement keys for a long time; extra borders are displaying; lines 43-44 in `main.cpp`
// !!! BUG: sometimes the player gets reset to standing for less than a second if spamming the movement keys
// ??? INVESTIGATION: why failing compile when putting `const vector<string> invalidArguments` into `helperConstants`?
// ??? INVESTIGATION: why cannot use `std::optional`?