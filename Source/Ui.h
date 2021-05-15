#ifndef _UI_H
#define _UI_H

#include "CastleManager.h"
#include "ItemManager.h"
#include "BuffManager.h"
#include "BasePlayer.h"
#include "BulletManager.h"
#include "TimeLimit.h"

class CastleManager;
class ItemManager;
class BuffManager;
class BuletManager;
class BasePlayer;
class TimeLimit;

class UI
{
private:
	static const int HPMOJI_X = 20;				//�����̂�
	static const int HPMOJI_Y = 25;				//������y
	static const int HP_X = 250;				//HP�̐��lx
	static const int HP_Y = 15;					//HP�̐��ly
	static const int HPBAR_X = 70;				//�g�̂��n�_
	static const int HPBAR_Y = 50;		
	static const int HPBAR_X1 = 370;			//�g�̂��I�_
	static const int HPBAR_Y1 = 80;
	static const int HPGAUGE_X = 70;			//�o�[�̂��n�_
	static const int HPGAUGE_Y = 50;
	static const int HPGAUGE_X1 = 100;			//�o�[�̂��I�_
	static const int HPGAUGE_Y1 = 80;	
	static const int REDGAUGE = 10;             //�G�l�~�[�̍ő�U���͂��ꔭ��������0�ɂȂ�l
	static const int MAX_DURABILTY = 100;		//���C�����_�ő�̗�
	static const int MAX_SABDURABILTY = 25;		//�T�u���_�ő��
	

	static const int PMOJI_X = 1700;			//�����̂�
	static const int PMOJI_Y = 800;
	static const int PMOJI_X1 = 1730;
	static const int PMOJI_Y1 = 750;
	static const int PBAR_X = 1700;				//�g�̂��n�_
	static const int PBAR_Y = 1050;
	static const int PBAR_X1 = 1730;			//�g�̂��I�_
	static const int PBAR_Y1 = 800;
	static const int PGAUGE_X = 1700;			//�o�[�̂��n�_
	static const int PGAUGE_Y = 1050;
	static const int PGAUGE_X1 = 1730;			//�o�[�̂��I�_
	static const int PGAUGE_Y1 = 1050;

	static const int SMOJI_X = 1800;			//�����̂�
	static const int SMOJI_Y = 800;
	static const int SMOJI_X1 = 1830;
	static const int SMOJI_Y1 = 750;
	static const int SBAR_X = 1800;				//�g�̂��n�_
	static const int SBAR_Y = 1050;
	static const int SBAR_X1 = 1830;			//�g�̂��I�_
	static const int SBAR_Y1 = 800;
	static const int SGAUGE_X = 1800;			//�o�[�̂��n�_
	static const int SGAUGE_Y = 1050;
	static const int SGAUGE_X1 = 1830;			//�o�[�̂��I�_
	static const int SGAUGE_Y1 = 1050;

	const int MAX_BUFF = 15;					//�o�t�Q�[�W�̍ő吔

	static const int SKILLBAR_X = 0;			//�g�̂��n�_
	static const int SKILLBAR_Y = 160;
	static const int SKILLBAR_X1 = 0;			//�g�̂��I�_
	static const int SKILLBAR_Y1 = 160;
	static const int SKILLGAUGE_X = 0;			//�o�[�̂��n�_
	static const int SKILLGAUGE_Y = 160;
	static const int SKILLGAUGE_X1 = 0;			//�o�[�̂��I�_
	static const int SKILLGAUGE_Y1 = 160;

	static const int CHARGEGAUGE_X = 25;        //�`���[�W�Q�[�W�̎n�_
	static const int CHARGEGAUGE_Y = 1000;
	static const int CHARGEGAUGE_X2 = 350;     //�`���[�W�Q�[�W�̏I�_
	static const int CHARGEGAUGE_Y2 = 1040;

	const int MAX_SAKUYATIME = 5;				//��邳��̎��~�ߍő�^�C��
	const int MAX_FRANTIME = 3;					//�t��������̟r�ōő�^�C��

	int percent;					//�p�[�Z���g
	int CastleDurability;			//���_�̗̑�
	int SubCastleDurability[5];		//���_�̐�
	int castleNum;                  //�ݒu�ł���T�u���_�̐�
	int castleNumber;               //�I�𒆂̐ݒu�\��T�u���_�ԍ�
	int i;
	
	int pBuffPoint;					//p�A�C�e���̃Q�[�W�㏸�p
	int sBuffPoint;					//s�A�C�e���̃Q�[�W�㏸�p
	int pBuffLevel;					//p�A�C�e���l�����̃o�t���x��
	int sBuffLevel;					//s�A�C�e���l�����̃o�t���x��
	int skillCount;					//�X�L���g�p��
	int skillClock;					//�X�L���̎g�p�^�C��
	int skillType;
	int hundredsTime;
	int tensTime;
	int onesTime;

	float pX;						//�v���C���[��x���W
	float pY;						//�v���C���[��y���W
	float castleX[5];				//���_��x���W
	float castleY[5];				//���_��y���W

	bool isActive[5];				//�T�u���_��Active��Ԃł��邩
	bool skillActive;				//�X�L�����������Ă邩
	bool skillFran;					//�t��������̂����邪�������Ă邩

	int maxGauge;                   //�ő�Q�[�W
	int chageGauge;                 //�`���[�W�Q�[�W
	int playerPower;                //�L�����p���[


public:
	void Get_CastleDurability();		//���C�����_�̗̑�UI
	void Get_BuffPoint();				//�A�C�e���|�C���g��UI
	void Get_SubCastleDurability();		//�T�u���_�̗̑�UI 
	void AbilityUi();					//�A�r���e�B��UI
	void ChargeGage();                  //�`���[�W�Q�[�W
	void TimeLimitUi();					//�^�C�����~�b�gUI
	void Update(GameResource* _gameRes);		//�X�V����
	void Draw(GameResource* _gameRes);						//�`�揈��

};

#endif 
