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
	// ‰Ÿ‚³‚ê‚½‚©‚Ç‚¤‚©‚Ì”»’è
	bool leftPressed;
	// ‰Ÿ‚³‚ê‚½uŠÔ
	bool leftClicked;
};