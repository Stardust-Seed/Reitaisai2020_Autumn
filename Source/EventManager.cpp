#include <DxLib.h>
#include "EventManager.h"


EventManager::EventManager(int level) {

	Event = NULL;		//�C�x���g�̏�����
	Sukima = NULL;		//�X�L�}������
	sBomb = NULL;		//�{��������

	waitCount = 0;		//�J�E���g������
	eventType = 0;		//�C�x���g�^�C�v������
	bombType = 0;		//�{���^�C�v������

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
	delete sBomb;
}

void EventManager::SpawnEvent() {
	waitCount++;

	if (waitCount >= FRAME * eventWaitTime) {// �t���[���� * �b = �ҋ@���ԁ@�ҋ@���Ԃ𒴂��Ă��O�̃C�x���g�����s���Ȃ���s���Ȃ�

		if (Event == NULL && sBomb == NULL) {//NULL(�����C�x���g���������Ă��Ȃ�)���ɐ���

			eventType = GetRand(EVENT_TYPES - 1);		//�����Ő�������C�x���g��I��

			if (eventType == 0) {
				Event = new DarknessEvent();	//����
			}

			if (eventType == 1) {
				SpawnBombs();			//�{������
				waitCount = 0;			//�J�E���g������
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

	if (sBomb != NULL) {		//NULL�łȂ��ꍇ

		sBomb->Update();  //�X�V

		if (sBomb->GetIsActive() == false)	 //������
		{
			delete sBomb;

			sBomb = NULL;
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

	if (sBomb != NULL) {
		sBomb->Draw();	//�`��
	}

}

void EventManager::SpawnSukima() {

	if (rand() % 600 == 0) {	//�m��
		if (Sukima == NULL) {	//��������ĂȂ��ꍇ

			Sukima = new SukimaEvent();

		}

	}
}


void EventManager::SpawnBombs() {
	bombType = GetRand(BOMB_TYPES - 1) +1;	//eBomb�ɍ��킹�邽�߂�1�����Z

	if (bombType == bomb) {
		sBomb = new Bomb(BPOWER[bombType - 1], BSPEED[bombType - 1], static_cast<eBombType>(bomb));
	}

	if (bombType == fakebomb) {
		sBomb = new FakeBomb(BPOWER[bombType - 1], BSPEED[bombType - 1], static_cast<eBombType>(fakebomb));
	}
}

int EventManager::Get_BombType() {
	return bombType;
}


int EventManager::Get_Power(int num) {
	if (sBomb != NULL) {
		return sBomb->GetPower();
	}
	return 0;
}

bool EventManager::Get_IsActive(int num) {
	if (sBomb != NULL) {
		return sBomb->GetIsTriggerFlg();
	}
	return 0;
}



