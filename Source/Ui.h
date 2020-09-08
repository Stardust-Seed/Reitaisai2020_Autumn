#ifndef _UI_H
#define _UI_H

#include "CastleManager.h"

class CastleManager;
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
	static const int MAX_DURABILTY = 100;		//���_�ő�̗�

	int percent;					//�p�[�Z���g
	int CastleDurability;			//���_�̗̑�
	int Color;						//�F

public:
	void Get_CastleDurability();		//���_�̗̑͂��󂯎��
	void PlayGuide();					//�v���C���[�̃K�C�h
	void Update(CastleManager* _castlemanager);		//�X�V����
	void Draw();						//�`�揈��
};

#endif 
