#include <DxLib.h>
#include "Define.h"
#include "Image.h"
#include "Star.h"

Star::Star(float _x, float _y, double _extX, double _extY, float _angle) {
	x = _x;
	y = _y;
	extX = _extX;
	extY = _extY;
	angle = _angle;
}

void Star::Update() {
	x += 5.0f;
	y += 2.5f;
}

void Star::Draw() {
	DrawRotaGraph3F(x, y, 900.0f / 2, 900.0f / 2, extX, extY,
		(angle * PAI) / 180,
		Image::Instance()->GetGraph(eImageType::Background_Star), TRUE);
}