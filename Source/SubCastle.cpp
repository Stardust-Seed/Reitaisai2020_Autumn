#include "DxLib.h"
#include "SubCastle.h"
#include "EnemyManager.h"

//コンストラクタ
SubCastle::SubCastle(int _durability,int _type,int _num)
	:BaseCastle(_durability) {
	durability = _durability;

	width =  48;
	height = 48;
	addPosX = 0;
	addPosY = 0;
	addSize = 8;

	//座標設定
	switch (_num)
	{
	case 1:    //左側

		//座標設定
		x = COORDINATE_X_ONE;
		y = COORDINATE_Y_ONE;

		addPosX = -48;
		addPosY = -80;

		//占領された時の敵の生成座標設定
		popPosX = x + addPosX;
		popPosY = y + addPosY;

		direction = eDirection::Left;
		break;
	case 2:    //左側

        //座標設定
		x = COORDINATE_X_TWO;
		y = COORDINATE_Y_TWO;

		addPosX = -48;
		addPosY = 32;

		//占領された時の敵の生成座標設定
		popPosX = x + addPosX;
		popPosY = y + addPosY;

		direction = eDirection::Left;
		break;

	case 3:    //右側

		//座標設定
		x = COORDINATE_X_THREE;
		y = COORDINATE_Y_THREE;

		addPosX = 32;
		addPosY = -48;

		//占領された時の敵の生成座標設定
		popPosX = x + addPosX;
		popPosY = y + addPosY;

		direction = eDirection::Up;
		break;

	case 4:    //上側

		//座標設定
		x = COORDINATE_X_FOUR;
		y = COORDINATE_Y_FOUR;

		addPosX = -80;
		addPosY = -48;

		//占領された時の敵の生成座標設定
		popPosX = x + addPosX;
		popPosY = y + addPosY;

		direction = eDirection::Up;
		break;

	case 5:    //下側

		//座標設定
		x = COORDINATE_X_FIVE;
		y = COORDINATE_Y_FIVE;

		addPosX = 48;
		addPosY = 32;

		//占領された時の敵の生成座標設定
		popPosX = x + addPosX;
		popPosY = y + addPosY;

		direction = eDirection::Right;
		break;
		
	case 6:    //下側

        //座標設定
		x = COORDINATE_X_SIX;
		y = COORDINATE_Y_SIX;

		addPosX = 48;
		addPosY = -80;

		//占領された時の敵の生成座標設定
		popPosX = x + addPosX;
		popPosY = y + addPosY;

		direction = eDirection::Right;
		break;
	case 7:    //下側

        //座標設定
		x = COORDINATE_X_SEVEN;
		y = COORDINATE_Y_SEVEN;

		addPosX = -80;
		addPosY = 48;

		//占領された時の敵の生成座標設定
		popPosX = x + addPosX;
		popPosY = y + addPosY;

		direction = eDirection::Down;
		break;
	case 8:    //下側

        //座標設定
		x = COORDINATE_X_EIGHT;
		y = COORDINATE_Y_EIGHT;

		addPosX = 32;
		addPosY = 48;

		//占領された時の敵の生成座標設定
		popPosX = x + addPosX;
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