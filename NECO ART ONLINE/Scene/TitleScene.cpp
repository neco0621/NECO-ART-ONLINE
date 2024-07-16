#include "TitleScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "../Input.h"
#include "../Game.h"

TitleScene::TitleScene(SceneManager& mgr) : Scene(mgr),
m_bgHandle(-1),
m_moveFlag(false),
m_pos(VGet(0,0,0)),
m_titleRogo(-1)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
}

void TitleScene::Update(Input& input)
{
	//Enter�������ꂽ�Ƃ�
	if (input.IsTriggered("OK"))
	{
		//���̃V�[���Ɉړ�����
		m_manager.ChangeScene(std::make_shared<GameScene>(m_manager));
	}
}

void TitleScene::Draw()
{
}
