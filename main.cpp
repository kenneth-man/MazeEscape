#include <iostream>
#include <conio.h>
#include "./Grid/Grid.h"
#include "./Actions/Actions.h"
#include "./TitleScreen/TitleScreen.h"

using namespace std;

int main() {
    Grid grid { 100, 15, "█" };
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

			gameStart = false;

			continue;
		}

		grid.render(player);

		input = getch();

		actions.movePlayer(input, player);
	}

    return 0;
}

// TODO:
// player starting position refactor
// create struct for while loop movement (COMPLETE)
// improve player sprite
// different terrain character map
// boundaries checking (outside area)
// title screen and instructions (ensure chcp 65001 to choose UTF-8 encoding and terminal font is Cascadia mono)
// prevent `displayRawString` displaying `R""`
// refactor grid border and align with grid size x and y
// collision detection (walls, structures)
// enemies chasing (timer? updates without needing player input?)
// raw string puzzles
// find a way to run `▓` in windows terminal without lag? (runs fine in vscode)
// player attack

