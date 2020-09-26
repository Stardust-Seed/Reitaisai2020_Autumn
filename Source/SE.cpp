#include "DxLib.h"
#include "SE.h"

//コンストラクタ
SE::SE(){
	Load();
}

//デストラクタ
SE::~SE() {

	//要素の数が何個なのか取得する
	int size = seNums.size();

	//ロードしたSEを消します
	for (int i = 0; i < size; i++)
	{
		DeleteSoundMem(seNums[i]);
	}

	//今まで追加してきた要素の箱も消すよ
	//中身を消去(メモリまだ解放されてない)
	seNums.clear();
	//メモリを解放
	seNums.shrink_to_fit();
}

//読み込み
void SE::Load()
{
	//ファイルパス指定
	seNum[SE_bomb] = LoadSE("./res/Sound/SE/bomb1.wav");
	seNum[SE_cursor] = LoadSE("./res/Sound/SE/cursor2.wav");
	seNum[SE_sukimaWarp] = LoadSE("./res/Sound/SE/magic-worp1.wav");
	seNum[SE_CastleDamage] = LoadSE("./res/Sound/SE/stone-break1.wav");
	seNum[SE_CastleBreak] = LoadSE("./res/Sound/SE/glass-break4.wav");
	seNum[SE_warning] = LoadSE("./res/Sound/SE/warning1.wav");
	seNum[SE_DarknessStart] = LoadSE("./res/Sound/SE/buun1.wav");
	seNum[SE_DarknessEnd] = LoadSE("./res/Sound/SE/buun1_reverse.wav");
}

//SEを再生
void SE::PlaySE(SEnum _SEnum,int _type)
{
	//その音が再生中だったら止める
	if (CheckSoundMem(seNum[_SEnum]) == 1)
	{
		StopSoundMem(seNum[_SEnum]);
	}

	PlaySoundMem(seNum[_SEnum], _type, TRUE);
}

//SEを止める
void SE::StopSE(SEnum _SEnum)
{
	StopSoundMem(seNum[_SEnum]);
}

//音量の設定
void SE::VolumeSE(int _volume)
{
	int size = seNums.size();
	for (int i = 0; i < size; i++)
	{
		ChangeVolumeSoundMem(255 * (_volume * 10) / 100, seNum[i]);
	}
}

//wavファイルを読み込んで読み込んだやつをメンバ変数に追加
int SE::LoadSE(const char* _FilePath)
{
	//読み込み
	int newHandle = LoadSoundMem(_FilePath);

	//要素の追加
	seNums.push_back(newHandle);

	//返却
	return newHandle;
}