#include <DxLib.h>
#include "Bomb.h"
#include "Image.h"
Bomb::Bomb(int _power, int _speed, eBombType _bombType)
	: BaseBomb(_power, _speed, _bombType)
{
	
};

//”š”­‚µ‚½‚Æ‚«‚Ìˆ—
void Bomb::DamageMotion()
{
	if (isTrigger == true)
	{ 
		Animation();
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
		DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Bomb, 0), TRUE);
	}
}

void Bomb::Animation()
{
	m_frameIndex++;

	if (act_frameIndex[m_frameIndex] == 0)
	{
		DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 0), TRUE);
	}

	if (act_frameIndex[m_frameIndex] == 1)
	{
		DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 1), TRUE);
	}

	if (act_frameIndex[m_frameIndex] == 2)
	{
		DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 2), TRUE);
	}

	if (act_frameIndex[m_frameIndex] == 3)
	{
		DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 3), TRUE);
	}

	if (act_frameIndex[m_frameIndex] == 4)
	{
		DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 4), TRUE);
	}

	if (act_frameIndex[m_frameIndex] == 5)
	{
		DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 5), TRUE);

		DeleteGraph(Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 0));
		DeleteGraph(Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 1));
		DeleteGraph(Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 2));
		DeleteGraph(Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 3));
		DeleteGraph(Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 4));
		DeleteGraph(Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 5));
	}
}
