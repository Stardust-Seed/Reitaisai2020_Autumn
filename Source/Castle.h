#ifndef _CASTLE_H
#define _CASTLE_H

#include "Object.h"

/*-------------------------------------------------------------
�I�u�W�F�N�g��:	Castle
�T�v	      : ���_
�A�N�Z�X      :
�p���N���X    : Object(�I�u�W�F�N�g)
�Ă΂��      :
�ڍא���	  : ���_
--------------------------------------------------------------*/

class Castle:Object{

private:

	int Durability;	//�ϋv��

	bool isActive;	//���_�̐����t���O

public:

	void EnemyHit(int _power);    //�G���Փ˂��Ă�������s�����֐�

};

#endif //_CASTLE_H