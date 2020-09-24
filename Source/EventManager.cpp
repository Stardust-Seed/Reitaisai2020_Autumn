#include <DxLib.h>
#include "EventManager.h"

EventManager::EventManager(int level) {

	Event = NULL;		//�C�x���g�̏�����
	waitCount = 0;		//�J�E���g������

	switch (level)				//����(0�`2)�œ�Փx�ʂ̐�������ݒ�
	{
	case 0:						//EASY		
		eventWaitTime = ACTIVEEVENT_EASY;
		break;
	case 1:						//NORMAL	
		eventWaitTime = ACTIVEEVENT_NORMAL;
		break;
	case 2:						//HARD		
		eventWaitTime = ACTIVEEVENT_HARD;
		break;
	default:					//��O
		eventWaitTime = 4;
		break;
	}

}

EventManager::~EventManager() {
	delete Event;		//�f���[�g
}

void EventManager::SpawnEvent() {
	waitCount++;

	if (waitCount >= FRAME * eventWaitTime) {// �t���[���� * �b = �ҋ@���ԁ@�ҋ@���Ԃ𒴂��Ă��O�̃C�x���g�����s���Ȃ���s���Ȃ�

		if (Event == NULL) {//NULL(�����C�x���g���������Ă��Ȃ�)���ɐ���

			SRand;			//����������

			eventType = GetRand(EVENT_TYPES - 1);		//�C�x���g��

			if (eventType == 0) {
				Event = new DarknessEvent();	//����
				waitCount = 0;
			}

			if (eventType == 1) {
			//	Event = new BaseEvent();	//test�p����
				waitCount = 0;
			}

		}

	}
}

void EventManager::Update() {
	SpawnEvent();			//����

	if (Event != NULL) {	//��������C�x���g���s���Ă���ꍇ
		Event->Update();	//�X�V

		if (Event->GetIsActive() == false) {//�C�x���g�̃A�N�e�B�u��Ԃ�false�̏ꍇ

			delete Event;					//�f���[�g

			Event = NULL;					//������

		}
	}

}

void EventManager::Draw() {
	if (Event != NULL) {	//��������C�x���g���s���Ă���ꍇ
		Event->Draw();		//�`��
	}
}