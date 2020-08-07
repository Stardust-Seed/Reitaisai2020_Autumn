#ifndef _UI_H
#define _UI_H

#include "Castle.h"

class UI:public virtual Castle
{
private:
	static const int HPBAR_X = 10;		
	static const int HPBAR_Y = 10;		
	static const int HPBAR_X1 = 10;
	static const int HPBAR_Y1 = 10;
	static const int MAX_DURABILTY = 100;

	int percent;					//�p�[�Z���g
	int CastleDurability;			//���_�̗̑�
	int Color;						//�F

public:
	void Set_CastleDurability();		//���_�̗̑͂��󂯎��
	void Set_EnemyiesRest(int);			//�R�����g�l���܂�
	void PlayGuide();					//�v���C���[�̃K�C�h
	void Update(Castle* _castle);		//�X�V����
	void Draw();						//�`�揈��
};
#endif 
