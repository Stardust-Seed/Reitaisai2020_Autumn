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

class Castle:Object{

private:

	int Durability;	//耐久力
	int	x;	        //拠点のx
    int	y;	        //拠点のy
    int	width;  	//拠点のwidth
    int	height; 	//拠点のheight

	bool isActive;	//拠点の生存フラグ

public:

	 bool ClisionHit(float mx, float my, float mw, float mh,
		     float ox, float oy, float ow, float oh);
	 //m = my 自分   o = opnet 相手

	 //void Update(Enemy& enemy);    //更新処理
	 void Update();                  //更新処理
	 void Draw();                    //描画処理

	 void Set_x(int _x) { x = _x; }                        //セッター
	 void Set_y(int _y) { y = _y; }                        //セッター
	 void Set_width(int _width) { width = _width; }        //セッター
	 void Set_height(int _height) { height = _height; }    //セッター

	 int Get_x() { return x; }                             //ゲッター
	 int Get_y() { return y; }                             //ゲッター
	 int Get_width() { return width; }                     //ゲッター
	 int Get_height() { return height; }                   //ゲッター

};

#endif //_CASTLE_H