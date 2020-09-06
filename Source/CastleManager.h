#ifndef _CASTLEMANAGER_H
#define _CASTLEMANAGER_H

#include "MainCastle.h"
#include "SubCastle.h"

class BaseCastle;
class MainCastle;
class SubCastle;

class EnemyManager;

class CastleManager {
private:
	static const int POPCASTLE = 5;

	BaseCastle* Castles[POPCASTLE];

	int durability;
	int activeCount;
	int popEnemyNum;

	bool spawnFlg;
	bool activeCountFlg[POPCASTLE];

public:
	CastleManager();

	~CastleManager();

	void SpawnCastle();

	void Update(EnemyManager*);
	void Draw();

	int Get_CastleNum();
	int Get_PopEnemyNum();			//アクティブな拠点の数を返す

	float Get_X(int);				//x座標を受け取る
	float Get_Y(int);				//y座標を受け取る
	float Get_Width(int);			//幅を受け取る
	float Get_Height(int);			//高さを受け取る
	bool Get_IsActive(int);			//アクティブフラグのセッター
	int Get_Durability(int);	
	float Get_EnemySpeed(int);
	float Get_EnemyPower(int);
	int Get_EnemyDurability(int);
	int Get_EnemyDirection(int);
	void Set_Durability(int,int);
};

#endif // !_CASTLEMANAGER_H
