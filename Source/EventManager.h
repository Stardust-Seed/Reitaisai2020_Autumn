#ifndef _EVENTMANAGER_H
#define _EVENTMANAGER_H

#include "BaseEvent.h"

class BaseEvent;

class EventManager {
private:
	static const int ACTIVEEVENT_EASY = 90;		//��Փx�ɂ���ĕς��C�x���g�̔����Ԋu(�b)

	static const int ACTIVEEVENT_NORMAL = 60;

	static const int ACTIVEEVENT_HARD = 30;

	static const int EVENT_TYPES = 2;			//�C�x���g�̎��

	static const int FREAM = 60;				//�t���[�����[�g

	int eventWaitTime;		//��Փx����ĕς��C�x���g�̔����Ԋu

	int eventType;			//��������C�x���g�̗���

	int waitCount;			//�C�x���g�̍ŒZ�����Ԋu

	BaseEvent* Event;		//�C�x���g������ϐ�

public:
	EventManager(int);			//�R���X�g���N�^

	~EventManager();			//�f�X�g���N�^

	void SpawnEvent();			//����

	void Update();				//�X�V

	void Draw();				//�`��

};


#endif // !_EVENTMANAGER_H
