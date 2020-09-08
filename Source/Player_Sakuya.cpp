#include"Player_Sakuya.h"
#include"Input.h"

Sakuya::Sakuya()
{
	speed = 10;		                //プレイヤーの移動速度
	power = 400;		            //プレイヤーの攻撃力
	attackTime = 0;                 //攻撃間隔

	abilityTimer = STOPTIME;               //スキル時間タイマー

	color = GetColor(255, 0, 0);		//色

	countDown = FRAME;              //スキルタイマーを減らすのに使う
}
Sakuya::~Sakuya()
{

}
void Sakuya::Ability()
{
	//スキル回数がまだ残っている時
	if (Get_abilityCount() > 0 && Get_isAbility() == false) {
		//スペースキーを押すとスキル発動
		if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1)
		{
			isAbility = true;
			abilityCount -= 1;
		}
	}
}
void Sakuya::SkilClock()
{
	DrawFormatString(10, 100, color, "咲夜スキル時間：%d", abilityTimer);
}
void Sakuya::Update()
{
	if (Get_isAbility() == true) {

		Ability();                         //スキル
		SkilClock();                    //スキルタイマーの表示

		if (abilityTimer >= 0 && countDown <= 0) {	    //表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
			abilityTimer -= 1;
			countDown = FRAME;
		}
		if (abilityTimer <= 0)
		{
			isAbility = false;
		}
		countDown -= 1;
	}

}
