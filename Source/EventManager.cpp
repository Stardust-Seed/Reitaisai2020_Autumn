#include <DxLib.h>
#include "EventManager.h"


EventManager::EventManager(int level) {

	Event = NULL;		//イベントの初期化
	Sukima = NULL;		//スキマ初期化
	waitCount = 0;		//カウント初期化

	for (int num = 0; num < BOMB_TYPES; num++) {
		Bombs[num] = NULL;	//ボム初期化
	}

	switch (level)				//引数(0〜2)で難易度別の生成数を設定
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

	for (int num = 0; num < BOMB_TYPES; num++) {
		delete Bombs[num];
	}
}

void EventManager::SpawnEvent() {
	waitCount++;

	if (waitCount >= FRAME * eventWaitTime) {// フレーム数 * 秒 = 待機時間　待機時間を超えても前のイベントが実行中なら実行しない

		if (Event == NULL) {//NULL(何もイベントが発生していない)時に生成

			SRand;			//乱数初期化

			eventType = GetRand(EVENT_TYPES - 1);		//イベント数

			if (eventType == 0) {
				Event = new DarknessEvent();	//生成
			}

			if (eventType == 1) {
			//	Event = new BaseEvent();	//test用生成
			}

		}

	}
}

void EventManager::Update(EnemyManager* enemyManager) {
	SpawnEvent();			//生成
	SpawnSukima();			//スキマ生成
	SpawnBombs();  //ボム生成

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

	for (int num = 0; num < BOMB_TYPES; num++) {

		if (Bombs[num] != NULL) {		//NULLでない場合

			Bombs[num]->Update();  //更新

			if (Bombs[num]->GetIsActive() == false)	 //初期化
			{
				delete Bombs[num];

				Bombs[num] = NULL;
			}
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

	for (int num = 0; num < BOMB_TYPES; num++) {
		if (Bombs[num] != NULL) {
			Bombs[num]->Draw();	//描画
		}
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

	waitCount++;
	//if (rand() % 700 == 0) {	//確率
	if (waitCount >= 50) {
		if (rand() % 100 == 0) {
			SRand;
			//bombType = GetRand(BOMB_TYPES);
			bombType = fakebomb;
			//bombType = bomb;

			for (int num = 0; num < BOMB_TYPES - 1; num++) {

				if (Bombs[num] == NULL) {	//生成されてない場合

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



