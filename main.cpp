// #include <chrono>
// #include <thread>
#include <iostream>
#include <conio.h>
#include "./Grid/Grid.h"
#include "./Actions/Actions.h"
#include "./TitleScreen/TitleScreen.h"
#include "helpers/constants/constants.h"

using namespace std;

int main() {
    Grid grid { 120, 20, helperConstants::terrain };
	Player player { 2, 4, helperConstants::player };
	Actions actions {};
	TitleScreen titleScreen {};
	// single quotes for `char`, double quotes for `std::string`
	char input {'0'};
	bool gameStart {false};
	
	while (input != 'q') {
		if (!gameStart) {
			titleScreen.render();

			input = getch();

			if (input == ' ') {
				gameStart = true;
			}

			// clear entire temrinal to make sure instructions aren't shown during gameplay
			// because instructions have a larger height than the grid
			system("CLS");

			continue;
		}

		grid.render(player);

		input = getch();

		actions.movePlayer(input, player);
	}

    return 0;
}

// TODO:
// detect if windows, mac or linux os, and use the appropriate `SetConsoleCursorPosition`-like function for windows so `clearScreen` is compatible
// walking animations (up, down, left, right, diagonals, reset e.g. on a timer after 2 seconds)
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