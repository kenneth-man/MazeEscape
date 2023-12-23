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
	vector<int> gridDimensions;
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
	int xSize,
	int ySize
) {
	srand(static_cast<unsigned>(time(NULL)));
	vector<NonPlayer> nonPlayer {};
	int nonPlayerSize {static_cast<int>(nonPlayerSprites.size())};

	for (int i {0}; i < nonPlayerSize; ++i) {
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

			int xDiff {player.xPos - x};
			int yDiff {player.yPos - y};
			// NonPlayer temp {x, y};
			// vector<NonPlayer>::iterator xyIt {find(nonPlayer.begin(), nonPlayer.end(), temp)};
			bool xWithinPlayerSprite {abs(xDiff) >= 0 && abs(xDiff) <= player.sprite[0].size()};
			bool yWithinPlayerSprite {abs(yDiff) >= 0 && abs(yDiff) <= player.sprite.size()};

			if (
				// xyIt != nonPlayer.end() ||
				x == player.xPos ||
				y == player.yPos ||
				xWithinPlayerSprite ||
				yWithinPlayerSprite 
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
