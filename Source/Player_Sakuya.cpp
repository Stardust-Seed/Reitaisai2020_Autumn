#include"Player_Sakuya.h"
#include"Input.h"

Sakuya::Sakuya()
{
	speed = 10;		                //プレイヤーの移動速度
	power = 400;		            //プレイヤーの攻撃力
	AttackTime = 0;                 //攻撃間隔

	SkilTimer = STOPTIME;               //スキル時間タイマー

	Color = GetColor(255, 0, 0);		//色

	CountDown = FRAME;              //スキルタイマーを減らすのに使う
}
Sakuya::~Sakuya()
{

}
void Sakuya::Skil()
{
	//スキル回数がまだ残っている時
	if (Get_SkilCount() > 0 && Get_isAbility() == false) {
		//スペースキーを押すとスキル発動
		if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1)
		{
			Set_isAbility(true);
			Set_SkilCount(Get_SkilCount() - 1);
		}
	}
}
void Sakuya::SkilClock()
{
	DrawFormatString(10, 100, Color, "咲夜スキル時間：%d", SkilTimer);
}
void Sakuya::Update()
{
	if (Get_isAbility() == true) {

		Skil();                         //スキル
		SkilClock();                    //スキルタイマーの表示

		if (SkilTimer >= 0 && CountDown <= 0) {	    //表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
			SkilTimer -= 1;
			CountDown = FRAME;
		}
		if (SkilTimer <= 0)
		{
			Set_isAbility(false);
		}
		CountDown -= 1;
	}

}
