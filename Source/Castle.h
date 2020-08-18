#ifndef _CASTLE_H
#define _CASTLE_H

#include "Object.h"
#include "Define.h"
#include "SE.h"
/*-------------------------------------------------------------
�I�u�W�F�N�g��:	Castle
�T�v	      : ���_
�A�N�Z�X      :
�p���N���X    : Object(�I�u�W�F�N�g)
�Ă΂��      :
�ڍא���	  : ���_
--------------------------------------------------------------*/

class EnemyManager;
class BaseEnemy;
class Castle:public virtual Object{

private:
	static const int MAX_DURABILITY;    //�ő�ϋv��

	int durability;	                    //�ϋv��

	bool hitFlg;                        //�q�b�g�������̃t���O
	bool isActive;	                    //���_�̐����t���O

public:
	 Castle();
	 //�������g��Ȃ�
	 bool ClisionHit(float mx, float my, float mw, float mh,
		 float ox, float oy, float ow, float oh) 
	 {
		 return isActive;
	 }
	 //m = my ����   o = opnet ����

	 //�������g��
	 bool ClisionHit(float ox, float oy, float ow, float oh,int pow,int num, bool attackFlg,bool activeFlg);

	 void Update(EnemyManager*);               //�X�V����
	 void Draw();                                    //�`�揈��

	 float Get_x() { return x; }                                            //�Q�b�^�[
	 float Get_y() { return y; }                                            //�Q�b�^�[
	 float Get_width() { return width; }                                    //�Q�b�^�[
	 float Get_height() { return height; }                                  //�Q�b�^�[
	 bool  Get_IsActive() { return isActive; }                              //�Q�b�^�[
	 int   Get_durability() { return durability; }                          //�Q�b�^�[
};

#endif //_CASTLE_H