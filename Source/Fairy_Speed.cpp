#include <DxLib.h>
#include "Fairy_Speed.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "CastleManager.h"

Fairy_Speed::Fairy_Speed(float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType)
	:BaseEnemy(_speed, _power, _durability, _direction, _enemyType) {

}

Fairy_Speed::Fairy_Speed(float _x, float _y, float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType)
	: BaseEnemy(_x, _y, _speed, _power, _durability, _direction, _enemyType) {

}

void Fairy_Speed::Update(CastleManager* _castleManager, BasePlayer* _player, BulletManager* _bulletManager) {
	BaseEnemy::Update(_castleManager, _player, _bulletManager);
}

void Fairy_Speed::Draw() {
	BaseEnemy::Draw();
}