#pragma once
#include "../Library/GameObject.h"
#include <vector>
#include "Piece.h"
#include "global.h"

class Stage : public GameObject
{
public:
	Stage();
	~Stage();
	void Draw() override;
	Piece piece;
	PieceColor pColor;
public:
	std::vector<std::vector<int>> board;
	std::vector<std::vector<int>> Pieces;
};