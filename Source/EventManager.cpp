#include <DxLib.h>
#include "EventManager.h"


EventManager::EventManager(int level) {

	Event = NULL;		//イベントの初期化
	Sukima = NULL;		//スキマ初期化
	sBomb = NULL;		//ボム初期化

	waitCount = 0;		//カウント初期化
	eventType = 0;		//イベントタイプ初期化
	bombType = 0;		//ボムタイプ初期化

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
		eventWaitTime = ACTIVEEVENT_HARD;
		break;
	}

}

EventManager::~EventManager() {
	delete Event;		//デリート
	delete Sukima;
	delete sBomb;
}

void EventManager::SpawnEvent() {
	waitCount++;

	if (waitCount >= FRAME * eventWaitTime) {// フレーム数 * 秒 = 待機時間　待機時間を超えても前のイベントが実行中なら実行しない

		if (Event == NULL && sBomb == NULL) {//NULL(何もイベントが発生していない)時に生成

			eventType = GetRand(EVENT_TYPES - 1);		//乱数で生成するイベントを選択

			if (eventType == 0) {
				Event = new DarknessEvent();	//生成
			}

			if (eventType == 1) {
				SpawnBombs();			//ボム生成
				waitCount = 0;			//カウント初期化
			}

		}

	}
}

void EventManager::Update(EnemyManager* enemyManager) {
	SpawnEvent();			//生成
	SpawnSukima();			//スキマ生成


	if (Event != NULL) {	//何かしらイベントが行われている場合
		Event->Update();	//更新

		if (Event->GetIsActive() == false) {//イベントのアクティブ状態がfalseの場合

			delete Event;					//デリート
			Event = NULL;					//初期化

			waitCount = 0;					//待機カウント初期化
		}
	}

	if (Sukima != NULL) {	//スキマ用
		Sukima->Update(enemyManager);	//更新

		if (Sukima->GetIsActive() == false) { //削除、初期化処理

			delete Sukima;

			Sukima = NULL;

		}
	}

	if (sBomb != NULL) {		//NULLでない場合

		sBomb->Update();  //更新

		if (sBomb->GetIsActive() == false)	 //初期化
		{
			delete sBomb;

			sBomb = NULL;
		}
	}


}

void EventManager::Draw() {

	if (Sukima != NULL) {	//スキマが生成されている場合
		Sukima->Draw();		//描画
	}

	if (Event != NULL) {	//何かしらイベントが行われている場合
		Event->Draw();		//描画
	}

	if (sBomb != NULL) {
		sBomb->Draw();	//描画
	}

}

void EventManager::SpawnSukima() {

	if (rand() % 600 == 0) {	//確率
		if (Sukima == NULL) {	//生成されてない場合

			Sukima = new SukimaEvent();

		}

	}
}


void EventManager::SpawnBombs() {
	bombType = GetRand(BOMB_TYPES - 1) +1;	//eBombに合わせるために1を加算

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



