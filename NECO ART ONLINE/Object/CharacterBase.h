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

	struct AnimData
	{
		int8_t idle = 0;	//�ҋ@���[�V����
		int8_t run = 0;		//���郂�[�V����
		int8_t attack = 0;	//�U�����[�V����
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
	AnimData m_animData;	//�A�j���[�V�����f�[�^
};

