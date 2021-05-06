#include "BaseCastle.h"

//コンストラクタ
BaseCastle::BaseCastle(int _durability){
	direction = eDirection::None;
    maxDurabiliy = _durability;
	durability = _durability;
	isActive = true;
	isHit = false;
    dyingFlg = false;
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
            SE::Instance()->PlaySE(SE_CastleDamage);
            durability -= pow;
            isHit = true;
        }

        if (durability <= maxDurabiliy / 3 && dyingFlg == false)
        {
            SE::Instance()->PlaySE(SE_warning);
            dyingFlg = true;
        }
    }

    return isHit;
}

void BaseCastle::Damage_Proc(int _damage)
{
    SE::Instance()->PlaySE(SE_CastleDamage);
    durability -= _damage;

    if (durability <= maxDurabiliy / 3 && dyingFlg == false)
    {
        SE::Instance()->PlaySE(SE_warning);
        dyingFlg = true;
    }
}
