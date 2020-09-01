#ifndef _BASEEVENT_H
#define _BASEEVENT_H

#include "Object.h"

class BaseEvent {
protected:
	bool isActive = false;					//アクティブ状態

public:
	BaseEvent();					//コンストラクタ
	
	virtual ~BaseEvent();			//デストラクタ

	virtual void Update();			//更新

	virtual void Draw();			//描画

	bool GetIsActive() { return isActive; }	//アクティブ状態を取得する
};

#endif _BASEEVENT_HS