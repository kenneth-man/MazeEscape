#include "./functions.h"

using namespace std;

void helperFunctions::displayString(const string input) {
	cout << input << "\n";
}

int helperFunctions::displayError(const vector<string> &errorMessages) {
	if (errorMessages.size() == 0) return 0;

	for(string e : errorMessages) {
		cerr << e << '\n';
	}

	return 1;
}

// IMainCommandArgs helperFunctions::useMainCommandArgs(
// 	const int &argc,
// 	const char* argv[]
// ) {
// 	vector<int> gridDimensions;

// 	if (argc != 2) {
// 		return IMainCommandArgs(displayError(helperConstants::invalidArguments));
// 	}

// 	for (int i = 0; i < argc; ++i) {
// 		int arg;

// 		try {
// 			int arg = stoi(argv[i]);
// 		} catch (const std::invalid_argument& e) {
// 			return IMainCommandArgs(displayError(helperConstants::invalidArguments));
// 		} catch (const std::out_of_range& e) {
// 			return IMainCommandArgs(displayError(helperConstants::outOfRange));
// 		}

// 		gridDimensions.push_back(arg);
// 	}

// 	return IMainCommandArgs(gridDimensions);
// }
