#include "./TitleScreen.h"
#include "../helpers/functions/functions.h"
#include "../helpers/constants/constants.h"

using namespace std;
using helperFunctions::displayString;
using helperConstants::titleName;
using helperConstants::titleDescription;

void TitleScreen::render() {
	displayString(titleName);
	displayString(titleDescription);
}
