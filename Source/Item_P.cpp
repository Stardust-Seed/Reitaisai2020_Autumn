#include <DxLib.h>
#include "Item_P.h"

#include "BasePlayer.h"

Item_P::Item_P(float _x, float _y, float _width, float _height, eItem _itemType) :
	BaseItem(_x, _y, _width, _height, _itemType) {

}

Item_P::~Item_P() {

}

void Item_P::Update(BasePlayer* _player) {
	//�����蔻�菈��
	isHit = ClisionHit(x, y, width, height,
		_player->Get_x(), _player->Get_y(), _player->Get_width(), _player->Get_height());

	//���݃A�C�e���I�u�W�F�N�g���A�N�e�B�u���`�F�b�N���鏈��
	CheckIsActive();

	//�ړ�����
	Move(_player->Get_x(), _player->Get_y());
}

void Item_P::Draw() {
	DrawBoxAA(x, y, x + width, y + height, GetColor(255, 0, 0), TRUE);
}