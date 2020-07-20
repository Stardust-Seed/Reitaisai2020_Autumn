#ifndef _BASEENEMY_H
#define _BASEENEMY_H
#include "Object.h"

/*-------------------------------------------------------------
�I�u�W�F�N�g��    BaseEnemy
�T�v    �G�l�~�[�̌��ɂȂ�I�u�W�F�N�g
�A�N�Z�X
�p���N���X    Object(�I�u�W�F�N�g)
�Ă΂��
�ڍא���    Object����p�������A�G�l�~�[�̌��ƂȂ�G�l�~�[
--------------------------------------------------------------*/

class BaseEnemy :Object {
	
protected:
	const float ENEMY_SPAWNXLEFT;	//�G�l�~�[�̏����ʒuX��
	const float ENEMY_SPAWNYLEFT;	//�G�l�~�[�̏����ʒuY��
	const float ENEMY_SPAWNXUP;		//�G�l�~�[�̏����ʒuX��
	const float ENEMY_SPAWNYUP;		//�G�l�~�[�̏����ʒuY��
	const float ENEMY_SPAWNXRIGHT;	//�G�l�~�[�̏����ʒuX�E
	const float ENEMY_SPAWNYRIGHT;	//�G�l�~�[�̏����ʒuY�E
	const float ENEMY_SPAWNXDOWN;	//�G�l�~�[�̏����ʒuX��
	const float ENEMY_SPAWNYDOWN;	//�G�l�~�[�̏����ʒuY��

	float speed;		//�G�l�~�[�̈ړ����x
	float power;		//�G�l�~�[�̍U����
	float dulability;	//�G�l�~�[�̗̑�
	float direction;	//�G�l�~�[�̐i�s����

	bool isAttack;		//�G�l�~�[�̍U���t���O
	bool isActive;		//�G�l�~�[�̐����t���O

public:
	virtual void Updata();		//�X�V����
	virtual void Move();		//�ړ�����
	virtual void Tackle();		//���_��v���C���[�ɑ΂���U������
	virtual void SearchPlayer();//�v���C���[���U���͈͓��ɂ��邩�T�[�`
	virtual void JudgeActive();	//�A�N�e�B�u���𔻒f����

	virtual int GetPower();		//�G�l�~�[�̍U���͎擾

	virtual bool GetisAttack();	//�A�^�b�N�t���O�̎擾
	

	virtual bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh) = 0;
	// m = my ����   o = opnet ����	//�����蔻�菈��

	virtual void Draw();   //�`�揈��

};

#endif _BASEENEMY_H