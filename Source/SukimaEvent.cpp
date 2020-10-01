#include "DxLib.h"
#include "SukimaEvent.h"
#include "EnemyManager.h"

//�R���X�g���N�^
SukimaEvent::SukimaEvent() {
	SRand;					//����������

	width = 48;
	height = width;
	addSize = 12;

	popFlg = true;
	deleteFlg = false;
	animationFlg = false;

	isHit = false;
	isActive = true;

	deleteCnt = 0;
	warpAnimationCnt = 0;
	popAnimationCnt = 0;

	type = GetRand(3);    //�����擾

	//���W�ݒ�
	switch (type)
	{
	case 0:    //����
		x = LEFT_X;
		y = LEFT_Y;

		break;

	case 1:    //�E��
		x = RIGHT_X;
		y = RIGHT_Y;

		break;

	case 2:    //�㑤
		x = UP_X;
		y = UP_Y;

		break;

	case 3:    //����
		x = DOWN_X;
		y = DOWN_Y;

		break;

	default:
		break;
	}
	warpPosX = x;
    warpPosY = y;
}
//�f�X�g���N�^
SukimaEvent::~SukimaEvent() {

}
//�X�V
void SukimaEvent::Update(EnemyManager* enemy)
{
	SRand;
	for (int num = 0; num < enemy->Get_enemyNum(); num++)
	{
		//�����蔻��
		if (enemy->Get_ActiveFlg(num) == true && animationFlg == false && deleteFlg == false && popFlg == false)
		{
			ClisionHit(x,y,width,height,
				enemy->Get_x(num), enemy->Get_y(num),
				enemy->Get_width(num),enemy->Get_height(num));
		}
		//���������烏�[�v
		if (isHit == true)
		{
			SE::Instance()->PlaySE(SE_sukimaWarp);
			deleteFlg = true;
			animationFlg = true;
			warpAnimationCnt = 0;
			int _type = GetRand(3);
			if (type == _type)return;
			switch (_type)
			{
			case 0:    //����
				enemy->Set_x(num, LEFT_X - width + 50);
				enemy->Set_y(num, LEFT_Y - height * 0.5f);
				enemy->Set_direction(num, eDirection::Left);
				warpPosX = LEFT_X;
				warpPosY = LEFT_Y;
				break;

			case 1:    //�E��
				enemy->Set_x(num, RIGHT_X - width + 50);
				enemy->Set_y(num, RIGHT_Y - height * 0.5f);
				enemy->Set_direction(num, eDirection::Right);
				warpPosX = RIGHT_X;
				warpPosY = RIGHT_Y;
				break;

			case 2:    //�㑤
				enemy->Set_x(num, UP_X - width * 0.5f);
				enemy->Set_y(num, UP_Y - height + 50);
				enemy->Set_direction(num, eDirection::Up);
				warpPosX = UP_X;
				warpPosY = UP_Y;
				break;

			case 3:    //����
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

	//��莞�Ԃ������玩�R���ł�����
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
//�`��
void SukimaEvent::Draw()
{
		if ( popFlg ||animationFlg == true)
		{
			Animation();
		}

		if (popFlg == false)
		{
			if (deleteFlg == false)
			{
				DrawGraph(x - width / 2 - addSize / 2, y - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 3), TRUE);
			}
		}
}
//�����蔻��
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
//�A�j���[�V�����Đ�
void SukimaEvent::Animation()
{
	if (popFlg == false)
	{
		warpAnimationCnt++;
		if (animation[warpAnimationCnt] == 0)
		{
			DrawGraph(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 0), TRUE);
		}
		if (animation[warpAnimationCnt] == 1)
		{
			DrawGraph(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 1), TRUE);
		}
		if (animation[warpAnimationCnt] == 2)
		{
			DrawGraph(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 2), TRUE);
		}
		if (animation[warpAnimationCnt] == 3)
		{
			DrawGraph(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 3), TRUE);
		}
		if (animation[warpAnimationCnt] == 4)
		{
			warpAnimationCnt = 0;
			animationFlg = false;
			isActive = false;
		}

		if (deleteFlg == true)
		{
			if (popAnimationCnt > 0)
			{
				popAnimationCnt--;
			}

			if (animation[popAnimationCnt] == 0)
			{
				DrawGraph(x - width / 2 - addSize / 2, y - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 0), TRUE);
			}
			if (animation[popAnimationCnt] == 1)
			{
				DrawGraph(x - width / 2 - addSize / 2, y - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 1), TRUE);
			}
			if (animation[popAnimationCnt] == 2)
			{
				DrawGraph(x - width / 2 - addSize / 2, y - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 2), TRUE);
			}
			if (animation[popAnimationCnt] == 3)
			{
				DrawGraph(x - width / 2 - addSize / 2, y - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 3), TRUE);
			}
		}
	}
	else
	{
		if (deleteFlg == false)
		{
			popAnimationCnt++;
		if (animation[popAnimationCnt] == 0)
		{
			DrawGraph(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 0), TRUE);
		}
		if (animation[popAnimationCnt] == 1)
		{
			DrawGraph(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 1), TRUE);
		}
		if (animation[popAnimationCnt] == 2)
		{
			DrawGraph(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 2), TRUE);
		}
		if (animation[popAnimationCnt] == 3)
		{
			if (popAnimationCnt == 31)
			{
				popFlg = false;
			}
			DrawGraph(warpPosX - width / 2 - addSize / 2, warpPosY - height / 2 - addSize / 2, Image::Instance()->GetGraph(eImageType::Gpicture_Sukima, 3), TRUE);
		}
		if (animation[popAnimationCnt] == 4)
		{
			animationFlg = false;
		}

		}
	}
}