#include <DxLib.h>
#include "FakeBomb.h"

FakeBomb::FakeBomb(int _power, int _speed, eBombType _bombType)
	: BaseBomb(_power, _speed, _bombType)
{
	fBomb = LoadGraph("res/Image/bomb.png");
	fAction = LoadGraph("res/Image/fake.png");
	isFakeAction = false;
};

//”š”­‚µ‚½‚Æ‚«‚Ìˆ—
void FakeBomb::FakeMotion()
{
	//‹U”š’e‚ª‹N“®
	if (isTrigger == true)
	{
		isFakeAction = true;
		if (isFakeAction == true)
		{
			DrawGraph(x, y, fAction, TRUE);
			isTrigger = false;
			isFakeAction = false;
		}

		if (isFakeAction == false)
		{
			DeleteGraph(fAction);
		}

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
		//DrawString(700, 370, "‹U•¨", GetColor(255, 255, 255));
		DrawGraph(x, y, fBomb, TRUE);
	}
}