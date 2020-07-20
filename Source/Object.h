#ifndef _OBJECT_H
#define _OBJECT_H

class Object
{
protected:
	float x;		//x座標
	float y;		//y座標
	float cx;		//中心座標x
	float cy;		//中心座標y
	float width;	//横幅
	float height;	//縦幅

	bool isHit;     //当たり判定のフラグ

public:
	virtual bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh) = 0;
	// m = my 自分   o = opnet 相手

	virtual void Draw() = 0;   //描画処理
	
};

#endif //