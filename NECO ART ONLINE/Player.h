#pragma once
#include <memory>
#include "DxLib.h"
#include "Collision.h"

class DataLoader;
class Player
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();
	void Draw();

	//�����o�ϐ��ɃA�N�Z�X����
	void SetHandle(int handle) { m_handle = handle; }

	//���W�̎擾
	VECTOR GetPos() const { return m_pos; }
private:
	//���W
	VECTOR m_pos;
	int m_handle;

};

