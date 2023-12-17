#ifndef _FUNCTIONS_
#define _FUNCTIONS_
#include <string>
#include <vector>
#include <iostream>
#include "../constants/constants.h"

using namespace std;

namespace helperFunctions {
	void displayString(string input);
	void exitProgramWithError(const vector<string> &errorMessages);
	vector<int> useMainArgs(int argc, char* argv[]);
}

#endif
