#pragma once
#include <DxLib.h>
#include<vector>
#include <memory>

class Model
{
public:
	//ファイル名を指定してロードを行う
	Model(const char* fileName);
	virtual ~Model();

	void Update();
	void Draw();

	//モデルハンドルの取得
	int GetModelHandle() const { return m_modelHandle; }

	//表示位置の設定
	void SetPos(VECTOR pos);

	//サイズの設定
	void SetScale(VECTOR scale);

	//座標の取得
	VECTOR GetPos() const { return m_pos; }

	//回転状態の設定
	void SetRot(VECTOR rot);

	void SetAnimation(int animNo, bool isLoop, bool isForceChange);

	void ChangeAnimation(int animNo, bool isLoop, bool isForceChange, int ChangeFrame);

	bool IsAnimEnd();

private:
	//アニメーション情報
	struct AnimData
	{
		int animNo;			//アニメーション番号
		
		int attachNo;		//アタッチ番号
		float totalTime;	//アニメーションの総再生時間
		bool isLoop;		//アニメーションをループさせるか
	};

private:
	//モデルの位置
	VECTOR m_pos;
	//アニメーションのデータクリア
	void ClearAnimData(AnimData& anim);
	// アニメーションの更新
	void UpdateAnim(AnimData anim, float dt = 1.0f);

private:
	//モデルのハンドル
	int m_modelHandle;

	int m_animChangeFrame;			// 現在の切り替えフレーム数
	int m_animChangeFrameTotal;		// 切り替えにかける総フレーム数

	// アニメーション変更速度
	int m_animSpeed;

	// アニメーションのアタッチ番号
	AnimData m_animPrev;	// 変更前アニメーション情報
	AnimData m_animNext;	// 変更後アニメーションデータ


};