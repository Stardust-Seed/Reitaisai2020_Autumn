#ifndef _BOMB_H
#define _BOMB_H

#include "BaseBomb.h"
#include "BasePlayer.h"

class BasePlayer;

class Bomb : public virtual BaseBomb {
private:
	const int BOMBDAMAGE = 10;
	
	
	int bomb_Animation[21] = { 0, 1, 1, 2, 2, 3, 3, 3, 4, 4,
		                      4, 5, 5, 4, 4, 3, 3, 2, 1, 0, 6 };    // ï\é¶Ç∑ÇÈî‘çÜ
	
	
public:
	Bomb() = default;
	Bomb(int _power, int _speed, eBombType _bombType);
	void Animation();
	void DamageMotion();
	void Update(BasePlayer*player);
	void Draw();
};

#endif // !_BOMB_H
