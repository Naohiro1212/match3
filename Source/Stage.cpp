#include "Stage.h"
#include "DxLib.h"
#include <cstdlib>
#include <ctime>
#include <vector>

const int STAGE_X = 7;
const int STAGE_Y = 7;
const int MARGIN_HOR = 100; // ���E�̗]��
const int MARGIN_VER = 100; // �㉺�̗]��
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
				Pieces[y][x] = rand() % (COLOR_COUNT - 1) + 1; // 1�`5�F

				bool retry = false;

				// ���`�F�b�N
				if (x >= 2 && Pieces[y][x] == Pieces[y][x - 1] && Pieces[y][x] == Pieces[y][x - 2])
					retry = true;

				// �c�`�F�b�N
				if (y >= 2 && Pieces[y][x] == Pieces[y - 1][x] && Pieces[y][x] == Pieces[y - 2][x])
					retry = true;

				if (!retry) break; // ���Ȃ���΃��[�v�𔲂���

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
			// �c����`��
			int px = MARGIN_HOR + x * 80;
			DrawLine(px, MARGIN_VER, px, MARGIN_VER + STAGE_Y * 80, GetColor(255, 255, 255));

			// ������`��
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
	// 7�}�X����̂ŁA���������ꍇ3�A�Ȃ��Ă�΂����̂�
	// 0~4�܂Ń��[�v����
	// �����Ƃ���Ƀt���O�𗧂āA�Ō�Ɉ�C�ɏ���
	for (int y = 0; y < STAGE_Y; y++) // �S�s�`�F�b�N
	{
		for (int x = 0; x <= STAGE_X - 3; x++) // ����3�}�X�����炷
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

	// �c�`�F�b�N
	for (int y = 0; y <= STAGE_Y - 3; y++) // �c��3�}�X�����炷
	{
		for (int x = 0; x < STAGE_X; x++) // �S��`�F�b�N
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

	// �t���O�������Ă���s�[�X������
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
	// 1���̃}�X��0�������ꍇ�A��̃s�[�X�������Ă���
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

	// ���Ɉ�ԏ�̃s�[�X���������ꍇ
	// �����_���ŐF�𐶐�����
	for (int x = 0; x < STAGE_X; x++)
	{
		if (Pieces[0][x] == 0)
		{
			Pieces[0][x] = rand() % (COLOR_COUNT - 1) + 1;
		}
	}
}

// �N���b�N���ē���ւ���
// �ׂ荇�킹�̏ꍇ�̂�
void Stage::SwapPiece()
{
}
