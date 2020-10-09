#include <DxLib.h>
#include "Bomb.h"
#include "Image.h"

//コンストラクタ
Bomb::Bomb(int _power, float _speed, eBombType _bombType)
	: BaseBomb(_power, _speed, _bombType)
{
	AnimationFlg = false;
};

//爆発したときの処理
void Bomb::DamageMotion()
{
	if (isTrigger == true)		//爆破してる状態
	{
		AnimationFlg = true;
		isTrigger = false;
	}
}

//更新
void Bomb::Update(BasePlayer* player)
{
	pType = player->Get_AbilityType();			//プレイヤタイプを受け取る

	isPAbility = player->Get_isAbility();		//時止めの発動してるかを受け取る

	//プレイヤーに当たったら消える
	if (isHit == true)
	{
		isSpawn = false;
		isCount = false;
		isTrigger = false;
		isXplosion = false;
		isActive = false;
	}
	//プレイヤーに当たってないとき
	else
	{
		if (type == bomb)
		{
			SpawnBomb();
		}

		if (isPAbility == false)		//スキルが発動してないとき
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

//描画
void Bomb::Draw()
{
	if (isSpawn == true)			//生成開始
	{
		DrawGraphF(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Bomb, 0), TRUE);
	}

	if (isCount == true)			//通常カウント
	{
		JudgeTrigger();
	}

	if (isStopCount == true)		//時止めカウント
	{
		SkillStop();
	}

	if (AnimationFlg == true)		//アニメーション開始
	{
		Animation();
	}
}

//アニメーション
void Bomb::Animation()
{
	m_frameIndex++;

	if (bomb_Animation[m_frameIndex] == 0)
	{
		DrawGraphF(x - 20.0f, y - 20.0f, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 0), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 1)
	{
		DrawGraphF(x - 20.0f, y - 20.0f, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 1), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 2)
	{
		DrawGraphF(x - 20.0f, y - 20.0f, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 2), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 3)
	{
		DrawGraphF(x - 20.0f, y - 20.0f, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 3), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 4)
	{
		DrawGraphF(x - 20.0f, y - 20.0f, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 4), TRUE);
	}

	if (bomb_Animation[m_frameIndex] == 5)
	{
		DrawGraphF(x - 20.0f, y - 20.0f, Image::Instance()->GetGraph(eImageType::Gpicture_Explosion, 5), TRUE);
	}

	//爆破アニメーション終了
	if (bomb_Animation[m_frameIndex] == 6)
	{
		AnimationFlg = false;
		isActive = false;
		m_frameIndex--;
	}
}
