#ifndef _SE_H
#define _SE_H

#include <vector>
#include "Singleton.h"

/********************************************************************************************
使用例
//再生するとき
SE::Instance()->PlaySE(SE_00);
SE::Instance()->PlaySE(SE_00,DX_PLAYTYPE_LOOP);

第二引数が指定されてないときは
DX_PLAYTYPE_BACKがデフォルトで指定されてます

DX_PLAYTYPE_NORMAL　 : 他の処理を止めて再生
DX_PLAYTYPE_BACK　　 : 他の処理は止まらずに再生
DX_PLAYTYPE_LOOP　　 : 他の処理は止まらずにループ再生

//再生を止めるとき
SE::Instance()->StopSE(SE_00);
********************************************************************************************/

// SEナンバー
//追加するときは名前でお願いします
enum SEnum {
	SE_test,

};


class SE:public Singleton <SE> {

	friend Singleton <SE>;

private:

	std::vector<int> seNums;
	int seNum[3];                         //格納するための配列
	int LoadSE(const char* _filePath);    //読み込み用に

public:

	SE();                                 //コンストラクタ
	~SE();                                //デストラクタ
	void Load();                          //読み込みたいやつら
	void PlaySE(SEnum,int _type= 1);      //再生
	void StopSE(SEnum);                   //停止

};

#endif //SE_H_