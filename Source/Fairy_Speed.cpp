#include <DxLib.h>
#include "Fairy_Speed.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "CastleManager.h"

Fairy_Speed::Fairy_Speed(float _speed, float _power, int _durability, eDirection _direction)
	:BaseEnemy(_speed, _power, _durability, _direction) {

}

Fairy_Speed::Fairy_Speed(float _speed, float _power, int _durability, eDirection _direction,
	float _x, float _y)
	: BaseEnemy(_speed, _power, _durability, _direction, _x, _y) {

}

void Fairy_Speed::Update(CastleManager* _castleManager, BasePlayer* _player, BulletManager* _bulletManager) {

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

	SearchPlayer(_player->Get_x(), _player->Get_y(), _player->Get_width(), _player->Get_height(),
		_player);

	if (isCoolDown == true) {
		SearchCoolDownTime();
	}

	for (int i = 0; i < _castleManager->Get_CastleNum(); i++) {
		SearchCastle(_castleManager->Get_X(i), _castleManager->Get_Y(i),
			_castleManager->Get_Width(i), _castleManager->Get_Height(i), _castleManager->Get_IsActive(i));
	}

	Move();

	if (isAttack) {
		AttackProc();
	}
}

void Fairy_Speed::Draw() {
	DrawBoxAA(x, y, x + width, y + height, GetColor(0, 0, 255), TRUE);
}