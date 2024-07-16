#pragma once
#include <memory>
#include "DxLib.h"
#include "../Collision.h"
#include "CharacterBase.h"

class Player : public CharacterBase
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();
	void Draw();

	//�����o�ϐ��ɃA�N�Z�X����
	void SetHandle(int handle) { m_info.modelHandle = handle; }

	//���W��getter/setter
	const VECTOR& GetPos() const { return m_info.pos; }
	void SetPos(const VECTOR set) { m_info.pos = set; }

	// ������getter/setter.
	const VECTOR& GetDir() const { return m_info.rot; }
	void SetDir(const VECTOR set) { m_info.rot = set; }

	//�ړ������Ɗp�x���l�������ړ��X�V
	VECTOR MoveUpdate();
private:
	//�A�j���[�V�����n���h��
	int m_animationHandle;

	int m_idleHandle;

	//3D���f���̃A�j���[�V�����C���f�b�N�X
	int m_attachIndex;

	//3D���f���̃A�j���[�V�����C���f�b�N�X
	int m_runIndex;

	//�A�j���[�V�����̍Đ�����
	float m_tottalTime;

	//�A�j���[�V�����̌��ݎ���
	float m_playTime;
};

