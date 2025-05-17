#include "Stage.h"
#include "DxLib.h"
#include <cstdlib>
#include <ctime>
#include <vector>

const int STAGE_X = 7;
const int STAGE_Y = 7;
const int MARGIN_HOR = 100; // ç∂âEÇÃó]îí
const int MARGIN_VER = 100; // è„â∫ÇÃó]îí
const int STAGE_CENTER = 40;

Stage::Stage()
{
	Pieces.resize(STAGE_Y, std::vector<int>(STAGE_X,0));
	srand((unsigned int)time(NULL));
	for (int y = 0; y < STAGE_Y; y++)
	{
		for (int x = 0; x < STAGE_X; x++)
		{
			Pieces[y][x] = piece.RandPiece();
		}
	}
}

Stage::~Stage()
{
}

void Stage::Draw()
{
	for (int y = 0; y <= STAGE_Y; y++)
	{
		for (int x = 0; x <= STAGE_X; x++)
		{
			// ècê¸Çï`Ç≠
			int px = MARGIN_HOR + x * 80;
			DrawLine(px, MARGIN_VER, px, MARGIN_VER + STAGE_Y * 80, GetColor(255, 255, 255));

			// â°ê¸Çï`Ç≠
			int py = MARGIN_VER + y * 80;
			DrawLine(MARGIN_HOR, py, MARGIN_HOR + STAGE_X * 80, py, GetColor(255, 255, 255));
		}
	}

	for (int y = 0; y < STAGE_Y; y++)
	{
		for (int x = 0; x < STAGE_X; x++)
		{
			//NONE = 0,GREEN = 1,RED = 2,BLUE = 3,YELLOW = 4,PURPLE = 5,
			switch (Pieces[y][x])
			{
			case 0:
				break;

			case 1:
				DrawCircle(MARGIN_HOR + STAGE_CENTER + 80 * x, MARGIN_VER + STAGE_CENTER + 80 * y,
					30, pGREEN, TRUE);
				break;
			case 2:
				DrawCircle(MARGIN_HOR + STAGE_CENTER + 80 * x, MARGIN_VER + STAGE_CENTER + 80 * y,
					30, pRED, TRUE);
				break;
			case 3:
				DrawCircle(MARGIN_HOR + STAGE_CENTER + 80 * x, MARGIN_VER + STAGE_CENTER + 80 * y,
					30, pBLUE, TRUE);
				break;
			case 4:
				DrawCircle(MARGIN_HOR + STAGE_CENTER + 80 * x, MARGIN_VER + STAGE_CENTER + 80 * y,
					30, pYELLOW, TRUE);
				break;
			case 5:
				DrawCircle(MARGIN_HOR + STAGE_CENTER + 80 * x, MARGIN_VER + STAGE_CENTER + 80 * y,
					30, pPURPLE, TRUE);
				break;
			}
		}
	}
}
