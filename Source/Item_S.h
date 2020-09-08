#ifndef _ITEM_S_H
#define _ITEM_S_H

#include "BaseItem.h"

/// <summary>
/// Item_S class
/// </summary>
class Item_S final :public virtual BaseItem {
public:
	/// <summary>
	/// Item_Sのコンストラクタ
	/// </summary>
	/// <param name="_x">x座標</param>
	/// <param name="_y">y座標</param>
	/// <param name="_width">横幅</param>
	/// <param name="_height">高さ</param>
	/// <param name="_itemType">アイテム識別変数</param>
	Item_S(float _x, float _y, float _width, float _height, eItem _itemType);

	/// <summary>
	/// Item_Sのデストラクタ
	/// </summary>
	~Item_S();

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

#endif // !_ITEM_S_H