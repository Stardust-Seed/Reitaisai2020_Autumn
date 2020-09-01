#ifndef _EVENTMANAGER_H
#define _EVENTMANAGER_H

#include "BaseEvent.h"

class BaseEvent;

class EventManager {
private:
	static const int ACTIVEEVENT_EASY = 90;		//難易度によって変わるイベントの発生間隔(秒)

	static const int ACTIVEEVENT_NORMAL = 60;

	static const int ACTIVEEVENT_HARD = 30;

	static const int EVENT_TYPES = 2;			//イベントの種類

	static const int FREAM = 60;				//フレームレート

	int eventWaitTime;		//難易度よって変わるイベントの発生間隔

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
