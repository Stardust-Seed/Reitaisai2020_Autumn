#ifndef _BASE_PLAYER_H
#define _BASE_PLAYER_H

#include"Object.h"
#include"DxLib.h"

class BulletManager;
class BuffManager;
class EnemyManager;
class BaseEnemy;

enum PlayerType
{
	//�L�����N�^�[
	SAKUYA,     //���
	FRAN        //�t����
};

//�L�����N�^�[�X�L���^�C�v
enum AbilityType
{
	//�L�����̃X�L���^�C�v
	SAKUYA_Ability,         //���̃X�L��
	FRAN_Ability            //�t�����̃X�L��
};

class BasePlayer :public virtual Object
{
	//�e�Ǘ��̃|�C���^�ϐ�
	BulletManager* bulletManager;

	//�G�l�~�[�Ǘ��̃|�C���^�ϐ�
	EnemyManager* enemyManager;

	//�G�l�~�[�̃|�C���^�ϐ�
	BaseEnemy* baseEnemy;

	//�L�����N�^�[�I��
	PlayerType playerType;

	//�L�����̃A�r���e�B
	AbilityType abilityType;

protected:

	const float PLAYER_SPOWNPOSX = 846;	    //�v���C���[�̏����ʒu_X
	const float PLAYER_SPOWNPOSY = 516;	    //�v���C���[�̏����ʒu_Y

	const float PLAYER_UPDOWNPOSX = 936;    //�v���C���[�̏�Ɖ��̈ʒuX

	const float PLAYER_UPPOSY = 426;        //�v���C���[�̏�̈ʒuY
	const float PLAYER_DOWNPOSY = 606;      //�v���C���[�̉��̈ʒuY

	const float PLAYER_LEFTRIGHTPOS = 516;  //�v���C���[�̍��ƉE�̍���
	const float PLAYER_LEFTPOS = 846;       //�v���C���[�̍��̈ʒu

	const float PLAYER_RIGHTPOS = 1026;     //�v���C���[�̉E�̈ʒu

	int speed;		                //�v���C���[�̈ړ����x
	int power;		                //�v���C���[�̍U����
	int stanTime;	                //�v���C���[�̃X�^���^�C��
	int stanTime_stay;              //��x�X�^�����Ă��玟�ɂ܂��X�^������܂ł̎���
	int attackTime;                 //�U���Ԋu

	bool isAbility;                 //�X�L�����������Ă����Ԃ��ǂ���
	int  abilityCount;              //�X�L����

	float width;
	float height;

	int playerPos;                  //�v���C���[�̌���
	// 0 = ��         1 = ��        2 = �E         3 = ��

	bool isMove;                   //���݈ړ����̃t���O

	bool isAttack;                  //�U���t���O
	bool isStan;                    //�X�^�������ǂ����̃t���O
	bool isStan_Next;               //�X�^�����N�����Ԃ��ǂ����̃t���O

public:

	//DX���C�u�����Œ�`����Ă���\����
//���g��float�^��(x,y,z)
	VECTOR pos;                     //�v���C���[�̍��W

	VECTOR vPos;                    //�v���C���[���ړ������邽��

	//�����蔻��
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);
	BasePlayer() {}
	BasePlayer( PlayerType _pType, AbilityType _pAbility);		   //�R���X�g���N�^
	~BasePlayer();         //�f�X�g���N�^
	void Draw();           //�`�揈��

	//�X�V����
	void Update(EnemyManager* _eManager,BuffManager* _bManager);

	void Move();           //�ړ�����
	void Move_UP();        //���ړ�����
	void Move_DOWN();      //���ړ�����
	void Move_LEFT();      //���ړ�����
	void Move_RIGHT();     //���ړ�����
	void Attack();         //�U������

	//�X�^������
	void Stan();           

	void Set_x(float _x) { pos.x = _x; }                    //�Z�b�^�[
	void Set_y(float _y) { pos.y = _y; }                    //�Z�b�^�[
	void Set_width(float _width) { width = _width; }        //�Z�b�^�[
	void Set_height(float _height) { height = _height; }    //�Z�b�^�[
	void Set_isAbility(bool _isAbility) { isAbility = _isAbility; } //�X�L����Active�Z�b�^�[
	void Set_abilityCount(int _abilityCount) { abilityCount = _abilityCount; }  //�X�L���񐔂̃Z�b�^�[      

	float Get_x() { return pos.x; }                         //x���W�Q�b�^�[
	float Get_y() { return pos.y; }                         //y���W�Q�b�^�[
	float Get_width() { return width; }                     //width�Q�b�^�[
	float Get_height() { return height; }                   //height�Q�b�^�[

	int  Get_power() { return power; }                      //�U���̓Q�b�^�[
	int  Get_abilityCount() { return abilityCount; }              //�X�L�����Ԃ̃Q�b�^�[

	bool Get_isStan() { return isStan; }                    //�X�^����ԃQ�b�^�[
	bool Get_isAbility() { return isAbility; }           //�X�L����Active�̃Q�b�^�[
	
	void SetBulletManager(BulletManager* bullet) { bulletManager = bullet; }//bulletManager�̃A�h���X���擾

	AbilityType Get_AbilityType() { return abilityType; }  //�X�L���^�C�v�̃Q�b�^�[
};


#endif _BASE_PLAYER_H_