#include <thread>
#include <mutex>
#include <iostream>
#include <conio.h>
#include <map>
#include "./src/helpers/functions/functions.h"
#include "./src/Grid/Grid.h"
#include "./src/Actions/Actions.h"
#include "./src/TitleScreen/TitleScreen.h"
#include "./src/NonPlayer/NonPlayer.h"
#include "./src/helpers/constants/constants.h"
#include "./src/helpers/constants/playerSprites.h"
#include "./src/helpers/constants/nonPlayerSprites.h"
#include "./src/helpers/constants/types.h"

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

			// deprecated
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

		// deprecated
		//input = getch();

		input = cin.get();

		actions.movePlayer(player, input);
	}

	helperFunctions::changeConsoleBlink(true);

    return 0;
}
