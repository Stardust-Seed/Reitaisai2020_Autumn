#ifndef _SAKUYA_H_
#define _SAKUYA_H

#include "BasePlayer.h"
#include "EnemyManager.h"

class EnemyManager;

class Sakuya :public virtual BasePlayer
{
private:
	const int STOPTIME = 5;         //時止めスキルの時間

	int abilityTimer;               //スキル発動時間

	unsigned int color;             //スキル時間の色

	int countDown;                  //スキルタイマーのカウントダウンに使用

public:

	Sakuya();			   //コンストラクタ
	~Sakuya();             //デストラクタ
	void Update();         //更新処理
	void abilityClock();   //スキルタイマー描画処理
	void Ability();        //スキル処理

	int  Get_SkilTime() {return STOPTIME;}   //スキルの発動時間

};

#endif //_SAKUYA_H_

