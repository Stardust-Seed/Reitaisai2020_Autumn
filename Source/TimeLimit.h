#ifndef _TIMELIMIT_H
#define _TIMELIMIT_H

#include "Define.h"

class TimeLimit {
private:
	static const int TIME = 180;							//���ۂ̐�������

	static const int MAX_LIMITTIME = FRAME * (TIME + 1)	-1;	// �t���[�����[�g * (�w�肵���b�� +1) - 1 // "+1) - 1"���̕����͕\���̈�a�����Ȃ�������

	int timer;						//��������(�@�B�p)
	
	int time;						//��������(�l�ԗp)

	int color;						//�e�L�X�g�J���[

	int hundredsPlace;				//�S�̈�

	int tensPlace;					//�\�̈�

	int onesPlace;					//��̈�

	bool finishTime;				//�I���t���O

public:
	TimeLimit();					//�R���X�g���N�^

	void Update();					//�X�V����

	void Draw();					//�`�揈��

	void CountDown();				//�J�E���g�_�E��

	int Get_hundredsPlace();			//�S�̈ʂ̃Q�b�^�[

	int Get_tensPlace();			//�\�̈ʂ̃Q�b�^�[

	int Get_onesPlace();			//��̈ʂ̃Q�b�^�[

	bool Get_finishTime();			//�I���t���O�̃Q�b�^�[
};

#endif //_TIMELIMIT_H
