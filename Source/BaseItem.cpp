#include <DxLib.h>
#include <cmath>
#include "BaseItem.h"

BaseItem::BaseItem(float _x, float _y, float _width, float _height, eItem _itemType) {
	x = _x;
	y = _y;
	width = _width;
	height = _height;
	itemType = _itemType;

	moveSpeed = 0.9f;

	isHit = false;
	isActive = true;
}

void BaseItem::Move(float _px, float _py) {
	//オブジェクトが非アクティブ状態の時処理は行わないように
	if (isActive == false) {
		return;
	}

	float vx = _px - x;	//エネミー→プレイヤーのベクトルX
	float vy = _py - y;	//エネミー→プレイヤーのベクトルY

	float l = sqrtf((vx * vx) + (vy * vy));	//ベクトルの計算

	//正規化
	float dx = (vx / l) * moveSpeed;
	float dy = (vy / l) * moveSpeed;

	//移動制御
	if (abs(vx) < 0.1f) {
		dx = 0.0f;
	}
	if (abs(vy) < 0.1f) {
		dy = 0.0f;
	}

	//現在の座標に速度ベクトルを加算
	x += dx;
	y += dy;
}

void BaseItem::CheckIsActive() {
	//オブジェクトがhit状態のとき
	if (isHit == true) {
		isActive = false;
	}
}

bool BaseItem::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh) {
	//当たった場合
	if (mx + mw >= ox && mx <= ox + ow && my + mh >= oy && my <= oy + oh) {
		return true;
	}

	//当たらなかった場合
	return false;
}