#include "Stage.h"
#include "DxLib.h"

static const int STAGE_X = 7;
static const int STAGE_Y = 7;
static const int MARGIN_HOR = 100; // ¶‰E‚Ì—]”’
static const int MARGIN_VER = 100; // ã‰º‚Ì—]”’

Stage::Stage()
{
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
			// cü‚ğ•`‚­
			int px = MARGIN_HOR + x * 80;
			DrawLine(px, MARGIN_VER, px, MARGIN_VER + STAGE_Y * 80, GetColor(0, 0, 0));

			// ‰¡ü‚ğ•`‚­
			int py = MARGIN_VER + y * 80;
			DrawLine(MARGIN_HOR, py, MARGIN_HOR + STAGE_X * 80, py, GetColor(0, 0, 0));
		}
	}
}
