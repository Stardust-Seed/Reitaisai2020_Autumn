#ifndef _BASEENEMY_H
#define _BASEENEMY_H

#include "Direction.h"
#include "Object.h"

class CastleManager;
class BasePlayer;
class BulletManager;

/// <summary>
/// ��A�N�e�B�u�̃^�C�v
/// </summary>
enum class eInactiveType {
	Defeat,		//���j
	Invasion,	//�N��
	None		//�������p
};

/// <summary>
/// BaseEnemy class
/// </summary>
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

	float speed;			//�G�l�~�[�̈ړ����x
	float power;			//�G�l�~�[�̍U����
	int durability;			//�G�l�~�[�̗̑�
	eDirection direction;	//�G�l�~�[�̐i�s����

	bool isCoolDown;	//�N�[���_�E���t���O

	bool isAttack;		//�G�l�~�[�̍U���t���O
	bool isActive;		//�G�l�~�[�̐����t���O

	eInactiveType inactiveType;	//��A�N�e�B�u�̃^�C�v
public:
	BaseEnemy(){}
	virtual ~BaseEnemy(){}
	BaseEnemy(float _speed, float _power, int _durability, eDirection _direction);
	BaseEnemy(float _speed, float _power, int _durability, eDirection _direction, float _x, float _y);

	virtual void Update(CastleManager* _castleManager, BasePlayer* _player,
		BulletManager* _bulletManager) {}							//�X�V����
	virtual void Draw() {}											//�`�揈��

	void Move();	//�ړ�����

	void SearchCastle(float _ox, float _oy, float _ow, float _oh, bool _isActive);	//��͈͓̔����T�[�`
	void SearchPlayer(float _px, float _py, float _pw, float _ph,
		BasePlayer* _player);										//�v���C���[���U���͈͓����T�[�`
	void SearchCoolDownTime();		//�T�[�`�̃N�[���_�E��
	void JudgeActive();				//�A�N�e�B�u���𔻒f����
	void AttackProc();				//�U�����̎��ԏ���
	void DamageProc(int _damage);	//�_���[�W����

	void Set_X(float _x) { x = _x; }							//x���W��ݒ肷��
	void Set_Y(float _y) { y = _y; }							//y���W��ݒ肷��
	void Set_Width(float _width) { width = _width; }			//width��ݒ肷��
	void Set_Height(float _height) { height = _height; }		//height��ݒ肷��
	void SetIsAttack(bool _isAttack) { isAttack = _isAttack; }	//isAttack��ݒ肷��
	void SetIsActive(bool _isActive) { isActive = _isActive; }	//isActive��ݒ肷��
	void SetDirection(eDirection _direction) { direction = _direction; }

	float Get_X() { return x; }									//x���W���擾����
	float Get_Y() { return y; }									//y���W���擾����
	float Get_Width() { return width; }							//width���擾����
	float Get_Height() { return height; }						//height���擾����
	float GetPower() { return power; }							//�G�l�~�[�̍U���͂��擾����
	bool GetIsActive() { return isActive; }						//�����t���O���擾����
	bool GetIsAttack() { return isAttack; }						//�A�^�b�N�t���O���擾����
	//bool GetTset() { return isCoolDown; }
	eDirection GetDirection() { return direction; }				//�������擾����
	eInactiveType GetInactiveType() { return inactiveType; }	//��A�N�e�B�u�̃^�C�v���擾����
	
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);			// m = my ����   o = opnet ����	//�����蔻�菈��
};

#endif _BASEENEMY_H