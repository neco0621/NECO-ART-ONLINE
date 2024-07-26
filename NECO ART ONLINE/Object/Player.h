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

	const Collision GetCol() const { return m_pCol; }
	void SetCol(const Collision col) { m_pCol = col; }

	void IdleInit() {};
	void IdleUpdate();

private:


	int m_idleHandle;				//待機アニメーションハンドル
	int m_runHandle;				//走るアニメーションハンドル
	int m_attackHandle;				//攻撃1のアニメーションハンドル
	int m_avoidanceHandle;			//回避アニメーションハンドル
	
	int m_idleIndex;				//待機アニメーションインデックス
	int m_runIndex;					//走るメーションインデックス
	int m_attackIndex;				//攻撃1アニメーションインデックス
	int m_avoidanceIndex;			//回避アニメーションインデックス

	float m_idleTotalTime;			//待機アニメーションの再生時間
	float m_runTotalTime;			//走るアニメーションの再生時間
	float m_attackTotalTime;		//攻撃1アニメーションの総再生時間
	float m_avoidanceTotalTime;		//回避アニメーションの総再生時間
	
	bool m_idleFlag;				//待機アニメーションへの切り替え
	bool m_runFlag;					//走るアニメーションへの切り替え
	bool m_attackFlag;				//攻撃1アニメーションへの切り替え
	bool m_avoidanceFlag;			//回避アニメーションへの切り替え


	//アニメーションの現在時間
	float m_playTime;

	//当たり判定
	Collision m_pCol;
};