#include "DxLib.h"
#include "SukimaEvent.h"
#include "EnemyManager.h"

//コンストラクタ
SukimaEvent::SukimaEvent() {
	SRand;					//乱数初期化

	warpPosX = 0;
    warpPosY = 0;
	width = 48;
	height = width;
	addSize = 12;

	isHit = false;

	animationCnt = 0;
	animationFlg = false;

	type = GetRand(3);    //乱数取得

	//座標設定
	switch (type)
	{
	case 0:    //左側
		x = LEFT_X;
		y = LEFT_Y;

		break;

	case 1:    //右側
		x = RIGHT_X;
		y = RIGHT_Y;

		break;

	case 2:    //上側
		x = UP_X;
		y = UP_Y;

		break;

	case 3:    //下側
		x = DOWN_X;
		y = DOWN_Y;

		break;

	default:
		break;
	}
}
//デストラクタ
SukimaEvent::~SukimaEvent() {

}
//更新
void SukimaEvent::Update(EnemyManager* enemy)
{
	SRand;

	for (int num = 0; num < enemy->Get_enemyNum(); num++)
	{
		//当たり判定
		if (enemy->Get_ActiveFlg(num) == true)
		{
			ClisionHit(x,y,width,height,
				enemy->Get_x(num), enemy->Get_y(num),
				enemy->Get_width(num),enemy->Get_height(num));
		}
		//当たったらワープ
		if (isHit == true)
		{
			animationFlg = true;
			animationCnt = 0;
			int _type = GetRand(3);
			if (type == _type)return;
			switch (_type)
			{
			case 0:    //左側
				enemy->Set_x(num, LEFT_X - width + 50);
				enemy->Set_y(num, LEFT_Y - height * 0.5f);
				enemy->Set_direction(num, eDirection::Left);
				warpPosX = LEFT_X;
				warpPosY = LEFT_Y;
				break;

			case 1:    //右側
				enemy->Set_x(num, RIGHT_X - width + 50);
				enemy->Set_y(num, RIGHT_Y - height * 0.5f);
				enemy->Set_direction(num, eDirection::Right);
				warpPosX = RIGHT_X;
				warpPosY = RIGHT_Y;
				break;

			case 2:    //上側
				enemy->Set_x(num, UP_X - width * 0.5f);
				enemy->Set_y(num, UP_Y - height + 50);
				enemy->Set_direction(num, eDirection::Up);
				warpPosX = UP_X;
				warpPosY = UP_Y;
				break;

			case 3:    //下側
				enemy->Set_x(num, DOWN_X - width * 0.5f);
				enemy->Set_y(num, DOWN_Y - height + 50);
				enemy->Set_direction(num, eDirection::Down);
				warpPosX = DOWN_X;
				warpPosY = DOWN_Y;
				break;

			default:
				break;
			}
			isHit = false;
		}
	}
}
//描画
void SukimaEvent::Draw()
{
	    DrawGraph(x - width / 2, y - height / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 3), TRUE);

		if (animationFlg == true)
		{
			Animation();
		}
}
//当たり判定
bool SukimaEvent:: ClisionHit(float mx, float my, float mw, float mh,
	                          float ox, float oy, float ow, float oh)
{
	if (x + width >= ox && x <= ox + ow &&
		y + height >= oy && y <= oy + oh)
	{
		isHit = true;
	}
	else
	{
		isHit = false;
	}
	return isHit;
}
//アニメーション再生
void SukimaEvent::Animation()
{
	animationCnt++;
	if (animationNum[animationCnt] == 0)
	{
	 	DrawGraph(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 0), TRUE);
	}
	if (animationNum[animationCnt] == 1)
	{
	 	DrawGraph(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 1), TRUE);
	}
	if (animationNum[animationCnt] == 2)
	{
	    DrawGraph(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 2), TRUE);
	}
	if (animationNum[animationCnt] == 3)
	{
	    DrawGraph(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 3), TRUE);
	}
	if (animationNum[animationCnt] == 4)
	{
		animationCnt = 0;
		animationFlg = false;
	}
}