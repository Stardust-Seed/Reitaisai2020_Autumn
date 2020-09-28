#ifndef _BOMB_H
#define _BOMB_H

#include "BaseBomb.h"

class Bomb : public virtual BaseBomb {
private:
	const int BOMBDAMAGE = 10;

	int gBomb[1];
	int act_frameIndex[12] = { 0, 1, 2, 2, 3, 4, 5, 4, 3, 2, 1, 0};    // 表示する番号
	int m_frameIndex = 0;
public:
	Bomb() = default;
	Bomb(int _power, int _speed, eBombType _bombType);
	void Animation();
	void DamageMotion();
	void Update();
	void Draw();
};

#endif // !_BOMB_H
