#include <DxLib.h>
#include "FakeBomb.h"

FakeBomb::FakeBomb()
	: BaseBomb()
{
	
};

void FakeBomb::FakeMotion()
{
	if (isTrigger == true)
	{
		damage = 0;
		DrawFormatString(700, 190, GetColor(255, 255, 255), "%d", damage);
		DrawString(700, 370, "‹U•¨", GetColor(255, 255, 255));
	}
}

void FakeBomb::Update() 
{
	Move();
	JudgeTrigger();
	FakeMotion();
}

void FakeBomb::Draw() 
{
	if (isSpown == true)
	{
		DrawCircle(x, y, 10, GetColor(0, 0, 255), TRUE);
	}
}