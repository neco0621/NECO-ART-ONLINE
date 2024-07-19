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

	void Rotate(float* x, float* y, float ang, const float mx, const float my);


	const VECTOR& GetPos() const { return m_pos; }

private:
	VECTOR m_pos;
	VECTOR m_rot;
};

