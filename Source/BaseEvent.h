#ifndef _BASEEVENT_H
#define _BASEEVENT_H

#include "Object.h"

class BaseEvent {
protected:

public:
	BaseEvent();					//�R���X�g���N�^
	
	virtual ~BaseEvent();			//�f�X�g���N�^

	virtual void Update();			//�X�V

	virtual void Draw();			//�`��
};

#endif _BASEEVENT_H