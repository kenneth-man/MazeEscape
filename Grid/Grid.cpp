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

void Grid::render(const Player &player, bool playerStand) {
	// 'this' is implicitly used here... e.g. this->clearScreen(); it is being called on an instance of the Grid class (this)
	// can only call members of a class without an instance if it's in that class '.cpp' file
	// to call outside of the class '.cpp' file without an instance, make it a static method
	Grid::clearScreen();

	string output;

	if (!playerStand) {
		IShouldBoundaryUpdate boundary {Grid::shouldBoundaryUpdate(player.xPos, player.yPos)};

		if (boundary.shouldUpdate) {
			calcBoundaryUpdate(boundary.updateDirection);
		}
	}

	for (int col {0}; col < Grid::ySize; ++col) {
		for (int row {0}; row < Grid::xSize; ++row) {
			string border {Grid::renderBorder(col, row)};
			if (border != helperConstants::falsyString) {
				output += border;
				continue;
			}

			string playerDim {Grid::renderSpriteDimension(player.sprite, player.xPos, player.yPos, col, row)};
			if (playerDim != helperConstants::falsyString) {
                output += playerDim;
                continue;
            }

            output += Grid::sprite;
		}
		output += "\n";
	}

	cout << output;
}

string Grid::renderBorder(int col, int row) {
	const bool firstCol {col == 0};
	const bool lastCol {col == Grid::ySize - 1};
	const bool firstRow {row == 0};
	const bool lastRow {row == Grid::xSize - 1};

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
	const Directions xDirection {
		checkShouldBoundaryUpdate(
			playerXPos,
			Grid::xScreen,
			Grid::xSize,
			Directions::LEFT,
			Directions::RIGHT
		)
	};

	if (xDirection != Directions::NULL_DIRECTION) {
		return IShouldBoundaryUpdate(xDirection);
	}

	const Directions yDirection {
		checkShouldBoundaryUpdate(
			playerYPos,
			Grid::yScreen,
			Grid::ySize,
			Directions::UP,
			Directions::DOWN
		)
	};

	if (yDirection != Directions::NULL_DIRECTION) {
		return IShouldBoundaryUpdate(yDirection);
	}
	
	return IShouldBoundaryUpdate();
}

Directions Grid::checkShouldBoundaryUpdate(
	int playerPos,
	int screen,
	int size,
	const Directions &dir1,
	const Directions &dir2
) {
	bool isScreenPositive {helperFunctions::isPositive(screen)};

	if (isScreenPositive) {
		if (playerPos < (screen == 1 ? 0 : (screen - 1) * size)) return dir1;
		if (playerPos > size * screen) return dir2;

		return Directions::NULL_DIRECTION;
	}

	if (playerPos > (screen == -1 ? 0 : (screen + 1) * size)) return dir2;
	if (playerPos < size * screen) return dir1;

	return Directions::NULL_DIRECTION;
}

void Grid::calcBoundaryUpdate(const Directions &direction) {
	if (direction == Directions::LEFT) {
		ignoreScreenZero(Grid::xScreen, -1);
		return;
	}
	if (direction == Directions::RIGHT) {
		ignoreScreenZero(Grid::xScreen, 1);
		return;
	}
	if (direction == Directions::UP) {
		ignoreScreenZero(Grid::yScreen, -1);
		return;
	}
	ignoreScreenZero(Grid::yScreen, 1);
}

void Grid::ignoreScreenZero(int &screen, int update) {
	const int newScreen {screen + (update)};
	screen = newScreen == 0 ? update : newScreen;
}

string Grid::renderSpriteDimension(
	const stringMatrix2d &sprite,
	int xPos,
	int yPos,
	int col,
	int row
) {
	int dim1 {Grid::calcSpriteDimension(col, yPos, Grid::yScreen, Grid::ySize)};
	int dim2 {Grid::calcSpriteDimension(row, xPos, Grid::xScreen, Grid::xSize)};

	if (
		dim1 >= 0 &&
		dim2 >= 0 &&
		dim1 < static_cast<int>(sprite.size()) &&
		dim2 < static_cast<int>(sprite[dim1].size())
	) {
		return sprite[dim1][dim2];
    }

	return helperConstants::falsyString;
}

int Grid::calcSpriteDimension(
	int index,
	int playerPos,
	int screen,
	int size
) {
	bool isScreenPositive {helperFunctions::isPositive(screen)};

	if (isScreenPositive) {
		return index - (playerPos - (screen == 1 ? 0 : (screen - 1) * size));
	}

	return index - (screen == -1 ? playerPos + size : size - (abs(playerPos) % size));
}
