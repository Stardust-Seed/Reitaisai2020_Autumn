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

class BaseEnemy :public virtual Object {
	
protected:
	static const float ENEMY_SPAWNXLEFT;	//�G�l�~�[�̏����ʒuX��
	static const float ENEMY_SPAWNYLEFT;	//�G�l�~�[�̏����ʒuY��
	static const float ENEMY_SPAWNXUP;		//�G�l�~�[�̏����ʒuX��
	static const float ENEMY_SPAWNYUP;		//�G�l�~�[�̏����ʒuY��
	static const float ENEMY_SPAWNXRIGHT;	//�G�l�~�[�̏����ʒuX�E
	static const float ENEMY_SPAWNYRIGHT;	//�G�l�~�[�̏����ʒuY�E
	static const float ENEMY_SPAWNXDOWN;	//�G�l�~�[�̏����ʒuX��
	static const float ENEMY_SPAWNYDOWN;	//�G�l�~�[�̏����ʒuY��

	static const int DIRECTIONLEFT;		//������
	static const int DIRECTIONRIGHT;	//�E����
	static const int DIRECTIONUP;		//�����
	static const int DIRECTIONDOWN;		//������

	float speed;		//�G�l�~�[�̈ړ����x
	float power;		//�G�l�~�[�̍U����
	int dulability;		//�G�l�~�[�̗̑�
	int direction;		//�G�l�~�[�̐i�s����

	bool isAttack;		//�G�l�~�[�̍U���t���O
	bool isActive;		//�G�l�~�[�̐����t���O

public:
	BaseEnemy();
	virtual void Update() {}		//�X�V����
	void Move();					//�ړ�����
	virtual void Tackle() {}		//���_��v���C���[�ɑ΂���U������
	virtual void SearchPlayer() {}	//�v���C���[���U���͈͓��ɂ��邩�T�[�`
	virtual void JudgeActive();		//�A�N�e�B�u���𔻒f����

	void Set_X(int _x) { x = _x; }						//x���W��ݒ肷��
	void Set_Y(int _y) { y = _y; }						//y���W��ݒ肷��
	void Set_Width(int _width) { width = _width; }		//width��ݒ肷��
	void Set_Height(int _height) { height = _height; }	//height��ݒ肷��

	int Get_X() { return x; }				//x���W���擾����
	int Get_Y() { return y; }				//y���W���擾����
	int Get_Width() { return width; }		//width���擾����
	int Get_Height() { return height; }		//height���擾����
	int GetPower() { return power; }		//�G�l�~�[�̍U���͂��擾����
	bool GetIsAttack() { return isAttack; }	//�A�^�b�N�t���O���擾����
	

	virtual bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);
	// m = my ����   o = opnet ����	//�����蔻�菈��

	virtual void Draw() {}   //�`�揈��

};

#endif _BASEENEMY_HS