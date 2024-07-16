#include <DxLib.h>
#include <cassert>
#include "../Input.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "../Game.h"
#include "../Player.h"
#include "../Camera.h"

GameScene::GameScene(SceneManager& manager) : Scene(manager)
{
	m_pPlayer = std::make_shared<Player>();
	m_pCamera = std::make_shared<Camera>();

	m_playerHandle = MV1LoadModel("data/model/Player.mv1");

	//�v���C���[�̃��f���̃Z�b�g
	m_pPlayer->SetHandle(m_playerHandle);
}

GameScene::~GameScene()
{
	
}

void GameScene::Init()
{
	m_pPlayer->Init();
}

void GameScene::Update(Input& input)
{
	m_pPlayer->Update();
	m_pCamera->Update(*m_pPlayer);
}

void GameScene::Draw()
{
	//�`���X�N���[�����N���A����
	ClearDrawScreen();

	m_pPlayer->Draw();
	m_pCamera->Draw();
}
