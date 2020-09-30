#ifndef _FAKEBOMB_H
#define _FAKEBOMB_H

#include "BaseBomb.h"

class FakeBomb : public virtual BaseBomb
{
private:
	int fake_Animation[18] = { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 
	                           2, 2, 2, 2, 2, 2, 3};   // ï\é¶Ç∑ÇÈî‘çÜ
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
