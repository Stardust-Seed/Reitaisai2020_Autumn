#include "BaseEnemy.h"

const float BaseEnemy::ENEMY_SPAWNXLEFT = 0;
const float BaseEnemy::ENEMY_SPAWNYLEFT = 0;
const float BaseEnemy::ENEMY_SPAWNXUP = 0;
const float BaseEnemy::ENEMY_SPAWNYUP = 0;
const float BaseEnemy::ENEMY_SPAWNXRIGHT = 0;
const float BaseEnemy::ENEMY_SPAWNYRIGHT = 0;
const float BaseEnemy::ENEMY_SPAWNXDOWN = 0;
const float BaseEnemy::ENEMY_SPAWNYDOWN = 0;
const int BaseEnemy::DIRECTIONLEFT = 0;
const int BaseEnemy::DIRECTIONRIGHT = 1;
const int BaseEnemy::DIRECTIONUP = 2;
const int BaseEnemy::DIRECTIONDOWN = 3;

//コンストラクタ
BaseEnemy::BaseEnemy() {
	speed = 0;
	power = 0;
	dulability = 0;
	direction = 0;
	isActive = true;
	isAttack = false;
}

//移動処理
void BaseEnemy::Move() {
	switch (direction) {
	case BaseEnemy::DIRECTIONLEFT:
		x += speed;
		break;
	case BaseEnemy::DIRECTIONRIGHT:
		x -= speed;
		break;
	case BaseEnemy::DIRECTIONUP:
		y += speed;
		break;
	case BaseEnemy::DIRECTIONDOWN:
		y -= speed;
		break;
	}
}

//生存判定処理
void BaseEnemy::JudgeActive() {
	if (dulability >= 0) {
		isActive = false;
	}
}

//当たり判定処理
bool BaseEnemy::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh){

	if (mx + mw >= ox && mx <= ox + ow && my + mh >= oy && my <= oy + oh) {
		return true;
	}

	return false;
}