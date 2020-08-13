#ifndef _BGM_H
#define _BGM_H

#include <vector>
#include "Singleton.h"

/********************************************************************************************
登録の仕方
BGM.hで
BGMnumに項目追加
int BGMNum[]; の箱を増やす分、数字を大きくする

BGM_urabe
int BGMNum[4];

BGM.cppで
Load()に項目追加

BGMNum[BGM_urabe] = LoadSE("./res/Sound/BGM/urabe.wav");

使用例

//再生するとき
BGM::Instance()->PlayBGM(BGM_test);
BGM::Instance()->PlayBGM(BGM_test,DX_PLAYTYPE_LOOP);
BGM::Instance()->PlayBGM(BGM_test,DX_PLAYTYPE_LOOP,FALSE);

第三引数使うときは第二引数もちゃんと指定してください

第二引数が指定されてないときは
DX_PLAYTYPE_BACKがデフォルトで指定されてます

DX_PLAYTYPE_NORMAL　 : 他の処理を止めて再生
DX_PLAYTYPE_BACK　　 : 他の処理は止まらずに再生
DX_PLAYTYPE_LOOP　　 : 他の処理は止まらずにループ再生

第三引数が指定されてないときは
TRUEがデフォルトで指定されてます

TRUE    : 最初から再生
FALSE   : 続きから再生

//再生を止めるとき
BGM::Instance()->StopBGM(BGM_test);
********************************************************************************************/

// BGMナンバー
//追加するときは名前でお願いします
enum BGMnum {
	BGM_test,

};

class BGM :public Singleton <BGM> {

	friend Singleton <BGM>;

private:

	std::vector<int> bgmNums;
	//追加するときはこの配列の数字も増やしてね
	int bgmNum[3];                                              //格納するための配列
	int LoadBGM(const char* _filePath);                         //読み込み用に

public:

	BGM();                                                      //コンストラクタ
	~BGM();                                                     //デストラクタ
	void Load();                                                //読み込みたいやつら
	void PlayBGM(BGMnum,int _type = 1, bool _topflg = true);    //再生
	void StopBGM(BGMnum);                                       //停止

};

#endif //BGM_H_