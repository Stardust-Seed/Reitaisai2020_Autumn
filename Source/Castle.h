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

	int Durability;	//耐久力

	bool isActive;	//拠点の生存フラグ

public:

	 virtual bool ClisionHit(float mx, float my, float mw, float mh,
		     float ox, float oy, float ow, float oh) = 0;
	 //m = my 自分   o = opnet 相手

	 virtual void Update();                //更新処理
	 virtual void Draw();                  //描画処理

	 virtual void Set_x(int _x) { x = _x; }                        //セッター
	 virtual void Set_y(int _y) { y = _y; }                        //セッター
	 virtual void Set_width(int _width) { width = _width; }        //セッター
	 virtual void Set_height(int _height) { height = _height; }    //セッター

	 virtual int Get_x() { return x; }                             //ゲッター
	 virtual int Get_y() { return y; }                             //ゲッター
	 virtual int Get_width() { return width; }                     //ゲッター
	 virtual int Get_height() { return height; }                   //ゲッター

};

#endif //_CASTLE_H