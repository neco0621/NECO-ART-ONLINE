#pragma once
#include "DxLib.h"
//プロトタイプ宣言
class Player;
class Camera
{
public:
	Camera();
	~Camera();

	void Update(const Player& player);
	void Draw();

	const VECTOR& GetPos() const { return m_pos; }

private:
	VECTOR m_pos;
};

