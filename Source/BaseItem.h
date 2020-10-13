#ifndef _BASEITEM_H
#define _BASEITEM_H

#include "Object.h"

class BasePlayer;

/// <summary>
/// eItem
/// </summary>
enum class eItem {
	Power,
	Speed,
};

/// <summary>
/// BaseItem class
/// </summary>
class BaseItem :public virtual Object {
private:
	float moveSpeed;	//アイテムの移動速度
	bool isActive;		//アクティブ状態フラグ
	eItem itemType;		//アイテム識別用変数
public:
	/// <summary>
	/// BaseItemのコンストラクタ
	/// </summary>
	/// <param name="_x">x座標</param>
	/// <param name="_y">y座標</param>
	/// <param name="_width">横幅</param>
	/// <param name="_height">高さ</param>
	/// <param name="_itemType">アイテム識別変数</param>
	BaseItem(float _x, float _y, float _width, float _height, eItem _itemType);

	/// <summary>
	/// BaseItemのデストラクタ
	/// </summary>
	virtual ~BaseItem() {}

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="_player">プレイヤー情報</param>
	virtual void Update(BasePlayer* _player) = 0;

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// 移動処理
	/// </summary>
	/// <param name="_px">プレイヤーのx座標</param>
	/// <param name="_py">プレイヤーのy座標</param>
	void Move(float _px, float _py);

	/// <summary>
	/// 現在アイテムオブジェクトがアクティブかチェックする処理
	/// </summary>
	void CheckIsActive();

	/// <summary>
	/// 当たり判定処理
	/// </summary>
	/// <param name="mx">Itemのx座標</param>
	/// <param name="my">Itemのy座標</param>
	/// <param name="mw">Itemの横幅</param>
	/// <param name="mh">Itemの高さ</param>
	/// <param name="ox">当たったオブジェクトのx座標</param>
	/// <param name="oy">当たったオブジェクトのy座標</param>
	/// <param name="ow">当たったオブジェクトの横幅</param>
	/// <param name="oh">当たったオブジェクトの高さ</param>
	/// <returns>当たったかどうかのbool値</returns>
	bool ClisionHit(float mx, float my, float mw, float mh,
		float ox, float oy, float ow, float oh);

	/// <summary>
	/// itemTypeのゲッター
	/// </summary>
	/// <returns>アイテムの識別タイプ</returns>
	eItem Get_ItemType() { return itemType; }

	/// <summary>
	/// isHitのゲッター
	/// </summary>
	/// <returns>当たったかどうかのbool値</returns>
	bool Get_IsHit() { return isHit; }

	/// <summary>
	/// isActiveのゲッター
	/// </summary>
	/// <returns>オブジェクトがアクティブかどうかのbool値</returns>
	bool Get_IsActive() { return isActive; }
};

#endif // !_BASEITEM_H