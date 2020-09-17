#ifndef _SAKUYA_H_
#define _SAKUYA_H

#include "BasePlayer.h"
#include "EnemyManager.h"

class EnemyManager;

class Fran :public virtual BasePlayer
{
private:

	int abilityTimer;     //�X�L����������

	int countDown;        //�X�L���^�C�}�[�̃J�E���g�_�E���Ɏg�p

	unsigned int color;   //�X�L�����Ԃ̐F

public:

	Fran();			   //�R���X�g���N�^
	~Fran();             //�f�X�g���N�^
	void Update();         //�X�V����
	void SkilClock();      //�X�L���^�C�}�[�`�揈��
	void Ability();        //�X�L������

};

#endif //_SAKUYA_H_
