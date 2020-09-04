#include <DxLib.h>
#include "BaseBomb.h"

//コンストラクタ
BaseBomb::BaseBomb(float _speed, int _damage, int _direction, int _countdown)
{
	speed = _speed;
	speed = 10;
	damage = _damage;
	direction = _direction;
	countdown = _countdown;

	isSpown = true;
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

/*void BaseBomb::SpawnBomb() 
{
	bool isSpawn = false;    //生成判定フラグ

	for (int i = 0; i < 1; i++) {
		//items[i]が空の場合
		if (bombs[i] == null) {
			int spawnPercent = GetRand(100);    //生成確率

			//50以下の場合生成判定フラグをtrueにする
			if (spawnPercent > 50) {
				isSpawn = true;
			}

			//生成判定フラグがtrueの場合
			if (isSpawn == true) {
				int spawnType = GetRand(1); 


				if (spawnType == static_cast<int>(eBombType::Bomb)) {
					bombs[i] = new Bomb(_ex, _ey, 48, 48, eBombType::Bomb);
				}

				
				if (spawnType == static_cast<int>(eBombType::fakeBomb)) {
					bombs[i] = new fakeBomb(_ex, _ey, 48, 48, eBombType::fakeBomb);
				}
			}

			break;
		}
	}
}*/

void BaseBomb::JudgeTrigger()
{
	countdown = 10;
	if (countdown > 0)
	{
		isTrigger = false;
	}
	if (countdown == 0)
	{
		DrawString(700, 100, "爆発", GetColor(255, 255, 255));
		isTrigger = true;
	}
}

//爆発時のダメージ
void BaseBomb::Damage(int _damage)
{
	BombType = 0;

	if (isTrigger == true) {
		if (BombType == Bomb) {
			damage = _damage;
		}

		if (BombType == fakeBomb)
		{
			damage = _damage;
		}
	}
}


void BaseBomb::Move()
{
	if (isSpown == false) {
		return;
	}

	if (direction == DIRECTIONLEFT)			//左
	{		
		y += speed;
	}

	if (direction == DIRECTIONRIGHT)		//右
	{
		y += speed;
	}

	if (direction == DIRECTIONUP)			//上
	{
		y += speed;
	}

	if (direction == DIRECTIONDOWN)			//下
	{
		y += speed;
	}
}

void BaseBomb::Draw() 
{
	DrawCircle(x, y, 5, GetColor(255, 0, 0), TRUE);
}

