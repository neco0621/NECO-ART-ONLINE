#pragma once
#include <memory>
#include "DxLib.h"
#include "../Collision.h"
#include "CharacterBase.h"

class Model;
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
	const VECTOR& GetRot() const { return m_info.rot; }
	void SetRot(const VECTOR set) { m_info.rot = set; }

	void IdleInit() {};
	void IdleUpdate();

private:


	int m_idleHandle;		//�ҋ@���[�V�����n���h��
	int m_runHandle;		//����A�j���[�V�����n���h��
	int m_attackHandle;		//�U��1�̃A�j���[�V�����n���h��

	
	int m_idleIndex;		//3D���f���̃A�j���[�V�����C���f�b�N�X
	int m_runIndex;			//���郁�[�V�����C���f�b�N�X
	int m_attackIndex;		//�U��1�A�j���[�V�����C���f�b�N�X


	
	float m_idleTotalTime;	//�ҋ@�A�j���[�V�����̍Đ�����
	float m_runTotalTime;	//����A�j���[�V�����̍Đ�����
	float m_attackTotalTime;//�U��1�A�j���[�V�����̑��Đ�����

	
	//�A�j���[�V�����̌��ݎ���
	float m_playTime;

	//����A�j���[�V�����ւ̐؂�ւ�
	bool m_runFlag;

	bool m_attackFlag;

	bool m_idleFlag;

};