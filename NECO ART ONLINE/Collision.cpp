#include "Collision.h"
#include <DxLib.h>
#include<cmath>
#include <cassert>

Collision::Collision() :
	//������
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

//�����蔻��̋�`�̕`��
void Collision::Draw(unsigned int color, bool isFill)
{
	DrawBox(static_cast<int> (m_left), static_cast<int>(m_top), static_cast<int> (m_right), static_cast<int>(m_bottom), color, isFill);
}

//�����蔻��̗����̂̕`��
void Collision::Draw3D(unsigned int color, unsigned int color2, bool isFill)
{
	DrawCube3D(VGet(static_cast<int> (m_left), static_cast<int>(m_top), static_cast<int> (m_back)), VGet(static_cast<int> (m_right), static_cast<int>(m_bottom), static_cast<int>(m_flont)), color, color2, isFill);
}

//�����蔻��̉~�̕`��
void Collision::DrawCircle2D(unsigned int color, bool isFill)
{
	DrawCircle(static_cast<int> (m_centerX), static_cast<int>(m_centerY), static_cast<int> (m_radius), color, isFill);
}

//�����蔻��̋��̕`��
void Collision::DrawBall(unsigned int color, unsigned int color2, bool isFill)
{
	DrawSphere3D(VGet(static_cast<int> (m_centerX), static_cast<int>(m_centerY), static_cast<int>(m_centerZ)), static_cast<int> (m_radius), m_divNum, color, color2, isFill);
}

//������W�ƕ��������w��
void Collision::SetLT(float left, float top, float width, float height)
{
	m_left = left;			//�����X���W
	m_top = top;			//�����Y���W
	m_right = left + width;	//�E����X���W
	m_bottom = top + height;//�E����Y���W
}

//������W�ƕ��ƍ����Ɖ��s���w��
void Collision::SetLT3D(float left, float top, float back, float width, float height, float flont)
{
	m_left = left;			//�����X���W
	m_top = top;			//�����Y���W
	m_right = left + width;	//�E����X���W
	m_bottom = top + height;//�E����Y���W
	m_flont = flont;		//��O��Z���W
	m_back = back;			//����Z���W
}

//���S���W�ƕ��������w��
void Collision::SetCenter(float x, float y, float width, float height)
{
	m_left = x - width / 2;
	m_top = y - height / 2;
	m_right = x + width / 2;
	m_bottom = y + height / 2;
}

//���S���W�ƕ��ƍ����Ɖ��s�����w��
void Collision::SetCenter3D(float x, float y, float width, float height, float z, float back)
{
	m_left = x - width / 2;
	m_top = y - height / 2;
	m_flont = z - back / 2;
	m_right = x + width / 2;
	m_bottom = y + height / 2;
	m_back = z + back / 2;
}

//���S���W�Ɣ��a���w��
void Collision::SetRadius(float x, float y, float radius)
{
	m_centerX = x;
	m_centerY = y;
	m_radius = radius;
}

//���S���W�Ɣ��a�Ɖ��s���w��
void Collision::SetRadius3D(float x, float y, float z, float radius)
{
	m_centerX = x;
	m_centerY = y;
	m_centerZ = z;
	m_radius = radius;
}

//���̎擾
float Collision::GetWidth() const
{
	assert(m_right >= m_left);
	return m_right - m_left;
}

//�����̎擾
float Collision::GetHeight() const
{
	assert(m_bottom >= m_top);

	return m_bottom - m_top;
}

//���s�̎擾
float Collision::GetBack() const
{
	assert(m_back >= m_flont);

	return m_back - m_flont;
}

//���S���W�̎擾
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

//2�̍��W�̋������擾
float Collision::DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2)
{
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}

//��`���m�̓����蔻��
bool Collision::BoxCollision(const Collision& col)
{
	//��΂ɓ�����Ȃ��p�^�[�����͂����Ă���
	if (m_left > col.m_right)	return false;
	if (m_top > col.m_bottom)	return false;
	if (m_right < col.m_left)	return false;
	if (m_bottom < col.m_top)	return false;

	//������Ȃ��p�^�[���ȊO�͓������Ă���
	return true;
}

//�~���m�̓����蔻��
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

//��`�Ɖ~�̓����蔻��
bool Collision::DistanceCollision(const Collision& col)
{
	//�������Ă��Ȃ��p�^�[�����͂���
	bool nResult = false;
	if ((m_centerX > col.m_left - m_radius) &&
		(m_centerX < col.m_right + m_radius) &&
		(m_centerY > col.m_top - m_radius) &&
		(m_centerY < col.m_bottom + m_radius))
	{
		nResult = true;
		float dl = m_radius * m_radius;
		// ��
		if (m_centerX < col.m_left)
		{
			// ����
			if ((m_centerY < col.m_top))
			{
				if ((DistanceSqrf(col.m_left, col.m_top, m_centerX, m_centerY) >= dl))
				{
					nResult = false;
				}
			}
			else
			{
				// ����
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
			// �E
			if (m_centerX > col.m_right)
			{
				// �E��
				if ((m_centerY < col.m_top))
				{
					if ((DistanceSqrf(col.m_right, col.m_top, m_centerX, m_centerY) >= dl))
					{
						nResult = false;
					}
				}
				else
				{
					// �E��
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

//�����̓��m�̓����蔻��
bool Collision::BoxCollision3D(const Collision& col)
{
	//��΂ɓ�����Ȃ��p�^�[�����͂����Ă���
	if (m_left > col.m_right)	return false;
	if (m_top > col.m_bottom)	return false;
	if (m_right < col.m_left)	return false;
	if (m_bottom < col.m_top)	return false;
	if (m_flont > col.m_back)  return false;
	if (m_back < col.m_flont)	return false;
	//������Ȃ��p�^�[���ȊO�͓������Ă���
	return true;
}

//�����m�̓����蔻��
bool Collision::SphereCollision(const Collision& col)
{
	VECTOR Vec = VSub(VGet(m_centerX, m_centerY, m_centerZ), VGet(col.m_centerX, col.m_centerY, col.m_centerZ));

	if (VSize(Vec) < m_radius + col.m_radius)
	{
		return true;
	}

	return false;
}