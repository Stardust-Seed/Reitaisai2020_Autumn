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

	//�o�t�Ǘ��̃|�C���^�ϐ�
	BuffManager* buffManager;

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

	const float PLAYER_UPPOSY = 426;    //�v���C���[�̏�̈ʒuY
	const float PLAYER_DOWNPOSY = 606;      //�v���C���[�̉��̈ʒuY

	const float PLAYER_LEFTRIGHTPOS = 516;  //�v���C���[�̍��ƉE�̍���
	const float PLAYER_LEFTPOS = 846;       //�v���C���[�̍��̈ʒu

	const float PLAYER_RIGHTPOS = 1026;      //�v���C���[�̉E�̈ʒu

	int speed;		                //�v���C���[�̈ړ����x
	int power;		                //�v���C���[�̍U����
	int stanTime;	                //�v���C���[�̃X�^���^�C��
	int stanTime_stay;              //��x�X�^�����Ă��玟�ɂ܂��X�^������܂ł̎���
	int attackTime;                 //�U���Ԋu

	bool isAbility;             //�X�L�����������Ă����Ԃ��ǂ���
	int  abilityCount;                 //�X�L����

	float width;
	float height;

	int playerPos;                  //�v���C���[�̂���ꏊ
	// 0 = ��         1 = ��        2 = �E         3 = ��

	int isMove;						//�v���C���[�̈ړ��̊Ǘ�
	// 0 = ���ֈړ�   1 =��ֈړ�   2 = �E�ֈړ�   3 = ���ֈړ�   4 = �Ȃ�

	int now_Move;                   //���݈ړ����̃t���O

	bool isMoveKey;                 //�L�[���͂ɂ��ړ������`�F�b�N����t���O�B���Έړ������Ƃ̏d����h������
	bool isOps;                     //���Έړ��������N�����邽�߂̃t���O
	bool isOps_RUN;                 //���Έړ����������s���邽�߂̃t���O
	bool isOps_UP;                  //��̔��΂Ɉړ����邽�߂̃t���O
	bool isOps_DOWN;                //���̔��΂Ɉړ����邽�߂̃t���O
	bool isOps_LEFT;                //���̔��΂Ɉړ����邽�߂̃t���O
	bool isOps_RIGHT;               //�E�̔��΂Ɉړ����邽�߂̃t���O
	bool isDamage;                  //�v���C���[�̔�e�t���O
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

	BasePlayer( enum PlayerType _pType,enum AbilityType _pAbility);		   //�R���X�g���N�^
	~BasePlayer();         //�f�X�g���N�^
	void Draw();           //�`�揈��

	//�X�V����
	void Update(EnemyManager* _eManager,BuffManager* _bManager);

	void Move();           //�ړ�����
	void Move_UP();        //���ړ�����
	void Move_DOWN();      //���ړ�����
	void Move_LEFT();      //���ړ�����
	void Move_RIGHT();     //���ړ�����
	void Move_OPS();       //���Έړ�����:�N��
	void Move_OPSRUN();    //���Έړ�����:����
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