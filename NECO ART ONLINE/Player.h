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

	//メンバ変数にアクセスする
	void SetHandle(int handle) { m_handle = handle; }

	//座標の取得
	VECTOR GetPos() const { return m_pos; }
private:
	//座標
	VECTOR m_pos;
	int m_handle;

};

