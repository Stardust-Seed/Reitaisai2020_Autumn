#ifndef _BASEENEMY_H
#define _BASEENEMY_H

#include "Direction.h"
#include "Object.h"

class CastleManager;
class BasePlayer;
class BulletManager;

/// <summary>
/// �G�l�~�[�̃^�C�v
/// </summary>
enum class eEnemyType {
	Speed		= 0,	//���x�^
	Power		= 2,	//�p���[�^
	Endurance	= 4		//�̗͌^
};

/// <summary>
/// ��A�N�e�B�u�̃^�C�v
/// </summary>
enum class eInactiveType {
	Defeat,		//���j
	Invasion,	//�N��
	None		//�������p
};

/// <summary>
/// �U���̃^�C�v
/// </summary>
enum class eAttackType {
	Invasion,	//�N�����̍U��
	Player,		//�v���C���[�ւ̍U��
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

	const int ANIMATION_SWITCHING = 30;

	const float ATTACK_ANIMATION_MOVEAMOUNT	= 48.0f / 30.0f;
	const float ATTACK_ANIMATION_JUNPPOWER	= 15.0f / 15.0f;

	float speed;			//�G�l�~�[�̈ړ����x
	float power;			//�G�l�~�[�̍U����
	int durability;			//�G�l�~�[�̗̑�
	eDirection direction;	//�G�l�~�[�̐i�s����
	eEnemyType enemyType;	//�G�l�~�[�̎��

	int animationCnt;	//�A�j���[�V�����J�E���^
	int attackCnt;		//�U�����̃J�E���^
	int coolDownCnt;	//�N�[���_�E���J�E���^

	bool isActive;		//�G�l�~�[�̐����t���O
	bool isAttack;		//�G�l�~�[�̍U���t���O
	bool isCoolDown;	//�N�[���_�E���t���O

	float addX;
	float addY;

	float distanceToPlayerX;
	float distanceToPlayerY;

	eAttackType attackType;		//�U���̃^�C�v
	eInactiveType inactiveType;	//��A�N�e�B�u�̃^�C�v

	/// <summary>
	/// ���ʂ̏��������ڂ̏���������
	/// </summary>
	/// <param name="_speed">�X�s�[�h�̏����l</param>
	/// <param name="_power">�U���͂̏����l</param>
	/// <param name="_durability">�̗͂̏����l</param>
	/// <param name="_direction">�����̏����l</param>
	/// <param name="_enemyType">�G�l�~�[�̃^�C�v���</param>
	void Init(float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType);

	/// <summary>
	/// �ړ�����
	/// </summary>
	void Move();

	/// <summary>
	/// �A�j���[�V����
	/// </summary>
	void Animation();
public:
	BaseEnemy(){}
	virtual ~BaseEnemy(){}
	BaseEnemy(float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType);
	BaseEnemy(float _x, float _y, float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType);

	virtual void Update(CastleManager* _castleManager, BasePlayer* _player,
		BulletManager* _bulletManager) {}							//�X�V����
	virtual void Draw() {}											//�`�揈��

	void SearchCastle(float _ox, float _oy, float _ow, float _oh, bool _isActive);	//��͈͓̔����T�[�`
	void SearchPlayer(float _px, float _py, float _pw, float _ph,
		BasePlayer* _player);										//�v���C���[���U���͈͓����T�[�`
	void SearchCoolDownTime();				//�T�[�`�̃N�[���_�E��
	void JudgeActive();						//�A�N�e�B�u���𔻒f����
	void AttackProc(float _cx, float _cy);	//�U�����̎��ԏ���
	void DamageProc(int _damage);			//�_���[�W����

	void Set_X(float _x) { x = _x; }										//x���W��ݒ肷��
	void Set_Y(float _y) { y = _y; }										//y���W��ݒ肷��
	void Set_Width(float _width) { width = _width; }						//width��ݒ肷��
	void Set_Height(float _height) { height = _height; }					//height��ݒ肷��
	void SetIsAttack(bool _isAttack) { isAttack = _isAttack; }				//isAttack��ݒ肷��
	void SetIsActive(bool _isActive) { isActive = _isActive; }				//isActive��ݒ肷��
	void SetDirection(eDirection _direction) { direction = _direction; }	//direction��ݒ肷��

	float Get_X() { return x; }									//x���W���擾����
	float Get_Y() { return y; }									//y���W���擾����
	float Get_CX() { return cx; }								//cx���W���擾����
	float Get_CY() { return cy; }								//cy���W���擾����
	float Get_Width() { return width; }							//width���擾����
	float Get_Height() { return height; }						//height���擾����
	float GetPower() { return power; }							//�G�l�~�[�̍U���͂��擾����
	bool GetIsActive() { return isActive; }						//�����t���O���擾����
	bool GetIsAttack() { return isAttack; }						//�A�^�b�N�t���O���擾����
	eDirection GetDirection() { return direction; }				//�������擾����
	eInactiveType GetInactiveType() { return inactiveType; }	//��A�N�e�B�u�̃^�C�v���擾����
	eAttackType GetAttackType() { return attackType; }			//�U���^�C�v���擾����
	
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);			// m = my ����   o = opnet ����	//�����蔻�菈��
};

#endif _BASEENEMY_H