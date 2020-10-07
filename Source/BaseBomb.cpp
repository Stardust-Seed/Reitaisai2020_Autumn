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
	
	countDown = COUNTMAX;						//カウントダウンのセット
	
	isActive = true;
	isSpown = false;
	isXplosion = false;							//初期状態
	isTrigger = false;

	if (direction == DIRECTIONLEFT)			//左
	{
		x = BOMB_SPOWNLEFTHX;
		y = BOMB_SPOWNLEFTY;
	}

	if (direction == DIRECTIONRIGHT)		//右
	{
		x = BOMB_SPOWNRIGHTX;
		y = BOMB_SPOWNRIGHTY;
	}

	if (direction == DIRECTIONUP)			//上
	{
		x = BOMB_SPOWNUPX;
		y = BOMB_SPOWNUPY;
	}

	if (direction == DIRECTIONDOWN)			//下
	{
		x = BOMB_SPOWNDOWNX;
		y = BOMB_SPOWNDOWNY;
	}

	cx = x + (width / 2);
	cy = y + (height / 2);

	width = 50;
	height = 50;
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
		y++;
		if (y == GAME_WIDTH / 2 - 450)
		{
			y --;
		}
		x += speed;
		if (x > BOMB_SPOWNLEFTHX + 920)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONRIGHT)		//右
	{
		y--;

		if (y == GAME_HEIHGT / 2)
		{
			y++;
		}

		x -= speed;

		if (x < BOMB_SPOWNRIGHTX - 980)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONUP)			//上
	{
		x++;
		if (x == GAME_WIDTH / 2 - 25)
		{
			x--;
		}
	
		y += speed;
		if (y > BOMB_SPOWNUPY + 455)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONDOWN)			//下
	{
		x--;
		if (x == GAME_WIDTH / 2 - 25)
		{
			x++;
		}
		y -= speed;
		if (y < BOMB_SPOWNDOWNY - 675)
		{
			speed = 0;
		}
	}
}

//爆弾起動
void BaseBomb::JudgeTrigger()
{
	//爆弾のタイマー
	if (speed == 0 && isPAbility == false)
	{
		isCount = true;


		if (isCount == true)
		{
			//カウントダウン
			DrawFormatStringToHandle(x + 5, y - 50, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "%d", countDown / FRAME);
			if (countDown <= FRAME)
			{
				isXplosion = true;                        //フラグ切替
			}

			if (countDown >= 0)
			{											//表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
				countDown -= 1;							//カウントダウン
			}
		}


		if (type == bomb && isXplosion == true)						//爆発する
		{
			SE::Instance()->PlaySE(SE_bomb);		 //爆発のSEが出る
			isCount = false;
			isTrigger = true;
			isXplosion = false;
			isSpown = false;

		}

		if (type == fakebomb && isXplosion == true)						//爆発する
		{
			isCount = false;
			isTrigger = true;
			isXplosion = false;
			isSpown = false;
		}
	}

	if (AnimationFlg == true)
	{
		SE::Instance()->StopSE(SE_bomb);
	}
}

void BaseBomb::SkillStop()
{
	if (pType == SAKUYA_Ability)
	{
		
		if (isPAbility == true)
		{
			isStopCount = true;

			sTime = countDown / FRAME;
    		
			if (speed == 0)
			{
				DrawFormatStringToHandle(x + 5, y - 50, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "%d", sTime);
			}
		}
	}
}


//当たり判定
bool BaseBomb::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{
	if (x + width >= ox && x <= ox + ow &&
		y + height >= oy && y <= oy + oh)
	{
		isHit = true;
		isStopCount = false;
	}
	else
	{
		isHit = false;
	}
	return isHit;
}



