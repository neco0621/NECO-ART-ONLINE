#pragma once
#include <cmath>
//ベクトルを便利に使うためのクラス

//ヘッダーファイルだけ移植すればいいようにしたいため
//プログラムを全部ヘッダーファイルにかく
class Vec3
{
public:
	float x;
	float y;
	float z;


public:
	Vec3() :
		x(0.0f),
		y(0.0f),
		z(0.0f)
	{

	}

	Vec3(float posX, float posY, float posZ) :
		x(posX),
		y(posY),
		z(posZ)
	{

	}
	//単項演算子+ Vec2 = +Vec2
	Vec3 operator+ () const
	{
		//自身の値をそのまま返せばいい
		return *this;
	}

	//単項演算子- Vec2 = -Vec2
	//逆ベクトルを求めるときに使う
	Vec3 operator- () const
	{
		return Vec3{ -x,-y,-z };
	}

	//足し算
	Vec3 operator+(Vec3 vec) const
	{
		return Vec3{ x + vec.x,y + vec.y, z + vec.z };
	}

	//Vec2 += Vec2
	Vec3 operator+= (Vec3 vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}

	//引き算
	Vec3 operator-(Vec3 vec) const
	{
		return Vec3{ x - vec.x,y - vec.y,z - vec.z };
	}

	//Vec2 -= Vec2
	Vec3 operator-= (Vec3 vec)
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		return *this;
	}

	//掛け算
	Vec3 operator* (float scale) const
	{
		return Vec3{ x * scale,y * scale, z * scale };
	}

	//Vec2 *= float;
	Vec3 operator*= (float scale)
	{
		x *= scale;
		y *= scale;
		z *= scale;
		return *this;
	}

	//割り算
	Vec3 operator/ (float scale) const
	{
		return Vec3{ x / scale,y / scale, z / scale };
	}

	//Vec2 /= float;
	Vec3 operator/= (float scale)
	{
		x /= scale;
		y /= scale;
		z /= scale;
		return *this;
	}


	//ベクトルの長さの2乗を求める(処理を軽くするため)
	float sqLength() const
	{
		return x * x + y * y;
	}

	//ベクトルの長さを求める
	float Length() const
	{
		return sqrtf(sqLength());
	}

	//自身の正規化を行う
	void normalize()
	{
		float len = Length();
		if (len > 0.0f)
		{
			x /= len;
			y /= len;
			z /= len;
		}
		//長さ0の場合は何もしない
	}

	//自身を正規化したベクトルを取得する
	Vec3 getNormalize() const
	{
		float len = Length();
		if (len > 0.0f)
		{
			return Vec3{ x / len, y / len, z / len };
		}
		//長さが0の場合
		return Vec3{ 0.0f,0.0f,0.0f };
	}
};

