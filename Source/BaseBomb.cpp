#include <DxLib.h>
#include "BaseBomb.h"

//コンストラクタ
BaseBomb::BaseBomb()
{
	direction = GetRand(3);
	speed = 3;
	countdown = COUNTMAX;						//カウントダウンのセット

	isXplosion = false;							//初期状態
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
			isXplosion = true;									//フラグ切替
		}
		if (countdown >= 0) {									//表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
			countdown -= 1;										//カウントダウン
		}
	}

	if (isXplosion == true)
	{
		DrawString(700, 300, "爆発", GetColor(255, 255, 255));
		isTrigger = true;
	}
}

