#include <DxLib.h>
#include "Fairy_Endurance.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "CastleManager.h"

Fairy_Endurance::Fairy_Endurance(float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType)
	:BaseEnemy(_speed, _power, _durability, _direction, _enemyType) {

}

Fairy_Endurance::Fairy_Endurance(float _x, float _y, float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType)
	: BaseEnemy(_x, _y, _speed, _power, _durability, _direction, _enemyType) {

}

void Fairy_Endurance::Update(CastleManager* _castleManager, BasePlayer* _player, BulletManager* _bulletManager) {
	BaseEnemy::Update(_castleManager, _player, _bulletManager);

	if (isHitCastle) {
		isAttack = true;
		inactiveType = eInactiveType::Invasion;
		attackType = eAttackType::Invasion;
		animationCnt = 0;
	}

	/*------------------------------------------------------------------------------
	移動処理
	------------------------------------------------------------------------------*/
	Move(_player->Get_isAbility(), _player->Get_AbilityType());

	/*------------------------------------------------------------------------------
	アニメーション処理
	------------------------------------------------------------------------------*/
	Animation(_player->Get_isAbility(), _player->Get_AbilityType());

	/*------------------------------------------------------------------------------
	攻撃処理
	------------------------------------------------------------------------------*/
	if (isAttack == true) {
		AttackProc(_player->Get_cx(), _player->Get_cy());
	}
}

void Fairy_Endurance::Draw() {
	BaseEnemy::Draw();
}