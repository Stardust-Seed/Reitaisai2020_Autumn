#ifndef _INPUT_H
#define _INPUT_H

#include "Singleton.h"

class Input : public Singleton<Input> {

	Input();
	friend Singleton< Input >;

public:
	int UpdateKey();	            //�L�[�̓��͏�Ԃ̍X�V�X�V
	int GetPressCount(int keyCode);	//�L�[��������Ă���t���[�����擾

private:
	static const int KEY_NUM = 256;	//�L�[����
	int KeyPressCount[KEY_NUM];		//�L�[��������Ă�ꍇ�̃J�E���^
	//int KeyRelessCount[KEY_NUM];	//�L�[��������Ă鎞�̃J�E���^

	bool IsAvailableCode(int keyCode);//keyCode���L���ȃL�[�ԍ����₤
};

#endif 