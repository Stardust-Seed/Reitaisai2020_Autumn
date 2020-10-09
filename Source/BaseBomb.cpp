#include <DxLib.h>
#include "BaseBomb.h"

//�R���X�g���N�^
BaseBomb::BaseBomb(int _power, float _speed, eBombType _bombType)
{
	speed = _speed;
	power = _power;
	type = _bombType;

	direction = GetRand(3);					//�����̗���
	
	countDown = COUNTMAX;					//�J�E���g�_�E���̃Z�b�g
	
	isActive = true;						//�������
	isSpawn = false;
	isXplosion = false;	
	isTrigger = false;
	isCount = false;
	isStopCount = false;
	isHit = false;
	isPAbility = false;
	AnimationFlg = false;

	if (direction == DIRECTIONLEFT)			//�΂ߍ�
	{
		x = BOMB_SPOWNLEFTHX;
		y = BOMB_SPOWNLEFTY;
	}

	if (direction == DIRECTIONRIGHT)		//�΂߉E
	{
		x = BOMB_SPOWNRIGHTX;
		y = BOMB_SPOWNRIGHTY;
	}

	if (direction == DIRECTIONUP)			//�΂ߏ�
	{
		x = BOMB_SPOWNUPX;
		y = BOMB_SPOWNUPY;
	}

	if (direction == DIRECTIONDOWN)			//�΂߉�
	{
		x = BOMB_SPOWNDOWNX;
		y = BOMB_SPOWNDOWNY;
	}

	cx = x + (width / 2);					//���Sx
	cy = y + (height / 2);					//���Sy

	width = 50.0f;							//��
	height = 50.0f;							//����
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
		isSpawn = true;
	}

	//�U
	if (type == fakebomb)
	{
		isSpawn = true;
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

		//�J�E���g�J�n
		if (isCount == true)
		{
			//�J�E���g�_�E��
			DrawFormatStringToHandle(x + 5.0f, y - 50.0f, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "%d", countDown / FRAME);
			if (countDown <= FRAME)
			{
				isXplosion = true;							//�t���O�ؑ�
			}

			if (countDown >= 0)
			{												//�\������Ă���^�C�}�[��0�ɂ������̂ŃJ�E���g�_�E�����̂�0�ɂȂ�܂œ�����
				countDown -= 1;								//�J�E���g�_�E��
			}
		}


		if (type == bomb && isXplosion == true)				//��������
		{
			SE::Instance()->PlaySE(SE_bomb);				//������SE���o��
			isCount = false;
			isTrigger = true;
			isXplosion = false;
			isSpawn = false;
		}

		if (type == fakebomb && isXplosion == true)			//��������
		{
			SE::Instance()->PlaySE(SE_Fake);				//���j���s��SE
			isCount = false;
			isTrigger = true;
			isXplosion = false;
			isSpawn = false;
		}
	}

	//�A�j���[�V�����J�n����SE�~�߂�
	if (AnimationFlg == true)
	{
		SE::Instance()->StopSE(SE_bomb);
		SE::Instance()->StopSE(SE_Fake);
	}
}

//���~�ߏ���
void BaseBomb::SkillStop()
{
	if (pType == SAKUYA_Ability)
	{
		
		if (isPAbility == true && speed == 0)
		{
			isStopCount = true;
			tX = x + 5;
			tY = y - 50;
			sTime = countDown / FRAME;		//���~�ߎ��Ɍ��݂̃J�E���g�_�E����ϐ��ɓ����
    		
			DrawFormatStringToHandle(tX, tY, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "%d", sTime);
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



