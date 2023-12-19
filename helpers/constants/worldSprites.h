#ifndef _WORLDSPRITES_
#define _WORLDSPRITES_
#include <string>
#include "./types.h"

using namespace std;

namespace worldSprites {
	const stringMatrix2d smallBuilding = {
		{ "/", "-", "\\" },
		{ "|", " ", "|" },
		{ "|", "▓", "|"}
	};
	const stringMatrix2d largeBuilding = {
		{ "/", "-", "-", "-", "\\" },
		{ "|", "▢", "▢", "▢", "|" },
		{ "|", "▢", " ", "▢","|"},
		{ "|", "_", "▓", "_", "|"}
	};
}

#endif
