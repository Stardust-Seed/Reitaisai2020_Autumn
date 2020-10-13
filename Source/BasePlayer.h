#ifndef _BASE_PLAYER_H
#define _BASE_PLAYER_H

#include"Object.h"
#include"DxLib.h"
#include "FontHandle.h"

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
	int playerType;


protected:
	const float PI = 3.141592654;

	const float PLAYER_SPOWNPOSX = 841;	    //�v���C���[�̏����ʒu_X
	const float PLAYER_SPOWNPOSY = 516;	    //�v���C���[�̏����ʒu_Y

	const float PLAYER_UPDOWNPOSX = 936;    //�v���C���[�̏�Ɖ��̈ʒuX

	const float PLAYER_UPPOSY = 426;        //�v���C���[�̏�̈ʒuY
	const float PLAYER_DOWNPOSY = 606;      //�v���C���[�̉��̈ʒuY

	const float PLAYER_LEFTRIGHTPOS = 516;  //�v���C���[�̍��ƉE�̍���
	const float PLAYER_LEFTPOS = 841;       //�v���C���[�̍��̈ʒu

	const float PLAYER_RIGHTPOS = 1026;     //�v���C���[�̉E�̈ʒu

	const int ANIMETION_MAX = 3;            //�A�j���[�V�����̍ő吔
	const int ANIMETION_SPEED = 10;         //�A�j���[�V�����̃X�s�[�h

	//���X�L���p
	const int STOPTIME = 5;         //���~�߃X�L���̎���
	int abilityTimer;               //�X�L����������
	int countDown;                  //�X�L���^�C�}�[�̃J�E���g�_�E���Ɏg�p

	//�t�����X�L���p
	const int FRANTIME = 3;
	int franTimer;
	bool franAbility;

	int drawCount;                  //�`��J�E���g
	double drawAngle;               //�`��p�x
	double drawZoom;                //�`��g�嗦

	int speed;		                //�v���C���[�̈ړ����x
	int power;		                //�v���C���[�̍U����
	int stanTime;	                //�v���C���[�̃X�^���^�C��
	int stanTime_stay;              //��x�X�^�����Ă��玟�ɂ܂��X�^������܂ł̎���
	int attackTime;                 //�U���Ԋu
	int star01X;                    //�X�^���X�^�[�@��x���W
	int star01Y;                    //�X�^���X�^�[�@��y���W
	int star02X;                    //�X�^���X�^�[�A��x���W
	int star02Y;                    //�X�^���X�^�[�A��y���W

	int graphNo;                    //�摜�ԍ�                0,1:��� 2,3:�t����
	int sakuyaAnim[4] = {2,2,3,3 }; //���A�j���[�V��������
	int franAnim[4] = { 0,0,1,1 };  //�t�����A�j���[�V�����ԍ�
	int animNo;                     //�A�j���[�V�����ԍ�
	int animWait;                   //�A�j���[�V�����ҋ@����

	bool animLR;                    //�A�j���[�V�����̍��E true :�� false :��

	bool isAbility;                 //�X�L�����������Ă����Ԃ��ǂ���
	int  abilityCount;              //�X�L����
	int  bulletCount;               //�e�̃J�E���g

	int playerDirection;                  //�v���C���[�̌���
	// 0 = ��         1 = ��        2 = �E         3 = ��

	bool isMove;                   //���݈ړ����̃t���O

	bool isDraw;                    //�v���C���[�`��t���O
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
	BasePlayer( int _pType);		   //�R���X�g���N�^
	~BasePlayer();         //�f�X�g���N�^
	void Draw();           //�`�揈��
	void Draw_Arow();      //���`��
	void Draw_Ability();   //�X�L���G�t�F�N�g�`��

	//�X�V����
	void Update(EnemyManager* _eManager,BuffManager* _bManager);

	void Move();           //�ړ�����
	void Move_UP();        //���ړ�����
	void Move_DOWN();      //���ړ�����
	void Move_LEFT();      //���ړ�����
	void Move_RIGHT();     //���ړ�����
	void Attack();         //�U������
	void Animation();      //�A�j���[�V����
	void onAbility();      //�X�L����������
	void CharaAbility();   //�X�L������

	//�X�^������
	void Stan(BuffManager* _bManager);           

	void Set_x(float _x) { pos.x = _x; }                    //�Z�b�^�[
	void Set_y(float _y) { pos.y = _y; }                    //�Z�b�^�[
	void Set_width(float _width) { width = _width; }        //�Z�b�^�[
	void Set_height(float _height) { height = _height; }    //�Z�b�^�[
	void Set_isAbility(bool _isAbility) { isAbility = _isAbility; } //�X�L����Active�Z�b�^�[
	void Set_abilityCount(int _abilityCount) { abilityCount = _abilityCount; }  //�X�L���񐔂̃Z�b�^�[      

	float Get_x() { return pos.x; }                         //x���W�Q�b�^�[
	float Get_y() { return pos.y; }                         //y���W�Q�b�^�[
	float Get_cx() { return pos.x + 24; }                   //cx���W�Q�b�^�[
	float Get_cy() { return pos.y + 24; }                   //cy���W�Q�b�^�[
	float Get_width() { return width; }                     //width�Q�b�^�[
	float Get_height() { return height; }                   //height�Q�b�^�[

	int  Get_power() { return power; }                      //�U���̓Q�b�^�[

	bool Get_isStan() { return isStan; }                    //�X�^����ԃQ�b�^�[
	bool Get_isAbility() { return isAbility; }              //�X�L����Active�̃Q�b�^�[
	
	void SetBulletManager(BulletManager* bullet) { bulletManager = bullet; }//bulletManager�̃A�h���X���擾

	int Get_AbilityType() { return playerType; }            //�X�L���^�C�v�̃Q�b�^�[

	bool Get_FranAbility(){ return franAbility; }          //�t�����A�r���e�B�̃Q�b�^�[
	int Get_AbilityCount() { return abilityCount; }         //�X�L���񐔂̃Q�b�^�[
	int Get_AbilityClock() { return abilityTimer; }        //�X�L�����Ԃ̃Q�b�^�[
};


#endif _BASE_PLAYER_H_