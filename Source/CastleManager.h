#ifndef _CASTLEMANAGER_H
#define _CASTLEMANAGER_H

#include "MainCastle.h"
#include "SubCastle.h"
#include "Direction.h"
#include "Input.h"

class BaseCastle;
class MainCastle;
class SubCastle;

class EnemyManager;
class EventManager;

class CastleManager {
private:
	static const int POPCASTLE = 5;    //生成する拠点の数

	BaseCastle* Castles[POPCASTLE];

	int durability;                    //耐久
	int occupiedNum;                   //占領数
	int cnt;                           //拠点数のカウント(というか番号)
	int installCnt;                    //サブ拠点を設置した数
	int number;                        //生成場所の番号
	bool numberFlg[8];                 //番号別の生成しているかどうかのフラグ
	bool activeCountFlg[POPCASTLE];    //アクティブな数を数えるフラグ

public:
	CastleManager();

	~CastleManager();

	void Update(EnemyManager*,EventManager*);
	void Draw();

	int Get_CastleNum();                    //拠点の数を返す
	int Get_installCastle();                //残りの設置できるサブ拠点の数を返す
	int Get_installNum();                   //選択中の設置予定場所番号

	float Get_X(int);				        //i番目の拠点のx座標を受け取る
	float Get_Y(int);				        //i番目の拠点のy座標を受け取る
	float Get_Width(int);			        //i番目の拠点の幅を受け取る
	float Get_Height(int);			        //i番目の拠点の高さを受け取る
	float Get_DrawPosX(int);	            //i番目の拠点を表示するX座標を受け取る
	float Get_DrawPosY(int);	            //i番目の拠点を表示するY座標を受け取る
	float Get_PopPosX(int);	                //i番目の拠点で生成する敵のX座標を受け取る
	float Get_PopPosY(int);	                //i番目の拠点で生成する敵のY座標を受け取る
	bool Get_IsActive(int);			        //i番目の拠点の生存しているかを受け取る
	int Get_Durability(int);	            //i番目の拠点の耐久を受け取る
	eDirection Get_CastleDirection(int);    //i番目の拠点の方向を受け取る
	int Get_OccupiedNum();                  //占領されたサブ拠点の数を受け取る
};

#endif // !_CASTLEMANAGER_H
