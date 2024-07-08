#pragma once
#include "Scene.h"
#include "Collision.h"
#include <vector>
#include <memory>
#include <DxLib.h>

class Player;
class Camera;
class DataLoader;
class GameScene : public Scene
{
public:
	GameScene(SceneManager& mgr);
	virtual ~GameScene();
	virtual void Init();
	virtual void Update(Input& input);
	virtual void Draw();

private:
	//プレイヤー
	std::shared_ptr<Player> m_pPlayer;
	//カメラ
	std::shared_ptr<Camera> m_pCamera;
	//当たり判定
	//std::shared_ptr<Collision> m_pCol;

	int m_playerHandle;

};

