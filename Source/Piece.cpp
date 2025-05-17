#include "Piece.h"
#include "global.h"

Piece::Piece()
{
	pos.x = 0;
	pos.y = 0;
}

Piece::Piece(int x, int y)
{
	pos.x = x;
	pos.y = x;
}

Piece::~Piece()
{
}

/// <summary>
/// 最初にピースをランダムで配置するための関数
/// </summary>
int Piece::RandPiece()
{
	// 1~5を出したいので、最初に0～4をrandで出してから+1する
	return (rand() % (PieceColor::COLOR_COUNT - 1)) + 1;
}
