#pragma once
#include "Vec3.h"
#include <DxLib.h>
//矩形の座標を管理するクラス
class Collision
{
public:
	Collision();
	virtual ~Collision();

	//当たり判定の矩形の描画
	void Draw(unsigned int Color, bool isFill);
	//当たり判定の立方体の描画
	void Draw3D(unsigned int Color, unsigned int Color2, bool isFill);
	//当たり判定の円の描画
	void DrawCircle2D(unsigned int Color, bool isFill);
	//当たり判定の球の描画
	void DrawBall(unsigned int color, unsigned int color2, bool isFill);

	//左上座標と幅高さを指定
	void SetLT(float left, float top, float width, float height);
	//左上座標と幅と高さと奥行を指定
	void SetLT3D(float left, float top, float back, float width, float height, float flont);
	//中心座標と幅高さを指定
	void SetCenter(float x, float y, float width, float height);
	//中心座標と幅と高さと奥行きを指定
	void SetCenter3D(float x, float y, float width, float height, float z, float back);
	//中心座標と半径を指定
	void SetRadius(float x, float y, float radius);
	//中心座標と半径と奥行を指定
	void SetRadius3D(float x, float y, float z, float radius);

	//必要な情報を取得する
	float GetWidth() const;		//幅
	float GetHeight() const;	//高さ
	float GetBack() const;		//奥行
	Vec3 GetCenter() const;		//中心座標
	//2点間の距離
	float DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2);

	//矩形同士の当たり判定
	bool BoxCollision(const Collision& col);
	//円同士の当たり判定
	bool CirCleCollision(const Collision& col);
	//矩形と円の当たり判定
	bool DistanceCollision(const Collision& col);
	//立方体同士の当たり判定
	bool BoxCollision3D(const Collision& col);
	//球同士の当たり判定
	bool SphereCollision(const Collision& col);


	float m_left;	//左上のX座標
	float m_right;	//右上のX座標
	float m_top;	//左上のY座標
	float m_bottom;	//右上のY座標
	float m_back;	//奥のZ座標
	float m_flont;	//手前のZ座標

	float m_centerX;	//中心のX座標
	float m_centerY;	//中心のY座標
	float m_centerZ;	//中心のZ座標
	float m_radius;		//半径

	VECTOR m_pos;	//現在地の座標

	int m_divNum;	//ポリゴン数
};