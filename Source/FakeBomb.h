#ifndef _FAKEBOMB_H
#define _FAKEBOMB_H

#include "BaseBomb.h"

class FakeBomb:public BaseBomb
{
public:
	FakeBomb();
	void FakeMotion();
	void Update();
	void Draw();
};

#endif // !_FAKEBOMB_H
