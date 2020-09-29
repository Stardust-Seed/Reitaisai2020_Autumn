#include <DxLib.h>
#include "Fairy_Power.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "CastleManager.h"
#include "Image.h"

Fairy_Power::Fairy_Power(float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType)
	:BaseEnemy(_speed, _power, _durability, _direction, _enemyType) {

}

Fairy_Power::Fairy_Power(float _x, float _y, float _speed, float _power, int _durability,
	eDirection _direction, eEnemyType _enemyType)
	: BaseEnemy(_x, _y, _speed, _power, _durability, _direction, _enemyType) {

}

void Fairy_Power::Update(CastleManager* _castleManager, BasePlayer* _player, BulletManager* _bulletManager) {

	cx = x + (width / 2);
	cy = y + (height / 2);

	if (isAttack == true && inactiveType == eInactiveType::Invasion) {
		isAttack = false;
	}

	for (int i = 0; i < _bulletManager->Get_MaxBullet(); i++) {
		if (_bulletManager->Get_IsActive(i) == true) {
			if (ClisionHit(x, y, width, height, _bulletManager->Get_X(i), _bulletManager->Get_Y(i),
				_bulletManager->Get_Width(i), _bulletManager->Get_Height(i))) {
				_bulletManager->Set_isActive(i, false);
				DamageProc(_player->Get_power());
			}
		}
	}

	JudgeActive();

	if (isCoolDown == true) {
		SearchCoolDownTime();
	}

	for (int i = 0; i < _castleManager->Get_CastleNum(); i++) {
		SearchCastle(_castleManager->Get_X(i), _castleManager->Get_Y(i),
			_castleManager->Get_Width(i), _castleManager->Get_Height(i), _castleManager->Get_IsActive(i));
	}

	SearchPlayer(_player->Get_x(), _player->Get_y(), _player->Get_width(), _player->Get_height(),
		_player);

	if (isAttack == true) {
		AttackProc(_player->Get_cx(), _player->Get_cy());
	}

	if (_player->Get_isAbility() == true && _player->Get_AbilityType() == SAKUYA_Ability) {
		return;
	}

	Move();
}

void Fairy_Power::Draw() {
	Animation();
}