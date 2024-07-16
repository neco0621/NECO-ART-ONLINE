#pragma once
#include <memory>
#include <array>
#include<DxLib.h>
#include "../CharacterComponent.h"

class ObjectBase
{
public:
	//���̂̎��
	enum class ColType
	{
		None,		//����
		Player,		//�v���C���[
		Enemy,		//�G�l�~�[
	};

public:
	ObjectBase();
	virtual ~ObjectBase();

	//���C���|�C���^�Z�b�g
	void SetMain() {}

	//���f���Z�b�g�n���h��
	void SetModelHandle(int handle) { m_modelHandle = handle; }

	virtual void Init() {};

	virtual void Update() {};

	//�L�����N�^�[���̎擾
	CharacterComponent::CharacterInfo GetInfo() const { return m_info; }

	//���g�̓����蔻����
	virtual ColType GetColType() const { return ColType::None; }

protected:
	//�L�����N�^�[���
	CharacterComponent::CharacterInfo m_info;

	//���f���n���h��
	int m_modelHandle;

	//�L�����N�^�[�̈ړ��X�s�[�h
	float m_moveSpeed;

	//�U�����󂯂���
	bool m_isDamage;
};

