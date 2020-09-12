#ifndef _BUFFMANAGER_H
#define _BUFFMANAGER_H

class EnemyManager;
class ItemManager;

/// <summary>
/// BuffManager class
/// </summary>
class BuffManager final {
private:
	const int MAX_BUFFLEVEL = 3;	//バフレベルの最大値

	const float POWERBUFF_LV0 = 1.0f;	//攻撃バフLv0
	const float POWERBUFF_LV1 = 1.25f;	//攻撃バフLv1
	const float POWERBUFF_LV2 = 1.5f;	//攻撃バフLv2
	const float POWERBUFF_LV3 = 1.75f;	//攻撃バフLv3

	const float SPEEDBUFF_LV0 = 1.0f;	//速度バフLv0
	const float SPEEDBUFF_LV1 = 1.25f;	//速度バフLv1
	const float SPEEDBUFF_LV2 = 1.5f;	//速度バフLv2
	const float SPEEDBUFF_LV3 = 1.75f;	//速度バフLv3

	int powerLevel;			//現在のパワーバフレベル
	int speedLevel;			//現在のスピードバフレベル
	bool isPowerLevelMax;	//現在のパワーバフのレベルマックスフラグ
	bool isSpeedLevelMax;	//現在のスピードバフのレベルマックスフラグ

	bool isLevelDown;	//レベルダウンフラグ

	float powerBuff;	//バフするパワー
	float speedBuff;	//バフする速度
public:
	/// <summary>
	/// BuffManagerのコンストラクタ
	/// </summary>
	BuffManager();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="_itemManager">アイテムマネージャーの情報</param>
	/// <param name="_enemyManager">エネミーマネージャーの情報</param>
	void Update(ItemManager* _itemManager, EnemyManager* _enemyManager);

	/// <summary>
	/// レベルダウンの処理
	/// </summary>
	void DownBuffLevel();

	/// <summary>
	///	パワーバフレベルのレベル上昇処理
	/// </summary>
	/// <param name="_powerCount">パワーアイテムの取得数</param>
	/// <returns>取得した値 or 0(Errorのとき)</returns>
	int PowerBuff_LevelUpCheck(int _powerCount);

	/// <summary>
	/// スピードバフレベルのレベル上昇処理
	/// </summary>
	/// <param name="_speedCount">スピードアイテムの取得数</param>
	/// <returns>取得した値 or 0(Errorのとき)</returns>
	int SpeedBuff_LevelUpCheck(int _speedCount);

	/// <summary>
	/// 現在のパワーバフレベルを取得する
	/// </summary>
	/// <returns>現在のパワーレベル</returns>
	int GetPowerLevel() { return powerLevel; }

	/// <summary>
	/// 現在のスピードバフレベルを取得する
	/// </summary>
	/// <returns>現在のスピードレベル</returns>
	int GetSpeedLevel() { return speedLevel; }

	/// <summary>
	/// バフするパワーを取得する
	/// </summary>
	/// <returns>バフするパワー</returns>
	float GetPowerBuff() { return powerBuff; }

	/// <summary>
	/// バフする速度を取得する
	/// </summary>
	/// <returns>バフする速度</returns>
	float GetSpeedBuff() { return speedBuff; }

	/// <summary>
	/// 現在のパワーバフのレベルマックスフラグを取得する
	/// </summary>
	/// <returns>現在のパワーバフのレベルマックスフラグ</returns>
	bool GetIsPowerLevelMax() { return isPowerLevelMax; }

	/// <summary>
	/// 現在のスピードバフのレベルマックスフラグを取得する
	/// </summary>
	/// <returns>現在のスピードバフのレベルマックスフラグ</returns>
	bool GetIsSpeedLevelMax() { return isSpeedLevelMax; }

	/// <summary>
	/// レベルダウンフラグを取得する
	/// </summary>
	/// <returns>レベルダウンフラグ</returns>
	bool GetIsLevelDown() { return isLevelDown; }
};

#endif // !_BUFFMANAGER_H