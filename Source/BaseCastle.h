#ifndef _BASECASTLE_H
#define _BASECASTLE_H

#include "Object.h"

/*-------------------------------------------------------------
�I�u�W�F�N�g��    BaseCastle
�T�v    ���_�̌��ɂȂ�I�u�W�F�N�g
�A�N�Z�X
�p���N���X    Object(�I�u�W�F�N�g)
�Ă΂��
�ڍא���    Object����p�������A���_�̌�
--------------------------------------------------------------*/

class EnemyManager;

class BaseCastle :public Object {
protected:
	static const int MAX_DURABILITY;		//�ő�ϋv��			

	int durability;		                    //���_�̗̑�

	bool isActive;		                    //���_�̐����t���O

	//�G�ɑ����̒n�_����o������G�̃p�����[�^
	float enemySpeed;                       //�G�̃X�s�[�h
	float enemyPower;                       //�G�̃p���[
	int enemyDurability;                    //�G�̗̑�
	int enemyDirection;                     //�G�̕���

public:
	BaseCastle(int);                        //�R���X�g���N�^

	virtual void Update(EnemyManager*) {} 	//�X�V����
	virtual void Draw() {}		        	//�`�揈��

	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh) 
	{
		return isActive;
	}
	// m = my ����   o = opnet ����	//�����蔻�菈��

	//�Q�b�^�[
	//���_�֘A
	int   Get_Durability() { return durability; }

	bool  GetIsActive()    { return isActive; }

	float Get_X() { return x; }
	float Get_Y() { return y; }
	float Get_Width() { return width; }
	float Get_Height() { return height; }

	//�G�p�����[�^�֘A
	float Get_EnemySpeed() { return enemySpeed; }
	float Get_EnemyPower() { return enemyPower; }
	int Get_EnemyDurability() { return enemyDurability; }
	int Get_EnemyDirection() { return enemyDirection; }

	//�Z�b�^�[
	//���_�֘A
	void Set_Durability(int _durability) { durability = _durability; }
	void Set_IsActive(bool _flg) { isActive = _flg; }

	//�G�p�����[�^�֘A
	void Set_EnemySpeed(float _speed) { enemySpeed = _speed; }
	void Set_EnemyPower(float _power) { enemyPower = _power; }
	void Set_EnemyDurability(int _durability) { enemyDurability = _durability; }
	void Set_EnemyDirection(int _direction) { enemyDirection = _direction; }
};

#endif //_BASECASTLE_H_