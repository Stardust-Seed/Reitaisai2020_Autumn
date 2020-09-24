#include"Player_Sakuya.h"
#include"Input.h"
#include"Define.h"

Sakuya::Sakuya(){
	speed = 10;		                //プレイヤーの移動速度
	power = 400;		            //プレイヤーの攻撃力
	attackTime = 0;                 //攻撃間隔

	color = GetColor(255, 0, 0);    //色

	abilityTimer = STOPTIME;        //スキル時間タイマー
	abilityCount = 3;               //スキル使用回数
	countDown = FRAME;              //スキルタイマーを減らすのに使う

	/*************
	キャラが咲夜の場合は咲夜の画像データを入れる

	playerGh[] ← 結合するまでBasePlayerのフューチャーにしかないので今は使えない。
	　　　　　　  これに咲夜の画像を分割読み込みでぶち込む

	**************/
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
void Sakuya::AbilityClock()
{
	DrawFormatString(10, 100, color, "咲夜スキル時間：%d", abilityTimer);
}
void Sakuya::Update()
{
	Ability();                             //スキル
	if (Get_isAbility() == true) {

		AbilityClock();                    //スキルタイマーの表示

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
