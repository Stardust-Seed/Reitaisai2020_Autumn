#include "DxLib.h"
#include "SubCastle.h"
#include "EnemyManager.h"

//コンストラクタ
SubCastle::SubCastle(int _durability,int _type,int _num)
	:BaseCastle(_durability) {

	durability = _durability;

	width = 48;
	height = 48;
	addPosX = 0;
	addPosY = 0;
	addSize = 8;

	cnt = 0;
	bwidth = 25;
	bheight = 25;
	alpha = 255;

	bflg = false;
	discoveryFlg = false;

	//座標設定
	switch (_num)
	{
	case 1:    //上左側

		//座標設定
		x = COORDINATE_X_ONE;
		y = COORDINATE_Y_ONE;

		addPosX = -48;
		addPosY = -80;

		//サブ拠点の表示場所の座標設定
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//占領された時の敵の生成座標設定
		popPosX = drawPosX;
		popPosY = (GAME_HEIHGT / 2) - (48 / 2);

		//弾の進行方向の設定
		directionMove = 3;

		direction = eDirection::Left;
		break;
	case 2:    //下左側

        //座標設定
		x = COORDINATE_X_TWO;
		y = COORDINATE_Y_TWO;

		addPosX = -48;
		addPosY = 32;

		//サブ拠点の表示場所の座標設定
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//占領された時の敵の生成座標設定
		popPosX = drawPosX;
		popPosY = (GAME_HEIHGT / 2) - (48 / 2);

		//弾の進行方向の設定
		directionMove = 4;

		direction = eDirection::Left;
		break;

	case 3:    //上右側

		//座標設定
		x = COORDINATE_X_THREE;
		y = COORDINATE_Y_THREE;

		addPosX = 32;
		addPosY = -48;

		//サブ拠点の表示場所の座標設定
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//占領された時の敵の生成座標設定
		popPosX = (GAME_WIDTH / 2) - (48 / 2);
		popPosY = drawPosY;

		//弾の進行方向の設定
		directionMove = 4;

		direction = eDirection::Up;
		break;

	case 4:    //上左側

		//座標設定
		x = COORDINATE_X_FOUR;
		y = COORDINATE_Y_FOUR;

		addPosX = -80;
		addPosY = -48;

		//サブ拠点の表示場所の座標設定
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//占領された時の敵の生成座標設定
		popPosX = (GAME_WIDTH / 2) - (48 / 2);
		popPosY = drawPosY;

		//弾の進行方向の設定
		directionMove = 2;

		direction = eDirection::Up;
		break;

	case 5:    //上左側

		//座標設定
		x = COORDINATE_X_FIVE;
		y = COORDINATE_Y_FIVE;

		addPosX = 48;
		addPosY = 32;

		//サブ拠点の表示場所の座標設定
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//占領された時の敵の生成座標設定
		popPosX = drawPosX;
		popPosY = (GAME_HEIHGT / 2) - (48 / 2);

		//弾の進行方向の設定
		directionMove = 2;

		direction = eDirection::Right;
		break;
		
	case 6:    //下左側

        //座標設定
		x = COORDINATE_X_SIX;
		y = COORDINATE_Y_SIX;

		addPosX = 48;
		addPosY = -80;

		//サブ拠点の表示場所の座標設定
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//占領された時の敵の生成座標設定
		popPosX = drawPosX;
		popPosY = (GAME_HEIHGT / 2) - (48 / 2);

		//弾の進行方向の設定
		directionMove = 1;

		direction = eDirection::Right;
		break;
	case 7:    //下左側

        //座標設定
		x = COORDINATE_X_SEVEN;
		y = COORDINATE_Y_SEVEN;

		addPosX = -80;
		addPosY = 48;

		//サブ拠点の表示場所の座標設定
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//占領された時の敵の生成座標設定
		popPosX = (GAME_WIDTH / 2) - (48 / 2);
		popPosY = drawPosY;

		//弾の進行方向の設定
		directionMove = 1;

		direction = eDirection::Down;
		break;
	case 8:    //下右側

        //座標設定
		x = COORDINATE_X_EIGHT;
		y = COORDINATE_Y_EIGHT;

		addPosX = 32;
		addPosY = 48;

		//サブ拠点の表示場所の座標設定
		drawPosX = x + addPosX - addSize / 2;
		drawPosY = y + addPosY - addSize / 2;

		//占領された時の敵の生成座標設定
		popPosX = (GAME_WIDTH / 2) - (48 / 2);
		popPosY = drawPosY;

		//弾の進行方向の設定
		directionMove = 3;

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
	//配置場所によって進んでいく方向を決める
	switch (directionMove)
	{
	//右下方向
	case 1:
		bx++;
		by++;
		break;
	//右上方向
	case 2:
		bx++;
		by--;
		break;
	//左下方向
	case 3:
		bx--;
		by++;
		break;
	//左上方向
	case 4:
		bx--;
		by--;
		break;
	default:
		break;
	}

	//強制フェードアウト
	if (bx > drawPosX + 100 ||
		bx < drawPosX - 100 ||
		by > drawPosY + 100 ||
		by < drawPosY - 100   )
	{
		alpha -= 5;
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

	//敵を発見したら
	if (discoveryFlg)
	{
		cnt++;
	}

	//フェードアウトしたら一度発見フラグをオフにする
	if (alpha <= 0)
	{
		discoveryFlg = false;
	}

	//生きてないならこの先の処理はしない
	if (isActive == false)return;

	//当たり判定
	for (int num = 0; num < enemy->Get_enemyNum(); num++)
	{
		//サブ拠点と敵の当たり判定
		if (enemy->Get_ActiveFlg(num) == true && enemy->Get_AttackFlg(num) == true &&
			enemy->Get_AttackType(num) != eAttackType::Player)
		{
			ClisionHit(enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num),
				enemy->Get_height(num), enemy->Get_Power(num), num,
				enemy->Get_AttackFlg(num), enemy->Get_ActiveFlg(num));
		}

		//同じ方向の索敵範囲に敵を発見したら
		if (x - enemy->Get_x(num) >= -250 && x - enemy->Get_x(num) <= 250 &&
			y - enemy->Get_y(num) >= -250 && y - enemy->Get_y(num) <= 250 &&
			direction == enemy->Get_direction(num))
		{
			discoveryFlg = true;
		}

		//カウントしたら弾発射
		if (cnt > 70)
		{
			bflg = true;
			cnt = 0;
			alpha = 255;
			bx = drawPosX + width / 2;
			by = drawPosY + height / 2;
			discoveryFlg = false;
		}

		//弾と敵の当たり判定
		if (bflg == true && ClisionHit(bx, by, bheight, bwidth, enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num),
			enemy->Get_height(num)) == true)
		{
			enemy->DamageSend(num, 25);
			bflg = false;
			discoveryFlg = false;
			bx = drawPosX + width / 2;
			by = drawPosY + height / 2;
		}
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

	//弾表示
	if (bflg==true)
	{
		//ブレンドモードを乗算済みα用のαブレンドにする
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);

		//弾表示
		DrawGraphF(bx,  by, Image::Instance()->GetGraph(eImageType::Gpicture_Bullet, 1), TRUE);

		//ブレンドモードを通常に戻す
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, alpha);

		//通常フェードアウト
		if (cnt > 50)
		{
			alpha -= 5;
		}
	}
}