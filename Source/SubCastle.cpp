#include "DxLib.h"
#include "SubCastle.h"
#include "EnemyManager.h"

//コンストラクタ
SubCastle::SubCastle(int _durability,int _type)
	:BaseCastle(_durability) {
	durability = _durability;

	width =  48;
	height = 48;
	addPosX = 0;
	addPosY = 0;
	addSize = 12;

	int posType = GetRand(1);

	//座標設定
	switch (_type)
	{
	case 1:    //左側

		x = GAME_WIDTH / 2 - width / 2 - 225 - GetRand(30);
		y = GAME_HEIHGT / 2 - height / 2;

		if (posType == 0)    //上
		{
			addPosX = -32;
			addPosY = -65;
		}
		else                 //下
		{
			addPosX = -32;
			addPosY = 53;
		}

		direction = eDirection::Left;

		break;

	case 2:    //右側

		x = GAME_WIDTH / 2 - width / 2 + 225 + GetRand(30);
		y = GAME_HEIHGT / 2 - height / 2;

		if (posType == 0)    //上
		{
			addPosX = 32;
			addPosY = -65;
		}
		else                 //下
		{
			addPosX = 32;
			addPosY = 53;
		}

		direction = eDirection::Right;



		break;

	case 3:    //上側

		x = GAME_WIDTH / 2 - width / 2;
		y = GAME_HEIHGT / 2 - height / 2 - 225 - GetRand(30);

		if (posType == 0)    //左
		{
			addPosY = -32;
			addPosX = -54;
		}
		else                 //右
		{
			addPosY = -32;
			addPosX = 55;
		}

		direction = eDirection::Up;

		break;

	case 4:    //下側

		x = GAME_WIDTH / 2 - width / 2;
		y = GAME_HEIHGT / 2 - height / 2 + 225 + GetRand(30);

		if (posType == 0)    //左
		{
			addPosY = 32;
			addPosX = -54;
		}
		else                 //右
		{
			addPosY = 32;
			addPosX = 55;
		}

		direction = eDirection::Down;

		break;

	default:
		break;
	}
}

void SubCastle::Update(EnemyManager* enemy)
{
	for (int num = 0; num < enemy->Get_enemyNum(); num++)
	{
		if (enemy->Get_ActiveFlg(num) == true && enemy->Get_AttackFlg(num) == true  &&
			enemy->Get_AttackType(num) != eAttackType::Player)
		{
			ClisionHit(enemy->Get_x(num),		  enemy->Get_y(num)         , enemy->Get_width(num),
				       enemy->Get_height(num),    enemy->Get_Power(num)     , num,
				       enemy->Get_AttackFlg(num), enemy->Get_ActiveFlg(num));
		}
	}

	//一回だけ処理する用のフラグ処理
	if (isHit == true)
	{
		isHit = false;
	}

	//耐久の処理
	if (durability <= 0)
	{
		isActive = false;
	}
}

void SubCastle::Draw()
{
	//適当に表示
	if (isActive == true)
	{
		DrawGraphF(x + addPosX - addSize / 2, y + addPosY - addSize / 2,
		Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 0), TRUE);
	}
	else
	{
		DrawGraphF(x + addPosX - addSize / 2, y + addPosY - addSize / 2,
		Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 1), TRUE);
	}

}


