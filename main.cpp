#include <iostream>
#include <conio.h>
#include "./Grid/Grid.h"

using namespace std;

int main() {
    Grid grid { 100, 15, "█" };
	Player player { 2, 4, "╇" };
	// single quotes for `char`, double quotes for `std::string`
	char input = '0';
	
	while(input != 'q') {
		grid.render(player);

		input = getch();

		if(input == 'w') {
			player.yPos -= 1;
		}

		if(input == 's') {
			player.yPos += 1;
		}

		if(input == 'a') {
			player.xPos -= 1;
		}

		if(input == 'd') {
			player.xPos += 1;
		}
	}

    return 0;
}

// TODO:
// player starting position refactor
// create struct for while loop movement
// improve player sprite
// different terrain character map
// boundaries checking (outside area)
// title screen and instructions (ensure chcp 65001 to choose UTF-8 encoding and terminal font is Cascadia mono)
// refactor grid border and align with grid size x and y
// collision detection (walls, structures)
// enemies chasing (timer? updates without needing player input?)
// raw string puzzles
// find a way to run `▓` in windows terminal without lag? (runs fine in vscode)

