#include "CsvLoad.h"
#include <vector>
#include<array>
#include <string>
#include<cassert>

//����̕��������o�����܂ŕ������v�b�V���o�b�N����
std::vector<std::string> Sprit(std::string& input, char delimiter)
{
	std::istringstream stream(input);
	std::string field;
	std::vector<std::string> result;
	while (getline(stream, field, delimiter)) {
		result.push_back(field);
	}
	return result;
}


CsvLoad::~CsvLoad()
{
}

void CsvLoad::AnimLoad(CharacterBase::AnimData& Data, const char* characterName)
{
	//�t�@�C�����̓ǂݍ���
	std::ifstream ifs("data/csv/AnimCsv.csv");
	std::string line;

	std::array<int8_t, 3> animData{};

	std::vector<std::string> strvec;

	while (getline(ifs, line))
	{
		//csv�f�[�^1�s���A','�ŕ����̕�����ɕ���
		strvec = Sprit(line, ',');


		//�Q�Ƃ������L�������������Ă���Ώ�������߂�
		const char* str = strvec[0].c_str();
		if (strcmp(str, characterName) == 0)
		{
			for (int i = 0; i < animData.size(); i++)
			{
				//�L�����N�^�[�����͂���Ȃ��̂ŏȂ�
				if (i == 0)continue;
				int animNum = stoi(strvec[i]);
				animData[i] = static_cast<int8_t>(animNum);
			}
			break;
		}
		else
		{
			strvec.erase(strvec.begin(), strvec.end());
		}
	}
	//�O���t�@�C�����玝���Ă����X�e�[�^�X�����X�e�[�^�X�f�[�^�ɓ����
	Data.idle = animData[1];
	Data.run = animData[2];
	Data.attack = animData[3];
}
