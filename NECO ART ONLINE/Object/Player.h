#pragma once
#include <memory>
#include "DxLib.h"
#include "../Collision.h"
#include "CharacterBase.h"

class Player : public CharacterBase
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update();
	void Draw();

	//メンバ変数にアクセスする
	void SetHandle(int handle) { m_info.modelHandle = handle; }

	//座標のgetter/setter
	const VECTOR& GetPos() const { return m_info.pos; }
	void SetPos(const VECTOR set) { m_info.pos = set; }

	// 向きのgetter/setter.
	const VECTOR& GetDir() const { return m_info.rot; }
	void SetDir(const VECTOR set) { m_info.rot = set; }

	//移動方向と角度を考慮した移動更新
	VECTOR MoveUpdate();
private:
	//アニメーションハンドル
	int m_animationHandle;

	int m_idleHandle;

	//3Dモデルのアニメーションインデックス
	int m_attachIndex;

	//3Dモデルのアニメーションインデックス
	int m_runIndex;

	//アニメーションの再生時間
	float m_tottalTime;

	//アニメーションの現在時間
	float m_playTime;
};

