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

	int Durability;	//�ϋv��

	bool isActive;	//���_�̐����t���O

public:

	 virtual bool ClisionHit(float mx, float my, float mw, float mh,
		     float ox, float oy, float ow, float oh) = 0;
	 //m = my ����   o = opnet ����

	 virtual void Update();                //�X�V����
	 virtual void Draw();                  //�`�揈��

	 virtual void Set_x(int _x) { x = _x; }                        //�Z�b�^�[
	 virtual void Set_y(int _y) { y = _y; }                        //�Z�b�^�[
	 virtual void Set_width(int _width) { width = _width; }        //�Z�b�^�[
	 virtual void Set_height(int _height) { height = _height; }    //�Z�b�^�[

	 virtual int Get_x() { return x; }                             //�Q�b�^�[
	 virtual int Get_y() { return y; }                             //�Q�b�^�[
	 virtual int Get_width() { return width; }                     //�Q�b�^�[
	 virtual int Get_height() { return height; }                   //�Q�b�^�[

};

#endif //_CASTLE_H