#include <iostream>
#include "./TitleScreen.h"
#include "../helpers/functions/functions.h"
#include "../helpers/constants/constants.h"

using namespace std;
using helperFunctions::displayRawString;
using helperConstants::demon;

void TitleScreen::render() {
	displayRawString(demon);
}
