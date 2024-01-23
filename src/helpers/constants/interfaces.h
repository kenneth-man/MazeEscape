#ifndef _INTERFACES_
#define _INTERFACES_
#include <string>
#include <vector>
#include "./types.h"
#include "./enums.h"

using namespace std;

// struct IExample {
//	vector<vector<stringMatrix2d>> playerMoveSprites;
//	vector<stringMatrix2d> playerStandSprites;
// };

// struct IAnotherExample {
//	vector<int> dimensions;
//	int dimension;
//	IAnotherExample(const vector<int> &d) : dimensions{d}, dimension{} {}
//	IAnotherExample(const int d) : dimensions{}, dimension{d} {}
// };

struct IShouldBoundaryUpdate {
	Directions updateDirection;
    bool shouldUpdate;
    IShouldBoundaryUpdate(Directions d) : updateDirection{d}, shouldUpdate{true} {}
    IShouldBoundaryUpdate() : shouldUpdate{false} {}
};

#endif
