#include "Model.h"
#include <assert.h>

Model::Model(const char* fileName) :
	m_animChangeFrame(0),
	m_animChangeFrameTotal(0),
	m_animSpeed(0),
	m_modelHandle(-1)
{
	m_pos = { 0,0,0 };
	m_modelHandle = MV1LoadModel(fileName);
	//�R�s�[�Ɏ��s�����ꍇ
	assert(m_modelHandle != -1);
	//�A�j���[�V�����f�[�^�̃N���A
	ClearAnimData(m_animPrev);
	ClearAnimData(m_animNext);
}

Model::~Model()
{
	MV1DeleteModel(m_modelHandle);
}

void Model::Update()
{
	m_animSpeed++;
	if (m_animSpeed >= m_animChangeFrameTotal)
	{
		UpdateAnim(m_animPrev);
		UpdateAnim(m_animNext);
		m_animSpeed = 0;
	}

	m_animChangeFrame++;
	if (m_animChangeFrame > m_animChangeFrameTotal)
	{
		m_animChangeFrame = m_animChangeFrameTotal;
	}

}

void Model::Draw()
{
	MV1DrawModel(m_modelHandle);
}

void Model::SetPos(VECTOR pos)
{
	m_pos = pos;
	MV1SetPosition(m_modelHandle, m_pos);
}

void Model::SetScale(VECTOR scale)
{
	MV1SetScale(m_modelHandle, scale);
}

void Model::SetRot(VECTOR rot)
{
	MV1SetRotationXYZ(m_modelHandle, rot);
}

void Model::SetAnimation(int animNo, bool isLoop, bool isForceChange)
{
	if (!isForceChange)
	{
		//���ɍĐ�����Ă���A�j���͍Đ����Ȃ�
		if (m_animNext.animNo == animNo) return;
	}

	//�ȑO�̃A�j���[�V�������c���Ă���ΏI��
	if (m_animPrev.attachNo != -1)
	{
		MV1DetachAnim(m_modelHandle, m_animPrev.attachNo);
		ClearAnimData(m_animPrev);
	}
	if (m_animNext.attachNo != -1)
	{
		MV1DetachAnim(m_modelHandle, m_animNext.attachNo);
		ClearAnimData(m_animNext);
	}

	//�V�����A�j���[�V������ݒ�
	m_animNext.animNo = animNo;
	m_animNext.attachNo = MV1AttachAnim(m_modelHandle, animNo, -1, false);
	m_animNext.totalTime = MV1GetAttachAnimTotalTime(m_modelHandle, m_animNext.attachNo);
	m_animNext.isLoop = isLoop;

	//�ύX�ɏ�����t���[�������o���Ă���
	m_animChangeFrameTotal = 1;
	m_animChangeFrame = 1;
}

void Model::ChangeAnimation(int animNo, bool isLoop, bool isForceChange, int ChangeFrame)
{
	//// �ύX�ɂ�����t���[�������o���Ă���
	if (!isForceChange)
	{
		// ���łɍĐ�����Ă���A�j���͍Đ����Ȃ�
		if (m_animNext.animNo == animNo) return;
	}


	// �ȑO�̃A�j���[�V�������c���Ă���ΏI��
	if (m_animPrev.attachNo != -1)
	{
		MV1DetachAnim(m_modelHandle, m_animPrev.attachNo);
		ClearAnimData(m_animPrev);
	}
	// ���ݍĐ����Ă���A�j���[�V�������Â��A�j���Ƃ���
	m_animPrev = m_animNext;
	// �V�����A�j���[�V������ݒ�
	m_animNext.animNo = animNo;
	m_animNext.attachNo = MV1AttachAnim(m_modelHandle, animNo, -1, false);
	m_animNext.totalTime = MV1GetAttachAnimTotalTime(m_modelHandle, m_animNext.attachNo);
	m_animNext.isLoop = isLoop;

	// �ύX�ɂ�����t���[�������o���Ă���
	m_animChangeFrameTotal = ChangeFrame;
	m_animChangeFrame = 0;
}

bool Model::IsAnimEnd()
{
	// Loop�A�j���̏ꍇ�͏��false��Ԃ�
	if (m_animNext.isLoop) return false;

	float time = MV1GetAttachAnimTime(m_modelHandle, m_animNext.attachNo);
	if (time >= m_animNext.totalTime)
	{
		return true;
	}

	return false;
}

void Model::ClearAnimData(AnimData& anim)
{
	anim.animNo = -1;
	anim.attachNo = -1;
	anim.totalTime = 0.0f;
	anim.isLoop = false;
}

void Model::UpdateAnim(AnimData anim, float dt)
{
	// �A�j���[�V�������ݒ肳��Ă��Ȃ��ꍇ�͉������Ȃ�
	if (anim.attachNo == -1) return;

	// �A�j���[�V�����̍X�V
	float time = MV1GetAttachAnimTime(m_modelHandle, anim.attachNo);
	time += dt;
	if (time > anim.totalTime)
	{
		if (anim.isLoop)
		{
			// �A�j���[�V�����̃��[�v
			time -= anim.totalTime;
		}
		else
		{
			time = anim.totalTime;
		}
	}
	MV1SetAttachAnimTime(m_modelHandle, anim.attachNo, time);
}
