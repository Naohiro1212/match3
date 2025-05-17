#include "Mouse.h"
#include "DxLib.h"

Mouse::Mouse()
{
	leftPressed = false;
	GetMousePoint(&MouseX, &MouseY);
}

Mouse::~Mouse()
{
}


