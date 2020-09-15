#ifndef _CASTLEMANAGER_H
#define _CASTLEMANAGER_H

#include "MainCastle.h"
#include "SubCastle.h"
#include "Direction.h"
class BaseCastle;
class MainCastle;
class SubCastle;

class EnemyManager;

class CastleManager {
private:
	static const int POPCASTLE = 5;

	BaseCastle* Castles[POPCASTLE];

	int durability;
	int occupiedNum;

	bool activeCountFlg[POPCASTLE];

public:
	CastleManager();

	~CastleManager();

	void Update(EnemyManager*);
	void Draw();

	int Get_CastleNum();    //拠点の数を返す

	float Get_X(int);				//x座標を受け取る
	float Get_Y(int);				//y座標を受け取る
	float Get_Width(int);			//幅を受け取る
	float Get_Height(int);			//高さを受け取る
	bool Get_IsActive(int);			//アクティブフラグのセッター
	int Get_Durability(int);	
	eDirection Get_CastleDirection(int);
	int Get_OccupiedNum();
};

#endif // !_CASTLEMANAGER_H
