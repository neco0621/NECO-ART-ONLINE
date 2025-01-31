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
	//Enterが押されたとき
	if (input.IsTriggered("OK"))
	{
		//次のシーンに移動する
		m_manager.ChangeScene(std::make_shared<GameScene>(m_manager));
	}
}

void TitleScene::Draw()
{
#ifdef _DEBUG
	DrawFormatString(100,100,0xffffff,"Title");
#endif

}
