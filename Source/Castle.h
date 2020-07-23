#ifndef _CASTLE_H
#define _CASTLE_H

#include "Object.h"

/*-------------------------------------------------------------
オブジェクト名:	Castle
概要	      : 拠点
アクセス      :
継承クラス    : Object(オブジェクト)
呼ばれ先      :
詳細説明	  : 拠点
--------------------------------------------------------------*/

class Castle:public virtual Object{

private:
	static const int MAX_DURABILITY;    //最大耐久力

	int Durability;	                    //耐久力

	bool isActive;	                    //拠点の生存フラグ

public:
	 Castle();
	 bool ClisionHit(float mx, float my, float mw, float mh,
		     float ox, float oy, float ow, float oh);
	 //m = my 自分   o = opnet 相手

	 void Update();                //更新処理
	 void Draw();                  //描画処理
	 void HitDamage();             //ダメージ処理
	 void JudgeActive();           //生存判定処理

	 void Set_x(int _x) { x = _x; }                                 //セッター
	 void Set_y(int _y) { y = _y; }                                 //セッター
	 void Set_width(int _width) { width = _width; }                 //セッター
	 void Set_height(int _height) { height = _height; }             //セッター
	 void Set_IsActive(bool _isActive) { isActive = _isActive; }    //セッター

	 int Get_x() { return x; }                                      //ゲッター
	 int Get_y() { return y; }                                      //ゲッター
	 int Get_width() { return width; }                              //ゲッター
	 int Get_height() { return height; }                            //ゲッター
	 int Get_IsActive() { return isActive; }                        //ゲッター
};

#endif //_CASTLE_H