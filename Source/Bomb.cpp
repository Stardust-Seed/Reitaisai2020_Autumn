#include <DxLib.h>
#include "Bomb.h"

Bomb::Bomb(float _speed, int _damage, int _direction, int _countdown)
	: BaseBomb(_speed, _damage, _direction, _countdown)
{

};

void Bomb::Update()
{

}

void  Bomb::Draw()
{
	DrawCircle(50, 50, 5, GetColor(255, 255, 255), TRUE);
}