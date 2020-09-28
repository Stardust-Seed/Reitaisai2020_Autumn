#include <DxLib.h>
#include "EventManager.h"


EventManager::EventManager(int level) {

	Event = NULL;		//�C�x���g�̏�����
	Sukima = NULL;		//�X�L�}������
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
		eventWaitTime = ACTIVEEVENT_HARD;
		break;
	}

}

EventManager::~EventManager() {
	delete Event;		//�f���[�g
	delete Sukima;
}

void EventManager::SpawnEvent() {
	waitCount++;

	if (waitCount >= FRAME * eventWaitTime) {// �t���[���� * �b = �ҋ@���ԁ@�ҋ@���Ԃ𒴂��Ă��O�̃C�x���g�����s���Ȃ���s���Ȃ�

		if (Event == NULL) {//NULL(�����C�x���g���������Ă��Ȃ�)���ɐ���

			SRand;			//����������

			eventType = GetRand(EVENT_TYPES - 1);		//�C�x���g��

			if (eventType == 0) {
				Event = new DarknessEvent();	//����
			}

			if (eventType == 1) {
			//	Event = new BaseEvent();	//test�p����
			}

		}

	}
}

void EventManager::Update(EnemyManager* enemyManager) {
	SpawnEvent();			//����
	SpawnSukima();			//�X�L�}����

	if (Event != NULL) {	//��������C�x���g���s���Ă���ꍇ
		Event->Update();	//�X�V

		if (Event->GetIsActive() == false) {//�C�x���g�̃A�N�e�B�u��Ԃ�false�̏ꍇ

			delete Event;					//�f���[�g
			Event = NULL;					//������

			waitCount = 0;					//�ҋ@�J�E���g������
		}
	}

	if (Sukima != NULL) {	//�X�L�}�p
		Sukima->Update(enemyManager);	//�X�V

		if (Sukima->GetIsActive() == false) { //�폜�A����������

			delete Sukima;

			Sukima = NULL;

		}
	}

}

void EventManager::Draw() {

	if (Sukima != NULL) {	//�X�L�}����������Ă���ꍇ
		Sukima->Draw();		//�`��
	}

	if (Event != NULL) {	//��������C�x���g���s���Ă���ꍇ
		Event->Draw();		//�`��
	}
}

void EventManager::SpawnSukima() {

	if (rand() % 600 == 0) {	//�m��
		if (Sukima == NULL) {	//��������ĂȂ��ꍇ

			Sukima = new SukimaEvent();

		}

	}
}