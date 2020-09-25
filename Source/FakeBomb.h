#ifndef _FAKEBOMB_H
#define _FAKEBOMB_H

#include "BaseBomb.h"

class FakeBomb:public BaseBomb
{
private:
	int fBomb;
	int fAction;
	bool isFakeAction;
public:
	FakeBomb(int _power, eBombType _btype);
	void FakeMotion();
	void Update();
	void Draw();
};

#endif // !_FAKEBOMB_H
