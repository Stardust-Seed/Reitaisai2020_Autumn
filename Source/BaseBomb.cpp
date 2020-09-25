#include <DxLib.h>
#include "BaseBomb.h"

//コンストラクタ
BaseBomb::BaseBomb(int _power, eBombType _btype)
{
	//SRand;								//乱数の初期化
	//type = GetRand(MAX_TYPE - 1);		//種類の乱数
	type = bomb;
	if (type == bomb)
	{
		power = _power;
	}

	if (type == fakebomb)
	{
		power = _power;
	}
	
	
	direction = GetRand(3);					//方向の乱数
	//direction = 3;
	speed = 3;
	countdown = COUNTMAX;						//カウントダウンのセット
	
	isSpown = false;
	isFakeSpown = false;
	isXplosion = false;							//初期状態
	isTrigger = false;
	isFakeTrigger = false;

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

	//DrawFormatString(10, 300, GetColor(255, 255, 255), "type%d", type);
	
	//DrawFormatString(10, 300, GetColor(255, 255, 255), "type%d", power);

	//真
	if (type == bomb)
	{
		isSpown = true;
	}

	//偽
	if (type == fakebomb)
	{
		isFakeSpown = true;
	}

}

//爆弾落下
void BaseBomb::Move()
{
	if (direction == DIRECTIONLEFT)			//左
	{
		y += speed;
		if (y > BOMB_SPOWNLR + 540)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONRIGHT)		//右
	{
		y += speed;
		if (y > BOMB_SPOWNLR + 540)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONUP)			//上
	{
		y += speed;
		if (y > BOMB_SPOWNUPY + 455)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONDOWN)			//下
	{
		y -= speed;
		if (y < BOMB_SPOWNDOWNY - 495)
		{
			speed = 0;
		}
	}	
}

//爆弾起動
void BaseBomb::JudgeTrigger()
{
	//爆弾のタイマー
	if (speed == 0)
	{
		DrawFormatString(10, 150, GetColor(255, 255, 255), "%d", countdown / FRAME);	//表示
		if (countdown <= FRAME) {								//残り一秒以下は割り算の結果0になるため、表示タイミングの調整
			isXplosion = true;									//フラグ切替
		}

		if (countdown >= 0) {									//表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
			countdown -= 1;										//カウントダウン
		}
	}

	if (type == bomb)
	{
		if (isXplosion == true)			//爆発する
		{
			//DrawString(700, 300, "爆発", GetColor(255, 255, 255));
			isTrigger = true;
			isXplosion = false;
			isSpown = false;
		}
	}

	if (type == fakebomb)
	{
		if (isXplosion == true)			//爆発する
		{
			//DrawString(600, 300, "偽爆発", GetColor(255, 255, 255));
			isFakeTrigger = true;
			isXplosion = false;
			isFakeSpown = false;
		}
	}
}


