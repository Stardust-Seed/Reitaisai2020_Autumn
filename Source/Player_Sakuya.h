#ifndef _SAKUYA_H_
#define _SAKUYA_H

#include "BasePlayer.h"
#include "EnemyManager.h"

class EnemyManager;

class Sakuya :public virtual BasePlayer
{
private:

	static const int FRAME = 60;	//�t���[�����[�g
	const int STOPTIME = 5;         //���~�߃X�L���̎���]

	int speed;		                //�v���C���[�̈ړ����x
	int power;		                //�v���C���[�̍U����
	int attackTime;                 //�U���Ԋu

	int abilityTimer;                  //�X�L����������

	unsigned int color;                      //�X�L�����Ԃ̐F

	int countDown;                  //�X�L���^�C�}�[�̃J�E���g�_�E���Ɏg�p

public:

	Sakuya();			   //�R���X�g���N�^
	~Sakuya();             //�f�X�g���N�^
	void Update();         //�X�V����
	void SkilClock();      //�X�L���^�C�}�[�`�揈��
	void Ability();        //�X�L������

	int  Get_SkilTime() {return STOPTIME;}   //�X�L���̔�������

};

#endif //_SAKUYA_H_

