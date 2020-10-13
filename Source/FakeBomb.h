#ifndef _FAKEBOMB_H
#define _FAKEBOMB_H

#include "BaseBomb.h"

class BasePlayer;

class FakeBomb : public virtual BaseBomb
{
private:
	int fake_Animation[18] = { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 
	                           2, 2, 2, 2, 2, 2, 3};   // •\¦‚·‚é”Ô†

	bool isFakeAction;		//‹U•¨”š’e‚ª”š”j‚µ‚½‚©‚Ì”»’è

public:
	FakeBomb() = default;
	FakeBomb(int _power, float _speed, eBombType _bombType);
	void FakeMotion();		//‹U•¨”š’e‚ª•s”­‚µ‚½‚Æ‚«‚Ìˆ—
	void Animation();		//ƒAƒjƒ[ƒVƒ‡ƒ“
	void Update(BasePlayer* player);
	void Draw();
};

#endif // !_FAKEBOMB_H
