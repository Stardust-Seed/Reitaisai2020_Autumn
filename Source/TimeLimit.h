#ifndef _TIMELIMIT_H
#define _TIMELIMIT_H

class TimeLimit {
private:
	static const int FRAME = 100;							//�t���[�����[�g(�����I�ɂ�60fps)

	static const int TIME = 10;								//���ۂ̐�������

	static const int MAX_LIMITTIME = FRAME * (TIME + 1)	-1;	// �t���[�����[�g * (�w�肵���b�� +1) - 1 // "+1) - 1"���̕����͕\���̈�a�����Ȃ�������

	int timer;						//��������(�����\��)
	
	int color;						//�e�L�X�g�J���[

	bool finishTime;				//�I���t���O

public:
	TimeLimit();					//�R���X�g���N�^

	void Update();					//�X�V����

	void Draw();					//�`�揈��

	void CountDown();				//�J�E���g�_�E��
};

#endif //_TIMELIMIT_H
