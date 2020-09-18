#ifndef _EVENTMANAGER_H
#define _EVENTMANAGER_H

#include "Define.h"
#include "DarknessEvent.h"

class BaseEvent;

class DarknessEvent;

class EventManager {
private:
	static const int ACTIVEEVENT_EASY = 60;		//��Փx�ɂ���ĕς��C�x���g�̔����Ԋu(�b)

	static const int ACTIVEEVENT_NORMAL = 45;

	static const int ACTIVEEVENT_HARD = 30;

	static const int EVENT_TYPES = 2;			//�C�x���g�̎��

	int eventWaitTime;		//��Փx����ĕς��C�x���g�̔����Ԋu

	int eventType;			//��������C�x���g�̗���

	int waitCount;			//�C�x���g�����̑ҋ@�J�E���g

	BaseEvent* Event;		//�C�x���g������ϐ�

public:
	EventManager(int);			//�R���X�g���N�^

	~EventManager();			//�f�X�g���N�^

	void SpawnEvent();			//����

	void Update();				//�X�V

	void Draw();				//�`��

};


#endif // !_EVENTMANAGER_H
