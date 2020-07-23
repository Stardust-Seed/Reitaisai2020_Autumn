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

class Castle:public virtual Object{

private:
	static const int MAX_DURABILITY;    //�ő�ϋv��

	int Durability;	                    //�ϋv��

	bool isActive;	                    //���_�̐����t���O

public:
	 Castle();
	 bool ClisionHit(float mx, float my, float mw, float mh,
		     float ox, float oy, float ow, float oh);
	 //m = my ����   o = opnet ����

	 void Update();                //�X�V����
	 void Draw();                  //�`�揈��
	 void HitDamage();             //�_���[�W����
	 void JudgeActive();           //�������菈��

	 void Set_x(int _x) { x = _x; }                                 //�Z�b�^�[
	 void Set_y(int _y) { y = _y; }                                 //�Z�b�^�[
	 void Set_width(int _width) { width = _width; }                 //�Z�b�^�[
	 void Set_height(int _height) { height = _height; }             //�Z�b�^�[
	 void Set_IsActive(bool _isActive) { isActive = _isActive; }    //�Z�b�^�[

	 int Get_x() { return x; }                                      //�Q�b�^�[
	 int Get_y() { return y; }                                      //�Q�b�^�[
	 int Get_width() { return width; }                              //�Q�b�^�[
	 int Get_height() { return height; }                            //�Q�b�^�[
	 int Get_IsActive() { return isActive; }                        //�Q�b�^�[
};

#endif //_CASTLE_H