#ifndef _MAINCASTLE_H
#define _MAINCASTLE_H

#include "BaseCastle.h"

/*-------------------------------------------------------------
�I�u�W�F�N�g��:	MainCastle
�T�v	      : ���_
�A�N�Z�X      :
�p���N���X    : Object(�I�u�W�F�N�g)
�Ă΂��      :
�ڍא���	  : ���_
--------------------------------------------------------------*/

class EnemyManager;

class MainCastle:public virtual BaseCastle{

private:
	int addSize;
public:
	 MainCastle(int);

	 void Update(EnemyManager*);                     //�X�V����
	 void Draw();                                    //�`�揈��
};

#endif //_MAINCASTLE_H