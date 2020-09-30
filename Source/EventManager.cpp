#include <DxLib.h>
#include "EventManager.h"


EventManager::EventManager(int level) {

	Event = NULL;		//�C�x���g�̏�����
	Sukima = NULL;		//�X�L�}������
	waitCount = 0;		//�J�E���g������

	eventType = 0;
	bombType = 0;
	bpower = 0;
	bspeed = 0;

	for (int num = 0; num < BOMB_TYPES; num++) {
		Bombs[num] = NULL;	//�{��������
	}

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

	for (int num = 0; num < BOMB_TYPES; num++) {
		delete Bombs[num];
	}
}

void EventManager::SpawnEvent() {
	waitCount++;

	if (waitCount >= FRAME * eventWaitTime) {// �t���[���� * �b = �ҋ@���ԁ@�ҋ@���Ԃ𒴂��Ă��O�̃C�x���g�����s���Ȃ���s���Ȃ�

		if (Event == NULL) {//NULL(�����C�x���g���������Ă��Ȃ�)���ɐ���

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
	SpawnBombs();			//�{������

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

	for (int num = 0; num < BOMB_TYPES; num++) {

		if (Bombs[num] != NULL) {		//NULL�łȂ��ꍇ

			Bombs[num]->Update();  //�X�V

			if (Bombs[num]->GetIsActive() == false)	 //������
			{
				delete Bombs[num];

				Bombs[num] = NULL;
			}
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

	for (int num = 0; num < BOMB_TYPES; num++) {
		if (Bombs[num] != NULL) {
			Bombs[num]->Draw();	//�`��
		}
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

	waitCount++;
	//if (rand() % 700 == 0) {	//�m��
	if (waitCount >= 50) {
		if (rand() % 100 == 0) {
			//bombType = GetRand(BOMB_TYPES);
			bombType = fakebomb;
			//bombType = bomb;

			for (int num = 0; num < BOMB_TYPES - 1; num++) {

				if (Bombs[num] == NULL) {	//��������ĂȂ��ꍇ

					DrawFormatString(10, 600, GetColor(255, 255, 255), "type%d", bombType);

					if (bombType == bomb) {
						bpower = 10;
						bspeed = 3;
						Bombs[num] = new Bomb(bpower, bspeed, static_cast<eBombType>(bomb));
						waitCount = 0;
						break;
					}

					if (bombType == fakebomb) {
						bpower = 0;
						bspeed = 3;
						Bombs[num] = new FakeBomb(bpower, bspeed, static_cast<eBombType>(fakebomb));
						waitCount = 0;
						break;
					}
				}
			}
		}
	}
}

int EventManager::Get_BombType() {
	return bombType;
}


int EventManager::Get_Power(int num) {
	if (Bombs[num] != NULL) {
		return Bombs[num]->GetPower();
	}
	return 0;
}

bool EventManager::Get_IsActive(int num) {
	if (Bombs[num] != NULL) {
		return Bombs[num]->GetIsTriggerFlg();
	}
	return 0;
}



