#include <DxLib.h>
#include "FakeBomb.h"
#include "Image.h"

FakeBomb::FakeBomb(int _power, int _speed, eBombType _bombType)
	: BaseBomb(_power, _speed, _bombType)
{
	isFakeAction = false;
};

//”š”­‚µ‚½‚Æ‚«‚Ìˆ—
void FakeBomb::FakeMotion()
{
	//‹U”š’e‚ª‹N“®
	if (isTrigger == true)
	{
		damage -= power;
		isFakeAction = true;
		if (isFakeAction == true)
		{
			AnimationFlg = true;
			if (AnimationFlg == true)
			{
				Animation();
			}
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
	if (isSpown == true)
	{
		DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Bomb, 1), TRUE);
	}
}

void FakeBomb::Animation()
{
	m_frameIndex++;

	if (act_frameIndex[m_frameIndex] == 0)
	{
		DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_fake, 0), TRUE);
	}

	if (act_frameIndex[m_frameIndex] == 1)
	{
		DrawGraph(x, y - 30, Image::Instance()->GetGraph(eImageType::Gpicture_fake, 1), TRUE);		
	}
	if (act_frameIndex[m_frameIndex] == 2)
	{
		DrawGraph(x, y -50, Image::Instance()->GetGraph(eImageType::Gpicture_fake, 2), TRUE);
	}

	if (act_frameIndex[m_frameIndex] == 3)
	{
		AnimationFlg = false;
		m_frameIndex = 0;
	}
}