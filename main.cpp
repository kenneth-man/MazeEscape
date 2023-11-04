#include <iostream>
#include <conio.h>
#include "./Grid/Grid.h"
#include "./Actions/Actions.h"
#include "./TitleScreen/TitleScreen.h"

using namespace std;

int main() {
    Grid grid { 120, 20, "█" };
	Player player { 2, 4, "╇" };
	Actions actions {};
	TitleScreen titleScreen {};
	// single quotes for `char`, double quotes for `std::string`
	char input {'0'};
	bool gameStart {true};
	
	while(input != 'q') {
		if(gameStart) {
			titleScreen.render();

			input = getch();

			if(input == ' ') {
				gameStart = false;
			}

			continue;
		}

		grid.render(player);

		input = getch();

		actions.movePlayer(input, player);
	}

    return 0;
}

// TODO:
// add double buffering to prevent flickering when player moves
// add border to game window
// boundaries checking (outside area) e.g. if past x position 120, then update player position to n - 120 ?
// figure out how to display things at defined coordinates e.g. structure at position 320,40
// different terrain character map
// player starting position refactor
// improve player sprite
// collision detection (walls, structures)
// enemies chasing (timer? updates without needing player input?)
// raw string puzzles
// player attack
// player lives; display on screen

// COMPLETE:
// create struct for while loop movement
// title screen and instructions (ensure chcp 65001 to choose UTF-8 encoding and terminal font is Cascadia mono)
// prevent `displayString` displaying `R""`