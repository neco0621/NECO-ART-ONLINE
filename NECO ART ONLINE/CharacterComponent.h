#pragma once
#include <DxLib.h>

//キャラクターが持ってる情報
namespace CharacterComponent
{
	//キャラクター情報
	struct CharacterInfo
	{
		VECTOR pos;		//座標
		VECTOR vec;		//移動ベクトル
		VECTOR rot;		//角度
		int modelHandle;//モデルハンドル
		int isExist;	//存在しているかどうか
	};

}

