#include "DxLib.h"
#include "SukimaEvent.h"
#include "EnemyManager.h"
#include "BasePlayer.h"

//コンストラクタ
SukimaEvent::SukimaEvent() {

	width = 48;
	height = 48;
	addSize = 8;

	hitNum = -1;
	popFlg = true;
	deleteFlg = false;
	animationFlg = false;

	isHit = false;
	isActive = true;

	deleteCnt = 0;
	warpAnimationCnt = 0;
	popAnimationCnt = 0;

	sakuyaSkill = false;

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
	//ワープ先の座標設定
	warpPosX = x;
    warpPosY = y;
}
//デストラクタ
SukimaEvent::~SukimaEvent() {

}
//更新
void SukimaEvent::Update(EnemyManager* enemy,BasePlayer* player)
{
	if (player->Get_isAbility() == true && player->Get_AbilityType() == SAKUYA)
	{
		sakuyaSkill = true;
	}
	else
	{
		sakuyaSkill = false;
		//当たり判定
		for (int num = 0; num < enemy->Get_enemyNum(); num++)
		{
			if (enemy->Get_ActiveFlg(num) == true && animationFlg == false &&
				deleteFlg == false && popFlg == false)
			{
				hitNum = num;
				ClisionHit(x, y, width, height,
					enemy->Get_x(num), enemy->Get_y(num),
					enemy->Get_width(num), enemy->Get_height(num));
			}
			//当たったらワープ(ランダムな方向に)
			if (isHit == true)
			{
				SE::Instance()->PlaySE(SE_sukimaWarp);
				animationFlg = true;
				warpAnimationCnt = 0;
				int _type = GetRand(3);

				if (type == _type)return;

				switch (_type)
				{
				case 0:    //左側
					enemy->Set_x(hitNum, LEFT_X - width + 16);
					enemy->Set_y(hitNum, LEFT_Y - height * 0.5f);
					enemy->Set_direction(hitNum, eDirection::Left);
					warpPosX = LEFT_X;
					warpPosY = LEFT_Y;
					break;

				case 1:    //右側
					enemy->Set_x(hitNum, RIGHT_X - width + 16);
					enemy->Set_y(hitNum, RIGHT_Y - height * 0.5f);
					enemy->Set_direction(hitNum, eDirection::Right);
					warpPosX = RIGHT_X;
					warpPosY = RIGHT_Y;
					break;

				case 2:    //上側
					enemy->Set_x(hitNum, UP_X - width * 0.5f);
					enemy->Set_y(hitNum, UP_Y - height + 16);
					enemy->Set_direction(hitNum, eDirection::Up);
					warpPosX = UP_X;
					warpPosY = UP_Y;
					break;

				case 3:    //下側
					enemy->Set_x(hitNum, DOWN_X - width * 0.5f);
					enemy->Set_y(hitNum, DOWN_Y - height + 16);
					enemy->Set_direction(hitNum, eDirection::Down);
					warpPosX = DOWN_X;
					warpPosY = DOWN_Y;
					break;

				default:
					break;
				}
				isHit = false;
				deleteFlg = true;
			}
		}

		//一定時間たったら自然消滅させる
		if (deleteCnt < 700 && animationFlg == false)
		{
			deleteCnt++;
		}
		else
		{
			deleteFlg = true;
			animationFlg = true;
			if (popAnimationCnt > 0)
			{
				popAnimationCnt--;
			}
		}

		if (deleteCnt == 700 && popAnimationCnt == 0)
		{
			isActive = false;
		}
	}
}
//描画
void SukimaEvent::Draw()
{
	    //アニメーション表示
		if ( popFlg ||animationFlg == true)
		{
			Animation();
		}
		
		//適当に表示
		if (popFlg == false)
		{
			if (deleteFlg == false)
			{
				DrawGraphF(x - width / 2 - addSize / 2, y - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 3), TRUE);
		    }
		}
}
//当たり判定
bool SukimaEvent:: ClisionHit(float mx, float my, float mw, float mh,
	                          float ox, float oy, float ow, float oh)
{
	if (x + width - addSize *6.5f >= ox && x - addSize  *1.05f <= ox + ow &&
		y + height - addSize *6.5f >= oy && y - addSize *1.05f <= oy + oh)
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
	//最初のアニメーションが終わっているとき
	if (popFlg == false)
	{
		if (sakuyaSkill != true)
		{
			warpAnimationCnt++;
		}
		if (animation[warpAnimationCnt] == 1)
		{
			DrawGraphF(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 1), TRUE);
		}

		if (animation[warpAnimationCnt] == 2)
		{
			DrawGraphF(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 2), TRUE);
		}

		if (animation[warpAnimationCnt] == 3)
		{
			DrawGraphF(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 3), TRUE);
		}
		//アニメーション終了したら消す
		if (animation[warpAnimationCnt] == 4)
		{
			warpAnimationCnt = 0;
			animationFlg = false;
			isActive = false;
		}
		//自然消滅のする時のアニメーション
		if (deleteFlg == true)
		{
			if (popAnimationCnt > 0	&& sakuyaSkill != true)
			{
				popAnimationCnt--;
			}

			if (animation[popAnimationCnt] == 0)
			{
				DrawGraphF(x - width / 2 - addSize / 2, y - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 0), TRUE);
			}

			if (animation[popAnimationCnt] == 1)
			{
				warpAnimationCnt = 0;
				DrawGraphF(x - width / 2 - addSize / 2, y - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 1), TRUE);
			}

			if (animation[popAnimationCnt] == 2)
			{
				DrawGraphF(x - width / 2 - addSize / 2, y - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 2), TRUE);
			}

			if (animation[popAnimationCnt] == 3)
			{
				DrawGraphF(x - width / 2 - addSize / 2, y - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 3), TRUE);
			}
		}

	}
	else
	{
		//生成されたときのアニメーション
		if (deleteFlg == false)
		{
			if (sakuyaSkill != true)
			{
				popAnimationCnt++;
			}

			if (animation[popAnimationCnt] == 0)
			{
				DrawGraphF(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 0), TRUE);
			}

			if (animation[popAnimationCnt] == 1)
			{
				DrawGraphF(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 1), TRUE);
			}

			if (animation[popAnimationCnt] == 2)
			{
				DrawGraphF(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 2), TRUE);
			}

			if (animation[popAnimationCnt] == 3)
			{
				if (popAnimationCnt == 31)
				{
					popFlg = false;
				}

				DrawGraphF(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 3), TRUE);
			}

			if (animation[popAnimationCnt] == 4)
			{
				animationFlg = false;
			}
		}
	}
}