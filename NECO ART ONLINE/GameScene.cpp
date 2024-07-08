#include <DxLib.h>
#include <cassert>
#include "Input.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "Game.h"
#include "Player.h"

GameScene::GameScene(SceneManager& manager) : Scene(manager)
{
	m_pPlayer = std::make_shared<Player>();

	m_playerHandle = MV1LoadModel("data/model/Player.mv1");
}

GameScene::~GameScene()
{
	
}

void GameScene::Init()
{
	
}

void GameScene::Update(Input& input)
{
	m_pPlayer->Update();
}

void GameScene::Draw()
{
	//描画先スクリーンをクリアする
	ClearDrawScreen();

	m_pPlayer->Draw();
}
