#include "./TitleScreen.h"

using namespace std;
using helperFunctions::displayString;
using rawStrings::titleName;
using rawStrings::titleDescription;

void TitleScreen::render() {
	displayString(titleName);
	displayString(titleDescription);
}
