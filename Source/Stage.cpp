#include "Stage.h"
#include "DxLib.h"
#include <cstdlib>
#include <ctime>
#include <vector>

const int STAGE_X = 7;
const int STAGE_Y = 7;
const int MARGIN_HOR = 100; // 左右の余白
const int MARGIN_VER = 100; // 上下の余白
const int STAGE_CENTER = 40;

Stage::Stage()
{
	Pieces.resize(STAGE_Y, std::vector<int>(STAGE_X,0));
	srand((unsigned int)time(NULL));
	for (int y = 0; y < STAGE_Y; y++)
	{
		for (int x = 0; x < STAGE_X; x++)
		{
			do
			{
				Pieces[y][x] = rand() % (COLOR_COUNT - 1) + 1; // 1～5色

				bool retry = false;

				// 横チェック
				if (x >= 2 && Pieces[y][x] == Pieces[y][x - 1] && Pieces[y][x] == Pieces[y][x - 2])
					retry = true;

				// 縦チェック
				if (y >= 2 && Pieces[y][x] == Pieces[y - 1][x] && Pieces[y][x] == Pieces[y - 2][x])
					retry = true;

				if (!retry) break; // 問題なければループを抜ける

			} while (true);
		}
	}
}

Stage::~Stage()
{
}

void Stage::Update()
{
	Match();
}

void Stage::Draw()
{
	for (int y = 0; y <= STAGE_Y; y++)
	{
		for (int x = 0; x <= STAGE_X; x++)
		{
			// 縦線を描く
			int px = MARGIN_HOR + x * 80;
			DrawLine(px, MARGIN_VER, px, MARGIN_VER + STAGE_Y * 80, GetColor(255, 255, 255));

			// 横線を描く
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

void Stage::Match()
{
	bool toTrue[STAGE_Y][STAGE_X] = {};
	// 7マスあるので、判定をする場合3つ連なってればいいので
	// 0~4までループを回す
	// 消すところにフラグを立て、最後に一気に消す
	for (int y = 0; y < STAGE_Y; y++) // 全行チェック
	{
		for (int x = 0; x <= STAGE_X - 3; x++) // 横は3マス分減らす
		{
			if (Pieces[y][x] != 0 &&
				Pieces[y][x] == Pieces[y][x + 1] &&
				Pieces[y][x] == Pieces[y][x + 2])
			{
				toTrue[y][x] = TRUE;
				toTrue[y][x + 1] = TRUE;
				toTrue[y][x + 2] = TRUE;
			}
		}
	}

	// 縦チェック
	for (int y = 0; y <= STAGE_Y - 3; y++) // 縦は3マス分減らす
	{
		for (int x = 0; x < STAGE_X; x++) // 全列チェック
		{
			if (Pieces[y][x] != 0 &&
				Pieces[y][x] == Pieces[y + 1][x] &&
				Pieces[y][x] == Pieces[y + 2][x])
			{
				toTrue[y][x] = TRUE;
				toTrue[y + 1][x] = TRUE;
				toTrue[y + 2][x] = TRUE;
			}
		}
	}

	// フラグが立っているピースを消す
	for (int y = 0; y < STAGE_Y; y++)
	{
		for (int x = 0; x < STAGE_X; x++)
		{
			if (toTrue[y][x])
			{
				Pieces[y][x] = 0;
			}
		}
	}
}

void Stage::FallPiece()
{
	// 1個下のマスが0だった場合、上のピースが落ちてくる
	for (int y = 0; y < STAGE_Y - 1; y++)
	{
		for (int x = 0; x < STAGE_X; x++)
		{
			if (Pieces[y + 1][x] == 0)
			{
				Pieces[y + 1][x] = Pieces[y][x];
			}
		}
	}

	// 仮に一番上のピースが消えた場合
	// ランダムで色を生成する
	for (int x = 0; x < STAGE_X; x++)
	{
		if (Pieces[0][x] == 0)
		{
			Pieces[0][x] = rand() % (COLOR_COUNT - 1) + 1;
		}
	}
}

// クリックして入れ替える
// 隣り合わせの場合のみ
void Stage::SwapPiece()
{
}
