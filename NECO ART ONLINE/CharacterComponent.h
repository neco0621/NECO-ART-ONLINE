#pragma once
#include <DxLib.h>

//�L�����N�^�[�������Ă���
namespace CharacterComponent
{
	//�L�����N�^�[���
	struct CharacterInfo
	{
		VECTOR pos;		//���W
		VECTOR vec;		//�ړ��x�N�g��
		VECTOR rot;		//�p�x
		int modelHandle;//���f���n���h��
		int isExist;	//���݂��Ă��邩�ǂ���
	};

}

