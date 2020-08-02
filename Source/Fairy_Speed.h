#ifndef _FAIRY_SPEED_H
#define _FAIRY_SPEED_H

#include "BaseEnemy.h"

class Fairy_Speed :public virtual BaseEnemy {
private:
public:
	Fairy_Speed() = default;
	Fairy_Speed(float _speed, float _power, int _durability, int _direction);
	void Update(Castle* _castle);
	void Draw();
};

#endif // !_FAIRY_SPEED_H