#include <DxLib.h>
#include "BaseEnemy.h"
#include "BasePlayer.h"
#include "BulletManager.h"

const float BaseEnemy::ENEMY_SPAWNXLEFT = 82;
const float BaseEnemy::ENEMY_SPAWNYLEFT = 360;
const float BaseEnemy::ENEMY_SPAWNXUP = 488;
const float BaseEnemy::ENEMY_SPAWNYUP = -48;
const float BaseEnemy::ENEMY_SPAWNXRIGHT = 894;
const float BaseEnemy::ENEMY_SPAWNYRIGHT = 360;
const float BaseEnemy::ENEMY_SPAWNXDOWN = 488;
const float BaseEnemy::ENEMY_SPAWNYDOWN = 816;
const int BaseEnemy::DIRECTIONLEFT = 0;
const int BaseEnemy::DIRECTIONRIGHT = 1;
const int BaseEnemy::DIRECTIONUP = 2;
const int BaseEnemy::DIRECTIONDOWN = 3;

//通常スポーン用のコンストラクタ
BaseEnemy::BaseEnemy(float _speed, float _power, int _durability, int _direction) {
	speed = _speed;
	power = _power;
	durability = _durability;
	direction = _direction;
	isActive = true;
	isAttack = false;
	isHit = false;
	inactiveType = eInactiveType::None;

	if (direction == DIRECTIONLEFT) {
		x = ENEMY_SPAWNXLEFT;
		y = ENEMY_SPAWNYLEFT;
	}

	if (direction == DIRECTIONRIGHT) {
		x = ENEMY_SPAWNXRIGHT;
		y = ENEMY_SPAWNYRIGHT;
	}

	if (direction == DIRECTIONUP) {
		x = ENEMY_SPAWNXUP;
		y = ENEMY_SPAWNYUP;
	}

	if (direction == DIRECTIONDOWN) {
		x = ENEMY_SPAWNXDOWN;
		y = ENEMY_SPAWNYDOWN;
	}

	width = 48;
	height = 48;
}

//サブ拠点用のコンストラクタ
BaseEnemy::BaseEnemy(float _speed, float _power, int _durability, int _direction, float _x, float _y) {
	speed = _speed;
	power = _power;
	durability = _durability;
	direction = _direction;
	isActive = true;
	isAttack = false;
	isHit = false;
	inactiveType = eInactiveType::None;
	x = _x;
	y = _y;

	width = 48;
	height = 48;
}

//移動処理
void BaseEnemy::Move() {

	if (isActive == false || isAttack == true) {
		return;
	}

	if (direction == DIRECTIONLEFT) {
		x += speed;
	}

	if (direction == DIRECTIONRIGHT) {
		x -= speed;
	}

	if (direction == DIRECTIONUP) {
		y += speed;
	}

	if (direction == DIRECTIONDOWN) {
		y -= speed;
	}

}

//生存判定処理
void BaseEnemy::JudgeActive() {
	if (durability <= 0) {
		inactiveType = eInactiveType::Defeat;
		isActive = false;
	}
}

void BaseEnemy::AttackProc() {
	static int attackTime = 0;

	if (attackTime == 30) {
		isAttack = false;
		attackTime = 0;
		return;
	}

	attackTime++;
}

void BaseEnemy::DamageProc(int _damage) {
	durability -= _damage;
}

//プレイヤーサーチ処理
/*
現状敵側は遠距離攻撃を想定してない判定式となってるので
敵が遠距離攻撃を行うようにする際は判定式を変更する必要性がある
*/
void BaseEnemy::SearchPlayer(float _px, float _py, float _pw, float _ph, BasePlayer* _player) {
	if (x + width >= _px && x <= _px + _pw && y + height >= _py && y <= _py + _ph) {
		//プレイヤーがスタンしてる場合攻撃を行わない
		if (_player->Get_isStan()) {
			return;
		}

		isAttack = true;
	}
}

//城サーチ処理
void BaseEnemy::SearchCastle(float _ox, float _oy, float _ow, float _oh, bool _isActive) {
	if ((x + width >= _ox && x <= _ox + _ow && y + height >= _oy && y <= _oy + _oh)
		&& _isActive == true) {
		isAttack = true;
	}
}

//当たり判定処理
bool BaseEnemy::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh) {

	if (mx + mw >= ox && mx <= ox + ow && my + mh >= oy && my <= oy + oh) {
		return true;
	}

	return false;
}