#ifndef _FAKEBOMB_H
#define _FAKEBOMB_H

#include "BaseBomb.h"

class BasePlayer;

class FakeBomb : public virtual BaseBomb
{
private:
	int fake_Animation[18] = { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 
	                           2, 2, 2, 2, 2, 2, 3};   // �\������ԍ�

	bool isFakeAction;		//�U�����e�����j�������̔���

public:
	FakeBomb() = default;
	FakeBomb(int _power, float _speed, eBombType _bombType);
	void FakeMotion();		//�U�����e���s�������Ƃ��̏���
	void Animation();		//�A�j���[�V����
	void Update(BasePlayer* player);
	void Draw();
};

#endif // !_FAKEBOMB_H
