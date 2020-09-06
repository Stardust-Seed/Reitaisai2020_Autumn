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
	int durability;	                    //�ϋv��

	bool hitFlg;                        //�q�b�g�������̃t���O
	bool isActive;	                    //���_�̐����t���O

public:
	 MainCastle(int);
	 //�������g��Ȃ�
	 bool ClisionHit(float mx, float my, float mw, float mh,
		 float ox, float oy, float ow, float oh) 
	 {
		 return isActive;
	 }
	 //m = my ����   o = opnet ����

	 //�������g��
	 bool ClisionHit(float, float, float, float,int,int, bool,bool);

	 void Update(EnemyManager*);               //�X�V����
	 void Draw();                              //�`�揈��

};

#endif //_MAINCASTLE_H