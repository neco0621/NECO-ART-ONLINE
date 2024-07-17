#include "Player.h"
#include "../Game.h"

namespace
{
	//プレイヤーのファイル名
	const char* const kPlayerFileName = "data/model/Player.mv1";

	//スピード
	constexpr float kSpeed = 7.0f;
	//半径
	constexpr float kRadius = 70.0f;
	//モデルのサイズ
	constexpr float kScale = 0.5f;
}

Player::Player() :
	m_playTime(0.0f),
	m_runFlag(true)
{	
	m_info.pos = VGet(0.0f,0.0f,0.0f);
	m_info.rot = VGet(0.0f, 0.0f, 0.0f);
}

Player::~Player()
{
}

void Player::Init()
{
	MV1SetScale(m_info.modelHandle, VGet(0.75f, 0.75f, 0.75f));

	m_idleHandle = MV1LoadModel("data/model/Idle.mv1");
	m_runHandle = MV1LoadModel("data/model/Run.mv1");
	
	m_idleIndex = MV1AttachAnim(m_info.modelHandle, 0, m_idleHandle, TRUE);
	m_runIndex = MV1AttachAnim(m_info.modelHandle, 0, m_runHandle, TRUE);
	
	m_idleTotalTime = MV1GetAttachAnimTotalTime(m_info.modelHandle, m_idleIndex);
	m_runTotalTime = MV1GetAttachAnimTotalTime(m_info.modelHandle, m_runIndex);

	MV1DetachAnim(m_info.modelHandle, m_runIndex);
	m_runIndex = -1;
}

void Player::Update()
{
	m_playTime++;
	//プレイヤーの移動
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);	

	if ((pad & PAD_INPUT_UP) != 0)
	{
		m_info.pos = VAdd(m_info.pos, VGet(0, 0, 7));
		m_info.rot.y = 180.0f;
		m_runFlag = true;
	}
	else if ((pad & PAD_INPUT_DOWN) != 0)
	{
		m_info.pos = VSub(m_info.pos, VGet(0, 0, 7));
		m_info.rot.y = 0.0f;
		m_runFlag = true;
	}
	else if ((pad & PAD_INPUT_LEFT) != 0)
	{
		m_info.pos = VSub(m_info.pos, VGet(7, 0, 0));
		m_info.rot.y = 90.0f;
		m_runFlag = true;
	}
	else if ((pad & PAD_INPUT_RIGHT) != 0)
	{
		m_info.pos = VAdd(m_info.pos, VGet(7, 0, 0));
		m_info.rot.y = -90.0f;
		m_runFlag = true;
	}
	else
	{
		m_runFlag = false;
	}

	// ３Dモデルのポジション設定
	MV1SetPosition(m_info.modelHandle, m_info.pos);

	// 新しい向きをセット
	MV1SetRotationXYZ(m_info.modelHandle, VGet(0.0f, m_info.rot.y / 180.0f * DX_PI_F, 0.0f));


	if (m_runFlag)
	{
		if (m_idleIndex != -1)
		{
			MV1DetachAnim(m_info.modelHandle, m_idleIndex);
			m_runIndex = MV1AttachAnim(m_info.modelHandle, 0, m_runHandle, TRUE);
			m_idleIndex = -1;
		}
	}
	if (!m_runFlag)
	{
		if (m_runIndex != -1)
		{
			MV1DetachAnim(m_info.modelHandle, m_runIndex);
			m_idleIndex = MV1AttachAnim(m_info.modelHandle, 0, m_idleHandle, TRUE);
			m_runIndex = -1;
		}
	}

	//アニメーションの再生
	if (m_idleIndex != -1)
	{
		MV1SetAttachAnimTime(m_info.modelHandle, m_idleIndex, m_playTime);
		// アニメーション再生時間がアニメーションの総時間を越えていたらループさせる
		if (m_playTime >= m_idleTotalTime)
		{
			// 新しいアニメーション再生時間は、アニメーション再生時間からアニメーション総時間を引いたもの
			m_playTime = 0;
		}
	}
	if (m_runIndex != -1)
	{
		MV1SetAttachAnimTime(m_info.modelHandle, m_runIndex, m_playTime);
		// アニメーション再生時間がアニメーションの総時間を越えていたらループさせる
		if (m_playTime >= m_runTotalTime)
		{
			// 新しいアニメーション再生時間は、アニメーション再生時間からアニメーション総時間を引いたもの
			m_playTime = 0;
		}
	}
}

void Player::Draw()
{
	//モデルの描画
	MV1DrawModel(m_info.modelHandle);
#ifdef _DEBUG
	DrawFormatString(80, 80, 0xffffff, "プレイヤーの座標(%.2f,%.5f)", m_info.pos.x, m_info.pos.z);
	DrawFormatString(120, 120, 0xffffff, "%f", m_playTime);
#endif
}