#ifndef _FAIRY_POWER_H
#define _FAIRY_POWER_H

#include "BaseEnemy.h"

class Fairy_Power :public virtual BaseEnemy {
private:
public:
	Fairy_Power() = default;
	Fairy_Power(float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType = eEnemyType::Power);
	Fairy_Power(float _x, float _y, float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType = eEnemyType::Power);

	void Update(GameResource* _gameRes);
	void Draw(GameResource* _gameRes);
};

#endif // !_FAIRY_POWER_H