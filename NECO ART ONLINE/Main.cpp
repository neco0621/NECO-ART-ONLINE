#include "DxLib.h"
#include "Scene/Scene.h"
#include "Scene/SceneManager.h"
#include "Scene/GameScene.h"
#include "Game.h"
#include "Input.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, 16);
	ChangeWindowMode(true);


	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);

	//3D�`��̉��s�����g�p����ݒ�
	SetUseZBuffer3D(true);
	//�`����s���Ƃ��AZ�o�b�t�@�ɂ��������ނ悤�ɂ���
	SetWriteZBuffer3D(true);

	SceneManager manager;
	manager.ChangeScene(std::make_shared<GameScene>(manager));
	Input input;
	manager.Init();


	//�Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		//���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();
		
		input.Update();
		manager.Init();
		manager.Update(input);
		manager.Draw();

		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		//esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60�Œ�ɂ���
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			//16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}