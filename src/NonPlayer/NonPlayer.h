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
	// using 'this->' because we want to compare the arg with this instance's 'sprite'
	// 'NonPlayer::sprite' would be a static member which is shared across all 'NonPlayer's
	bool operator==(const stringMatrix2d &rhs) const {
		return rhs == this->sprite;
	}
	// for using `NonPlayer` with `std::map`
    bool operator<(const NonPlayer &rhs) const {
        return rhs.xPos > this->xPos || rhs.yPos > this->yPos;
    }
};

#endif
