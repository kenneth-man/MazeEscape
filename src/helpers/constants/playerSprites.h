#ifndef _PLAYERSPRITES_
#define _PLAYERSPRITES_
#include <string>
#include <vector>
#include "./types.h"

using namespace std;

namespace playerSprites {
	const stringMatrix2d standUp = {
		{ "_", "◓", "_" },
		{ "|", "|", "|" },
		{ "/", " ", "\\"}
	};
	const stringMatrix2d moveUpInitial = {
		{ "_", "◓", "_" },
		{ "╵", "|", "|" },
		{ "|", " ", "╵"}
	};
	const stringMatrix2d moveUpFinal = {
		{ "_", "◓", "_" },
		{ "|", "|", "╵" },
		{ "╵", " ", "|"}
	};
	const stringMatrix2d standLeft = {
		{ "_", "◐", "_" },
		{ "/", "|", "\\" },
		{ "|", " ", "|"}
	};
	const stringMatrix2d moveLeftInitial = {
		{ "_", "◐", "_" },
		{ "/", "|", "|" },
		{ "/", " ", "\\"}
	};
	const stringMatrix2d moveLeftFinal = {
		{ "_", "◐", "_" },
		{ "\\", "|", "\\" },
		{ "\\", " ", "\\"}
	};
	const stringMatrix2d standDown = {
		{ "_", "◒", "_" },
		{ "|", "|", "|" },
		{ "/", " ", "\\"}
	};
	const stringMatrix2d moveDownIntial = {
		{ "_", "◒", "_" },
		{ "╵", "|", "|" },
		{ "|", " ", "╵"}
	};
	const stringMatrix2d moveDownFinal = {
		{ "_", "◒", "_" },
		{ "|", "|", "╵" },
		{ "╵", " ", "|"}
	};
	const stringMatrix2d standRight = {
		{ "_", "◑", "_" },
		{ "/", "|", "\\" },
		{ "|", " ", "|"}
	};
	const stringMatrix2d moveRightInitial = {
		{ "_", "◑", "_" },
		{ "|", "|", "\\" },
		{ "/", " ", "\\"}
	};
	const stringMatrix2d moveRightFinal = {
		{ "_", "◑", "_" },
		{ "/", "|", "/" },
		{ "/", " ", "/"}
	};
	const vector<vector<stringMatrix2d>> move {
		{
			moveUpInitial,
			moveUpFinal
		},
		{
			moveLeftInitial,
			moveLeftFinal
		},
		{
			moveDownIntial,
			moveDownFinal
		},
		{
			moveRightInitial,
			moveRightFinal
		},
	};
	const vector<stringMatrix2d> stand {
		standUp,
		standLeft,
		standDown,
		standRight,
	};
}

#endif
