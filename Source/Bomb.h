#ifndef _BOMB_H
#define _BOMB_H

#include "BaseBomb.h"

class Bomb :public BaseBomb {
private:
	const int BOMBDAMAGE = 10;

	int gBomb;
	int m_Image;	        // �摜�n���h��
	int GHandle[6];      // �i�[�p�摜�n���h��
	int act_frameIndex[12] = { 0, 1, 2, 2, 3, 4, 5, 4, 3, 2, 1, 0};    // �\������ԍ�
	int m_frameIndex = 0;
public:
	Bomb(int _power, eBombType _btype);
	void DamageMotion();
	void Update();
	void Draw();
};

#endif // !_BOMB_H
