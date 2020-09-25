#include "DxLib.h"
#include "BGM.h"

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
	//中身を消去(メモリまだ解放されてない)
	bgmNums.clear();
	//メモリを解放
	bgmNums.shrink_to_fit();
}

//読み込み
void BGM::Load()
{
	//ファイルパス指定
	bgmNum[BGM_title] = LoadBGM("./res/Sound/BGM/gensoukyounohatuaki.wav");
	bgmNum[BGM_menu] = LoadBGM("./res/Sound/BGM/engawakaranagameru.wav");
	bgmNum[BGM_gameScene] = LoadBGM("./res/Sound/BGM/youseinoakudoi.wav");
	bgmNum[BGM_result] = LoadBGM("./res/Sound/BGM/asobiniikuhinoasa_2.wav");
}

//BGMを再生
void BGM::PlayBGM(BGMnum _BGMnum, int _type, bool _topFlg)
{
	DrawFormatString(10, 500, GetColor(255, 255, 255), "サウンド再生_番号:%d", PlaySoundMem(bgmNum[_BGMnum], _type, TRUE));
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

//音量の設定
void BGM::VolumeBGM(int _volume)
{
	int size = bgmNums.size();
	for (int i = 0; i < size; i++)
	{
		ChangeVolumeSoundMem(255 * (_volume * 10) / 100, bgmNum[i]);
	}
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