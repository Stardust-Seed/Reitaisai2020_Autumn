#include <DxLib.h>
#include "SubCastle.h"
#include "EnemyManager.h"

//コンストラクタ
SubCastle::SubCastle(int _durability,int _type)
	:BaseCastle(_durability) {
	durability = _durability;
	SRand;					//乱数初期化

	width =  60;
	height = width;

	//座標設定
	switch (_type)
	{
	case 1:    //左側
		//右か左か(上か下か)
		posType = GetRand(1);
		x = 250 + GetRand(50) - width;

		if (posType == 0)    //上
		{
			y = 360 - height;
		}
		else                 //下
		{
			y = 348 + height;
		}
		direction = eDirection::Left;

		break;

	case 2:    //右側
		//右か左か(上か下か)
		posType = GetRand(1);
		x = 800 + GetRand(50) - width;

		if (posType == 0)    //上
		{
			y = 360 - height;
		}
		else                 //下
		{
			y = 348 + height;
		}
		direction = eDirection::Right;

		break;

	case 3:    //上側
		//右か左か(上か下か)
		posType = GetRand(1);
		if (posType == 0)    //上
		{
			x = 490 - width;
		}
		else                 //下
		{
			x = 475 + width;
		}

		y = 175 + GetRand(75) - height;
		direction = eDirection::Up;

		break;

	case 4:    //下側
		//右か左か(上か下か)
		posType = GetRand(1);
		if (posType == 0)    //上
		{
			x = 490 - width;
		}
		else                 //下
		{
			x = 475 + width;
		}

		y = 575 + GetRand(75) - height;
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
		if (enemy->Get_ActiveFlg(num) == true)
		{
			ClisionHit(enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num),
				enemy->Get_height(num), enemy->Get_Power(num), num,
				enemy->Get_AttackFlg(num), enemy->Get_ActiveFlg(num));
		}

		if (isHit == true)
		{
			enemy->Set_IsAttack(num, false);
			enemy->Set_IsActive(num, false);
		}
	}
}

void SubCastle::Draw()
{
	//適当に表示
	if (isActive == true)
	{
		DrawBox(x, y, x + width, y + height, GetColor(0, 0, 128), true);
	}
	else
	{
		DrawBox(x, y, x + width, y + height, GetColor(128, 0, 0), true);
	}
}


