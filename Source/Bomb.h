#ifndef _BOMB_H
#define _BOMB_H

#include "BaseBomb.h"

class Bomb :public BaseBomb {
private:
	const int BOMBDAMAGE = 10;

public:
	Bomb();
	void Damage();
};

#endif // !_BOMB_H
