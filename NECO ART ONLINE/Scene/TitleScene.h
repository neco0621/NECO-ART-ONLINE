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
    //�w�i�̃n���h��
    int m_bgHandle;
    //�^�C�g���̕����̃n���h��
    int m_titleRogo;
    //�\�����W
    VECTOR m_pos;
    //�㉺�̐؂�ւ��t���O
    bool m_moveFlag;
};

