#include"Player_Sakuya.h"
#include"Input.h"

Sakuya::Sakuya()
{
	speed = 10;		                //プレイヤーの移動速度
	power = 400;		            //プレイヤーの攻撃力
	AttackTime = 0;                 //攻撃間隔

	SkilTimer = STOPTIME;               //スキル時間タイマー

	Color = GetColor(255, 0, 0);		//色
}
Sakuya::~Sakuya()
{

}
void Sakuya::Draw()
{
	//自機の描画
	DrawGraph(pos.x, pos.y,handle[SAKUYA_GRAPH1],true);
}
void Sakuya::Skil()
{
	//スキル回数がまだ残っている時
	if (SkilCount > 0 && Skil_isActive == false) {
		//スペースキーを押すとスキル発動
		if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1)
		{
			Skil_isActive = true;
			SkilCount -= 1;
		}
	}
}
void Sakuya::SkilClock()
{
	if (Skil_isActive == true) {
		DrawFormatString(10, 100, Color, "咲夜スキル時間：%d", SkilTimer / FRAME);
	}
}
void Sakuya::Update(EnemyManager* _eManager)
{
	Sakuya::Draw();						    //描画
	BasePlayer::Update(_eManager);          //更新
	SkilClock();
	Skil();                     //スキル
	if (SkilTimer >= 0) {	    //表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
		SkilTimer -= 1;
	}

	//スキル発動時はエネミーの移動を止める
	if (Skil_isActive == true)
	{
		for (int i = 0; i < _eManager->Get_enemyNum(); i++)
		{
			_eManager->Set_IsMove(i, false);
		}
	}
	if (Skil_isActive == false)
	{
		for (int i = 0; i < _eManager->Get_enemyNum(); i++)
		{
			_eManager->Set_IsMove(i, true);
		}
	}
}
