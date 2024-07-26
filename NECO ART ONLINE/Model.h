#pragma once
#include <DxLib.h>
#include<vector>
#include <memory>

class Model
{
public:
	//�t�@�C�������w�肵�ă��[�h���s��
	Model(const char* fileName);
	virtual ~Model();

	void Update();
	void Draw();

	//���f���n���h���̎擾
	int GetModelHandle() const { return m_modelHandle; }

	//�\���ʒu�̐ݒ�
	void SetPos(VECTOR pos);

	//�T�C�Y�̐ݒ�
	void SetScale(VECTOR scale);

	//���W�̎擾
	VECTOR GetPos() const { return m_pos; }

	//��]��Ԃ̐ݒ�
	void SetRot(VECTOR rot);

	void SetAnimation(int animNo, bool isLoop, bool isForceChange);

	void ChangeAnimation(int animNo, bool isLoop, bool isForceChange, int ChangeFrame);

	bool IsAnimEnd();

private:
	//�A�j���[�V�������
	struct AnimData
	{
		int animNo;			//�A�j���[�V�����ԍ�
		
		int attachNo;		//�A�^�b�`�ԍ�
		float totalTime;	//�A�j���[�V�����̑��Đ�����
		bool isLoop;		//�A�j���[�V���������[�v�����邩
	};

private:
	//���f���̈ʒu
	VECTOR m_pos;
	//�A�j���[�V�����̃f�[�^�N���A
	void ClearAnimData(AnimData& anim);
	// �A�j���[�V�����̍X�V
	void UpdateAnim(AnimData anim, float dt = 1.0f);

private:
	//���f���̃n���h��
	int m_modelHandle;

	int m_animChangeFrame;			// ���݂̐؂�ւ��t���[����
	int m_animChangeFrameTotal;		// �؂�ւ��ɂ����鑍�t���[����

	// �A�j���[�V�����ύX���x
	int m_animSpeed;

	// �A�j���[�V�����̃A�^�b�`�ԍ�
	AnimData m_animPrev;	// �ύX�O�A�j���[�V�������
	AnimData m_animNext;	// �ύX��A�j���[�V�����f�[�^


};