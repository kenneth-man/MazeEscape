#ifndef _CONSTANTS_
#define _CONSTANTS_
#include <string>
#include <vector>
#include "./interfaces.h"
#include "./types.h"

using namespace std;

namespace helperConstants {
	// single quotes for `char`, double quotes for `std::string`
	const char defaultInput {'0'};
	const char inputQuit {'q'};
	const char inputSpace {' '};
	const char inputUp {'w'};
	const char inputLeft {'a'};
	const char inputDown {'s'};
	const char inputRight {'d'};
	const string falsyString {""};
	const string defaultTerrain {" "};
	const string wall {"█"};
	const string xBorder {"║"};
	const string yBorder {"═"};
	const string topLeftBorder {"╔"};
	const string topRightBorder {"╗"};
	const string botLeftBorder {"╚"};
	const string botRightBorder {"╝"};
}

#endif
