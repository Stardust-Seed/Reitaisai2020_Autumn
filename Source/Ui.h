#ifndef _UI_H
#define _UI_H

#include "CastleManager.h"
#include "ItemManager.h"
#include "BuffManager.h"

class CastleManager;
class ItemManager;
class BuffManager;
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
	static const int MAX_SABDURABILTY = 50;	//�T�u���_�ő�̗�

	static const int PMOJI_X = 1150;			//�����̂�
	static const int PMOJI_Y = 760;
	static const int PBAR_X = 1200;				//�g�̂��n�_
	static const int PBAR_Y = 760;
	static const int PBAR_X1 = 1200;			//�g�̂��I�_
	static const int PBAR_Y1 = 760;
	static const int PGAUGE_X = 1200;			//�o�[�̂��n�_
	static const int PGAUGE_Y = 760;
	static const int PGAUGE_X1 = 1200;			//�o�[�̂��I�_
	static const int PGAUGE_Y1 = 760;

	static const int SMOJI_X = 1150;			//�����̂�
	static const int SMOJI_Y = 800;
	static const int SBAR_X = 1200;				//�g�̂��n�_
	static const int SBAR_Y = 800;
	static const int SBAR_X1 = 1200;			//�g�̂��I�_
	static const int SBAR_Y1 = 800;
	static const int SGAUGE_X = 1200;			//�o�[�̂��n�_
	static const int SGAUGE_Y = 800;
	static const int SGAUGE_X1 = 1200;			//�o�[�̂��I�_
	static const int SGAUGE_Y1 = 800;

	const float MAX_BUFF = 10.0;				//�o�t�Q�[�W�̍ő吔

	int percent;					//�p�[�Z���g
	int CastleDurability;			//���_�̗̑�
	int pBuffPoint;					//p�A�C�e���̃Q�[�W�㏸�p
	int sBuffPoint;					//s�A�C�e���̃Q�[�W�㏸�p
	int pBuffLevel;					//p�A�C�e���l�����̃o�t���x��
	int sBuffLevel;					//s�A�C�e���l�����̃o�t���x��
	int Color;						//�F

public:
	void Get_CastleDurability();		//���C�����_�̗̑�UI
	void Get_BuffPoint();
	void Get_SubCastleDurability();		//�T�u���_�̗̑�UI 
	void Update(CastleManager* _castlemanager, ItemManager* _itemmanager, BuffManager* _buffmanager);		//�X�V����
	void Draw();						//�`�揈��
};

#endif 
