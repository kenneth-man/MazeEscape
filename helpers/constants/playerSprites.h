#ifndef _PLAYERSPRITES_
#define _PLAYERSPRITES_
#include <string>
#include <vector>
#include "./types.h"

using namespace std;

namespace playerSprites {
	const PlayerSprite standUp = {
		{ "_", "◓", "_" },
		{ "|", "|", "|" },
		{ "/", " ", "\\"}
	};
	const PlayerSprite moveUpInitial = {
		{ "_", "◓", "_" },
		{ "╵", "|", "|" },
		{ "|", " ", "╵"}
	};
	const PlayerSprite moveUpFinal = {
		{ "_", "◓", "_" },
		{ "|", "|", "╵" },
		{ "╵", " ", "|"}
	};
	const PlayerSprite standLeft = {
		{ "_", "◐", "_" },
		{ "/", "|", "\\" },
		{ "|", " ", "|"}
	};
	const PlayerSprite moveLeftInitial = {
		{ "_", "◐", "_" },
		{ "/", "|", "|" },
		{ "/", " ", "\\"}
	};
	const PlayerSprite moveLeftFinal = {
		{ "_", "◐", "_" },
		{ "\\", "|", "\\" },
		{ "\\", " ", "\\"}
	};
	const PlayerSprite standDown = {
		{ "_", "◒", "_" },
		{ "|", "|", "|" },
		{ "/", " ", "\\"}
	};
	const PlayerSprite moveDownIntial = {
		{ "_", "◒", "_" },
		{ "╵", "|", "|" },
		{ "|", " ", "╵"}
	};
	const PlayerSprite moveDownFinal = {
		{ "_", "◒", "_" },
		{ "|", "|", "╵" },
		{ "╵", " ", "|"}
	};
	const PlayerSprite standRight = {
		{ "_", "◑", "_" },
		{ "/", "|", "\\" },
		{ "|", " ", "|"}
	};
	const PlayerSprite moveRightInitial = {
		{ "_", "◑", "_" },
		{ "|", "|", "\\" },
		{ "/", " ", "\\"}
	};
	const PlayerSprite moveRightFinal = {
		{ "_", "◑", "_" },
		{ "/", "|", "/" },
		{ "/", " ", "/"}
	};
	const vector<vector<PlayerSprite>> move {
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
	const vector<PlayerSprite> stand {
		standUp,
		standLeft,
		standDown,
		standRight,
	};
}

#endif
