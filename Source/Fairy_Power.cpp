#include <DxLib.h>
#include "Fairy_Power.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "CastleManager.h"

Fairy_Power::Fairy_Power(float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType)
	:BaseEnemy(_speed, _power, _durability, _direction, _enemyType) {

}

Fairy_Power::Fairy_Power(float _x, float _y, float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType)
	: BaseEnemy(_x, _y, _speed, _power, _durability, _direction, _enemyType) {

}

void Fairy_Power::Update(CastleManager* _castleManager, BasePlayer* _player, BulletManager* _bulletManager) {
	BaseEnemy::Update(_castleManager, _player, _bulletManager);
}

void Fairy_Power::Draw() {
	BaseEnemy::Draw();
}