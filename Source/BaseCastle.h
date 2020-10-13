#ifndef _BASECASTLE_H
#define _BASECASTLE_H

#include "Object.h"
#include "Direction.h"
#include "Define.h"
#include "Image.h"
#include "SE.h"
/*-------------------------------------------------------------
オブジェクト名    BaseCastle
概要    拠点の元になるオブジェクト
アクセス
継承クラス    Object(オブジェクト)
呼ばれ先
詳細説明    Objectから継承した、拠点の元
--------------------------------------------------------------*/

class EnemyManager;
class EventManager;

class BaseCastle :public Object {
protected:
	int maxDurabiliy;		                //最大耐久力			

	int durability;		                    //拠点の体力
	eDirection direction;
	bool isActive;		                    //拠点の生存フラグ
	bool dyingFlg;                          //瀕死フラグ

	int addSize;                            //追加のサイズ
	float addPosX;                          //追加のX座標
	float addPosY;                          //追加のY座標

	float popPosX;                          //サブ拠点から出るエネミーの座標X
	float popPosY;                          //サブ拠点から出るエネミーの座標Y

	float drawPosX;                         //表示部分の座標X
	float drawPosY;                         //表示部分の座標Y
public:
	BaseCastle(int);                        //コンストラクタ

	virtual void Update(EnemyManager*) {} 	//更新処理
	virtual void Update(EnemyManager*,EventManager*) {} 	//更新処理(メインキャッスル)
	virtual void Draw() {}		        	//描画処理

	//こっちは使わない
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh) {
		return false;
	}
	// m = my 自分   o = opnet 相手	//当たり判定処理

	//こっち使う
	bool ClisionHit(float ox, float oy, float ow, float oh,
		int pow, int num, bool attackFlg, bool activeFlg);

	//ゲッター
	//拠点関連
	int   Get_Durability() { return durability; }             //拠点のHPのゲッター

	bool  GetIsActive()    { return isActive; }               //拠点が生存しているかのゲッター

	float Get_X() { return x; }                               //拠点のゲッターX
	float Get_Y() { return y; }                               //拠点のゲッターY
	float Get_Width() { return width; }                       //横幅のゲッター
	float Get_Height() { return height; }                     //縦幅のゲッター

	float Get_PopPosX() { return popPosX; }                   //敵の生成場所のゲッターX
	float Get_PopPosY() { return popPosY; }                   //敵の生成場所のゲッターY

	float Get_DrawPosX() { return drawPosX; }                 //表示場所のゲッターX
	float Get_DrawPosY() { return drawPosY; }                 //表示場所のゲッターY

	eDirection Get_CastleDirection() { return direction; }    //方向のゲッター
};

#endif //_BASECASTLE_H_