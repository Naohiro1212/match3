#pragma once
#include "../Library/GameObject.h"

class Mouse : public GameObject
{
public:
	Mouse();
	~Mouse();
	bool IsLeftPressed() { return leftPressed; }
	bool IsLeftClicked() { return leftClicked; }
private:
	int MouseX = 0;
	int MouseY = 0;
	// �����ꂽ���ǂ����̔���
	bool leftPressed;
	// �����ꂽ�u��
	bool leftClicked;
};