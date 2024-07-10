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
	const VECTOR& GetPos() const { return m_pos; }
	void SetPos(const VECTOR set) { m_pos = set; }

	// �f�B���N�V������getter/setter.
	const VECTOR& GetDir() const { return m_dir; }
	void SetDir(const VECTOR set) { m_dir = set; }
private:
	//���W
	VECTOR m_pos;

	int m_handle;

	VECTOR m_dir;

};

