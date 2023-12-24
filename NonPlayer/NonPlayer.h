#ifndef _NONPLAYER_
#define _NONPLAYER_
#include <string>
#include <vector>
#include "../helpers/constants/types.h"

using namespace std;

struct NonPlayer {
	int xPos;
	int yPos;
	stringMatrix2d sprite;
	// using 'this->' because we want to compare the instance's 'xPos' and 'yPos'
	// 'NonPlayer::xPos' would be a static member which is shared across all 'NonPlayer's
	// bool operator==(const NonPlayer &np) { return this->xPos == np.xPos || this->yPos == np.yPos; }
};

#endif
