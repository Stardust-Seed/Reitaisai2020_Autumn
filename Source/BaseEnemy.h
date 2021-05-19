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
	Endurance	= 4,	//�̗͌^
	Bomb		= 6,	//���j��
	Boss		= 8		//�{�X
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

	const int ANIMATION_SWITCHING = 30;		//�A�j���[�V�����̐؂�ւ��t���O

	const float ATTACK_MOTION_JUNPPOWER		= 15.0f / 15.0f;	//������ւ̃W�����v��

	float speed;			//�G�l�~�[�̈ړ����x
	float power;			//�G�l�~�[�̍U����
	int durability;			//�G�l�~�[�̗̑�
	eDirection direction;	//�G�l�~�[�̐i�s����
	eEnemyType enemyType;	//�G�l�~�[�̎��

	int animationCnt;	//�A�j���[�V�����J�E���^
	int attackCnt;		//�U�����̃J�E���^
	int coolDownCnt;	//�N�[���_�E���J�E���^

	int imageIndex;		//�`��w��ϐ�
	bool isTurn;		//LR���]�t���O

	bool isActive;		//�G�l�~�[�̐����t���O
	bool isAttack;		//�G�l�~�[�̍U���t���O
	bool isHitCastle;	//�锭���t���O
	bool isCoolDown;	//�N�[���_�E���t���O

	float addX;			//�U�����[�V�����p�̉��Zx
	float addY;			//�U�����[�V�����p�̉��Zy

	float distanceToPlayerX;	//�v���C���[�ƃG�l�~�[�̒��S���W�Ԃ̋���x
	float distanceToPlayerY;	//�v���C���[�ƃG�l�~�[�̒��S���W�Ԃ̋���y

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
	/// <param name="_isAbility">�v���C���[�̃A�r���e�B�t���O</param>
	/// <param name="_abilityType">�v���C���[�̃A�r���e�B�^�C�v</param>
	void Move(bool _isAbility, int _abilityType);

	/// <summary>
	/// �������菈��
	/// </summary>
	void JudgeActive();

	/// <summary>
	/// �U���̏���
	/// </summary>
	/// <param name="_cx">�v���C���[��cx���W</param>
	/// <param name="_cy">�v���C���[��cy���W</param>
	void AttackProc(float _cx, float _cy);

	/// <summary>
	/// �U�����[�V����
	/// </summary>
	/// <param name="_move">�ړ��������</param>
	/// <param name="_jump">�W�����v�������</param>
	/// <param name="_addMove">���Z������ړ��l</param>
	/// <param name="_addJump">���Z������W�����v�l</param>
	void AttackMotion(float* _move, float* _jump, float _addMove, float _addJump);

	/// <summary>
	/// �ړ�����
	/// </summary>
	/// <param name="_isAbility">�v���C���[�̃A�r���e�B�t���O</param>
	/// <param name="_abilityType">�v���C���[�̃A�r���e�B�^�C�v</param>
	void Animation(bool _isAbility, int _abilityType);

	/// <summary>
	/// �v���C���[�̃T�[�`����
	/// </summary>
	/// <param name="_px">�v���C���[��x���W</param>
	/// <param name="_py">�v���C���[��y���W</param>
	/// <param name="_pw">�v���C���[�̉���</param>
	/// <param name="_ph">�v���C���[�̏c��</param>
	/// <param name="_player">�v���C���[</param>
	void SearchPlayer(float _px, float _py, float _pw, float _ph, BasePlayer* _player);

	/// <summary>
	/// �T�[�`�̃N�[���_�E��
	/// </summary>
	void SearchCoolDownTime();

	/// <summary>
	/// ���_�̃T�[�`����
	/// </summary>
	/// <param name="_ox">���_��x���W</param>
	/// <param name="_oy">���_��y���W</param>
	/// <param name="_ow">���_�̏c��</param>
	/// <param name="_oh">���_�̏c��</param>
	/// <param name="_isActive">���_�̃A�N�e�B�u�t���O</param>
	bool SearchCastle(float _ox, float _oy, float _ow, float _oh, bool _isActive);
