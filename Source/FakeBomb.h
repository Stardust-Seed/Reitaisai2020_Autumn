#ifndef _FAKEBOMB_H
#define _FAKEBOMB_H

#include "BaseBomb.h"

class FakeBomb : public virtual BaseBomb
{
private:
	int fBomb;
	int fAction;
	bool isFakeAction;
public:
	FakeBomb() = default;
	FakeBomb(int _power, int _speed, eBombType _bombType);
	void FakeMotion();
	void Update();
	void Draw();
};

#endif // !_FAKEBOMB_H
