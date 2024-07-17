#pragma once
#include <memory>
#include "DxLib.h"
#include "../Collision.h"
#include "CharacterBase.h"

class Model;
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
	const VECTOR& GetRot() const { return m_info.rot; }
	void SetRot(const VECTOR set) { m_info.rot = set; }

	void IdleInit() {};
	void IdleUpdate();

private:
	//アニメーションハンドル
	int m_runHandle;

	//待機モーションハンドル
	int m_idleHandle;

	//3Dモデルのアニメーションインデックス
	int m_idleIndex;

	//3Dモデルのアニメーションインデックス
	int m_runIndex;

	//走るアニメーションの再生時間
	float m_runTotalTime;

	//待機アニメーションの再生時間
	float m_idleTotalTime;

	//アニメーションの現在時間
	float m_playTime;

	//走るアニメーションへの切り替え
	bool m_runFlag;

	//待機アニメーションへの切り替え
	bool m_idleFlag;
};