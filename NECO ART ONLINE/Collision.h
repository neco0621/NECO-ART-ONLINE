#pragma once
#include "Vec3.h"
#include <DxLib.h>
//��`�̍��W���Ǘ�����N���X
class Collision
{
public:
	Collision();
	virtual ~Collision();

	//�����蔻��̋�`�̕`��
	void Draw(unsigned int Color, bool isFill);
	//�����蔻��̗����̂̕`��
	void Draw3D(unsigned int Color, unsigned int Color2, bool isFill);
	//�����蔻��̉~�̕`��
	void DrawCircle2D(unsigned int Color, bool isFill);
	//�����蔻��̋��̕`��
	void DrawBall(unsigned int color, unsigned int color2, bool isFill);

	//������W�ƕ��������w��
	void SetLT(float left, float top, float width, float height);
	//������W�ƕ��ƍ����Ɖ��s���w��
	void SetLT3D(float left, float top, float back, float width, float height, float flont);
	//���S���W�ƕ��������w��
	void SetCenter(float x, float y, float width, float height);
	//���S���W�ƕ��ƍ����Ɖ��s�����w��
	void SetCenter3D(float x, float y, float width, float height, float z, float back);
	//���S���W�Ɣ��a���w��
	void SetRadius(float x, float y, float radius);
	//���S���W�Ɣ��a�Ɖ��s���w��
	void SetRadius3D(float x, float y, float z, float radius);

	//�K�v�ȏ����擾����
	float GetWidth() const;		//��
	float GetHeight() const;	//����
	float GetBack() const;		//���s
	Vec3 GetCenter() const;		//���S���W
	//2�_�Ԃ̋���
	float DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2);

	//��`���m�̓����蔻��
	bool BoxCollision(const Collision& col);
	//�~���m�̓����蔻��
	bool CirCleCollision(const Collision& col);
	//��`�Ɖ~�̓����蔻��
	bool DistanceCollision(const Collision& col);
	//�����̓��m�̓����蔻��
	bool BoxCollision3D(const Collision& col);
	//�����m�̓����蔻��
	bool SphereCollision(const Collision& col);


	float m_left;	//�����X���W
	float m_right;	//�E���X���W
	float m_top;	//�����Y���W
	float m_bottom;	//�E���Y���W
	float m_back;	//����Z���W
	float m_flont;	//��O��Z���W

	float m_centerX;	//���S��X���W
	float m_centerY;	//���S��Y���W
	float m_centerZ;	//���S��Z���W
	float m_radius;		//���a

	VECTOR m_pos;	//���ݒn�̍��W

	int m_divNum;	//�|���S����
};