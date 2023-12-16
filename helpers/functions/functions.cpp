#include <iostream>
#include "./functions.h"

using namespace std;

void helperFunctions::displayString(string input) {
	cout << input << "\n";
}

void helperFunctions::exitProgramWithError(const vector<string> &errorMessages) {
	if (errorMessages.size() == 0) return;

	for(string e : errorMessages) {
		cerr << e << '\n';
	}

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

	for (int i = 1; i < argc; ++i) {
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
