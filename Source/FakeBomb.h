#ifndef _FAKEBOMB_H
#define _FAKEBOMB_H

#include "BaseBomb.h"

class BasePlayer;

class FakeBomb : public virtual BaseBomb
{
private:
	int fake_Animation[18] = { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 
	                           2, 2, 2, 2, 2, 2, 3};   // 表示する番号

	bool isFakeAction;		//偽物爆弾が爆破したかの判定

public:
	FakeBomb() = default;
	FakeBomb(int _power, float _speed, eBombType _bombType);
	void FakeMotion();		//偽物爆弾が不発したときの処理
	void Animation();		//アニメーション
	void Update(BasePlayer* player);
	void Draw();
};

#endif // !_FAKEBOMB_H
