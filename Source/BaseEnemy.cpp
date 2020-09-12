#include <DxLib.h>
#include "Define.h"
#include "BaseEnemy.h"
#include "BasePlayer.h"
#include "BulletManager.h"

const float BaseEnemy::ENEMY_SPAWNXLEFT = 420;
const float BaseEnemy::ENEMY_SPAWNYLEFT = (GAME_HEIHGT / 2) + (48 / 2);
const float BaseEnemy::ENEMY_SPAWNXUP = (GAME_WIDTH / 2) + (48 / 2);
const float BaseEnemy::ENEMY_SPAWNYUP = 0 - 48;
const float BaseEnemy::ENEMY_SPAWNXRIGHT = 1500;
const float BaseEnemy::ENEMY_SPAWNYRIGHT = (GAME_HEIHGT / 2) + (48 / 2);
const float BaseEnemy::ENEMY_SPAWNXDOWN = (GAME_WIDTH / 2) + (48 / 2);
const float BaseEnemy::ENEMY_SPAWNYDOWN = GAME_HEIHGT + 48;

//通常スポーン用のコンストラクタ
BaseEnemy::BaseEnemy(float _speed, float _power, int _durability, eDirection _direction) {
	speed = _speed;
	power = _power;
	durability = _durability;
	direction = _direction;
	isActive = true;
	isAttack = false;
	isHit = false;
	inactiveType = eInactiveType::None;

	if (direction == eDirection::Left) {
		x = ENEMY_SPAWNXLEFT;
		y = ENEMY_SPAWNYLEFT;
	}

	if (direction == eDirection::Right) {
		x = ENEMY_SPAWNXRIGHT;
		y = ENEMY_SPAWNYRIGHT;
	}

	if (direction == eDirection::Up) {
		x = ENEMY_SPAWNXUP;
		y = ENEMY_SPAWNYUP;
	}

	if (direction == eDirection::Down) {
		x = ENEMY_SPAWNXDOWN;
		y = ENEMY_SPAWNYDOWN;
	}

	width = 48;
	height = 48;
}

//サブ拠点用のコンストラクタ
BaseEnemy::BaseEnemy(float _speed, float _power, int _durability, eDirection _direction, float _x, float _y) {
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

	if (direction == eDirection::Left) {
		x += speed;
	}

	if (direction == eDirection::Down) {
		x -= speed;
	}

	if (direction == eDirection::Up) {
		y += speed;
	}

	if (direction == eDirection::Down) {
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