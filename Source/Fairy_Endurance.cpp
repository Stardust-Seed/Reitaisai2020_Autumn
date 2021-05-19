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

void Fairy_Endurance::Update(GameResource* _gameRes) {
	BaseEnemy::Update(_gameRes);

	if (isHitCastle) {
		isAttack = true;
		inactiveType = eInactiveType::Invasion;
		attackType = eAttackType::Invasion;
		animationCnt = 0;
	}

	bool pIsAbility = _gameRes->player->Get_isAbility();
	int pAbilityType = _gameRes->player->Get_AbilityType();

	//移動処理
	Move(pIsAbility, pAbilityType);

	//アニメーション処理
	Animation(pIsAbility, pAbilityType);

	//攻撃処理
	if (isAttack == true) {
		AttackProc(_gameRes->player->Get_cx(), _gameRes->player->Get_cy());
	}
}

void Fairy_Endurance::Draw(GameResource* _gameRes) {
	BaseEnemy::Draw(_gameRes);
}