#include <DxLib.h>
#include "BaseBomb.h"

//コンストラクタ
BaseBomb::BaseBomb()
{
	//BombType = GetRand(1);
	direction = GetRand(3);
	speed = 3;
	countdown = COUNTMAX;						//制限時間のセット

	finishxplosion = false;							//初期状態
	isSpown = false;
	isTrigger = false;

	if (direction == DIRECTIONLEFT)			//左
	{
		x = BOMB_SPOWNLEFTHX;
		y = BOMB_SPOWNLR;
	}

	if (direction == DIRECTIONRIGHT)		//右
	{
		x = BOMB_SPOWNRIGHTX;
		y = BOMB_SPOWNLR;
	}

	if (direction == DIRECTIONUP)			//上
	{
		x = BOMB_SPOWNUPDOWNX;
		y = BOMB_SPOWNUPY;
	}

	if (direction == DIRECTIONDOWN)			//下
	{
		x = BOMB_SPOWNUPDOWNX;
		y = BOMB_SPOWNDOWNY;
	}
}

BaseBomb::~BaseBomb() 
{
	
}

//爆弾生成
void BaseBomb::SpawnBomb() 
{
	isSpown = true;
}

//爆弾落下
void BaseBomb::Move()
{
	
	SpawnBomb();				//爆弾生成

	if (direction == DIRECTIONLEFT)			//左
	{
		y += speed;
		if (y > BOMB_SPOWNLR + 356)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONRIGHT)		//右
	{
		y += speed;
		if (y > BOMB_SPOWNLR + 356)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONUP)			//上
	{
		y += speed;
		if (y > BOMB_SPOWNUPY + 264)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONDOWN)			//下
	{
		y -= speed;
		if (y < BOMB_SPOWNDOWNY - 264)
		{
			speed = 0;
		}
	}	
}

//爆弾起動
void BaseBomb::JudgeTrigger()
{
	if (speed == 0)
	{
		DrawFormatString(10, 150, GetColor(255, 255, 255), "制限時間%d", countdown / FRAME);	//表示
		if (countdown <= FRAME) {								//残り一秒以下は割り算の結果0になるため、表示タイミングの調整
			finishxplosion = true;							//フラグ切替
		}
		if (countdown >= 0) {									//表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
			countdown -= 1;							//カウントダウン
		}
	}

	if (finishxplosion == true)
	{
		DrawString(700, 300, "爆発", GetColor(255, 255, 255));
		isTrigger = true;
	}
}

//爆発時のダメージ
/*void BaseBomb::Damage(int _damage)
{
	if (isTrigger == true) 
	{
		if (BombType == Bomb) 
		{
			damage= _damage;
			DrawFormatString(700, 170, GetColor(255, 255, 255), "%d", damage);
			DrawString(700, 350, "本物", GetColor(255, 255, 255));
		}

		if (BombType == fakeBomb)
		{
			damage = _damage;
			DrawFormatString(700, 170, GetColor(255, 255, 255), "%d", damage);
			DrawString(700, 350, "偽物", GetColor(255, 255, 255));
		}
	}
}*/

//更新
/*void BaseBomb::Update()
{
	Move();
	JudgeTrigger();
	Damage(damage);
}*/

//描画
/*void BaseBomb::Draw() 
{
	if (isSpown == true)
	{
		DrawCircle(x, y, 10, GetColor(255, 0, 0), TRUE);
		//DrawFormatString(700, 170, GetColor(255, 255, 255), "%f", y);
	}
}*/

