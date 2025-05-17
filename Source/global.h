#pragma once

// ÉsÅ[ÉXÇÃenum
enum PieceColor
{
	NONE = 0,
	GREEN = 1,
	RED = 2,
	BLUE = 3,
	YELLOW = 4,
	PURPLE = 5,
	COLOR_COUNT = 6
};

static const int pGREEN = GetColor(0, 255, 0);
static const int pRED = GetColor(255, 0, 0);
static const int pBLUE = GetColor(0, 0, 255);
static const int pYELLOW = GetColor(255, 255, 0);
static const int pPURPLE = GetColor(255, 0, 255);