#ifndef _SE_H
#define _SE_H

#include <vector>
#include "Singleton.h"

/********************************************************************************************
使用例
//再生するとき
SE::Instance()->PlaySE(SE_00,Back);
//再生を止めるとき
SE::Instance()->StopSE(SE_00);
********************************************************************************************/

// SEナンバー
//番号にするか、名前で表示するかで迷ってます(今は番号)
//PlaySE(SE_00);  PlaySE(SE_Hit); 
enum SEnum {
	SE_00,
	SE_01,
	SE_02,
};

//再生タイプ
/***************************************************************
BackとLoopの間に変なのがあるのはPlaySoundMemの第二引数で

DX_PLAYTYPE_NORMAL　 : ノーマル再生
DX_PLAYTYPE_BACK　　 : バックグラウンド再生
DX_PLAYTYPE_LOOP　　 : ループ再生

があるんですけど数値で見ると
DX_PLAYTYPE_NORMAL　 : 0
DX_PLAYTYPE_BACK　　 : 1
DX_PLAYTYPE_LOOP　　 : 3

になっててそれを合わせるために追加してます
ぶっちゃけ使うときの引数に
DX_PLAYTYPE_NORMAL
DX_PLAYTYPE_BACK
DX_PLAYTYPE_LOOP

って入れればいいんですけどそれだと長いかなって思って
これを作ってあります。いらないなら普通に消しますん
****************************************************************/
enum PlayBackType {
	Normal,    //他の処理は止められ、再生されます
	Back,      //他の処理は止まらず、再生されます
	No,        //使わないでください。使用時の挙動はBackと同じ
	Loop,      //他の処理は止まらず、ループ再生されます
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
	void PlaySE(SEnum,PlayBackType);      //再生
	void StopSE(SEnum);                   //停止

};

#endif //SE_H_