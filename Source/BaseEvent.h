#ifndef _BASEEVENT_H
#define _BASEEVENT_H

#include "Object.h"

class BaseEvent {
protected:

public:
	BaseEvent();					//コンストラクタ
	
	virtual ~BaseEvent();			//デストラクタ

	virtual void Update();			//更新

	virtual void Draw();			//描画
};

#endif _BASEEVENT_H