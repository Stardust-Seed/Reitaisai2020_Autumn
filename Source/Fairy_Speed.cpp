#include <DxLib.h>
#include "Fairy_Speed.h"

#include "BasePlayer.h"
#include "BulletManager.h"
#include "Castle.h"

Fairy_Speed::Fairy_Speed(float _speed, float _power, int _durability, int _direction)
	:BaseEnemy(_speed, _power, _durability, _direction) {

}

void Fairy_Speed::Update(Castle* _castle, BasePlayer* _player, BulletManager* _bulletManager) {

	for (int i = 0; i < 10; i++) {

		if (_bulletManager->Get_IsActive(i) == true) {
			if (ClisionHit(x, y, width, height, _bulletManager->Get_X(i), _bulletManager->Get_Y(i),
				_bulletManager->Get_Width(i), _bulletManager->Get_Height(i))) {
				DamageProc(_player->Get_power());
			}
		}
	}

	JudgeActive();

	SearchPlayer(_player->Get_x(), _player->Get_y(), _player->Get_width(), _player->Get_height(),
		_player);
	SearchCastle(_castle->Get_x(), _castle->Get_y(), _castle->Get_width(), _castle->Get_height());

	Move();

	if (isAttack) {
		AttackProc();
	}
}

void Fairy_Speed::Draw() {
	DrawBoxAA(x, y, x + width, y + height, GetColor(0, 0, 255), TRUE);
}