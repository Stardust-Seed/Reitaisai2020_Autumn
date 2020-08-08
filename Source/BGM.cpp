#include "BGM.h"
#include"DxLib.h"

//コンストラクタ
BGM::BGM() {

	Load();
}

//デストラクタ
BGM::~BGM() {

	//要素の数が何個なのか取得する
	int size = bgmNums.size();

	//ロードしたBGMを消します
	for (int i = 0; i < size; i++)
	{
		DeleteSoundMem(bgmNums[i]);
	}

	//今まで追加してきた要素の箱も消すよ
	bgmNums.clear();
}

//読み込み
void BGM::Load()
{
	//ファイルパス指定
	bgmNum[BGM_test] = LoadBGM("./res/Sound/BGM/OOHSYUK.wav");

}

//BGMを再生
void BGM::PlayBGM(BGMnum _BGMnum, int _type, bool _topFlg)
{
	//DrawFormatString(10, 500, GetColor(255, 255, 255), "サウンド再生_番号:%d",_BGMnum);
	if (_topFlg == true)
	{
		//DrawFormatString(50, 500, GetColor(255, 255, 255), "最初から再生");
		PlaySoundMem(bgmNum[_BGMnum], _type, TRUE);
	}
	else
	{
		//DrawFormatString(50, 500, GetColor(255, 255, 255), "続きから再生");
		PlaySoundMem(bgmNum[_BGMnum], _type, FALSE);
	}
}

//BGMを止める
void BGM::StopBGM(BGMnum _BGMnum)
{
	StopSoundMem(bgmNum[_BGMnum]);
}

//wavファイルを読み込んで読み込んだやつをメンバ変数に追加
int BGM::LoadBGM(const char* _FilePath)
{
	//読み込み
	int newHandle = LoadSoundMem(_FilePath);

	//要素の追加
	bgmNums.push_back(newHandle);

	//返却
	return newHandle;
}