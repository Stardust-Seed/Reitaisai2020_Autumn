#ifndef _BOMB_H
#define _BOMB_H

#include "BaseBomb.h"

class MainCastle;

class Bomb : public virtual BaseBomb {
private:
	const int BOMBDAMAGE = 10;
	MainCastle* castle;
	int act_frameIndex[20] = { 0, 1, 1, 2, 2, 3, 3, 3, 4, 4,
		                      4, 5, 5, 4, 4, 3, 3, 2, 1, 0 };    // ï\é¶Ç∑ÇÈî‘çÜ
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
