#ifndef _EVENTMANAGER_H
#define _EVENTMANAGER_H

#include "Define.h"
#include "DarknessEvent.h"
#include "SukimaEvent.h"
#include "BaseBomb.h"
#include "Bomb.h"
#include "FakeBomb.h"

#include "EnemyManager.h"



class EventManager {
private:
	static const int ACTIVEEVENT_EASY = 45;		//��Փx�ɂ���ĕς��C�x���g�̔����Ԋu(�b)

	static const int ACTIVEEVENT_NORMAL = 35;

	static const int ACTIVEEVENT_HARD = 25;

	static const int EVENT_TYPES = 2;			//�C�x���g�̎��

	static const int BOMB_TYPES = 2;			//�{���̎��

	const int BPOWER[BOMB_TYPES] = { 10, 0};

	const int BSPEED[BOMB_TYPES] = { 3, 3};

	int eventWaitTime;		//��Փx����ĕς��C�x���g�̔����Ԋu

	int eventType;			//��������C�x���g�̗���

	int waitCount;			//�C�x���g�����̑ҋ@�J�E���g

	int seCount;			//�C�x���g�����O��SE��炷���߂̕ϐ�

	int bombType;

	BaseBomb* sBomb;

	BaseEvent* Event;		//�C�x���g������ϐ�

	SukimaEvent* Sukima;	//�X�L�}�C�x���g�i�[

public:
	EventManager(int);			//�R���X�g���N�^

	~EventManager();			//�f�X�g���N�^

	void SpawnEvent();			//����

	void Update(EnemyManager*,BasePlayer*);	//�X�V

	void Draw();				//�`��

	void SpawnSukima();			//�X�L�}�̐���

	void SpawnBombs();

	int Get_BombType();

	int Get_Power();			//�U���͂��󂯎��

	bool Get_IsActive();		//�A�N�e�B�u�Ȃ̂����󂯎��
};


#endif // !_EVENTMANAGER_H
