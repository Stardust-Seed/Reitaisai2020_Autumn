#include <DxLib.h>
#include "BaseBomb.h"

//�R���X�g���N�^
BaseBomb::BaseBomb(int _power, int _speed, eBombType _bombType)
{
	SRand;
	speed = _speed;
	power = _power;
	type = _bombType;
	
	direction = GetRand(3);					//�����̗���
	
	countDown = COUNTMAX;						//�J�E���g�_�E���̃Z�b�g
	
	isActive = true;
	isSpown = false;
	isXplosion = false;							//�������
	isTrigger = false;

	if (direction == DIRECTIONLEFT)			//��
	{
		x = BOMB_SPOWNLEFTHX;
		y = BOMB_SPOWNLEFTY;
	}

	if (direction == DIRECTIONRIGHT)		//�E
	{
		x = BOMB_SPOWNRIGHTX;
		y = BOMB_SPOWNRIGHTY;
	}

	if (direction == DIRECTIONUP)			//��
	{
		x = BOMB_SPOWNUPX;
		y = BOMB_SPOWNUPY;
	}

	if (direction == DIRECTIONDOWN)			//��
	{
		x = BOMB_SPOWNDOWNX;
		y = BOMB_SPOWNDOWNY;
	}

	cx = x + (width / 2);
	cy = y + (height / 2);

	width = 50;
	height = 50;
}

BaseBomb::~BaseBomb() 
{
	
}

//���e����
void BaseBomb::SpawnBomb()
{
	//�^
	if (type == bomb)
	{
		isSpown = true;
	}

	//�U
	if (type == fakebomb)
	{
		isSpown = true;
	}

}

//���e����
void BaseBomb::Move()
{
	if (direction == DIRECTIONLEFT)			//��
	{
		y++;
		if (y == GAME_WIDTH / 2 - 450)
		{
			y --;
		}
		x += speed;
		if (x > BOMB_SPOWNLEFTHX + 920)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONRIGHT)		//�E
	{
		y--;

		if (y == GAME_HEIHGT / 2)
		{
			y++;
		}

		x -= speed;

		if (x < BOMB_SPOWNRIGHTX - 980)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONUP)			//��
	{
		x++;
		if (x == GAME_WIDTH / 2 - 25)
		{
			x--;
		}
	
		y += speed;
		if (y > BOMB_SPOWNUPY + 455)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONDOWN)			//��
	{
		x--;
		if (x == GAME_WIDTH / 2 - 25)
		{
			x++;
		}
		y -= speed;
		if (y < BOMB_SPOWNDOWNY - 675)
		{
			speed = 0;
		}
	}
}

//���e�N��
void BaseBomb::JudgeTrigger()
{
	//���e�̃^�C�}�[
	if (speed == 0 && isPAbility == false)
	{
		isCount = true;


		if (isCount == true)
		{
			//�J�E���g�_�E��
			DrawFormatStringToHandle(x + 5, y - 50, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "%d", countDown / FRAME);
			if (countDown <= FRAME)
			{
				isXplosion = true;                        //�t���O�ؑ�
			}

			if (countDown >= 0)
			{											//�\������Ă���^�C�}�[��0�ɂ������̂ŃJ�E���g�_�E�����̂�0�ɂȂ�܂œ�����
				countDown -= 1;							//�J�E���g�_�E��
			}
		}


		if (type == bomb && isXplosion == true)						//��������
		{
			SE::Instance()->PlaySE(SE_bomb);		 //������SE���o��
			isCount = false;
			isTrigger = true;
			isXplosion = false;
			isSpown = false;

		}

		if (type == fakebomb && isXplosion == true)						//��������
		{
			isCount = false;
			isTrigger = true;
			isXplosion = false;
			isSpown = false;
		}
	}

	if (AnimationFlg == true)
	{
		SE::Instance()->StopSE(SE_bomb);
	}
}

void BaseBomb::SkillStop()
{
	if (pType == SAKUYA_Ability)
	{
		
		if (isPAbility == true)
		{
			isStopCount = true;

			sTime = countDown / FRAME;
    		
			if (speed == 0)
			{
				DrawFormatStringToHandle(x + 5, y - 50, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "%d", sTime);
			}
		}
	}
}


//�����蔻��
bool BaseBomb::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{
	if (x + width >= ox && x <= ox + ow &&
		y + height >= oy && y <= oy + oh)
	{
		isHit = true;
		isStopCount = false;
	}
	else
	{
		isHit = false;
	}
	return isHit;
}



