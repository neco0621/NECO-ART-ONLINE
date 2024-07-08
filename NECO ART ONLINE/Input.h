#pragma once
#include<array>
#include<map>				//�\�[�g(���בւ����Ă����)map
#include<unordered_map>		//�\�[�g���Ȃ�map
#include<string>

enum class InputType {
	keyboard,	//�L�[�{�[�h
	pad			//�p�b�h
	//mouse�Ƃ��������ɓ���āZ
};

using InputTable_t = std::unordered_map<std::string, std::map<InputType, int>>;

class KeyConfigScene;

class Input
{
	friend KeyConfigScene;
	std::vector<std::string> exclusiveKeyConfigCommands_;

private:
	//�R�}���h���Ɠ��͂��y�A�ɂ����e�[�u��
	//�L�[�{�[�h�̎���keyboard&KEY_INPUT����
	//�p�b�h�̎���pad&PAD_INPUT����
	//���`�F�b�N����
	InputTable_t commandTable_;

	//�R�}���h�̓��͂��o���Ă���
	std::map < std::string, bool> inputData_;		//���݂̓���
	std::map < std::string, bool> lastInputData_;	//���O�̓���

	const InputTable_t GetCommandTable()const;
public:
	Input();

	/// <summary>
	/// ���͏����X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �w��̃R�}���h�������ꂽ�u�ԂȂ̂�
	/// </summary>
	/// <param name="command">�R�}���h������</param>
	/// <returns> true : �����ꂽ�u��, false : ������Ă��Ȃ����A��������</returns>
	bool IsTriggered(const char* command)const;
};