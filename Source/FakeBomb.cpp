#include <DxLib.h>
#include "FakeBomb.h"
#include "Image.h"

//コンストラクタ
FakeBomb::FakeBomb(int _power, float _speed, eBombType _bombType)
	: BaseBomb(_power, _speed, _bombType)
{
	isFakeAction = false;
	AnimationFlg = false;
};

//偽爆発したときの処理
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

//更新
void FakeBomb::Update(BasePlayer* player)
{
	pType = player->Get_AbilityType();		//プレイヤタイプを受け取る

	isPAbility = player->Get_isAbility();	//時止めの発動してるかを受け取る

	if (isHit == true)						//プレイヤーと当たったら
	{
		isSpawn = false;
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

		if (isPAbility == false)		//咲夜さんのスキルが発動してなかったら動く
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

//描画
void FakeBomb::Draw()
{

	if (isSpawn == true)			//生成開始
	{
		DrawGraphF(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Bomb, 1), TRUE);
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
		isFakeAction = false;
		Animation();
	}
}

//アニメーション
void FakeBomb::Animation()
{
	m_frameIndex++;

	if (fake_Animation[m_frameIndex] == 0)
	{
		DrawGraphF(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_FakeBomb, 0), TRUE);
	}

	if (fake_Animation[m_frameIndex] == 1)
	{
		DrawGraphF(x, y - 10.0f, Image::Instance()->GetGraph(eImageType::Gpicture_FakeBomb, 1), TRUE);
	}
	if (fake_Animation[m_frameIndex] == 2)
	{
		DrawGraphF(x, y - 30.0f, Image::Instance()->GetGraph(eImageType::Gpicture_FakeBomb, 2), TRUE);
	}

	//アニメーション終了
	if (fake_Animation[m_frameIndex] == 3)
	{
		AnimationFlg = false;
		isActive = false;
		m_frameIndex--;
	}
}