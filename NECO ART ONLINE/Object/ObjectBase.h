#pragma once
#include <memory>
#include <array>
#include<DxLib.h>
#include "../CharacterComponent.h"

class ObjectBase
{
public:
	//物体の種類
	enum class ColType
	{
		None,		//無し
		Player,		//プレイヤー
		Enemy,		//エネミー
	};

public:
	ObjectBase();
	virtual ~ObjectBase();

	//メインポインタセット
	void SetMain() {}

	//モデルセットハンドル
	void SetModelHandle(int handle) { m_modelHandle = handle; }

	virtual void Init() {};

	virtual void Update() {};

	//キャラクター情報の取得
	CharacterComponent::CharacterInfo GetInfo() const { return m_info; }

	//自身の当たり判定情報
	virtual ColType GetColType() const { return ColType::None; }

protected:
	//キャラクター情報
	CharacterComponent::CharacterInfo m_info;

	//モデルハンドル
	int m_modelHandle;

	//キャラクターの移動スピード
	float m_moveSpeed;

	//攻撃を受けたか
	bool m_isDamage;
};

