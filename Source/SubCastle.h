#ifndef _SUBCASTLE_H
#define _SUBCASTLE_H

#include "BaseCastle.h"

/*-------------------------------------------------------------
オブジェクト名:	SubCastle
概要	      : サブ拠点
アクセス      :
継承クラス    : BaseCastle
呼ばれ先      :
詳細説明	  : サブ拠点、破壊されたら敵増加
--------------------------------------------------------------*/

class EnemyManager;
class BaseEnemy;
class SubCastle :public virtual BaseCastle {

private:
	int posType;                   //サブ拠点の場所

	int bx;                        //弾のX座標
	int by;                        //弾のY座標
	int bheight;                   //弾の高さ
	int bwidth;                    //弾の幅

	int cnt;                       //弾発射のカウント
	int alpha;                     //弾の透明度
	int directionMove;             //弾の進行方向

	bool bflg;                     //弾の表示フラグ
	bool discoveryFlg;             //発見フラグ

public:
	//サブ拠点の設置場所の座標
	static const int COORDINATE_X_ONE = GAME_WIDTH / 2 - 375 + 80;
	static const int COORDINATE_Y_ONE = GAME_HEIHGT / 2;

	static const int COORDINATE_X_TWO = GAME_WIDTH / 2 - 225 + 48;
	static const int COORDINATE_Y_TWO = GAME_HEIHGT / 2;

	static const int COORDINATE_X_THREE = GAME_WIDTH / 2 ;
	static const int COORDINATE_Y_THREE = GAME_HEIHGT / 2 - 350 + 48;

	static const int COORDINATE_X_FOUR = GAME_WIDTH / 2;
	static const int COORDINATE_Y_FOUR = GAME_HEIHGT / 2 - 225 + 48;

	static const int COORDINATE_X_FIVE = GAME_WIDTH / 2 + 300 - 48;
	static const int COORDINATE_Y_FIVE = GAME_HEIHGT / 2;

	static const int COORDINATE_X_SIX = GAME_WIDTH / 2 + 175 - 48;
	static const int COORDINATE_Y_SIX = GAME_HEIHGT / 2 ;

	static const int COORDINATE_X_SEVEN = GAME_WIDTH / 2;
	static const int COORDINATE_Y_SEVEN = GAME_HEIHGT / 2 + 300 - 48;

	static const int COORDINATE_X_EIGHT = GAME_WIDTH / 2 ;
	static const int COORDINATE_Y_EIGHT = GAME_HEIHGT / 2 + 175 - 48;

	SubCastle(int,int,int);

	void Update(EnemyManager*);    //更新処理
	void Draw();                   //描画処理
};

#endif //_SUBCASTLE_H