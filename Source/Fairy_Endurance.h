#ifndef _FAIRY_ENDURANCE_H
#define _FAIRY_ENDURANCE_H

#include "BaseEnemy.h"

class Fairy_Endurance :public virtual BaseEnemy {
private:
public:
	Fairy_Endurance() = default;
	Fairy_Endurance(float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType = eEnemyType::Endurance);
	Fairy_Endurance(float _x, float _y, float _speed, float _power, int _durability,
		eDirection _direction, eEnemyType _enemyType = eEnemyType::Endurance);

	void Update(GameResource* _gameRes);
	void Draw(GameResource* _gameRes);
};


#endif // !_FAIRY_ENDURANCE_H