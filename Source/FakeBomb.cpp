#include <DxLib.h>
#include "FakeBomb.h"

FakeBomb::FakeBomb(int _power, eBombType _btype)
	: BaseBomb(_power, _btype)
{
	fBomb = LoadGraph("res/Image/bomb.png");
	fAction = LoadGraph("res/Image/fake.png");
	_power = 0;
	isFakeAction = false;
};

//”š”­‚µ‚½‚Æ‚«‚Ìˆ—
void FakeBomb::FakeMotion()
{
	//‹U”š’e‚ª‹N“®
	if (isFakeTrigger == true)
	{
		isFakeAction = true;
		if (isFakeAction == true)
		{
			DrawGraph(x, y + 400, fAction, TRUE);
			isFakeTrigger = false;
			isFakeAction = false;
		}

		if (isFakeAction == false)
		{
			DeleteGraph(fAction);
		}

		power = 0;
		//DrawFormatString(700, 190, GetColor(255, 255, 255), "%d", damage);
		//DrawString(700, 370, "‹U•¨", GetColor(255, 255, 255));
	}
}

void FakeBomb::Update() 
{
	if (type == fakebomb)
	{
		SpawnBomb();
	}
	Move();
	JudgeTrigger();
	FakeMotion();
}

void FakeBomb::Draw() 
{
	if (isFakeSpown == true)
	{
		DrawGraph(x, y, fBomb, TRUE);
	}
}