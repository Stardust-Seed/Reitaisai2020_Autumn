#ifndef _SAKUYA_H_
#define _SAKUYA_H

#include "BasePlayer.h"
#include "EnemyManager.h"

class EnemyManager;

class Sakuya :public BasePlayer
{
private:

	static const int FRAME = 60;	//�t���[�����[�g
	const int STOPTIME = 5;         //���~�߃X�L���̎���]
	static const int TIME = 10;								//���ۂ̐�������
	static const int MAX_LIMITTIME = FRAME * (TIME + 1) - 1;	
	//�t���[�����[�g * (�w�肵���b�� +1) - 1 // "+1) - 1"���̕����͕\���̈�a�����Ȃ�������

	int speed;		                //�v���C���[�̈ړ����x
	int power;		                //�v���C���[�̍U����
	int AttackTime;                 //�U���Ԋu

	int SkilTimer;                  //�X�L����������

	int Color;                      //�X�L�����Ԃ̐F

	int CountDown;

public:

	Sakuya();			   //�R���X�g���N�^
	~Sakuya();             //�f�X�g���N�^
	void Update();         //�X�V����
	void SkilClock();      //�X�L���^�C�}�[�`�揈��
	void Skil();           //�X�L������

	int  Get_SkilTime() {return STOPTIME;}   //�X�L���̔�������

};

#endif //_SAKUYA_H_

