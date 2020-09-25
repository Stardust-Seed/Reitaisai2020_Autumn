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
		eventWaitTime = 4;
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
				waitCount = 0;
			}

			if (eventType == 1) {
			//	Event = new BaseEvent();	//test�p����
				waitCount = 0;
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
	if (Event != NULL) {	//��������C�x���g���s���Ă���ꍇ
		Event->Draw();		//�`��
	}

	if (Sukima != NULL) {
		Sukima->Draw();
	}
}

void EventManager::SpawnSukima() {

	if (rand() % 700 == 0) {	//�m��
		if (Sukima == NULL) {	//��������ĂȂ��ꍇ

			Sukima = new SukimaEvent();

		}

	}
}