#include "Player.h"
#include "Game.h"

Player::Player() :
m_handle(-1),
m_pos(VGet(0, 0, 0)),
m_dir(VGet(0,0,1))
{
}

Player::~Player()
{
}

void Player::Init()
{
	MV1SetScale(m_handle,VGet(0.5f,0.5f,0.5f));
}

void Player::Update()
{
	//プレイヤーの移動
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (((pad & PAD_INPUT_UP) | (pad & PAD_INPUT_8)) != 0)
	{
		m_pos = VAdd(m_pos, VGet(0, 0, 7));
	}

	if (((pad & PAD_INPUT_DOWN) | (pad & PAD_INPUT_5)) != 0)
	{
		m_pos = VSub(m_pos, VGet(0, 0, 7));
	}

	if (((pad & PAD_INPUT_LEFT) | (pad & PAD_INPUT_4)) != 0)
	{
		m_pos = VSub(m_pos, VGet(7, 0, 0));
	}

	if (((pad & PAD_INPUT_RIGHT) | (pad & PAD_INPUT_6)) != 0)
	{
		m_pos = VAdd(m_pos, VGet(7, 0, 0));
	}

	// ３Dモデルのポジション設定
	MV1SetPosition(m_handle, m_pos);

	// 向きに合わせて回転.
	MV1SetRotationZYAxis(m_handle, m_dir, VGet(0.0f, 1.0f, 0.0f), 0.0f);

	// モデルに向いてほしい方向に回転.
	MATRIX tmpMat = MV1GetMatrix(m_handle);
	MATRIX rotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
	tmpMat = MMult(tmpMat, rotYMat);
	MV1SetRotationMatrix(m_handle, tmpMat);
}

void Player::Draw()
{
	//モデルの描画
	MV1DrawModel(m_handle);
#ifdef _DEBUG
	DrawFormatString(80, 80, 0xffffff, "プレイヤーの座標(%.2f,%.5f)", m_pos.x, m_pos.z);
#endif
}
