#include "BaseCastle.h"

const int BaseCastle::MAX_DURABILITY = 100;		//最大耐久力	

//コンストラクタ
BaseCastle::BaseCastle(int _durability){
	direction = 0;
	durability = _durability;
	isActive = true;
	isHit = false;

}

//拠点がダメージを受けたときの処理
bool BaseCastle::ClisionHit(float ox, float oy, float ow, float oh,
	int pow, int num, bool attackFlg, bool activeFlg)
{
	if (x + width >= ox && x <= ox + ow &&
		y + height >= oy && y <= oy + oh &&
		attackFlg == true && activeFlg == true)
	{
		//一回だけ処理
		if (isHit == false)
		{
			durability -= pow;
			isHit = true;
			return isHit;
		}

	}

	//一回だけ処理する用のフラグ処理
	if (isHit == true)
	{
		isHit = false;
	}

	//耐久の処理
	if (durability <= 0)
	{
		isActive = false;
	}

	return isHit;
}

