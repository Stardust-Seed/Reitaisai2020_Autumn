#ifndef _FAIRY_BOMB_H
#define _FAIRY_BOMB_H

#include "BaseEnemy.h"

class Fairy_Bomb : public virtual BaseEnemy {
public:
	//デフォルトコンストラクタ
	Fairy_Bomb() = default;

	//初期スポーン位置からの生成用コンストラクタ
	Fairy_Bomb(float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType = eEnemyType::Bomb);

	//占領した拠点からの生成用コンストラクタ
	Fairy_Bomb(float _x, float _y, float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType);

	//更新処理
	void Update(CastleManager * _castleManager, BasePlayer * _player,
		BulletManager * _bulletManager);

	//描画処理
	void Draw();
};

#endif // !_FAIRY_BOMB_H