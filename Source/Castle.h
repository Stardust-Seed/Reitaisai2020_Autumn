#ifndef _CASTLE_H
#define _CASTLE_H

#include "Object.h"
#include "Define.h"

/*-------------------------------------------------------------
�I�u�W�F�N�g��:	Castle
�T�v	      : ���_
�A�N�Z�X      :
�p���N���X    : Object(�I�u�W�F�N�g)
�Ă΂��      :
�ڍא���	  : ���_
--------------------------------------------------------------*/
class Fairy_Speed;
//class EnemyManager;
class Castle:public virtual Object{

private:
	static const int MAX_DURABILITY;    //�ő�ϋv��

	int durability;	                    //�ϋv��

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
	 bool ClisionHit(float ox, float oy, float ow, float oh,int pow);

	 void Update(Fairy_Speed* enemy);                //�X�V����
	 //void Update(EnemyManager* enemy);                //�X�V����
	 void Draw();                                    //�`�揈��


	 //void Set_x(float _x) { x = _x; }                                 //�Z�b�^�[
	 //void Set_y(float _y) { y = _y; }                                 //�Z�b�^�[
	 //void Set_width(float _width) { width = _width; }                 //�Z�b�^�[
	 //void Set_height(float _height) { height = _height; }             //�Z�b�^�[
	 //void Set_IsActive(bool _isActive) { isActive = _isActive; }      //�Z�b�^�[

	 float Get_x() { return x; }                                        //�Q�b�^�[
	 float Get_y() { return y; }                                        //�Q�b�^�[
	 float Get_width() { return width; }                                //�Q�b�^�[
	 float Get_height() { return height; }                              //�Q�b�^�[
	 bool Get_IsActive() { return isActive; }                           //�Q�b�^�[
};

#endif //_CASTLE_H