#ifndef _SUBCASTLE_H
#define _SUBCASTLE_H

#include "BaseCastle.h"
#include "Define.h"

/*-------------------------------------------------------------
�I�u�W�F�N�g��:	SubCastle
�T�v	      : �T�u���_
�A�N�Z�X      :
�p���N���X    : BaseCastle
�Ă΂��      :
�ڍא���	  : �T�u���_�A�j�󂳂ꂽ��G����
--------------------------------------------------------------*/

class EnemyManager;
class BaseEnemy;
class SubCastle :public virtual BaseCastle {

private:
	int posType;    //�T�u���_�̏ꏊ
	int addPosX;    //�ǉ��̍��WX(�\�������̂�)  
	int addPosY;    //�ǉ��̍��WY(�\�������̂�)  
	int addSize;    //�ǉ��̑傫��(�\�������̂�)  

public:
	SubCastle(int,int);

	void Update(EnemyManager*);    //�X�V����
	void Draw();                   //�`�揈��

};

#endif //_SUBCASTLE_H