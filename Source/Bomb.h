#ifndef _BOMB_H
#define _BOMB_H

#include "BaseBomb.h"

class Bomb :public BaseBomb {
private:
	const int BOMBDAMAGE = 10;
public:
	Bomb(float _speed, int _damage, int _direction, int _countdown);
	void Update();
	void Draw();
};

#endif // !_BOMB_H
