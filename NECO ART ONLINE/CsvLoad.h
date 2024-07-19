#pragma once
#include "CharacterComponent.h"
#include <sstream>
#include <fstream>
#include <unordered_map>
#include "Object/ObjectBase.h"
#include "Object/CharacterBase.h"

using namespace CharacterComponent;


class CsvLoad
{
public:
	~CsvLoad();

	static CsvLoad& GetInstandce()
	{
		static CsvLoad instance;

		return instance;
	};

	void AnimLoad(CharacterBase::AnimData& Data, const char* characterName);

private:
	//シングルトンパターンなのでコンストラクタはprivateに置く
	CsvLoad();

	//コピーも代入も禁止する
	CsvLoad(const CsvLoad&) = delete;				//コピーコンストラクタ
	void operator = (const CsvLoad&) = delete;		//代入も禁止

};

