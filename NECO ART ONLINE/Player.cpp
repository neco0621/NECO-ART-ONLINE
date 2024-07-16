#include "Player.h"
#include "Game.h"

namespace
{
	//�X�s�[�h
	constexpr float kSpeed = 7.0f;
	//���a
	constexpr float kRadius = 70.0f;
	//���f���̃T�C�Y
	constexpr float kScale = 0.5f;
}

Player::Player() :
m_handle(-1),
m_pos(VGet(0, 0, 0)),
m_dir(VGet(0,0,1))
{
	m_attachIndex = MV1AttachAnim(m_handle, 1, -1);
	m_tottalTime = MV1GetAttachAnimTotalTime(m_handle, m_attachIndex);
	MV1SetAttachAnimTime(m_handle, m_attachIndex, m_playTime);

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

	// �A�j���[�V�����Đ����Ԃ��A�j���[�V�����̑����Ԃ��z���Ă����烋�[�v������
	if (m_playTime >= m_tottalTime)
	{
		// �V�����A�j���[�V�����Đ����Ԃ́A�A�j���[�V�����Đ����Ԃ���A�j���[�V���������Ԃ�����������
		m_playTime -= m_tottalTime;
	}

	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_handle, m_pos);

	// �����ɍ��킹�ĉ�].
	MV1SetRotationZYAxis(m_handle, m_dir, VGet(0.0f, 1.0f, 0.0f), 0.0f);

	// ���f���Ɍ����Ăق��������ɉ�].
	MATRIX tmpMat = MV1GetMatrix(m_handle);
	MATRIX rotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
	tmpMat = MMult(tmpMat, rotYMat);
	MV1SetRotationMatrix(m_handle, tmpMat);
	
	MV1SetAttachAnimTime(m_handle, m_attachIndex, m_playTime);
}

void Player::Draw()
{
	//���f���̕`��
	MV1DrawModel(m_handle);
#ifdef _DEBUG
	DrawFormatString(80, 80, 0xffffff, "�v���C���[�̍��W(%.2f,%.5f)", m_pos.x, m_pos.z);
#endif
}
