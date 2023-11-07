#include <iostream>
#include <stdlib.h>
#include "./Grid.h"
#include "../helpers/constants/constants.h"

using namespace std;

void Grid::render(const Player &player) {
	system("CLS");

	for (int col = 0; col < Grid::ySize; col++) {
		for (int row = 0; row < Grid::xSize; row ++) {
			// refactor this all
			if (row == 0 && col == Grid::ySize - 1) {
				cout << helperConstants::botLeftBorder;
				continue;
			}
			if (row == Grid::xSize - 1 && col == Grid::ySize - 1) {
				cout << helperConstants::botRightBorder;
				continue;
			}
			if (row == Grid::xSize - 1 && col == 0) {
				cout << helperConstants::topRightBorder;
				continue;
			}
			if (row == 0 && col == 0) {
				cout << helperConstants::topLeftBorder;
				continue;
			}
			if (row == Grid::xSize - 1 || row == 0) {
				cout << helperConstants::xBorder;
				continue;
			}
			if (col == Grid::ySize - 1 || col == 0) {
				cout << helperConstants::yBorder;
				continue;
			}
			if (player.xPos == row && player.yPos == col) {
				cout << player.sprite;
				continue;
			}
			cout << Grid::sprite;
		}
		cout << "\n";
	}
}
