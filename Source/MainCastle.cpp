#include "MainCastle.h"
#include "DxLib.h"
#include"EnemyManager.h"

//コンストラクタ
MainCastle::MainCastle(int _durability)
	:BaseCastle(_durability) {

	durability = _durability;
	width = 120;
	height = 120;
	x = GAME_WIDTH / 2 - width / 2;       //452
	y = GAME_HEIHGT / 2 - height / 2;     //324

}

void MainCastle::Update(EnemyManager* enemy)
{
	for (int num = 0; num < enemy->Get_enemyNum(); num++)
	{
		if (enemy->Get_ActiveFlg(num) == true)
		{
			ClisionHit(enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num),
				       enemy->Get_height(num), enemy->Get_Power(num),num,
				       enemy->Get_AttackFlg(num),enemy->Get_ActiveFlg(num));
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

//拠点の描画
void MainCastle::Draw()
{
	//プレイヤーの移動範囲(これUIの方がいいのでは)
	DrawBox(x - 60.0f, y - 60.0f, x + width + 60.0f, y + height + 60.0f, GetColor(25, 25, 25), true);

	if (isActive == true)
	{
		//拠点の画像を読み込んで描画させます今は四角を表示
		DrawBox(x, y, x + width, y + height, GetColor(255, 255, 255), true);
	}
}

//拠点がダメージを受けたときの処理
bool MainCastle::ClisionHit(float ox, float oy, float ow, float oh,
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