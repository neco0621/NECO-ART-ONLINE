#include "Camera.h"
#include "Player.h"

#define USE_LEAP_CAMERA 1
namespace
{
	constexpr float kCameraPlayerTargetHeight = 65.0f;
}

Camera::Camera()
{
    //���s0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���
    SetCameraNearFar(0.1f, 10000.0f);

    m_pos = VGet(0, 0, 0);
}

Camera::~Camera()
{
}

void Camera::Update(const Player& player)
{
#if !USE_LERP_CAMERA
	// z����ŁA�v���C���[�����苗�����ꂽ��ԂŃv���C���[����Ɍ�������悤�ʒu����
	m_pos = VGet(player.GetPos().x, player.GetPos().y + 200.0f, player.GetPos().z - 150.0f);
#else
	// lerp���g�p���Ď���.
	// lerp(VECTOR a, VECTOR b, float t)��
	// answer = a + ((b-a) * t)
	VECTOR aimPos = VAdd(player.GetPos(), VScale(player.GetDir(), -30.0f));
	aimPos = VAdd(aimPos, VGet(0, 20.0f, 0));
	VECTOR posToAim = VSub(aimPos, m_pos);
	VECTOR scaledPosToAim = VScale(posToAim, 0.1f);
	pos = VAdd(m_pos, scaledPosToAim);
#endif
	
	// �J�����Ɉʒu�𔽉f.
	SetCameraPositionAndTarget_UpVecY(m_pos, player.GetPos());
}

void Camera::Draw()
{
#ifdef _DEBUG
    //�J�����̍��W��\��
    DrawFormatString(80, 100, 0xffffff, "%.2f,%.2f,%.2f", m_pos.x, m_pos.y, m_pos.z);
#endif
}