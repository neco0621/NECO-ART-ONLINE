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
	//�V���O���g���p�^�[���Ȃ̂ŃR���X�g���N�^��private�ɒu��
	CsvLoad();

	//�R�s�[��������֎~����
	CsvLoad(const CsvLoad&) = delete;				//�R�s�[�R���X�g���N�^
	void operator = (const CsvLoad&) = delete;		//������֎~

};

