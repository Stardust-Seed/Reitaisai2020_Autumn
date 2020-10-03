#include <DxLib.h>
#include "Item_S.h"

#include "BasePlayer.h"
#include "Image.h"

Item_S::Item_S(float _x, float _y, float _width, float _height, eItem _itemType) :
	BaseItem(_x, _y, _width, _height, _itemType) {

}

Item_S::~Item_S() {

}

void Item_S::Update(BasePlayer* _player) {
	//当たり判定処理
	isHit = ClisionHit(x, y, width, height,
		_player->Get_x(), _player->Get_y(), _player->Get_width(), _player->Get_height());

	//現在アイテムオブジェクトがアクティブかチェックする処理
	CheckIsActive();

	//移動処理
	Move(_player->Get_cx(), _player->Get_cy());
}

void Item_S::Draw() {
	DrawGraph(x, y, Image::Instance()->GetGraph(eImageType::Gpicture_Item, 1), TRUE);
}