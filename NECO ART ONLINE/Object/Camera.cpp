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
	m_rot = VGet(0, 0, 0);
}

Camera::~Camera()
{
}

void Camera::Update(const Player& player)
{
	// z����ŁA�v���C���[�����苗�����ꂽ��ԂŃv���C���[����Ɍ�������悤�ʒu����
	m_pos = VGet(player.GetPos().x, player.GetPos().y + 200.0f, player.GetPos().z - 150.0f);
	
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