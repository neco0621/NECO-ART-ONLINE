#include "Camera.h"
#include "Player.h"

#define USE_LEAP_CAMERA 1
namespace
{
	constexpr float kCameraPlayerTargetHeight = 65.0f;
}

Camera::Camera()
{
    //奥行0.1～1000までをカメラの描画範囲とする
    SetCameraNearFar(0.1f, 10000.0f);

    m_pos = VGet(0, 0, 0);
}

Camera::~Camera()
{
}

void Camera::Update(const Player& player)
{
#if !USE_LERP_CAMERA
	// z軸上で、プレイヤーから一定距離離れた状態でプレイヤーを常に見続けるよう位置調整
	m_pos = VGet(player.GetPos().x, player.GetPos().y + 200.0f, player.GetPos().z - 150.0f);
#else
	// lerpを使用して実装.
	// lerp(VECTOR a, VECTOR b, float t)は
	// answer = a + ((b-a) * t)
	VECTOR aimPos = VAdd(player.GetPos(), VScale(player.GetDir(), -30.0f));
	aimPos = VAdd(aimPos, VGet(0, 20.0f, 0));
	VECTOR posToAim = VSub(aimPos, m_pos);
	VECTOR scaledPosToAim = VScale(posToAim, 0.1f);
	pos = VAdd(m_pos, scaledPosToAim);
#endif
	
	// カメラに位置を反映.
	SetCameraPositionAndTarget_UpVecY(m_pos, player.GetPos());
}

void Camera::Draw()
{
#ifdef _DEBUG
    //カメラの座標を表示
    DrawFormatString(80, 100, 0xffffff, "%.2f,%.2f,%.2f", m_pos.x, m_pos.y, m_pos.z);
#endif
}