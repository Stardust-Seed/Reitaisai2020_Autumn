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
	cnt = 0;
	isHit = false;

	int type = GetRand(3);    //乱数取得
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
	cnt++;

	Animation();

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
			cnt = 0;
			int type = GetRand(3);
			switch (type)
			{
			case 0:    //左側
				enemy->Set_x(num, LEFT_X+50);
				enemy->Set_y(num, LEFT_Y);
				enemy->Set_direction(num, eDirection::Left);
				warpPosX = LEFT_X;
				warpPosY = LEFT_Y;
				break;

			case 1:    //右側
				enemy->Set_x(num, RIGHT_X-50);
				enemy->Set_y(num, RIGHT_Y);
				enemy->Set_direction(num, eDirection::Right);
				warpPosX = RIGHT_X;
				warpPosY = RIGHT_Y;
				break;

			case 2:    //上側
				enemy->Set_x(num, UP_X);
				enemy->Set_y(num, UP_Y + 50);
				enemy->Set_direction(num, eDirection::Up);
				warpPosX = UP_X;
				warpPosY = UP_Y;
				break;

			case 3:    //下側
				enemy->Set_x(num, DOWN_X);
				enemy->Set_y(num, DOWN_Y - 50);
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
	DrawBoxAA(x - width/2, y - height/2, x + width/2, y + height/2, GetColor(255, 0, 255), TRUE);
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
//仮置き
void SukimaEvent::Animation()
{
	//今はただの四角を少しの間表示してるだけ
	//後で調整
	if (cnt < 50)
	{
		DrawBoxAA(warpPosX- width / 2-addSize / 2, warpPosY- height / 2-addSize / 2, warpPosX + width / 2+addSize / 2, warpPosY + height / 2+addSize / 2, GetColor(255, 255, 255), TRUE);
	}
}