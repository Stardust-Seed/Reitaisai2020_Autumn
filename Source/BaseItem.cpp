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
	//�I�u�W�F�N�g����A�N�e�B�u��Ԃ̎������͍s��Ȃ��悤��
	if (isActive == false) {
		return;
	}

	float vx = _px - x;	//�G�l�~�[���v���C���[�̃x�N�g��X
	float vy = _py - y;	//�G�l�~�[���v���C���[�̃x�N�g��Y

	float l = sqrtf((vx * vx) + (vy * vy));	//�x�N�g���̌v�Z

	//���K��
	float dx = (vx / l) * moveSpeed;
	float dy = (vy / l) * moveSpeed;

	//�ړ�����
	if (abs(vx) < 0.1f) {
		dx = 0.0f;
	}
	if (abs(vy) < 0.1f) {
		dy = 0.0f;
	}

	//���݂̍��W�ɑ��x�x�N�g�������Z
	x += dx;
	y += dy;
}

void BaseItem::CheckIsActive() {
	//�I�u�W�F�N�g��hit��Ԃ̂Ƃ�
	if (isHit == true) {
		isActive = false;
	}
}

bool BaseItem::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh) {
	//���������ꍇ
	if (mx + mw >= ox && mx <= ox + ow && my + mh >= oy && my <= oy + oh) {
		return true;
	}

	//������Ȃ������ꍇ
	return false;
}