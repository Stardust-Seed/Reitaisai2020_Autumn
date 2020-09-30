#include <DxLib.h>
#include "BaseBomb.h"

//コンストラクタ
BaseBomb::BaseBomb(int _power, int _speed, eBombType _bombType)
{
	SRand;
	speed = _speed;
	power = _power;
	type = _bombType;
	
	direction = GetRand(3);					//方向の乱数
	countdown = COUNTMAX;						//カウントダウンのセット
	
	isSpown = false;
	isXplosion = false;							//初期状態
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
	//真
	if (type == bomb)
	{
		isSpown = true;
	}

	//偽
	if (type == fakebomb)
	{
		isSpown = true;
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
		isCount = true;
		if (isCount == true)
		{
			//カウントダウン
			DrawFormatStringToHandle(x + 5, y - 50, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_3(), "%d", countdown / FRAME);
			
			if (countdown <= FRAME)
			{								//残り一秒以下は割り算の結果0になるため、表示タイミングの調整
				isXplosion = true;                                  //フラグ切替
			}

			if (countdown >= 0)
			{									//表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
				countdown -= 1;										//カウントダウン
			}
		}

		if (type == bomb)
		{
			if (isXplosion == true)			//爆発する
			{
				//SE::Instance()->PlaySE(SE_bomb);		//爆発の音
				isCount = false;
				isTrigger = true;
				isXplosion = false;
				isSpown = false;
			}
		}
	}

		if (type == fakebomb)
		{
			if (isXplosion == true)			//爆発する
			{
				//SE::Instance()->PlaySE(SE_bomb);		//爆発の音
				isTrigger = true;
				isXplosion = false;
				isCount = false;
				isSpown = false;
			}
		}

		if (isCount == false)
		{
			InitFontToHandle();
		}
}



