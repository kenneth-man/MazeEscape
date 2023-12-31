#ifndef _NONPLAYERSPRITES_
#define _NONPLAYERSPRITES_
#include <string>
#include "./types.h"

using namespace std;

namespace nonPlayerSprites {
	const stringMatrix2d buildingNoWindows = {
		{ "/", "-", "-", "-", "-", "-", "-", "-", "\\" },
		{ "|", " ", " ", " ", " ", " ", " ", " ", "|" },
		{ "|", " ", " ", " ", " ", " ", " ", " ", "|" },
		{ "|", "_", "_", "_", "▓", "_", "_", "_", "|"}
	};
	const stringMatrix2d buildingWithWindows = {
		{ "/", "-", "-", "-", "-", "-", "-", "-", "\\" },
		{ "|", " ", "▢", "▢", "", "▢", "▢", " ", "|" },
		{ "|", " ", "▢", "▢", " ", "▢", "▢", " ", "|" },
		{ "|", "_", "_", "_", "▓", "_", "_", "_", "|"}
	};
	const stringMatrix2d buildingWithWindows2 = {
		{ "/", "-", "-", "-", "-", "-", "-", "-", "\\" },
		{ "|", " ", "▢", " ", "", " ", "▢", " ", "|" },
		{ "|", " ", "▢", " ", " ", " ", "▢", " ", "|" },
		{ "|", "_", "_", "_", "▓", "_", "_", "_", "|"}
	};
	const stringMatrix2d buildingSpecial = {
		{ "/", "^", "^", "^", "^", "^", "^", "^", "\\" },
		{ "|", "Ж", "Ψ", "Ж", "Ψ", "Ж", "Ψ", "Ж", "|" },
		{ "|", "Ψ", "Ж", "Ψ", " ", "Ψ", "Ж", "Ψ", "|" },
		{ "|", "_", "_", "_", "▓", "_", "_", "_", "|"}
	};
}

#endif
