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

void Fairy_Power::Update(GameResource* _gameRes) {
	BaseEnemy::Update(_gameRes);

	if (isHitCastle) {
		isAttack = true;
		inactiveType = eInactiveType::Invasion;
		attackType = eAttackType::Invasion;
		animationCnt = 0;
	}

	bool pIsAbility = _gameRes->player->Get_isAbility();
	int pAbilityType = _gameRes->player->Get_AbilityType();

	//�ړ�����
	Move(pIsAbility, pAbilityType);

	//�A�j���[�V��������
	Animation(pIsAbility, pAbilityType);

	//�U������
	if (isAttack == true) {
		AttackProc(_gameRes->player->Get_cx(), _gameRes->player->Get_cy());
	}
}

void Fairy_Power::Draw(GameResource* _gameRes) {
	BaseEnemy::Draw(_gameRes);
}