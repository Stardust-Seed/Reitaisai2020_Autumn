#ifndef _BASEPLAYER_H
#define _BASEPLAYER_H

#include "Object.h"

/*-------------------------------------------------------------
�I�u�W�F�N�g��:	BasePlayer
�T�v	      : �v���C���[�̌��ɂȂ�I�u�W�F�N�g
�A�N�Z�X      :
�p���N���X	  : Object(�I�u�W�F�N�g)
�Ă΂��      :
�ڍא���	  : Object����p�������A�v���C���[�̌��ƂȂ�v���C���[
--------------------------------------------------------------*/

class BasePlayer:public virtual Object {

protected:

	const float	PLAYER_SPOWNPOSX;	//�v���C���[�̏����ʒu_X
	const float	PLEYER_SPOWNPOSY;	//�v���C���[�̏����ʒu_Y

	int speed;		                //�v���C���[�̈ړ����x
	int power;		                //�v���C���[�̍U����
	int stanTime;	                //�v���C���[�̃X�^���^�C��
	int attackTime;                 //�v���C���[�̍U���Ԋu

	bool isDamage;                  //�v���C���[�̔�e�t���O

public:
	 virtual bool ClisionHit(float mx, float my, float mw, float mh,
		     float ox, float oy, float ow, float oh) = 0;
	 //m = my ����   o = opnet ����

	 virtual void Update();         //�X�V����
	 virtual void Draw();           //�`�揈��
	 virtual void Move();           //�ړ�����
	 virtual void Attack();         //�U������

	 virtual void Set_x(int _x) { x = _x; }                        //�Z�b�^�[
	 virtual void Set_y(int _y) { y = _y; }                        //�Z�b�^�[
	 virtual void Set_width(int _width) { width = _width; }        //�Z�b�^�[
	 virtual void Set_height(int _height) { height = _height; }    //�Z�b�^�[

	 virtual int Get_x() { return x; }                             //�Q�b�^�[
	 virtual int Get_y() { return y; }                             //�Q�b�^�[
	 virtual int Get_width() { return width; }                     //�Q�b�^�[
	 virtual int Get_height() { return height; }                   //�Q�b�^�[

};

#endif //_BASEPLAYER_H