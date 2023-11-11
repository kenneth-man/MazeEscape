#include <iostream>
#include <stdlib.h>
#include "./Grid.h"
#include "../helpers/constants/constants.h"

using namespace std;

void Grid::render(const Player &player) {
	system("CLS");

	for (int col = 0; col < Grid::ySize; col++) {
		for (int row = 0; row < Grid::xSize; row ++) {
			if (Grid::renderBorder(col, row)) {
				continue;
			}

			int vecSecondIndex = row - player.xPos;
			int vecFirstIndex = col - player.yPos;

			if (
				vecFirstIndex >= 0 &&
				vecSecondIndex >= 0 &&
				vecFirstIndex < player.sprite.size() &&
				vecSecondIndex < player.sprite[vecFirstIndex].size()
			) {
                cout << player.sprite[vecFirstIndex][vecSecondIndex];
                continue;
            }

            cout << Grid::sprite;
		}
		cout << "\n";
	}
}

bool Grid::renderBorder(int col, int row) {
	const bool firstCol = col == 0;
	const bool lastCol = col == Grid::ySize - 1;
	const bool firstRow = row == 0;
	const bool lastRow = row == Grid::xSize - 1;

	if (firstRow && lastCol) {
		cout << helperConstants::botLeftBorder;
		return true;
	}
	if (lastRow && lastCol) {
		cout << helperConstants::botRightBorder;
		return true;
	}
	if (lastRow && firstCol) {
		cout << helperConstants::topRightBorder;
		return true;
	}
	if (firstRow && firstCol) {
		cout << helperConstants::topLeftBorder;
		return true;
	}
	if (firstRow || lastRow) {
		cout << helperConstants::xBorder;
		return true;
	}
	if (firstCol || lastCol) {
		cout << helperConstants::yBorder;
		return true;
	}

	return false;
}
