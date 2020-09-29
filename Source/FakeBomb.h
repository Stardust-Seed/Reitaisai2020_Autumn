#ifndef _FAKEBOMB_H
#define _FAKEBOMB_H

#include "BaseBomb.h"

class FakeBomb : public virtual BaseBomb
{
private:
	int act_frameIndex[16] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	                           2, 2, 2, 3};   // ï\é¶Ç∑ÇÈî‘çÜ
	int m_frameIndex = 0;
	bool isFakeAction;
public:
	FakeBomb() = default;
	FakeBomb(int _power, int _speed, eBombType _bombType);
	void FakeMotion();
	void Animation();
	void Update();
	void Draw();
};

#endif // !_FAKEBOMB_H
