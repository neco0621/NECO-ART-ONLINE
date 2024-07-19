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
	m_rot = VGet(0, 0, 0);
}

Camera::~Camera()
{
}

void Camera::Update(const Player& player)
{
	// z軸上で、プレイヤーから一定距離離れた状態でプレイヤーを常に見続けるよう位置調整
	m_pos = VGet(player.GetPos().x, player.GetPos().y + 200.0f, player.GetPos().z - 150.0f);
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	DINPUT_JOYSTATE input;
	int pad2 = GetJoypadDirectInputState(DX_INPUT_PAD1, &input);

	if ((pad & PAD_INPUT_7) != 0)
	{
		Rotate(&m_pos.x, &m_pos.z, +(DX_PI_F / 90), player.GetPos().x, player.GetPos().z);
	}
	if ((pad & PAD_INPUT_8) != 0)
	{
		Rotate(&m_pos.x, &m_pos.z, -(DX_PI_F / 90), player.GetPos().x, player.GetPos().z);
	}
	// カメラに位置を反映.
	SetCameraPositionAndTarget_UpVecY(m_pos, player.GetPos());
}

void Camera::Draw()
{
#ifdef _DEBUG
    //カメラの座標を表示
    //DrawFormatString(80, 100, 0xffffff, "%.2f,%.2f,%.2f", m_pos.x, m_pos.y, m_pos.z);
	DINPUT_JOYSTATE input;
	int pad2 = GetJoypadDirectInputState(DX_INPUT_PAD1, &input);

	DrawFormatString(0, 0, 0xffffff, "X:%d Y:%d Z:%d",
		input.X, input.Y, input.Z);
	DrawFormatString(0, 16, 0xffffff, "Rx:%d Ry:%d Rz:%d",
		input.Rx, input.Ry, input.Rz);
	DrawFormatString(0, 32, 0xffffff, "Slider 0:%d 1:%d",
		input.Slider[0], input.Slider[1]);
	DrawFormatString(0, 48, 0xffffff, "POV 0:%d 1:%d 2:%d 3:%d",
		input.POV[0], input.POV[1],
		input.POV[2], input.POV[3]);
	DrawString(0, 64, "Button", 0xffffff);
	for (int i = 0; i < 32; i++)
	{
		DrawFormatString(64 + i % 8 * 64, 64 + i / 8 * 16, 0xffffff,
			"%2d:%d", i, input.Buttons[i]);
	}
#endif
}

void Camera::Rotate(float* x, float* y, float ang, const float mx, const float my)
{
	const float ox = *x - mx, oy = *y - my;
	*x = ox * cos(ang) + oy * sin(ang);
	*y = -ox * sin(ang) + oy * cos(ang);
	*x += mx;
	*y += my;
}
