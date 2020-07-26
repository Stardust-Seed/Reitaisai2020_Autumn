#include <DxLib.h>
#include "Fairy_Speed.h"

Fairy_Speed::Fairy_Speed(float _speed, float _power, int _durability, int _direction)
	:BaseEnemy(_speed, _power, _durability, _direction) {

}

void Fairy_Speed::Update() {
	JudgeActive();

	Move();
}

void Fairy_Speed::Draw() {
	DrawBoxAA(x, y, x + width, y + height, GetColor(0, 0, 255), TRUE);
}