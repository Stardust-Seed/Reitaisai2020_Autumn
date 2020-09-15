#ifndef _FAIRY_ENDURANCE_H
#define _FAIRY_ENDURANCE_H

#include "BaseEnemy.h"

class Fairy_Endurance :public virtual BaseEnemy {
private:
public:
	Fairy_Endurance() = default;
	Fairy_Endurance(float _speed, float _power, int _durability, eDirection _direction);
	Fairy_Endurance(float _speed, float _power,int _durability , eDirection _direction,int _x,int _y);
	void Update(CastleManager* _castleManager, BasePlayer* _player, BulletManager* _bulletManager);
	void Draw();
};


#endif // !_FAIRY_ENDURANCE_H