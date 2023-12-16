#ifndef _FUNCTIONS_
#define _FUNCTIONS_
#include <iostream>
#include <string>
#include <vector>
#include "../constants/interfaces.h"
#include "../constants/constants.h"

using namespace std;

namespace helperFunctions {
	void displayString(const string input);
	int displayError(const vector<string> &errorMessages);
	//IMainCommandArgs useMainCommandArgs(const int &argc, const char* argv[]);
}

#endif
