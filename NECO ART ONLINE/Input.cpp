#include "Input.h"
#include <DxLib.h>
#include <string>
#include <algorithm>

using namespace std;

const InputTable_t Input::GetCommandTable() const
{
	//�L�[�R���t�B�O��ʂɈړ��L�[��\�����������Ȃ����߂̏���
	InputTable_t ret = commandTable_;
	for (const auto& ex : exclusiveKeyConfigCommands_)
	{
		ret.erase(ex);
	}

	return ret;
}


Input::Input()
{
	commandTable_["OK"] = { {InputType::keyboard, KEY_INPUT_RETURN},
							{InputType::pad,PAD_INPUT_A} };

	commandTable_["pause"] = { {InputType::keyboard, KEY_INPUT_P},
								{InputType::pad, PAD_INPUT_R} };	//�X�^�[�g�{�^��

	commandTable_["keyconf"] = { {InputType::keyboard, KEY_INPUT_K},
								{InputType::pad, PAD_INPUT_L} };	//�L�[�R���t�B�O�{�^��

	commandTable_["up"] = { {InputType::keyboard, KEY_INPUT_UP},
							{InputType::pad, PAD_INPUT_UP} };	//�L�[�R���t�B�O�{�^��

	commandTable_["down"] = { {InputType::keyboard, KEY_INPUT_DOWN},
							{InputType::pad, PAD_INPUT_DOWN} };	//�L�[�R���t�B�O�{�^��

	commandTable_["left"] = { {InputType::keyboard, KEY_INPUT_LEFT},
							{InputType::pad, PAD_INPUT_LEFT} };	//�L�[�R���t�B�O�{�^��

	commandTable_["right"] = { {InputType::keyboard, KEY_INPUT_RIGHT},
							{InputType::pad, PAD_INPUT_RIGHT} };	//�L�[�R���t�B�O�{�^��

	exclusiveKeyConfigCommands_ = { "up","down","left","right" };
}

void Input::Update()
{
	lastInputData_ = inputData_;	//���O���͂��R�s�[���Ă���(�������u�Ԃ��擾����p)

	//�n�[�h�E�F�A���̓`�F�b�N
	char keystate[256];
	GetHitKeyStateAll(keystate);//���݂̃L�[�{�[�h���͂��擾
	int padstate = GetJoypadInputState(DX_INPUT_PAD1);//�p�b�h���̎擾

	//�o�^���ꂽ���ƃn�[�h�̏����Ƃ炵���킹�Ȃ���
	//inputData_�̓��e���X�V���Ă���
	for (const auto& cmd : commandTable_)
	{
		auto& input = inputData_[cmd.first];//�R�}���h�̖��O������̓f�[�^�����

		for (const auto& hardIO : cmd.second)
		{
			//�L�[�{�[�h�̃`�F�b�N
			input = false;
			if (hardIO.first == InputType::keyboard)
			{
				if (keystate[hardIO.second])
				{
					input = true;
					break;
				}
			}
			else if (hardIO.first == InputType::pad)
			{
				if (padstate & hardIO.second)
				{
					input = true;
					break;
				}
			}
		}
	}
}

bool Input::IsTriggered(const char* command) const
{
	auto it = inputData_.find(command);
	if (it == inputData_.end())	//��񂪂Ȃ����false��Ԃ�
	{
		return false;
	}
	return (inputData_.at(command) && !lastInputData_.at(command));

}