#include <DxLib.h>
#include "Bomb.h"

Bomb::Bomb()
	: BaseBomb()
{
	gBomb = LoadGraph("res/Image/bomb.png");
	LoadDivGraph("res/Image/ex.png", 6, 6, 1, 98, 100, GHandle);
};

//îöî≠ÇµÇΩÇ∆Ç´ÇÃèàóù
void Bomb::DamageMotion()
{
	if (isTrigger == true)
	{
		damage = BOMBDAMAGE; 
		
		//DrawFormatString(700, 170, GetColor(255, 255, 255), "%d", damage);
		//DrawString(700, 350, "ñ{ï®", GetColor(255, 255, 255));
		m_frameIndex++;
		m_frameIndex %= 12;

		int motion_bomb = act_frameIndex[m_frameIndex];
		DrawGraph(x, y, GHandle[motion_bomb], TRUE);
		DeleteGraph(GHandle[motion_bomb]);
		isTrigger = false;
	}
}

void Bomb::Update()
{
	if (type == bomb)
	{
		SpawnBomb();
	}
	Move();
	JudgeTrigger();
	DamageMotion();
}

void Bomb::Draw()
{
	if (isSpown == true)
	{
		DrawGraph(x, y, gBomb, TRUE);
	}
}


