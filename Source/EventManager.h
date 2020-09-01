#ifndef _EVENTMANAGER_H
#define _EVENTMANAGER_H

#include "BaseEvent.h"

class BaseEvent;

class EventManager {
private:
	static const int ACTIVEEVENT_EASY = 1;		//難易度によって変わるイベントの発生回数

	static const int ACTIVEEVENT_NORMAL = 2;

	static const int ACTIVEEVENT_HARD = 3;

	static const int EVENT_TYPES = 2;			//イベントの種類

	int eventNum;			//難易度よって変わるイベントの発生回数

	int eventType;			//発生するイベントの乱数

	int waitCount;			//イベントの最短発生間隔

	BaseEvent* Event;		//イベントを入れる変数

public:
	EventManager(int);			//コンストラクタ

	~EventManager();			//デストラクタ

	void SpawnEvent();			//生成

	void Update();				//更新

	void Draw();				//描画

};


#endif // !_EVENTMANAGER_H
