#include <DxLib.h>
#include "BaseBomb.h"

//�R���X�g���N�^
BaseBomb::BaseBomb(int _power, eBombType _btype)
{
	//SRand;								//�����̏�����
	//type = GetRand(MAX_TYPE - 1);		//��ނ̗���
	type = bomb;
	if (type == bomb)
	{
		power = _power;
	}

	if (type == fakebomb)
	{
		power = _power;
	}
	
	
	direction = GetRand(3);					//�����̗���
	//direction = 3;
	speed = 3;
	countdown = COUNTMAX;						//�J�E���g�_�E���̃Z�b�g
	
	isSpown = false;
	isFakeSpown = false;
	isXplosion = false;							//�������
	isTrigger = false;
	isFakeTrigger = false;

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

	//DrawFormatString(10, 300, GetColor(255, 255, 255), "type%d", type);
	
	//DrawFormatString(10, 300, GetColor(255, 255, 255), "type%d", power);

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
		DrawFormatString(10, 150, GetColor(255, 255, 255), "%d", countdown / FRAME);	//�\��
		if (countdown <= FRAME) {								//�c���b�ȉ��͊���Z�̌���0�ɂȂ邽�߁A�\���^�C�~���O�̒���
			isXplosion = true;									//�t���O�ؑ�
		}

		if (countdown >= 0) {									//�\������Ă���^�C�}�[��0�ɂ������̂ŃJ�E���g�_�E�����̂�0�ɂȂ�܂œ�����
			countdown -= 1;										//�J�E���g�_�E��
		}
	}

	if (type == bomb)
	{
		if (isXplosion == true)			//��������
		{
			//DrawString(700, 300, "����", GetColor(255, 255, 255));
			isTrigger = true;
			isXplosion = false;
			isSpown = false;
		}
	}

	if (type == fakebomb)
	{
		if (isXplosion == true)			//��������
		{
			//DrawString(600, 300, "�U����", GetColor(255, 255, 255));
			isFakeTrigger = true;
			isXplosion = false;
			isFakeSpown = false;
		}
	}
}


