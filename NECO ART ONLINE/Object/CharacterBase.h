#pragma once
#include "ObjectBase.h"


class CharacterBase : public ObjectBase
{
public:
	//ステータス構造体
	struct Status
	{
		int hp = 10;	//体力
		int atk = 10;	//攻撃力
		float speed = 10; //スピード
	};

	struct AnimData
	{
		int8_t idle = 0;	//待機モーション
		int8_t run = 0;		//走るモーション
		int8_t attack = 0;	//攻撃モーション
	};

public:
	CharacterBase();
	virtual ~CharacterBase();

	virtual void Init() {};
	virtual void Update() {};

	virtual void Draw() {};
	//敵に攻撃が当たったときの処理
	virtual void HitAttack();

	//敵からの攻撃に当たったときの処理
	virtual void OnDamage(VECTOR targetPos, int damagePoint);

protected:
	Status m_statusData;	//ステータスデータ
	AnimData m_animData;	//アニメーションデータ
};

