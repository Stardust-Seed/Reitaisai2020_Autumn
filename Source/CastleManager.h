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
	int x, y, width, heigth;
	int activeCount;

public:
	CastleManager();

	~CastleManager();

	void SpawnCastle();

	void Update(EnemyManager*);
	void Draw();

	//int Get_ActiveCount();			//アクティブな拠点の数を返す

	int Get_X(int);					//x座標を受け取る
	int Get_Y(int);					//y座標を受け取る
	int Get_Width(int);				//幅を受け取る
	int Get_Height(int);			//高さを受け取る
	int Get_IsActive(int);			//アクティブフラグのセッター
	int Get_Durability(int);		
	void Set_Durability(int,int);
};

#endif // !_CASTLEMANAGER_H
