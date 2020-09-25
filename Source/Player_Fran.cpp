#include"Player_Fran.h"
#include"Input.h"
#include"Define.h"

Fran::Fran()
{
	speed = 10;		                //プレイヤーの移動速度
	power = 400;		            //プレイヤーの攻撃力
	attackTime = 0;                 //攻撃間隔

	color = GetColor(255, 0, 0);    //色

	abilityCount = 2;               //スキル使用回数

	countDown = FRAME;              //スキルタイマーを減らすのに使う

}
Fran::~Fran()
{

}
void Fran::Ability()
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
void Fran::Update()
{
	Ability();    //スキル

	if (Get_isAbility() == true) {

		if (abilityTimer == 1) {    //フランのスキルは発動したらすぐ終了する
			isAbility = false;
			abilityTimer = 0;
		}
		if (Get_isAbility() == true && abilityTimer < 1)
		{
			abilityTimer += 1;
		}
	}

}
