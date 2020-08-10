#ifndef _BASEENEMY_H
#define _BASEENEMY_H

#include "Object.h"

class Castle;
class BasePlayer;

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
	int durability;		//�G�l�~�[�̗̑�
	int direction;		//�G�l�~�[�̐i�s����

	bool isAttack;		//�G�l�~�[�̍U���t���O
	bool isActive;		//�G�l�~�[�̐����t���O

public:
	BaseEnemy(){}
	virtual ~BaseEnemy(){}

	BaseEnemy(float _speed, float _power, int _durability, int _direction);
	virtual void Update(Castle* _castle, BasePlayer* _player) {}	//�X�V����
	void Move();					//�ړ�����
	void SearchCastle(float _ox, float _oy, float _ow, float _oh);	//��͈͓̔����T�[�`
	void SearchPlayer(float _px, float _py, float _pw, float _ph);	//�v���C���[���U���͈͓��ɂ��邩�T�[�`
	void JudgeActive();		//�A�N�e�B�u���𔻒f����
	void AttackProc();		//�U�����̎��ԏ���

	void Set_X(float _x) { x = _x; }						//x���W��ݒ肷��
	void Set_Y(float _y) { y = _y; }						//y���W��ݒ肷��
	void Set_Width(float _width) { width = _width; }		//width��ݒ肷��
	void Set_Height(float _height) { height = _height; }	//height��ݒ肷��

	float Get_X() { return x; }				//x���W���擾����
	float Get_Y() { return y; }				//y���W���擾����
	float Get_Width() { return width; }		//width���擾����
	float Get_Height() { return height; }	//height���擾����
	float GetPower() { return power; }		//�G�l�~�[�̍U���͂��擾����
	bool GetIsActive() { return isActive; }	//�����t���O���擾����
	bool GetIsAttack() { return isAttack; }	//�A�^�b�N�t���O���擾����
	
	virtual bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);
	// m = my ����   o = opnet ����	//�����蔻�菈��

	virtual void Draw() {}   //�`�揈��
};

#endif _BASEENEMY_HS