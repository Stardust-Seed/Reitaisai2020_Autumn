#ifndef _SE_H
#define _SE_H

#include <vector>
#include "Singleton.h"

/********************************************************************************************
登録の仕方
SE.hで
SEnumに項目追加
int seNum[]; の箱を増やす分、数字を大きくする

,SE_urabe
int seNum[2];

SE.cppで
Load()に項目追加

seNum[SE_urabe] = LoadSE("./res/Sound/SE/urabe.wav");

使用例
//再生するとき
SE::Instance()->PlaySE(SE_test);
SE::Instance()->PlaySE(SE_test,DX_PLAYTYPE_LOOP);

第二引数が指定されてないときは
DX_PLAYTYPE_BACKがデフォルトで指定されてます

DX_PLAYTYPE_NORMAL　 : 他の処理を止めて再生
DX_PLAYTYPE_BACK　　 : 他の処理は止まらずに再生
DX_PLAYTYPE_LOOP　　 : 他の処理は止まらずにループ再生

//再生を止めるとき
SE::Instance()->StopSE(SE_test);
********************************************************************************************/

// SEナンバー
//追加するときは名前でお願いします
enum SEnum {
	SE_bomb,
	SE_cursor,
	SE_sukimaWarp,
	SE_CastleBreak,
	SE_CastleDamage,
	SE_warning,
	SE_DarknessStart,
	SE_DarknessEnd,
	SE_SakuyaAttack,
	SE_SakuyaAbility,
	SE_FranAttack,
	SE_FranAbility
};

class SE :public Singleton <SE> {

	friend Singleton <SE>;

private:

	std::vector<int> seNums;
	//追加するときはこの配列の数字も増やしてね
	int seNum[12];                        //格納するための配列
	int LoadSE(const char* _filePath);    //読み込み用に

public:

	SE();                                 //コンストラクタ
	~SE();                                //デストラクタ
	void Load();                          //読み込みたいやつら
	void PlaySE(SEnum, int _type = 1);    //再生
	void StopSE(SEnum);                   //停止
	void VolumeSE(int);                   //音量設定

};

#endif //SE_H_