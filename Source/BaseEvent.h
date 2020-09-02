#ifndef _BASEEVENT_H
#define _BASEEVENT_H

class BaseEvent{
protected:
	bool isActive = false;			//�A�N�e�B�u��� �G�ɏ�����

public:
	BaseEvent() {}					//�R���X�g���N�^
	
	virtual ~BaseEvent(){}			//�f�X�g���N�^

	virtual void Update() {}		//�X�V

	virtual void Draw() {}			//�`��

	bool GetIsActive() { return isActive; }	//�A�N�e�B�u��Ԃ��擾����
};

#endif _BASEEVENT_H