#include <DxLib.h>
#include "Bomb.h"

#include "Castle.h"

Bomb::Bomb(float _speed, int _damage, int _direction, int _countdown)
	: BaseBomb(_speed, _damage, _direction, _countdown)
{

};

void Bomb::Update()
{
	JudgeTrigger();
	Damage(BOMBDAMAGE);

}

void  Bomb::Draw()
{
	//DrawCircle(50, 50, 5, GetColor(255, 0, 0), TRUE);
}