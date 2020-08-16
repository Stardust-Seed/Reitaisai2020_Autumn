#ifndef _FAIRY_ENDURANCE_H
#define _FAIRY_ENDURANCE_H

#include "BaseEnemy.h"

class Fairy_Endurance :public virtual BaseEnemy {
private:
public:
	Fairy_Endurance() = default;
	Fairy_Endurance(float _speed, float _power, int _durability, int _direction);
	void Update(Castle* _castle, BasePlayer* _player, BulletManager* _bulletManager);
	void Draw();
};


#endif // !_FAIRY_ENDURANCE_H