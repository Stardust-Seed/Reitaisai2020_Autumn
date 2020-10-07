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
	addSize = 8;

	int posType = GetRand(1);

	//座標設定
	switch (_type)
	{
	case 1:    //左側

		//座標設定
		x = GAME_WIDTH / 2 - width / 2 - 225 - GetRand(30);
		y = GAME_HEIHGT / 2 - height / 2;

		//追加の座標設定
		if (posType == 0)    //上
		{
			addPosX = -48;
			addPosY = -65;

		}
		else                 //下
		{
			addPosX = -48;
			addPosY = 53;
		}

		//占領された時の敵の生成座標設定
		popPosX = x + addPosX;
		popPosY = y;

		direction = eDirection::Left;

		break;

	case 2:    //右側

		//座標設定
		x = GAME_WIDTH / 2 - width / 2 + 225 + GetRand(30);
		y = GAME_HEIHGT / 2 - height / 2;

		//追加の座標設定
		if (posType == 0)    //上
		{
			addPosX = 48;
			addPosY = -65;
		}
		else                 //下
		{
			addPosX = 48;
			addPosY = 53;
		}

		//占領された時の敵の生成座標設定
		popPosX = x + addPosX;
		popPosY = y;

		direction = eDirection::Right;

		break;

	case 3:    //上側

		//座標設定
		x = GAME_WIDTH / 2 - width / 2;
		y = GAME_HEIHGT / 2 - height / 2 - 225 - GetRand(30);

		//追加の座標設定
		if (posType == 0)    //左
		{
			addPosY = -48;
			addPosX = -54;
		}
		else                 //右
		{
			addPosY = -48;
			addPosX = 55;
		}

		//占領された時の敵の生成座標設定
		popPosX = x;
		popPosY = y + addPosY;

		direction = eDirection::Up;

		break;

	case 4:    //下側

		//座標設定
		x = GAME_WIDTH / 2 - width / 2;
		y = GAME_HEIHGT / 2 - height / 2 + 225 + GetRand(30);

		//追加の座標設定
		if (posType == 0)    //左
		{
			addPosY = 48;
			addPosX = -54;
		}
		else                 //右
		{
			addPosY = 48;
			addPosX = 55;
		}

		//占領された時の敵の生成座標設定
		popPosX = x;
		popPosY = y + addPosY;

		direction = eDirection::Down;

		break;

	default:
		break;
	}
	//サブ拠点の表示場所の座標設定
	drawPosX = x + addPosX - addSize / 2;
	drawPosY = y + addPosY - addSize / 2;

}

void SubCastle::Update(EnemyManager* enemy)
{
	//当たり判定
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
		DrawGraphF(drawPosX,drawPosY,Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 0), TRUE);
	}
	else
	{
		DrawGraphF(drawPosX, drawPosY, Image::Instance()->GetGraph(eImageType::Gpicture_SubCastle, 1), TRUE);
	}
}