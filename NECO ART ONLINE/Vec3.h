#pragma once
#include <cmath>
//�x�N�g����֗��Ɏg�����߂̃N���X

//�w�b�_�[�t�@�C�������ڐA����΂����悤�ɂ���������
//�v���O������S���w�b�_�[�t�@�C���ɂ���
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
	//�P�����Z�q+ Vec2 = +Vec2
	Vec3 operator+ () const
	{
		//���g�̒l�����̂܂ܕԂ��΂���
		return *this;
	}

	//�P�����Z�q- Vec2 = -Vec2
	//�t�x�N�g�������߂�Ƃ��Ɏg��
	Vec3 operator- () const
	{
		return Vec3{ -x,-y,-z };
	}

	//�����Z
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

	//�����Z
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

	//�|���Z
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

	//����Z
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


	//�x�N�g���̒�����2������߂�(�������y�����邽��)
	float sqLength() const
	{
		return x * x + y * y;
	}

	//�x�N�g���̒��������߂�
	float Length() const
	{
		return sqrtf(sqLength());
	}

	//���g�̐��K�����s��
	void normalize()
	{
		float len = Length();
		if (len > 0.0f)
		{
			x /= len;
			y /= len;
			z /= len;
		}
		//����0�̏ꍇ�͉������Ȃ�
	}

	//���g�𐳋K�������x�N�g�����擾����
	Vec3 getNormalize() const
	{
		float len = Length();
		if (len > 0.0f)
		{
			return Vec3{ x / len, y / len, z / len };
		}
		//������0�̏ꍇ
		return Vec3{ 0.0f,0.0f,0.0f };
	}
};

