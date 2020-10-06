#include <DxLib.h>
#include "FakeBomb.h"
#include "Image.h"

FakeBomb::FakeBomb(int _power, int _speed, eBombType _bombType)
	: BaseBomb(_power, _speed, _bombType)
{
	isFakeAction = false;
	AnimationFlg = false;
};

//爆発したときの処理
void FakeBomb::FakeMotion()
{
	//偽爆弾が起動
	if (isTrigger == true)
	{
		isFakeAction = true;
		if (isFakeAction == true)
		{
			isTrigger = false;
			AnimationFlg = true;
		}
	}
}

void FakeBomb::Update(BasePlayer* player)
{
	pType = player->Get_AbilityType();

	isPAbility = player->Get_isAbility();

	if (isHit == true)
	{
		isSpown = false;
		isCount = false;
		isTrigger = false;
		isXplosion = false;
		isActive = false;
	}
	else
	{
		if (type == fakebomb)
		{
			SpawnBomb();
		}

		if (isPAbility == false)
		{
			Move();
		}


		JudgeTrigger();
		SkillStop();
		FakeMotion();

		//当たり判定
		ClisionHit(x, y, width, height,
			player->Get_x(), player->Get_y(),
			player->Get_width(), player->Get_height());
	}
}

void FakeBomb::Draw()
{

	if (isSpown == true)
	{
		DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Bomb, 1), TRUE);
	}

	if (isCount == true)
	{
		JudgeTrigger();
	}

	if (isStopCount == true)
	{
		SkillStop();
	}

	if (AnimationFlg == true)
	{
		isFakeAction = false;
		Animation();
	}
}

void FakeBomb::Animation()
{
	m_frameIndex++;
	m_frameIndex %= 18;

	if (fake_Animation[m_frameIndex] == 0)
	{
		DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_FakeBomb, 0), TRUE);
	}

	if (fake_Animation[m_frameIndex] == 1)
	{
		DrawGraph(x, y - 10, Image::Instance()->GetGraph(eImageType::Gpicture_FakeBomb, 1), TRUE);
	}
	if (fake_Animation[m_frameIndex] == 2)
	{
		DrawGraph(x, y - 30, Image::Instance()->GetGraph(eImageType::Gpicture_FakeBomb, 2), TRUE);
	}

	if (fake_Animation[m_frameIndex] == 3)
	{
		AnimationFlg = false;
		isActive = false;
		m_frameIndex--;
	}
}