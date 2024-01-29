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

void Grid::render(
	const Player &player,
	const vector<NonPlayer> &buildings,
	bool &boundaryUpdated,
	bool playerStand
) {
	// 'this' is implicitly used here... e.g. this->clearScreen(); it is being called on an instance of the Grid class (this)
	// can only call members of a class without an instance if it's in that class '.cpp' file
	// to call outside of the class '.cpp' file without an instance, make it a static method
	Grid::clearScreen();

	string output;

	if (!playerStand) {
		IShouldBoundaryUpdate boundary {Grid::shouldBoundaryUpdate(player.xPos, player.yPos)};

		if (boundary.shouldUpdate) {
			calcBoundaryUpdate(boundary.updateDirection);
			boundaryUpdated = true;
		}
	}

	for (int col {0}; col < Grid::ySize; ++col) {
		for (int row {0}; row < Grid::xSize; ++row) {
			string border {Grid::renderBorder(col, row)};
			if (border != helperConstants::falsyString) {
				output += border;
				continue;
			}

			bool buildingDimRendered {false};
			for (NonPlayer building : buildings) {
				string dim {Grid::renderSpriteDimension(building.sprite, building.xPos, building.yPos, col, row)};
				if (dim != helperConstants::falsyString) {
					output += dim;
					buildingDimRendered = true;
					break;
				}
			}
			if (buildingDimRendered) {
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

// Using ANSI escape codes to cout the 'HUD' so they don't interfere with the grid character positions in `Grid::render` loop
void Grid::renderHUD(
	const Player &player,
	string oSpecialBuilding
) {
	const string posTwoThree {"\033[2;3H"};
	const string posThreeThree {"\033[3;3H"};
	const string posFourThree {"\033[4;3H"};
	bool specialBuildingExists {oSpecialBuilding != helperConstants::falsyString};
	const string posMovement {specialBuildingExists ? posFourThree : posThreeThree};

	cout << posTwoThree << "x: " + to_string(player.xPos) + " " + "y: " + to_string(player.yPos) << '\n';

	if (specialBuildingExists) cout << posThreeThree << oSpecialBuilding;

	cout << posMovement << "Movement steps: ";
}

string Grid::renderBorder(
	int col,
	int row
) {
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

IShouldBoundaryUpdate Grid::shouldBoundaryUpdate(
	int playerXPos,
	int playerYPos
) {
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
	bool isScreenPositive {screen > 0};

	if (isScreenPositive) {
		if (playerPos < (screen == 1 ? 0 : (screen - 1) * size)) return dir1;
		if (playerPos > size * screen) return dir2;

		return Directions::NULL_DIRECTION;
	}

	if (playerPos > (screen == -1 ? 0 : (screen + 1) * size)) return dir2;
	if (playerPos < size * screen) return dir1;

	return Directions::NULL_DIRECTION;
}

void Grid::calcBoundaryUpdate(
	const Directions &direction
) {
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

void Grid::ignoreScreenZero(
	int &screen,
	int update
) {
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
	int pos,
	int screen,
	int size
) {
	bool isScreenPositive {screen > 0};

	if (isScreenPositive) {
		return index - (pos - (screen == 1 ? 0 : (screen - 1) * size));
	}

	return index - (
		screen == -1
			? pos + size
			: (
				pos > (screen * size) && pos <= ((screen + 1) * size) ? size - (abs(pos) % size) : index + 1
			)
		);
}
