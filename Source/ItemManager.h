#ifndef _ITEMMANAGER_H
#define _ITEMMANAGER_H

#include "BaseItem.h"

class BasePlayer;

/// <summary>
/// ItemManager class
/// </summary>
class ItemManager final {
private:
	static const int MAX_ITEM_NUM = 50;				//アイテムの画面上最大生成数
	static const int ITEM_GENERATION_RATE = 100;	//アイテムの生成率

	BaseItem* items[MAX_ITEM_NUM];	//アイテム

	int p_Count;	//Pの取得数カウント
	int s_Count;	//Sの取得数カウント
public:
	/// <summary>
	/// ItemManagerのコンストラクタ
	/// </summary>
	ItemManager();

	/// <summary>
	/// ItemManagerのコンストラクタ
	/// </summary>
	~ItemManager();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="_player">プレイヤー情報</param>
	void Update(BasePlayer* _player);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// アイテムの生成処理
	/// </summary>
	/// <param name="_ex">エネミーのx座標</param>
	/// <param name="_ey">エネミーのy座標</param>
	void SpawnItem(float _ex, float _ey);

	/// <summary>
	/// p_Countのゲッター
	/// </summary>
	/// <returns>p_Count</returns>
	int Get_P_Count() { return p_Count; }

	/// <summary>
	/// s_Countのゲッター
	/// </summary>
	/// <returns>s_Count</returns>
	int Get_S_Count() { return s_Count; }
};

#endif // !_ITEMMANAGER_H