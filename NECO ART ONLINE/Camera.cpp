#include "Camera.h"
#include "Player.h"



Camera::Camera()
{
    //���s0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���
    SetCameraNearFar(0.1f, 10000.0f);

    //(0,10,-20)�̎��_����(0,10,0)�̃^�[�Q�b�g������p�x�ɃJ������ݒu
    m_pos = VGet(0, 10, -20);
    SetCameraPositionAndTarget_UpVecY(m_pos, VGet(0.0f, 10.0f, 0.0f));
}

Camera::~Camera()
{
}

void Camera::Update(const Player& player)
{
	// �J�����Ɉʒu�𔽉f
	SetCameraPositionAndTarget_UpVecY(m_pos, player.GetPos());
}

void Camera::Draw()
{
#ifdef _DEBUG
    //�J�����̍��W��\��
    DrawFormatString(80, 100, 0xffffff, "%.2f,%.2f,%.2f", m_pos.x, m_pos.y, m_pos.z);
#endif
}