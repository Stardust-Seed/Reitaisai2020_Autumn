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
	
	countdown = COUNTMAX;						//�J�E���g�_�E���̃Z�b�g
	
	isSpown = false;
	isFakeSpown = false;
	isXplosion = false;							//�������
	isTrigger = false;
	isFakeTrigger = false;
	isCount == false;

	if (direction == DIRECTIONLEFT)			//��
	{
		x = BOMB_SPOWNLEFTHX;
		y = BOMB_SPOWNLR;
	}

	if (direction == DIRECTIONRIGHT)		//�E
	{
		x = BOMB_SPOWNRIGHTX;
		y = BOMB_SPOWNLR;
	}

	if (direction == DIRECTIONUP)			//��
	{
		x = BOMB_SPOWNUPDOWNX;
		y = BOMB_SPOWNUPY;
	}

	if (direction == DIRECTIONDOWN)			//��
	{
		x = BOMB_SPOWNUPDOWNX;
		y = BOMB_SPOWNDOWNY;
	}
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
		isFakeSpown = true;
	}

}

//���e����
void BaseBomb::Move()
{
	if (direction == DIRECTIONLEFT)			//��
	{
		y += speed;
		if (y > BOMB_SPOWNLR + 540)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONRIGHT)		//�E
	{
		y += speed;
		if (y > BOMB_SPOWNLR + 540)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONUP)			//��
	{
		y += speed;
		if (y > BOMB_SPOWNUPY + 455)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONDOWN)			//��
	{
		y -= speed;
		if (y < BOMB_SPOWNDOWNY - 495)
		{
			speed = 0;
		}
	}	
}

//���e�N��
void BaseBomb::JudgeTrigger()
{
	//���e�̃^�C�}�[
	if (speed == 0)
	{
		isCount = true;
		if (isCount == true)
		{
			DrawFormatString(10, 150, GetColor(255, 255, 255), "%d", countdown / FRAME);	//�\��

			if (countdown <= FRAME) {								//�c���b�ȉ��͊���Z�̌���0�ɂȂ邽�߁A�\���^�C�~���O�̒���
				isXplosion = true;                                  //�t���O�ؑ�
				isCount = false;
			}

			if (countdown >= 0) {									//�\������Ă���^�C�}�[��0�ɂ������̂ŃJ�E���g�_�E�����̂�0�ɂȂ�܂œ�����
				countdown -= 1;										//�J�E���g�_�E��
			}
		}
	}

	if (isCount == false)
	{
		
	}

	if (type == bomb)
	{
		if (isXplosion == true)			//��������
		{
			//SE::Instance()->PlaySE(SE_bomb);		//�����̉�
			isTrigger = true;
			isXplosion = false;
			isSpown = false;
			
		}
	}

	if (type == fakebomb)
	{
		if (isXplosion == true)			//��������
		{
			isTrigger = true;
			isXplosion = false;
			//isCount = false;
			isFakeSpown = false;
		}
	}
}



