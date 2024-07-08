#include "Camera.h"
#include "Player.h"



Camera::Camera()
{
    //奥行0.1～1000までをカメラの描画範囲とする
    SetCameraNearFar(0.1f, 10000.0f);

    //(0,10,-20)の視点から(0,10,0)のターゲットを見る角度にカメラを設置
    m_pos = VGet(0, 10, -20);
    SetCameraPositionAndTarget_UpVecY(m_pos, VGet(0.0f, 10.0f, 0.0f));
}

Camera::~Camera()
{
}

void Camera::Update(const Player& player)
{
	// カメラに位置を反映
	SetCameraPositionAndTarget_UpVecY(m_pos, player.GetPos());
}

void Camera::Draw()
{
#ifdef _DEBUG
    //カメラの座標を表示
    DrawFormatString(80, 100, 0xffffff, "%.2f,%.2f,%.2f", m_pos.x, m_pos.y, m_pos.z);
#endif
}