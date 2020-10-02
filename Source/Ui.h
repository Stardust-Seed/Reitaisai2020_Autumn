#ifndef _UI_H
#define _UI_H

#include "CastleManager.h"
#include "ItemManager.h"
#include "BuffManager.h"
#include "BasePlayer.h"

class CastleManager;
class ItemManager;
class BuffManager;
class BasePlayer;
class UI
{
private:
	static const int HPMOJI_X = 0;				//�����̂�
	static const int HPMOJI_Y = 10;				
	static const int HPBAR_X = 50;				//�g�̂��n�_
	static const int HPBAR_Y = 10;		
	static const int HPBAR_X1 = 50;				//�g�̂��I�_
	static const int HPBAR_Y1 = 10;
	static const int HPGAUGE_X = 50;			//�o�[�̂��n�_
	static const int HPGAUGE_Y = 10;
	static const int HPGAUGE_X1 = 50;			//�o�[�̂��I�_
	static const int HPGAUGE_Y1 = 10;	
	static const int MAX_DURABILTY = 100;		//���C�����_�ő�̗�
	static const int MAX_SABDURABILTY = 10;	//�T�u���_�ő�̗�

	static const int PMOJI_X = 1550;			//�����̂�
	static const int PMOJI_Y = 960;
	static const int PBAR_X = 1600;				//�g�̂��n�_
	static const int PBAR_Y = 960;
	static const int PBAR_X1 = 1600;			//�g�̂��I�_
	static const int PBAR_Y1 = 960;
	static const int PGAUGE_X = 1600;			//�o�[�̂��n�_
	static const int PGAUGE_Y = 960;
	static const int PGAUGE_X1 = 1600;			//�o�[�̂��I�_
	static const int PGAUGE_Y1 = 960;

	static const int SMOJI_X = 1550;			//�����̂�
	static const int SMOJI_Y = 1000;
	static const int SBAR_X = 1600;				//�g�̂��n�_
	static const int SBAR_Y = 1000;
	static const int SBAR_X1 = 1600;			//�g�̂��I�_
	static const int SBAR_Y1 = 1000;
	static const int SGAUGE_X = 1600;			//�o�[�̂��n�_
	static const int SGAUGE_Y = 1000;
	static const int SGAUGE_X1 = 1600;			//�o�[�̂��I�_
	static const int SGAUGE_Y1 = 1000;

	const int MAX_BUFF = 15;				//�o�t�Q�[�W�̍ő吔

	static const int SKILLBAR_X = 0;				//�g�̂��n�_
	static const int SKILLBAR_Y = 160;
	static const int SKILLBAR_X1 = 0;			   //�g�̂��I�_
	static const int SKILLBAR_Y1 = 160;
	static const int SKILLGAUGE_X = 0;			   //�o�[�̂��n�_
	static const int SKILLGAUGE_Y = 160;
	static const int SKILLGAUGE_X1 = 0;			   //�o�[�̂��I�_
	static const int SKILLGAUGE_Y1 = 160;

	const int MAX_STOPTIME = 5;				//��邳��̎��~�ߍő�^�C��

	int percent;					//�p�[�Z���g
	int CastleDurability;			//���_�̗̑�
	int SubCastleDurability[5];		//���_�̐�
	int i;
	
	int pBuffPoint;					//p�A�C�e���̃Q�[�W�㏸�p
	int sBuffPoint;					//s�A�C�e���̃Q�[�W�㏸�p
	int pBuffLevel;					//p�A�C�e���l�����̃o�t���x��
	int sBuffLevel;					//s�A�C�e���l�����̃o�t���x��
	int skillCount;					//�X�L���g�p��
	int skillClock;					//�X�L���̎g�p�^�C��
	int skillType;

	bool isActive[5];
	bool skillActive;


public:
	void Get_CastleDurability();		//���C�����_�̗̑�UI
	void Get_BuffPoint();				//�A�C�e���|�C���g��UI
	void Get_SubCastleDurability();		//�T�u���_�̗̑�UI 
	void AbilityUi();					//�A�r���e�B��UI
	void Update(CastleManager* _castlemanager, ItemManager* _itemmanager, BuffManager* _buffmanager, BasePlayer* _baseplayer);		//�X�V����
	void Draw();						//�`�揈��
};

#endif 
