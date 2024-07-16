#pragma once
#include "ObjectBase.h"


class CharacterBase : public ObjectBase
{
public:
	//�X�e�[�^�X�\����
	struct Status
	{
		int hp = 10;	//�̗�
		int atk = 10;	//�U����
		float speed = 10; //�X�s�[�h
	};


public:
	CharacterBase();
	virtual ~CharacterBase();

	virtual void Init() {};
	virtual void Update() {};

	virtual void Draw() {};
	//�G�ɍU�������������Ƃ��̏���
	virtual void HitAttack();

	//�G����̍U���ɓ��������Ƃ��̏���
	virtual void OnDamage(VECTOR targetPos, int damagePoint);

protected:
	Status m_statusData;	//�X�e�[�^�X�f�[�^
};

