#include <DxLib.h>
#include "SubCastle.h"
#include "EnemyManager.h"

//コンストラクタ
SubCastle::SubCastle(int _durability,int _type)
	:BaseCastle(_durability) {
	durability = _durability;

	//座標設定
	switch (_type)
	{
	case 1:    //左側
		width = 50;
		height = 50;
		x = 350  - width;
		y = 450  - height;
		enemyDirection = 0;

		break;

	case 2:    //右側
		width = 30;
		height = 30;
		x = 850 - width;
		y = 400 - height;
		enemyDirection = 1;

		break;

	case 3:    //上側
		width = 60;
		height = 60;
		x = 550 - width;
		y = 250 - height;
		enemyDirection = 2;

		break;

	case 4:    //下側
		width = 50;
		height = 50;
		x = 550 - width;
		y = 750 - height;
		enemyDirection = 3;

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
			ClisionHit(enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num),
				enemy->Get_height(num), enemy->Get_Power(num), num,
				enemy->Get_AttackFlg(num), enemy->Get_ActiveFlg(num));
		}

		if (ClisionHit(enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num),
			enemy->Get_height(num), enemy->Get_Power(num), num,
			enemy->Get_AttackFlg(num), enemy->Get_ActiveFlg(num)) == true)
		{
			enemy->Set_IsAttack(num, false);
			enemy->Set_IsActive(num, false);
		}
	}

	//占領状態なら
	if (isActive == false)
	{
		EnemyCastle();
	}

}

void SubCastle::Draw()
{
	//適当に表示
	if (isActive == true)
	{
		DrawBox(x, y, x + width, y + height, GetColor(0, 0, 128), true);
	}
	else
	{
		DrawBox(x, y, x + width, y + height, GetColor(128, 0, 0), true);
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
		//一回だけ処理
		if (isHit == false)
		{
			durability -= pow;
			//セットしてあげないと挙動してくれない
			Set_Durability(durability);
			isHit = true;
		}

		return true;
	}

	//一回だけ処理する用のフラグ処理
	if (isHit == true)
	{
		isHit = false;
	}

	//耐久の処理
	if (durability > 0)
	{
		isActive = true;
	}
	else
	{
		isActive = false;
	}

	//セットしてあげないと挙動してくれない
	Set_IsActive(isActive);

	return false;
}

void SubCastle::EnemyCastle()
{
	//EnemyManagerに送り付けるパラメータを設定(調整部分)
	enemySpeed =10;
	enemyPower=1;
	enemyDurability=10;

	Set_EnemySpeed(enemySpeed);
	Set_EnemyPower(enemyPower);
	Set_EnemyDurability(enemyDurability);
	Set_EnemyDirection(enemyDirection);
}

