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

//�ʏ�X�|�[���p�̃R���X�g���N�^
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

//�T�u���_�p�̃R���X�g���N�^
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

//�ړ�����
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

//�������菈��
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

//�v���C���[�T�[�`����
/*
����G���͉������U����z�肵�ĂȂ����莮�ƂȂ��Ă�̂�
�G���������U�����s���悤�ɂ���ۂ͔��莮��ύX����K�v��������
*/
void BaseEnemy::SearchPlayer(float _px, float _py, float _pw, float _ph, BasePlayer* _player) {
	if (x + width >= _px && x <= _px + _pw && y + height >= _py && y <= _py + _ph) {
		//�v���C���[���X�^�����Ă�ꍇ�U�����s��Ȃ�
		if (_player->Get_isStan()) {
			return;
		}

		isAttack = true;
	}
}

//��T�[�`����
void BaseEnemy::SearchCastle(float _ox, float _oy, float _ow, float _oh, bool _isActive) {
	if ((x + width >= _ox && x <= _ox + _ow && y + height >= _oy && y <= _oy + _oh)
		&& _isActive == true) {
		isAttack = true;
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