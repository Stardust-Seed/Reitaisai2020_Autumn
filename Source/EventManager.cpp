#include <DxLib.h>
#include "EventManager.h"

EventManager::EventManager(int level) {

	Event = NULL;		//イベントの初期化
	waitCount = 0;		//カウント初期化

	switch (level)				//引数(0～2)で難易度別の生成数を設定
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
	default:					//例外
		eventWaitTime = 4;
		break;
	}

}

EventManager::~EventManager() {
	delete Event;		//デリート
}

void EventManager::SpawnEvent() {
	waitCount++;

	if (waitCount >= FRAME * eventWaitTime) {// フレーム数 * 秒 = 待機時間　待機時間を超えても前のイベントが実行中なら実行しない

		if (Event == NULL) {//NULL(何もイベントが発生していない)時に生成

			SRand;			//乱数初期化

			eventType = GetRand(EVENT_TYPES - 1);		//イベント数

			if (eventType == 0) {
				Event = new DarknessEvent();	//生成
				waitCount = 0;
			}

			if (eventType == 1) {
			//	Event = new BaseEvent();	//test用生成
				waitCount = 0;
			}

		}

	}
}

void EventManager::Update() {
	SpawnEvent();			//生成

	if (Event != NULL) {	//何かしらイベントが行われている場合
		Event->Update();	//更新

		if (Event->GetIsActive() == false) {//イベントのアクティブ状態がfalseの場合

			delete Event;					//デリート

			Event = NULL;					//初期化

		}
	}

}

void EventManager::Draw() {
	if (Event != NULL) {	//何かしらイベントが行われている場合
		Event->Draw();		//描画
	}
}