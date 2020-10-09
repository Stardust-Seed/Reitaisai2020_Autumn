#include <DxLib.h>
#include "BaseBomb.h"

//コンストラクタ
BaseBomb::BaseBomb(int _power, float _speed, eBombType _bombType)
{
	speed = _speed;
	power = _power;
	type = _bombType;

	direction = GetRand(3);					//方向の乱数
	
	countDown = COUNTMAX;					//カウントダウンのセット
	
	isActive = true;						//初期状態
	isSpawn = false;
	isXplosion = false;	
	isTrigger = false;
	isCount = false;
	isStopCount = false;
	isHit = false;
	isPAbility = false;
	AnimationFlg = false;

	if (direction == DIRECTIONLEFT)			//斜め左
	{
		x = BOMB_SPOWNLEFTHX;
		y = BOMB_SPOWNLEFTY;
	}

	if (direction == DIRECTIONRIGHT)		//斜め右
	{
		x = BOMB_SPOWNRIGHTX;
		y = BOMB_SPOWNRIGHTY;
	}

	if (direction == DIRECTIONUP)			//斜め上
	{
		x = BOMB_SPOWNUPX;
		y = BOMB_SPOWNUPY;
	}

	if (direction == DIRECTIONDOWN)			//斜め下
	{
		x = BOMB_SPOWNDOWNX;
		y = BOMB_SPOWNDOWNY;
	}

	cx = x + (width / 2);					//中心x
	cy = y + (height / 2);					//中心y

	width = 50.0f;							//幅
	height = 50.0f;							//高さ
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
		isSpawn = true;
	}

	//偽
	if (type == fakebomb)
	{
		isSpawn = true;
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

		//カウント開始
		if (isCount == true)
		{
			//カウントダウン
			DrawFormatStringToHandle(x + 5.0f, y - 50.0f, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "%d", countDown / FRAME);
			if (countDown <= FRAME)
			{
				isXplosion = true;							//フラグ切替
			}

			if (countDown >= 0)
			{												//表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
				countDown -= 1;								//カウントダウン
			}
		}


		if (type == bomb && isXplosion == true)				//爆発する
		{
			SE::Instance()->PlaySE(SE_bomb);				//爆発のSEが出る
			isCount = false;
			isTrigger = true;
			isXplosion = false;
			isSpawn = false;
		}

		if (type == fakebomb && isXplosion == true)			//爆発する
		{
			SE::Instance()->PlaySE(SE_Fake);				//爆破失敗のSE
			isCount = false;
			isTrigger = true;
			isXplosion = false;
			isSpawn = false;
		}
	}

	//アニメーション開始時にSE止める
	if (AnimationFlg == true)
	{
		SE::Instance()->StopSE(SE_bomb);
		SE::Instance()->StopSE(SE_Fake);
	}
}

//時止め処理
void BaseBomb::SkillStop()
{
	if (pType == SAKUYA_Ability)
	{
		
		if (isPAbility == true && speed == 0)
		{
			isStopCount = true;
			tX = x + 5;
			tY = y - 50;
			sTime = countDown / FRAME;		//時止め時に現在のカウントダウンを変数に入れる
    		
			DrawFormatStringToHandle(tX, tY, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "%d", sTime);
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



