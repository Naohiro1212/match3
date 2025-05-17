#pragma once
#include "../Library/GameObject.h"
#include <vector>

class Stage : public GameObject
{
public:
	Stage();
	~Stage();
	void Draw() override;
public:
	std::vector<std::vector<int>> board;
};