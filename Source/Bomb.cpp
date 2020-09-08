#include <DxLib.h>
#include "Bomb.h"

Bomb::Bomb()
	: BaseBomb()
{
	
};

void Bomb::DamageMotion()
{
	
	if (isTrigger == true)
	{
		damage = BOMBDAMAGE;
		DrawFormatString(700, 170, GetColor(255, 255, 255), "%d", damage);
		DrawString(700, 350, "–{•¨", GetColor(255, 255, 255));

	}
}

void Bomb::Update()
{
	SpawnBomb();
	Move();
	JudgeTrigger();
	DamageMotion();
}

void Bomb::Draw()
{
	if (isSpown == true)
	{
		DrawCircle(x, y, 10, GetColor(255, 0, 0), TRUE);
	}
}


