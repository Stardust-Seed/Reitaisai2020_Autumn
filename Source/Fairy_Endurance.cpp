#include <DxLib.h>
#include "Fairy_Endurance.h"

Fairy_Endurance::Fairy_Endurance(float _speed, float _power, int _durability, int _direction)
	:BaseEnemy(_speed, _power, _durability, _direction) {

}

void Fairy_Endurance::Update() {
	JudgeActive();

	Move();
}

void Fairy_Endurance::Draw() {
	DrawBoxAA(x, y, x + width, y + height, GetColor(0, 255, 0), TRUE);
}