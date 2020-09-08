#include <DxLib.h>
#include "BaseBomb.h"

//�R���X�g���N�^
BaseBomb::BaseBomb()
{
	direction = GetRand(3);
	speed = 3;
	countdown = COUNTMAX;						//�J�E���g�_�E���̃Z�b�g

	isXplosion = false;							//�������
	isSpown = false;
	isTrigger = false;

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
	isSpown = true;
}

//���e����
void BaseBomb::Move()
{
	
	SpawnBomb();				//���e����

	if (direction == DIRECTIONLEFT)			//��
	{
		y += speed;
		if (y > BOMB_SPOWNLR + 356)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONRIGHT)		//�E
	{
		y += speed;
		if (y > BOMB_SPOWNLR + 356)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONUP)			//��
	{
		y += speed;
		if (y > BOMB_SPOWNUPY + 264)
		{
			speed = 0;
		}
	}

	if (direction == DIRECTIONDOWN)			//��
	{
		y -= speed;
		if (y < BOMB_SPOWNDOWNY - 264)
		{
			speed = 0;
		}
	}	
}

//���e�N��
void BaseBomb::JudgeTrigger()
{
	if (speed == 0)
	{
		DrawFormatString(10, 150, GetColor(255, 255, 255), "��������%d", countdown / FRAME);	//�\��
		if (countdown <= FRAME) {								//�c���b�ȉ��͊���Z�̌���0�ɂȂ邽�߁A�\���^�C�~���O�̒���
			isXplosion = true;									//�t���O�ؑ�
		}
		if (countdown >= 0) {									//�\������Ă���^�C�}�[��0�ɂ������̂ŃJ�E���g�_�E�����̂�0�ɂȂ�܂œ�����
			countdown -= 1;										//�J�E���g�_�E��
		}
	}

	if (isXplosion == true)
	{
		DrawString(700, 300, "����", GetColor(255, 255, 255));
		isTrigger = true;
	}
}

