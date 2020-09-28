#include <DxLib.h>
#include "FakeBomb.h"

FakeBomb::FakeBomb(int _power, int _speed, eBombType _bombType)
	: BaseBomb(_power, _speed, _bombType)
{
	fBomb = LoadGraph("res/Image/fakebomb.png");
	//fAction = LoadGraph("res/Image/fake.png");
	LoadDivGraph("res/Image/smog.png", 3, 3, 1, 50, 50, GHandle);
	isFakeAction = false;
};

//îöî≠ÇµÇΩÇ∆Ç´ÇÃèàóù
void FakeBomb::FakeMotion()
{
	//ãUîöíeÇ™ãNìÆ
	if (isTrigger == true)
	{
		isFakeAction = true;
		if (isFakeAction == true)
		{
			//DrawGraph(x, y, fAction, TRUE);
			Animation();
			isTrigger = false;
			isFakeAction = false;
		}

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
		//DrawString(700, 370, "ãUï®", GetColor(255, 255, 255));
		DrawGraph(x, y, fBomb, TRUE);
	}
}

void FakeBomb::Animation()
{
	m_frameIndex++;

	if (act_frameIndex[m_frameIndex] == 0)
	{
		DrawGraph(x, y, GHandle[0], TRUE);
		DeleteGraph(GHandle[0]);
	}

	if (act_frameIndex[m_frameIndex] == 1)
	{
		DrawGraph(x, y , GHandle[1], TRUE);
			
		DeleteGraph(GHandle[1]);
			
	}

	if (act_frameIndex[m_frameIndex] == 2)
	{

		DrawGraph(x, y + 5, GHandle[2], TRUE);
		DeleteGraph(GHandle[2]);
	}
}