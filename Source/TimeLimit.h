#ifndef _TIMELIMIT_H
#define _TIMELIMIT_H

class TimeLimit {
private:
	static const int MAX_LIMITTIME;	//��������

	int timer;					//��������(�����\��)

	int color;					//�e�L�X�g�J���[

	bool finishTime;			//�I���t���O

public:
	TimeLimit();				//�R���X�g���N�^

	void Update();				//�X�V����

	void Draw();				//�`�揈��

	void CountDown();			//�J�E���g�_�E��
};

#endif //_TIMELIMIT_H
