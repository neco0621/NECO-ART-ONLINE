#include "Collision.h"
#include <DxLib.h>
#include<cmath>
#include <cassert>

Collision::Collision() :
	//初期化
	m_left(0.0f),
	m_right(0.0f),
	m_top(0.0f),
	m_bottom(0.0f),
	m_back(0.0f),
	m_flont(0.0f),
	m_centerX(0.0f),
	m_centerY(0.0f),
	m_centerZ(0.0f),
	m_radius(0.0f),
	m_divNum(16),
	m_pos(VGet(0, 0, 0))
{
}

Collision::~Collision()
{
}

//当たり判定の矩形の描画
void Collision::Draw(unsigned int color, bool isFill)
{
	DrawBox(static_cast<int> (m_left), static_cast<int>(m_top), static_cast<int> (m_right), static_cast<int>(m_bottom), color, isFill);
}

//当たり判定の立方体の描画
void Collision::Draw3D(unsigned int color, unsigned int color2, bool isFill)
{
	DrawCube3D(VGet(static_cast<int> (m_left), static_cast<int>(m_top), static_cast<int> (m_back)), VGet(static_cast<int> (m_right), static_cast<int>(m_bottom), static_cast<int>(m_flont)), color, color2, isFill);
}

//当たり判定の円の描画
void Collision::DrawCircle2D(unsigned int color, bool isFill)
{
	DrawCircle(static_cast<int> (m_centerX), static_cast<int>(m_centerY), static_cast<int> (m_radius), color, isFill);
}

//当たり判定の球の描画
void Collision::DrawBall(unsigned int color, unsigned int color2, bool isFill)
{
	DrawSphere3D(VGet(static_cast<int> (m_centerX), static_cast<int>(m_centerY), static_cast<int>(m_centerZ)), static_cast<int> (m_radius), m_divNum, color, color2, isFill);
}

//左上座標と幅高さを指定
void Collision::SetLT(float left, float top, float width, float height)
{
	m_left = left;			//左上のX座標
	m_top = top;			//左上のY座標
	m_right = left + width;	//右下のX座標
	m_bottom = top + height;//右下のY座標
}

//左上座標と幅と高さと奥行を指定
void Collision::SetLT3D(float left, float top, float back, float width, float height, float flont)
{
	m_left = left;			//左上のX座標
	m_top = top;			//左上のY座標
	m_right = left + width;	//右下のX座標
	m_bottom = top + height;//右下のY座標
	m_flont = flont;		//手前のZ座標
	m_back = back;			//奥のZ座標
}

//中心座標と幅高さを指定
void Collision::SetCenter(float x, float y, float width, float height)
{
	m_left = x - width / 2;
	m_top = y - height / 2;
	m_right = x + width / 2;
	m_bottom = y + height / 2;
}

//中心座標と幅と高さと奥行きを指定
void Collision::SetCenter3D(float x, float y, float width, float height, float z, float back)
{
	m_left = x - width / 2;
	m_top = y - height / 2;
	m_flont = z - back / 2;
	m_right = x + width / 2;
	m_bottom = y + height / 2;
	m_back = z + back / 2;
}

//中心座標と半径を指定
void Collision::SetRadius(float x, float y, float radius)
{
	m_centerX = x;
	m_centerY = y;
	m_radius = radius;
}

//中心座標と半径と奥行を指定
void Collision::SetRadius3D(float x, float y, float z, float radius)
{
	m_centerX = x;
	m_centerY = y;
	m_centerZ = z;
	m_radius = radius;
}

//幅の取得
float Collision::GetWidth() const
{
	assert(m_right >= m_left);
	return m_right - m_left;
}

//高さの取得
float Collision::GetHeight() const
{
	assert(m_bottom >= m_top);

	return m_bottom - m_top;
}

//奥行の取得
float Collision::GetBack() const
{
	assert(m_back >= m_flont);

	return m_back - m_flont;
}

//中心座標の取得
Vec3 Collision::GetCenter() const
{
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	x = (m_right + m_left) / 2;
	y = (m_top + m_bottom) / 2;
	z = (m_back + m_flont) / 2;

	return Vec3{ x,y,z };
}

//2つの座標の距離を取得
float Collision::DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2)
{
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}

//矩形同士の当たり判定
bool Collision::BoxCollision(const Collision& col)
{
	//絶対に当たらないパターンをはじいていく
	if (m_left > col.m_right)	return false;
	if (m_top > col.m_bottom)	return false;
	if (m_right < col.m_left)	return false;
	if (m_bottom < col.m_top)	return false;

	//当たらないパターン以外は当たっている
	return true;
}

//円同士の当たり判定
bool Collision::CirCleCollision(const Collision& col)
{
	float dx = m_centerX - col.m_centerX;
	float dy = m_centerY - col.m_centerY;
	float dr = dx * dx + dy * dy;

	float ar = m_radius + col.m_radius;
	float dl = ar * ar;
	if (dr <= dl)
	{
		return true;
	}
	return false;
}

//矩形と円の当たり判定
bool Collision::DistanceCollision(const Collision& col)
{
	//当たっていないパターンをはじく
	bool nResult = false;
	if ((m_centerX > col.m_left - m_radius) &&
		(m_centerX < col.m_right + m_radius) &&
		(m_centerY > col.m_top - m_radius) &&
		(m_centerY < col.m_bottom + m_radius))
	{
		nResult = true;
		float dl = m_radius * m_radius;
		// 左
		if (m_centerX < col.m_left)
		{
			// 左上
			if ((m_centerY < col.m_top))
			{
				if ((DistanceSqrf(col.m_left, col.m_top, m_centerX, m_centerY) >= dl))
				{
					nResult = false;
				}
			}
			else
			{
				// 左下
				if ((m_centerY > col.m_bottom))
				{
					if ((DistanceSqrf(col.m_left, col.m_bottom, m_centerX, m_centerY) >= dl))
					{
						nResult = false;
					}
				}
			}
		}
		else
		{
			// 右
			if (m_centerX > col.m_right)
			{
				// 右上
				if ((m_centerY < col.m_top))
				{
					if ((DistanceSqrf(col.m_right, col.m_top, m_centerX, m_centerY) >= dl))
					{
						nResult = false;
					}
				}
				else
				{
					// 右下
					if ((m_centerY > col.m_bottom))
					{
						if ((DistanceSqrf(col.m_right, col.m_bottom, m_centerX, m_centerY) >= dl))
						{
							nResult = false;
						}
					}
				}
			}
		}
	}

	return nResult;
}

//立方体同士の当たり判定
bool Collision::BoxCollision3D(const Collision& col)
{
	//絶対に当たらないパターンをはじいていく
	if (m_left > col.m_right)	return false;
	if (m_top > col.m_bottom)	return false;
	if (m_right < col.m_left)	return false;
	if (m_bottom < col.m_top)	return false;
	if (m_flont > col.m_back)  return false;
	if (m_back < col.m_flont)	return false;
	//当たらないパターン以外は当たっている
	return true;
}

//球同士の当たり判定
bool Collision::SphereCollision(const Collision& col)
{
	VECTOR Vec = VSub(VGet(m_centerX, m_centerY, m_centerZ), VGet(col.m_centerX, col.m_centerY, col.m_centerZ));

	if (VSize(Vec) < m_radius + col.m_radius)
	{
		return true;
	}

	return false;
}