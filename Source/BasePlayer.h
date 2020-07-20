#ifndef _BASEPLAYER_H
#define _BASEPLAYER_H

#include "Object.h"

/*-------------------------------------------------------------
�I�u�W�F�N�g��:	BasePlayer
�T�v	      : �v���C���[�̌��ɂȂ�I�u�W�F�N�g
�A�N�Z�X      :
�p���N���X	  : Object(�I�u�W�F�N�g)
�Ă΂��      :
�ڍא���	  : Object����p�������A�v���C���[�̌��ƂȂ�v���C���[
--------------------------------------------------------------*/

class BasePlayer:Object{

protected:

	const float	PLAYER_SPOWNPOSX;	//�v���C���[�̏����ʒu_X
	const float	PLEYER_SPOWNPOSY;	//�v���C���[�̏����ʒu_Y

	int speed;		                //�v���C���[�̈ړ����x
	int power;		                //�v���C���[�̍U����
	int stanTime;	                //�v���C���[�̃X�^���^�C��
	int attackTime;                 //�v���C���[�̍U���Ԋu

	bool isDamage;                  //�v���C���[�̔�e�t���O

public:

	 virtual void Move();           //�ړ�����

	 virtual void Attack();         //�U������

};

#endif //_BASEPLAYER_H