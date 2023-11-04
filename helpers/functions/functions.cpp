#include <iostream>
#include "./functions.h"

using namespace std;

void helperFunctions::displayRawString(string input) {
	cout << "R\"" + input + "\"";
}