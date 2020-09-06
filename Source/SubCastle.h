#ifndef _SUBCASTLE_H
#define _SUBCASTLE_H

#include "BaseCastle.h"

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
class SubCastle :public BaseCastle {

private:
	int durability;	                    //�ϋv��
	int popEnemy;                       //�ǉ����̓G�̐�
	bool hitFlg;                        //�q�b�g�������̃t���O
	bool isActive;	                    //���_�̐����t���O

public:
	SubCastle(int,int);
	//�������g��Ȃ�
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh)
	{
		return isActive;
	}
	bool ClisionHit(float ox, float oy, float ow, float oh, int pow, int num, bool attackFlg, bool activeFlg);

	void Update(EnemyManager*);    //�X�V����
	void Draw();                   //�`�揈��

	void EnemyCastle();            //�G�p�����[�^�̐ݒ菈��

};

#endif //_SUBCASTLE_H