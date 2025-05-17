#pragma once
#include "../Library/GameObject.h"
#include "global.h"

class Piece : public GameObject
{
public:
	Piece();
	Piece(int x, int y);
	~Piece();
	int RandPiece();
private:
	VECTOR pos;
};