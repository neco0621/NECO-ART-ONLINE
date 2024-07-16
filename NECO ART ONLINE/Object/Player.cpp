#include "Player.h"
#include "../Game.h"

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
	m_playTime(0.0f),
	m_dir(VGet(0,0,1))
{	
	m_info.pos = VGet(0.0f,0.0f,0.0f);
}

Player::~Player()
{
}

void Player::Init()
{
	MV1SetScale(m_info.modelHandle, VGet(0.75f, 0.75f, 0.75f));

	m_animationHandle = MV1LoadModel("data/model/Run.mv1");
	m_idleHandle = MV1LoadModel("data/model/Idle.mv1");

	m_runIndex = MV1AttachAnim(m_info.modelHandle, 0, m_animationHandle, TRUE);
	m_tottalTime = MV1GetAttachAnimTotalTime(m_info.modelHandle, m_runIndex);
	m_attachIndex = -1;
}

void Player::Update()
{
	//�v���C���[�̈ړ�
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	

	if (((pad & PAD_INPUT_UP) | (pad & PAD_INPUT_8)) != 0)
	{
		m_info.pos = VAdd(m_info.pos, VGet(0, 0, 7));
		m_playTime++;
		m_info.rot.y = 180.0f;
	}

	if (((pad & PAD_INPUT_DOWN) | (pad & PAD_INPUT_5)) != 0)
	{
		m_info.pos = VSub(m_info.pos, VGet(0, 0, 7));
		m_playTime++;
		m_info.rot.y = 0.0f;
	}

	if (((pad & PAD_INPUT_LEFT) | (pad & PAD_INPUT_4)) != 0)
	{
		m_info.pos = VSub(m_info.pos, VGet(7, 0, 0));
		m_playTime++;
		m_info.rot.y = 90.0f;
	}

	if (((pad & PAD_INPUT_RIGHT) | (pad & PAD_INPUT_6)) != 0)
	{
		m_info.pos = VAdd(m_info.pos, VGet(7, 0, 0));
		m_playTime++;
		m_info.rot.y = -90.0f;
	}

	// �A�j���[�V�����Đ����Ԃ��A�j���[�V�����̑����Ԃ��z���Ă����烋�[�v������
	if (m_playTime >= m_tottalTime)
	{
		// �V�����A�j���[�V�����Đ����Ԃ́A�A�j���[�V�����Đ����Ԃ���A�j���[�V���������Ԃ�����������
		m_playTime -= m_tottalTime;
	}

	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(m_info.modelHandle, m_info.pos);

	// �V�����������Z�b�g
	MV1SetRotationXYZ(m_info.modelHandle, VGet(0.0f, m_info.rot.y / 180.0f * DX_PI_F, 0.0f));

	MV1SetAttachAnimTime(m_info.modelHandle, m_runIndex, m_playTime);
}

void Player::Draw()
{
	//���f���̕`��
	MV1DrawModel(m_info.modelHandle);
#ifdef _DEBUG
	DrawFormatString(80, 80, 0xffffff, "�v���C���[�̍��W(%.2f,%.5f)", m_info.pos.x, m_info.pos.z);
#endif
}

VECTOR Player::MoveUpdate()
{
	if (m_moveSpeed == 0.0f) return VGet(0.0f, 0.0f, 0.0f);


	return VECTOR();
}
