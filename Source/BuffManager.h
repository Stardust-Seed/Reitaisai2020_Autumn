#ifndef _BUFFMANAGER_H
#define _BUFFMANAGER_H

class EnemyManager;
class ItemManager;

/// <summary>
/// BuffManager class
/// </summary>
class BuffManager final {
private:


	int powerLevel;		//現在のパワーバフレベル
	int speedLevel;		//現在のスピードバフレベル
	float powerBuff;	//バフするパワー
	float speedBuff;	//バフする速度
public:
	/// <summary>
	/// BuffManagerのコンストラクタ
	/// </summary>
	BuffManager();

	void Update(ItemManager* _itemManager, EnemyManager* _enemyManager);

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
};

#endif // !_BUFFMANAGER_H