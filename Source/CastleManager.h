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
	static const int POPCASTLE = 5;    //拠点の生成数

	BaseCastle* Castles[POPCASTLE];

	int durability;
	int x, y, width, heigth;
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

	//ゲッター
	//拠点関連
	int Get_CastleNum();              //拠点の数を返す
	int Get_PopEnemyNum();			  //追加の敵の数を返す
	int Get_X(int);
	int Get_Y(int);
	int Get_Width(int);
	int Get_Height(int);
	int Get_IsActive(int);

	//敵パラメータ関連
	int Get_Durability(int);	
	int Get_EnemyDurability(int);
	int Get_EnemyDirection(int);

	float Get_EnemySpeed(int);
	float Get_EnemyPower(int);

	//セッター
	void Set_Durability(int,int);
};

#endif // !_CASTLEMANAGER_H
