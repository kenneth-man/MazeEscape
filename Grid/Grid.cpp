#include <iostream>
#include <windows.h>
#include "./Grid.h"
#include "../helpers/constants/constants.h"

using namespace std;

// moving the cursor to terminal's top left
// 'system('CLS') caused flickering before drawing to the terminal
void Grid::clearScreen() const {	
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Grid::render(const Player &player) const {
	// 'this' is implicitly used here... e.g. this->clearScreen(); it is being called on an instance of the Grid class (this)
	// can only call members of a class without an instance if it's in that class '.cpp' file
	// to call outside of the class '.cpp' file without an instance, make it a static method
	Grid::clearScreen();

	string output;

	for (int col = 0; col < Grid::ySize; col++) {
		for (int row = 0; row < Grid::xSize; row ++) {
			string border = Grid::renderBorder(col, row);

			if (border != "") {
				output += border;
				continue;
			}

			size_t vecSecondIndex = row - player.xPos;
			size_t vecFirstIndex = col - player.yPos;

			if (
				vecFirstIndex >= 0 &&
				vecSecondIndex >= 0 &&
				vecFirstIndex < player.sprite.size() &&
				vecSecondIndex < player.sprite[vecFirstIndex].size()
			) {
                output += player.sprite[vecFirstIndex][vecSecondIndex];
                continue;
            }

            output += Grid::sprite;
		}
		output += "\n";
	}

	cout << output;
}

string Grid::renderBorder(int col, int row) const {
	const bool firstCol = col == 0;
	const bool lastCol = col == Grid::ySize - 1;
	const bool firstRow = row == 0;
	const bool lastRow = row == Grid::xSize - 1;

	if (firstRow && lastCol) {
		return helperConstants::botLeftBorder;
	}
	if (lastRow && lastCol) {
		return helperConstants::botRightBorder;
	}
	if (lastRow && firstCol) {
		return helperConstants::topRightBorder;
	}
	if (firstRow && firstCol) {
		return helperConstants::topLeftBorder;
	}
	if (firstRow || lastRow) {
		return helperConstants::xBorder;
	}
	if (firstCol || lastCol) {
		return helperConstants::yBorder;
	}

	return "";
}
