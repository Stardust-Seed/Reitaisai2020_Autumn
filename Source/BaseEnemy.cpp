#include <DxLib.h>
#include "BaseEnemy.h"

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

//�R���X�g���N�^
BaseEnemy::BaseEnemy(float _speed, float _power, int _durability, int _direction) {
	speed = _speed;
	power = _power;
	durability = _durability;
	direction = _direction;
	isActive = true;
	isAttack = false;

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

//�ړ�����
void BaseEnemy::Move() {

	if (isActive == false) {
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

//�������菈��
void BaseEnemy::JudgeActive() {
	if (durability <= 0) {
		isActive = false;
	}
}

//�v���C���[�T�[�`����
void BaseEnemy::SearchPlayer(int _px, int _py, int _pw, int _ph) {

	if (direction == DIRECTIONLEFT) {
		if (_px + _pw >= x + width && _px <= x + width && _py + _ph >= y && _py <= y + height) {
			isAttack = true;
		}
	}

	if (direction == DIRECTIONRIGHT) {
		if (_px + _pw >= x - width && _px <= x - width && _py + _ph >= y && _py <= y + height) {
			isAttack = true;
		}
	}

	if (direction == DIRECTIONUP) {
		if (_px + _pw >= x && _px <= x + width && _py + _ph >= y + height && _py <= y + height) {
			isAttack = true;
		}
	}

	if (direction == DIRECTIONDOWN) {
		if (_px + _pw >= x && _px <= x + width && _py + _ph >= y - height && _py <= y - height) {
			isAttack = true;
		}
	}
}

//��T�[�`����
void BaseEnemy::SearchCastle(int _ox, int _oy, int _ow, int _oh) {

	if (direction == DIRECTIONLEFT) {
		if (x + width >= _ox + width && x <= _ox + _ow && y + height >= _oy && y <= _oy + _oh) {
			isAttack = true;
			isActive = false;
		}
	}

	if (direction == DIRECTIONRIGHT) {
		if (x + width >= _ox && x <= (_ox + _ow) - width && y + height >= _oy && y <= _oy + _oh) {
			isAttack = true;
			isActive = false;
		}
	}

	if (direction == DIRECTIONUP) {
		if (x + width >= _ox && x <= _ox + _ow && y + height >= _oy + height && y <= _oy + _oh) {
			isAttack = true;
			isActive = false;
		}
	}

	if (direction == DIRECTIONDOWN) {
		if (x + width >= _ox && x <= _ox + _ow && y + height >= _oy && y <= (_oy + _oh) - height) {
			isAttack = true;
			isActive = false;
		}
	}
}

//�����蔻�菈��
bool BaseEnemy::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh) {

	if (mx + mw >= ox && mx <= ox + ow && my + mh >= oy && my <= oy + oh) {
		return true;
	}

	return false;
}