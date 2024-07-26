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
	//コピーに失敗した場合
	assert(m_modelHandle != -1);
	//アニメーションデータのクリア
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
		//既に再生されているアニメは再生しない
		if (m_animNext.animNo == animNo) return;
	}

	//以前のアニメーションが残っていれば終了
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

	//新しくアニメーションを設定
	m_animNext.animNo = animNo;
	m_animNext.attachNo = MV1AttachAnim(m_modelHandle, animNo, -1, false);
	m_animNext.totalTime = MV1GetAttachAnimTotalTime(m_modelHandle, m_animNext.attachNo);
	m_animNext.isLoop = isLoop;

	//変更に書けるフレーム数を覚えておく
	m_animChangeFrameTotal = 1;
	m_animChangeFrame = 1;
}

void Model::ChangeAnimation(int animNo, bool isLoop, bool isForceChange, int ChangeFrame)
{
	//// 変更にかけるフレーム数を覚えておく
	if (!isForceChange)
	{
		// すでに再生されているアニメは再生しない
		if (m_animNext.animNo == animNo) return;
	}


	// 以前のアニメーションが残っていれば終了
	if (m_animPrev.attachNo != -1)
	{
		MV1DetachAnim(m_modelHandle, m_animPrev.attachNo);
		ClearAnimData(m_animPrev);
	}
	// 現在再生しているアニメーションを古いアニメとする
	m_animPrev = m_animNext;
	// 新しくアニメーションを設定
	m_animNext.animNo = animNo;
	m_animNext.attachNo = MV1AttachAnim(m_modelHandle, animNo, -1, false);
	m_animNext.totalTime = MV1GetAttachAnimTotalTime(m_modelHandle, m_animNext.attachNo);
	m_animNext.isLoop = isLoop;

	// 変更にかけるフレーム数を覚えておく
	m_animChangeFrameTotal = ChangeFrame;
	m_animChangeFrame = 0;
}

bool Model::IsAnimEnd()
{
	// Loopアニメの場合は常にfalseを返す
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
	// アニメーションが設定されていない場合は何もしない
	if (anim.attachNo == -1) return;

	// アニメーションの更新
	float time = MV1GetAttachAnimTime(m_modelHandle, anim.attachNo);
	time += dt;
	if (time > anim.totalTime)
	{
		if (anim.isLoop)
		{
			// アニメーションのループ
			time -= anim.totalTime;
		}
		else
		{
			time = anim.totalTime;
		}
	}
	MV1SetAttachAnimTime(m_modelHandle, anim.attachNo, time);
}
