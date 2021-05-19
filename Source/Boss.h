#ifndef _BOSS_H
#define _BOSS_H

#include "BaseEnemy.h"

//ボスクラス
class Boss final : public virtual BaseEnemy {
private:
	const int STOPTIME = 120;	//停止秒数
	int stopCnt;				//停止カウント

	const int COOLTIME = 300;	//攻撃のクールタイム
	int attackCnt;				//攻撃カウンタ

	const int EFFECT_MAX_NUM = 8;	//エフェクトの最大数
	int* effectArray;				//エフェクト描画用配列
	int effectIndex;				//エフェクト描画用配列のindex指定用
	bool isEffect;					//エフェクトフラグ
	float effectDrawX;				//エフェクトを描画する位置(x座標)
	float effectDrawY;				//エフェクトを描画する位置(y座標)
public:
	//デフォルトコンストラクタ
	Boss() = default;

	//デストラクタ
	~Boss();

	//初期スポーン位置からの生成用コンストラクタ
	Boss(float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType = eEnemyType::Boss);

	//更新処理
	void Update(GameResource* _gameRes);
	//描画処理
	void Draw(GameResource* _gameRes);
};

#endif // !_BOSS_H