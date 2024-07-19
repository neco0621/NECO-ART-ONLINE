#include "CsvLoad.h"
#include <vector>
#include<array>
#include <string>
#include<cassert>

//特定の文字が検出されるまで文字をプッシュバックする
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
	//ファイル情報の読み込み
	std::ifstream ifs("data/csv/AnimCsv.csv");
	std::string line;

	std::array<int8_t, 3> animData{};

	std::vector<std::string> strvec;

	while (getline(ifs, line))
	{
		//csvデータ1行を、','で複数の文字列に分割
		strvec = Sprit(line, ',');


		//参照したいキャラが見つかっていれば処理をやめる
		const char* str = strvec[0].c_str();
		if (strcmp(str, characterName) == 0)
		{
			for (int i = 0; i < animData.size(); i++)
			{
				//キャラクター名情報はいらないので省く
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
	//外部ファイルから持ってきたステータス情報をステータスデータに入れる
	Data.idle = animData[1];
	Data.run = animData[2];
	Data.attack = animData[3];
}