public:
	/// <summary>
	/// �f�t�H���g�R���X�g���N�^
	/// </summary>
	BaseEnemy(){}

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~BaseEnemy(){}

	/// <summary>
	/// �ʏ�X�|�[���p�̃R���X�g���N�^
	/// </summary>
	/// <param name="_speed">�X�|�[������Enemy�̑��x</param>
	/// <param name="_power">�X�|�[������Enemy�̍U����</param>
	/// <param name="_durability">�X�|�[������Enemy�̑ϋv��</param>
	/// <param name="_direction">�X�|�[������Enemy�̕���</param>
	/// <param name="_enemyType">�X�|�[������Enemy�̎��</param>
	BaseEnemy(float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType);

	/// <summary>
	/// �T�u���_�X�|�[���p�̃R���X�g���N�^
	/// </summary>
	/// <param name="_x">�X�|�[���ʒux���W</param>
	/// <param name="_y">�X�|�[���ʒuy���W</param>
	/// <param name="_speed">�X�|�[������Enemy�̑��x</param>
	/// <param name="_power">�X�|�[������Enemy�̍U����</param>
	/// <param name="_durability">�X�|�[������Enemy�̑ϋv��</param>
	/// <param name="_direction">�X�|�[������Enemy�̕���</param>
	/// <param name="_enemyType">�X�|�[������Enemy�̎��</param>
	BaseEnemy(float _x, float _y, float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType);

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="_castleManager">���_�̊Ǘ��N���X</param>
	/// <param name="_player">�v���C���[�N���X</param>
	/// <param name="_bulletManager">�e�̊Ǘ��N���X</param>
	virtual void Update(GameResource* _gameRes);

	/// <summary>
	/// �_���[�W����
	/// </summary>
	/// <param name="_damage">�_���[�W��</param>
	void DamageProc(int _damage);

	/// <summary>
	/// �`�揈��
	/// </summary>
	virtual void Draw(GameResource* _gameRes);

	/// <summary>
	/// x���W��ݒ肷��
	/// </summary>
	/// <param name="_x">�ݒ肷��x���W</param>
	void Set_X(float _x) { x = _x; }

	/// <summary>
	/// y���W��ݒ肷��
	/// </summary>
	/// <param name="_y">�ݒ肷��y���W</param>
	void Set_Y(float _y) { y = _y; }

	/// <summary>
	/// width��ݒ肷��
	/// </summary>
	/// <param name="_width">�ݒ肷�鉡��</param>
	void Set_Width(float _width) { width = _width; }

	/// <summary>
	/// height��ݒ肷��
	/// </summary>
	/// <param name="_height">�ݒ肷��c��</param>
	void Set_Height(float _height) { height = _height; }

	/// <summary>
	/// isAttack��ݒ肷��
	/// </summary>
	/// <param name="_isAttack">�ݒ肷��U���t���O</param>
	void SetIsAttack(bool _isAttack) { isAttack = _isAttack; }

	/// <summary>
	/// isActive��ݒ肷��
	/// </summary>
	/// <param name="_isActive">�ݒ肷��A�N�e�B�u�t���O</param>
	void SetIsActive(bool _isActive) { isActive = _isActive; }

	/// <summary>
	/// direction��ݒ肷��
	/// </summary>
	/// <param name="_direction">�ݒ肷�����</param>
	void SetDirection(eDirection _direction);

	/// <summary>
	/// x���W���擾����
	/// </summary>
	/// <returns>x���W</returns>
	float Get_X() { return x; }

	/// <summary>
	/// y���W���擾����
	/// </summary>
	/// <returns>y���W</returns>
	float Get_Y() { return y; }

	/// <summary>
	/// cx���W���擾����
	/// </summary>
	/// <returns>cx���W</returns>
	float Get_CX() { return cx; }

	/// <summary>
	/// cy���W���擾����
	/// </summary>
	/// <returns>cy���W</returns>
	float Get_CY() { return cy; }

	/// <summary>
	/// width���擾����
	/// </summary>
	/// <returns>width</returns>
	float Get_Width() { return width; }

	/// <summary>
	/// height���擾����
	/// </summary>
	/// <returns>height</returns>
	float Get_Height() { return height; }

	/// <summary>
	/// �G�l�~�[�̍U���͂��擾����
	/// </summary>
	/// <returns>�G�l�~�[�̍U����</returns>
	float GetPower() { return power; }

	/// <summary>
	/// �����t���O���擾����
	/// </summary>
	/// <returns>�����t���O</returns>
	bool GetIsActive() { return isActive; }

	/// <summary>
	/// �A�^�b�N�t���O���擾����
	/// </summary>
	/// <returns>�A�^�b�N�t���O</returns>
	bool GetIsAttack() { return isAttack; }

	/// <summary>
	/// �������擾����
	/// </summary>
	/// <returns>����</returns>
	eDirection GetDirection() { return direction; }

	/// <summary>
	/// ��A�N�e�B�u�̃^�C�v���擾����
	/// </summary>
	/// <returns>��A�N�e�B�u�̃^�C�v</returns>
	eInactiveType GetInactiveType() { return inactiveType; }

	/// <summary>
	/// �U���^�C�v���擾����
	/// </summary>
	/// <returns>�U���^�C�v</returns>
	eAttackType GetAttackType() { return attackType; }
	
	/// <summary>
	/// �����蔻�菈��
	/// </summary>
	/// <param name="mx">�G�l�~�[��x���W</param>
	/// <param name="my">�G�l�~�[��y���W</param>
	/// <param name="mw">�G�l�~�[�̉���</param>
	/// <param name="mh">�G�l�~�[�̏c��</param>
	/// <param name="ox">�����x���W</param>
	/// <param name="oy">�����y���W</param>
	/// <param name="ow">����̉���</param>
	/// <param name="oh">����̏c��</param>
	/// <returns>���������ꍇ true / ������Ȃ������ꍇ false</returns>
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);
};

#endif _BASEENEMY_H