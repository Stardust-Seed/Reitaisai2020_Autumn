#ifndef _ITEM_P_H
#define _ITEM_P_H

#include "BaseItem.h"

/// <summary>
/// Item_P class
/// </summary>
class Item_P final :public virtual BaseItem {
public:
	/// <summary>
	/// Item_Pのコンストラクタ
	/// </summary>
	/// <param name="_x">x座標</param>
	/// <param name="_y">y座標</param>
	/// <param name="_width">横幅</param>
	/// <param name="_height">高さ</param>
	/// <param name="_itemType">アイテム識別変数</param>
	Item_P(float _x, float _y, float _width, float _height, eItem _itemType);

	/// <summary>
	/// Item_Pのデストラクタ
	/// </summary>
	~Item_P();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="_player">プレイヤー情報</param>
	void Update(BasePlayer* _player);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
};

#endif // !_ITEM_P_H
