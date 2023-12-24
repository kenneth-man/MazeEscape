#include "./functions.h"

using namespace std;

void helperFunctions::displayString(string input) {
	cout << input << "\n";
}

void helperFunctions::exitProgramWithError(const vector<string> &errorMessages) {
	if (errorMessages.size() == 0) return;

	displayString(rawStrings::error);

	for (string e : errorMessages) {
		displayString(e);
	}

	displayString("");

	exit(1);
}

vector<int> helperFunctions::useMainArgs(
	int argc,
	char* argv[]
) {
	vector<int> gridDimensions {};

	// no height and width values were passed into the command; E.g. `./main.exe`
	if (argc == 1) {
		return gridDimensions;
	}

	const vector<string> invalidArguments {
		"Must provide 2 arguments for the terminal height and width",
		"For example: `./main.exe 120 20`"
	};
	const vector<string> outOfRange {
		"Argument/s for the terminal height and width is out of range for type `int`"
	};

	if (argc != 3) {
		exitProgramWithError(invalidArguments);
	}

	for (int i {1}; i < argc; ++i) {
		int arg;

		try {
			arg = stoi(argv[i]);
		} catch (const std::invalid_argument& e) {
			exitProgramWithError(invalidArguments);
		} catch (const std::out_of_range& e) {
			exitProgramWithError(outOfRange);
		}

		gridDimensions.push_back(arg);
	}

	return gridDimensions;
}

bool helperFunctions::isPositive(int number) {
	return number > 0;
}

vector<NonPlayer> helperFunctions::generateRandomXYPos(
	const Player &player,
	const vector<stringMatrix2d> &nonPlayerSprites,
	int count,
	int xSize,
	int ySize
) {
	srand(static_cast<unsigned>(time(NULL)));
	vector<NonPlayer> nonPlayer {};
	int nonPlayerSize {static_cast<int>(nonPlayerSprites.size())};

	for (int i {0}; i < count; ++i) {
		int randomIndex {rand() % nonPlayerSize};
		// 2-6 range; '+2' because never want the multiplier to be either '0' or '1'
		int randomMultiplier {rand() % 4 + 2};

		int x {};
		int xMax {xSize * randomMultiplier};
		int xMin {xMax * -1};

		int y {};
		int yMax {ySize * randomMultiplier};
		int yMin {yMax * -1};

		while (true) {
			x = rand() % (xMax * 2 + 1) + xMin;
			y = rand() % (yMax * 2 + 1) + yMin;

			int xAbs {abs(x)};
			int yAbs {abs(y)};
			int xDiff {player.xPos - x};
			int yDiff {player.yPos - y};

			int xPlayerSpriteSize {static_cast<int>(player.sprite[0].size())};
			int yPlayerSpriteSize {static_cast<int>(player.sprite.size())};
			int xNonPlayerSpriteSize {static_cast<int>(nonPlayerSprites[randomIndex][0].size())};
			int yNonPlayerSpriteSize {static_cast<int>(nonPlayerSprites[randomIndex].size())};
			int xSizeMultiplier {xAbs / xSize};
			int ySizeMultiplier {yAbs / ySize};

			bool xIntersectPlayerSprite {abs(xDiff) >= 0 && abs(xDiff) <= xPlayerSpriteSize};
			bool yIntersectPlayerSprite {abs(yDiff) >= 0 && abs(yDiff) <= yPlayerSpriteSize};
			bool xIntersectScreen {xAbs % xSize <= xNonPlayerSpriteSize || xAbs >= (xAbs > xSize ? xSize * (xSizeMultiplier + 1) : xSize * xSizeMultiplier) - xNonPlayerSpriteSize};
			bool yIntersectScreen {yAbs % ySize <= yNonPlayerSpriteSize || yAbs >= (yAbs > ySize ? ySize * (ySizeMultiplier + 1) : ySize * ySizeMultiplier) - yNonPlayerSpriteSize};

			if (
				x == player.xPos ||
				y == player.yPos ||
				xIntersectPlayerSprite ||
				yIntersectPlayerSprite ||
				xIntersectScreen ||
				yIntersectScreen
			) {
				continue;
			}

			break;
		}

		NonPlayer np {x, y, nonPlayerSprites[randomIndex]};

		nonPlayer.push_back(np);
	}

	return nonPlayer;
}
