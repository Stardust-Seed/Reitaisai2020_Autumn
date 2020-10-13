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
	static const int ACTIVEEVENT_EASY = 45;		//難易度によって変わるイベントの発生間隔(秒)

	static const int ACTIVEEVENT_NORMAL = 35;

	static const int ACTIVEEVENT_HARD = 25;

	static const int EVENT_TYPES = 2;			//イベントの種類

	static const int BOMB_TYPES = 2;			//ボムの種類

	const int BPOWER[BOMB_TYPES] = { 10, 0};

	const int BSPEED[BOMB_TYPES] = { 3, 3};

	int eventWaitTime;		//難易度よって変わるイベントの発生間隔

	int eventType;			//発生するイベントの乱数

	int waitCount;			//イベント発生の待機カウント

	int seCount;			//イベント発生前にSEを鳴らすための変数

	int bombType;

	BaseBomb* sBomb;

	BaseEvent* Event;		//イベントを入れる変数

	SukimaEvent* Sukima;	//スキマイベント格納

public:
	EventManager(int);			//コンストラクタ

	~EventManager();			//デストラクタ

	void SpawnEvent();			//生成

	void Update(EnemyManager*,BasePlayer*);	//更新

	void Draw();				//描画

	void SpawnSukima();			//スキマの生成

	void SpawnBombs();

	int Get_BombType();

	int Get_Power();			//攻撃力を受け取る

	bool Get_IsActive();		//アクティブなのかを受け取る
};


#endif // !_EVENTMANAGER_H
