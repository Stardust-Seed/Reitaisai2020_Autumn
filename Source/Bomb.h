#ifndef _BOMB_H
#define _BOMB_H

#include "BaseBomb.h"

class BasePlayer;

class Bomb : public virtual BaseBomb {
private:
	
	int bomb_Animation[25] = { 0, 0, 1, 1, 1, 2, 2, 2, 3, 3,
		                      4, 5, 5, 4, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0, 6 };    // 表示する番号
	
public:
	Bomb() = default;
	Bomb(int _power, float _speed, eBombType _bombType);
	void Animation();		//アニメーション
	void DamageMotion();	//爆破したときの処理
	void Update(BasePlayer*player);
	void Draw();
};

#endif // !_BOMB_H
