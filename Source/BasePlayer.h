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

	const float	PLAYER_SPOWNPOSX = 392;	   //�v���C���[�̏����ʒu_X
	const float	PLAYER_SPOWNPOSY = 348;	   //�v���C���[�̏����ʒu_Y
	const float PLAYER_UPDOWNPOSX = 485;   //�v���C���[�̏�Ɖ��̈ʒuX
	const float PLAYER_UPPOSY = 264;       //�v���C���[�̏�̈ʒuY
	const float PLAYER_DOWNPOSY = 456;     //�v���C���[�̉��̈ʒuY
	const float PLAYER_LEFTRIGHTPOS = 345; //�v���C���[�̍��ƉE�̍���
	const float PLAYER_LEFTPOS = 392;      //�v���C���[�̍��̈ʒu
	const float PLAYER_RIGHTPOS = 584;     //�v���C���[�̉E�̈ʒu

	int speed;		                //�v���C���[�̈ړ����x
	int power;		                //�v���C���[�̍U����
	int stanTime;	                //�v���C���[�̃X�^���^�C��
	int attackTime;                 //�v���C���[�̍U���Ԋu

	int PlayerPos;                  //�v���C���[�̂���ꏊ
	// 0 = ��         1 = ��        2 = �E         3 = ��

	int isMove;                     //�v���C���[�̈ړ�����
	// 0 = ���ֈړ�   1 =��ֈړ�   2 = �E�ֈړ�   3 = ���ֈړ�   4 = �Ȃ�

	bool isMoveKey;                 //�L�[���͂ɂ��ړ������`�F�b�N����t���O�B���Έړ������Ƃ̏d����h������
	bool isOps;                     //���Έړ��������N�����邽�߂̃t���O
	bool isOps_RUN;                 //���Έړ����������s���邽�߂̃t���O
	bool isOps_UP;                  //��̔��΂Ɉړ����邽�߂̃t���O
	bool isOps_DOWN;                //���̔��΂Ɉړ����邽�߂̃t���O
	bool isOps_LEFT;                //���̔��΂Ɉړ����邽�߂̃t���O
	bool isOps_RIGHT;               //�E�̔��΂Ɉړ����邽�߂̃t���O
	bool isDamage;                  //�v���C���[�̔�e�t���O

	//�e�X�g�p
	int x2;
	int y2;

public:
	 virtual bool ClisionHit(float mx, float my, float mw, float mh,
		     float ox, float oy, float ow, float oh) = 0;
	 //m = my ����   o = opnet ����

	 BasePlayer();                  //�x�[�X�v���C���[�̃R���X�g���N�^

	 virtual void Update();         //�X�V����
	 virtual void Draw();           //�`�揈��
	 virtual void Move();           //�ړ�����
	 virtual void Move_UP();        //���ړ�����
	 virtual void Move_DOWN();      //���ړ�����
	 virtual void Move_LEFT();      //���ړ�����
	 virtual void Move_RIGHT();     //���ړ�����
	 virtual void Move_OPS();       //���Έړ�����:�N��
	 virtual void Move_OPSRUN();    //���Έړ�����:����
	 virtual void Attack();         //�U������

	 virtual void Set_x(float _x) { x = _x; }                        //�Z�b�^�[
	 virtual void Set_y(float _y) { y = _y; }                        //�Z�b�^�[
	 virtual void Set_width(float _width) { width = _width; }        //�Z�b�^�[
	 virtual void Set_height(float _height) { height = _height; }    //�Z�b�^�[

	 virtual float Get_x() { return x; }                             //�Q�b�^�[
	 virtual float Get_y() { return y; }                             //�Q�b�^�[
	 virtual float Get_width() { return width; }                     //�Q�b�^�[
	 virtual float Get_height() { return height; }                   //�Q�b�^�[

};

#endif //_BASEPLAYER_H