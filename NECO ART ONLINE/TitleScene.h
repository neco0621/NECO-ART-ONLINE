#pragma once
#include "Scene.h"
#include <vector>
#include <memory>
#include <DxLib.h>


class TitleScene : public Scene
{
public:
	TitleScene(SceneManager& mgr);
	virtual ~TitleScene();
	virtual void Init();
	virtual void Update(Input& input);
	virtual void Draw();

private:
    //背景のハンドル
    int m_bgHandle;
    //タイトルの文字のハンドル
    int m_titleRogo;
    //表示座標
    VECTOR m_pos;
    //上下の切り替えフラグ
    bool m_moveFlag;
};

