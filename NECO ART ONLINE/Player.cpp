#include "Player.h"
#include "Game.h"

Player::Player() :
m_handle(-1),
m_pos(VGet(960, 0, 540))
{
}

Player::~Player()
{
}

void Player::Init()
{
	//���C�g���g�����g��Ȃ���
	SetUseLighting(false);
}

void Player::Update()
{
	//�v���C���[�̈ړ�
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

	//�v���C���[����ʊO�ɍs���Ȃ��悤�ɍ��W��ݒ�
	if (m_pos.x > Game::kScreenWidth)
	{
		m_pos = VGet(Game::kScreenWidth, m_pos.y, m_pos.z);
	}
	if (m_pos.x < 0)
	{
		m_pos = VGet(0, m_pos.y, m_pos.z);
	}
	if (m_pos.z > Game::kScreenHeight)
	{
		m_pos = VGet(m_pos.x, m_pos.y, Game::kScreenHeight);
	}
	if (m_pos.z < 0)
	{
		m_pos = VGet(m_pos.x, m_pos.y, 0);
	}

	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_handle, m_pos);
}

void Player::Draw()
{
	//���f���̕`��
	MV1DrawModel(m_handle);
#ifdef _DEBUG
	DrawFormatString(80, 80, 0xffffff, "�v���C���[�̍��W(%.2f,%.5f)", m_pos.x, m_pos.z);
#endif
}
