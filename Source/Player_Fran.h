#ifndef _SAKUYA_H_
#define _SAKUYA_H

#include "BasePlayer.h"
#include "EnemyManager.h"

class EnemyManager;

class Fran :public virtual BasePlayer
{
private:

	int abilityTimer;     //スキル発動時間

	int countDown;        //スキルタイマーのカウントダウンに使用

	unsigned int color;   //スキル時間の色

public:

	Fran();			   //コンストラクタ
	~Fran();             //デストラクタ
	void Update();         //更新処理
	void SkilClock();      //スキルタイマー描画処理
	void Ability();        //スキル処理

};

#endif //_SAKUYA_H_

