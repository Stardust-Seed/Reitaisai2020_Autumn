#ifndef _GAMERESOURCE_H
#define _GAMERESOURCE_H

class BasePlayer;
class BuffManager;
class BulletManager;
class CastleManager;
class EnemyManager;
class EventManager;
class ItemManager;
class TimeLimit;

//ゲームリソース構造体
typedef struct {
	BasePlayer*			player;			//プレイヤー
	BuffManager*		buffManager;	//バフ管理クラス
	BulletManager*		bulletManager;	//弾管理クラス
	CastleManager*		castleManager;	//城管理クラス
	EnemyManager*		enemyManager;	//敵管理クラス
	EventManager*		eventManager;	//イベント管理クラス
	ItemManager*		itemManager;	//アイテム管理クラス
	TimeLimit*			timeLimit;		//制限時間クラス
}GameResource;

#endif // !_GAMERESOURCE_H