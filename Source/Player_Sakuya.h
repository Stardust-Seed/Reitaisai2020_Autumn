#ifndef _SAKUYA_H_
#define _SAKUYA_H

#include "BasePlayer.h"
#include "EnemyManager.h"

class EnemyManager;

class Sakuya :public BasePlayer
{
private:

	static const int FRAME = 60;	//フレームレート
	const int STOPTIME = 5;         //時止めスキルの時間]
	static const int TIME = 10;								//実際の制限時間
	static const int MAX_LIMITTIME = FRAME * (TIME + 1) - 1;	
	//フレームレート * (指定した秒数 +1) - 1 // "+1) - 1"この部分は表示の違和感をなくすため

	int speed;		                //プレイヤーの移動速度
	int power;		                //プレイヤーの攻撃力
	int AttackTime;                 //攻撃間隔

	int SkilTimer;                  //スキル発動時間

	int Color;                      //スキル時間の色

	int CountDown;

public:

	Sakuya();			   //コンストラクタ
	~Sakuya();             //デストラクタ
	void Update();         //更新処理
	void SkilClock();      //スキルタイマー描画処理
	void Skil();           //スキル処理

	int  Get_SkilTime() {return STOPTIME;}   //スキルの発動時間

};

#endif //_SAKUYA_H_

