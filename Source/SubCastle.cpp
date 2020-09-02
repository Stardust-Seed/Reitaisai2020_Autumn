#include <DxLib.h>
#include "SubCastle.h"
#include"EnemyManager.h"

SubCastle::SubCastle(int _durability,int _type)
	:BaseCastle(_durability) {       //コンストラクタ
	durability = _durability;


	switch (_type)
	{
	case 1:
		width = 50;
		height = 50;
		x = 350  - width;
		y = 450  - height;
		break;

	case 2:
		width = 30;
		height = 30;
		x = 850 - width;
		y = 400 - height;
		break;

	case 3:
		width = 60;
		height = 60;
		x = 550 - width;
		y = 250 - height;
		break;

	case 4:
		width = 50;
		height = 50;
		x = 550 - width;
		y = 750 - height;
		break;

	default:
		break;
	}


}

void SubCastle::Update(EnemyManager* enemy)
{
	for (int num = 0; num < enemy->Get_enemyNum(); num++)
	{
		if (enemy->Get_ActiveFlg(num) == true)
		{
			for (int i = 0; i < 4; i++)
			{
				ClisionHit(enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num),
					enemy->Get_height(num), enemy->Get_Power(num), num,
					enemy->Get_AttackFlg(num), enemy->Get_ActiveFlg(num));
			}
		}

		if (ClisionHit(enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num),
			enemy->Get_height(num), enemy->Get_Power(num), num,
			enemy->Get_AttackFlg(num), enemy->Get_ActiveFlg(num)) == true)
		{
			enemy->Set_IsAttack(num, false);
			enemy->Set_IsActive(num, false);
		}
	}
}

void SubCastle::Draw()
{
	//適当に表示
	if (isActive == true)
	{
		DrawBox(x, y, x + width, y + height, GetColor(0, 0, 128), true);
	}
}

//拠点がダメージを受けたときの処理
bool SubCastle::ClisionHit(float ox, float oy, float ow, float oh,
	int pow, int num, bool attackFlg, bool activeFlg)
{
	if (x + width >= ox && x <= ox + ow &&
		y + height >= oy && y <= oy + oh &&
		attackFlg == true && activeFlg == true)
	{
		//こんな感じでif文かませないと処理が1回以上されてしまうのでウェイ
		if (isHit == false)
		{
			durability -= pow;
			Set_Durability(durability);
			isHit = true;
		}

		return true;
	}

	if (isHit == true)
	{
		isHit = false;
	}

	//俺死んでしまう時の処理
	if (durability > 0)
	{
		isActive = true;
	}
	else
	{
		isActive = false;
	}

	Set_IsActive(isActive);

	return false;
}
