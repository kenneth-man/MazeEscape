#include <windows.h>
#include "./Grid.h"

using namespace std;

// moving the cursor to terminal's top left
// 'system('CLS') caused flickering before drawing to the terminal
void Grid::clearScreen() {	
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Grid::render(const Player &player) {
	// 'this' is implicitly used here... e.g. this->clearScreen(); it is being called on an instance of the Grid class (this)
	// can only call members of a class without an instance if it's in that class '.cpp' file
	// to call outside of the class '.cpp' file without an instance, make it a static method
	Grid::clearScreen();
	cout << "PLAYER x:" << player.xPos << " y:" << player.yPos << '\n';
	cout << "GRID x:" << Grid::xSize << " y:" << Grid::ySize << '\n';
	cout << "SCREEN x:" << Grid::xScreen << " y:" << Grid::yScreen << '\n';

	string output;
	IShouldBoundaryUpdate boundary {Grid::shouldBoundaryUpdate(player.xPos, player.yPos)};

	if (boundary.shouldUpdate) {
		calcBoundaryUpdate(boundary.updateDirection);
	}

	for (int col = 0; col < Grid::ySize; ++col) {
		for (int row = 0; row < Grid::xSize; ++row) {
			string border = Grid::renderBorder(col, row);

			if (border != helperConstants::falsyString) {
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

string Grid::renderBorder(int col, int row) {
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

	return helperConstants::falsyString;
}

IShouldBoundaryUpdate Grid::shouldBoundaryUpdate(int playerXPos, int playerYPos) {
	if (playerXPos < Grid::xSizeMin || playerXPos > Grid::xSize) {
		return IShouldBoundaryUpdate(playerXPos < Grid::xSizeMin ? Directions::LEFT : Directions::RIGHT);
	}
	if (playerYPos < Grid::ySizeMin || playerYPos > Grid::ySize) {
		return IShouldBoundaryUpdate(playerYPos < Grid::ySizeMin ? Directions::UP : Directions::DOWN);
	}
	
	return IShouldBoundaryUpdate();
}

void Grid::calcBoundaryUpdate(const Directions &updateDirection) {
	if (updateDirection == Directions::LEFT) {
		ignoreScreenZero(Grid::xScreen, -1);
		return;
	}
	if (updateDirection == Directions::RIGHT) {
		ignoreScreenZero(Grid::xScreen, 1);
		return;
	}
	if (updateDirection == Directions::UP) {
		ignoreScreenZero(Grid::yScreen, -1);
		return;
	}
	ignoreScreenZero(Grid::yScreen, 1);
}

void Grid::ignoreScreenZero(int &screen, int update) {
	const int newScreen {screen + (update)};
	screen = newScreen == 0 ? update : newScreen;
}
