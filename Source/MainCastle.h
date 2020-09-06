#ifndef _MAINCASTLE_H
#define _MAINCASTLE_H

#include "BaseCastle.h"
#include "Define.h"
#include "SE.h"
/*-------------------------------------------------------------
�I�u�W�F�N�g��:	MainCastle
�T�v	      : ���_
�A�N�Z�X      :
�p���N���X    : Object(�I�u�W�F�N�g)
�Ă΂��      :
�ڍא���	  : ���_
--------------------------------------------------------------*/

class EnemyManager;

class MainCastle:public BaseCastle{

private:

public:
	 MainCastle(int);

	 bool ClisionHit(float ox, float oy, float ow, float oh,
		  int pow, int num, bool attackFlg, bool activeFlg);

	 void Update(EnemyManager*);               //�X�V����
	 void Draw();                              //�`�揈��

};

#endif //_MAINCASTLE_H