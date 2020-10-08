#include <DxLib.h>
#include "Bomb.h"
#include "Image.h"

Bomb::Bomb(int _power, int _speed, eBombType _bombType)
	: BaseBomb(_power, _speed, _bombType)
{
	AnimationFlg = false;
};

//爆発したときの処理
void Bomb::DamageMotion()
{
	if (isTrigger == true)
	{
		AnimationFlg = true;
		isTrigger = false;
	}
}

void Bomb::Update(BasePlayer* player)
{
	pType = player->Get_AbilityType();

	isPAbility = player->Get_isAbility();

	//プレイヤーに当たったら消える
	if (isHit == true)
	{
		isSpawn = false;
		isCount = false;
		isTrigger = false;
		isXplosion = false;
		isActive = false;
	}
	else
	{
		if (type == bomb)
		{
			SpawnBomb();
		}

		if (isPAbility == false)
		{
			Move();
		}

		JudgeTrigger();
		SkillStop();
		DamageMotion();

		//当たり判定
		ClisionHit(x, y, width, height,
			player->Get_x(), player->Get_y(),
			player->Get_width(), player->Get_height());
	}
}

void Bomb::Draw()
{
	if (isSpawn == true)
	{
		DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Bomb, 0), TRUE);
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
		Animation();
	}
}

void Bomb::Animation()
{
	m_frameIndex++;
	if (bomb_Animation[m_frameIndex] == 0)
	{
		DrawGraph(x -20, y - 20, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 0), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 1)
	{
		DrawGraph(x - 20, y - 20, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 1), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 2)
	{
		DrawGraph(x - 20, y - 20, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 2), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 3)
	{
		DrawGraph(x - 20, y - 20, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 3), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 4)
	{
		DrawGraph(x - 20, y - 20, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 4), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 5)
	{
		DrawGraph(x - 20, y - 20, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 5), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 6)
	{
		AnimationFlg = false;
		isActive = false;
		m_frameIndex--;
	}
}
