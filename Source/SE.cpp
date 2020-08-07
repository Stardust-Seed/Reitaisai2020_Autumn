#include "SE.h"
#include"DxLib.h"
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
	seNums.clear();
}

//読み込み
//多分シーンごとに読み込むやつ振り分けておいた方がいいと思うのかなーと思いますね
//Loadに引数でEBaseSceneをもってきてそのシーン別にswitch文で読み込むやつを実行みたいな
void SE::Load()
{
	//ファイルパス指定
	seNum[SE_00] = LoadSE("./res/Sound/SE/OOHSYUK.wav");
	seNum[SE_01] = 0;
	seNum[SE_02] = 0;
}

//SEを再生
void SE::PlaySE(SEnum _SEnum, PlayBackType _PlayBackType)
{
	//DrawFormatString(10, 500, GetColor(255, 255, 255), "サウンド再生_番号:%d",_SEnum);
	PlaySoundMem(seNum[_SEnum], _PlayBackType,TRUE);
}

//SEを止める
void SE::StopSE(SEnum _SEnum)
{
	StopSoundMem(seNum[_SEnum]);
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