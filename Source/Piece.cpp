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

// �ŏ��Ƀs�[�X�������_���Ŕz�u���邽�߂̊֐�
int Piece::RandPiece()
{
	// 1~5���o�������̂ŁA�ŏ���0�`4��rand�ŏo���Ă���+1����
	return (rand() % (PieceColor::COLOR_COUNT - 1)) + 1;
}
