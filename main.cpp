#include <thread>
#include <mutex>
#include <iostream>
#include <conio.h>
#include <map>
#include "./Grid/Grid.h"
#include "./Actions/Actions.h"
#include "./TitleScreen/TitleScreen.h"
#include "./NonPlayer/NonPlayer.h"
#include "./helpers/constants/constants.h"
#include "./helpers/constants/playerSprites.h"
#include "./helpers/constants/nonPlayerSprites.h"
#include "./helpers/constants/types.h"
#include "./helpers/functions/functions.h"

using namespace std;

int main(
	int argc,
	char* argv[]
) {
	const vector<int> mainArgs {helperFunctions::useMainArgs(argc, argv)};
	const int xSize {mainArgs.size() == 0 ? helperConstants::defaultGridXSize : mainArgs[0]};
	const int ySize {mainArgs.size() == 0 ? helperConstants::defaultGridYSize : mainArgs[1]};
	char input {helperConstants::defaultInput};
	bool gameStart {false};
	bool boundaryUpdated {false};
	bool playerWouldCollide {false};
	map<NonPlayer, coord> someRendered {};
	mutex m;
    Grid grid {xSize, ySize, helperConstants::defaultTerrain};
	Player player {xSize / 2, ySize / 2, playerSprites::standDown};
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
	map<NonPlayer, coord> buildingsMap {helperFunctions::calcNonPlayerMap(buildings)};
	string oSpecialBuilding {helperFunctions::findSpecialBuilding(buildings)};

	helperFunctions::changeConsoleBlink(false);

	while (tolower(input) != helperConstants::inputQuit) {
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

		grid.render(player, buildings, boundaryUpdated);

		grid.renderHUD(player, oSpecialBuilding);

		if (boundaryUpdated) {
			helperFunctions::checkSomeRendered(buildingsMap, someRendered, grid, boundaryUpdated);
		}

		if (static_cast<int>(someRendered.size()) > 0) {
			player.checkWouldCollide(someRendered, playerWouldCollide);
		}

		input = getch();

		actions.movePlayer(player, input);
	}

	helperFunctions::changeConsoleBlink(true);

    return 0;
}



// (TODO)
// # - refactor someRendered
// # - collision detection of walls, structures
// - handle inside buildings and entering
// - render maze entrance and coords
// - inside maze
// - randomized dirt terrain with different floor character map
// - detect if windows, mac or linux os, and use the appropriate `SetConsoleCursorPosition`-like function for windows so `clearScreen` is compatible
// - enemies chasing if get too close (on a timer? updates per second without needing player input?)
// - raw string puzzles
// - player attack; enemy health; to kill takes a certain amount of attacks
// - player lives; display on screen
// - player block

// (BUGS/INVESTIGATIONS)
// # !!! BUG: Actions::standPlayer causing a render bug if holding down the movement keys for a long time; extra borders are displaying; lines 43-44 in `main.cpp`
// !!! BUG: sometimes the player gets reset to standing for less than a second if spamming the movement keys
// ??? INVESTIGATION: why cannot use `std::optional`?