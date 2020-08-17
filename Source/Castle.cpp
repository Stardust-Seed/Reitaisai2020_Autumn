#include "Castle.h"
#include "DxLib.h"
#include"EnemyManager.h"

//拠点の耐久力を設定
const int Castle::MAX_DURABILITY = 100;

//コンストラクタ
Castle::Castle() {

	durability = MAX_DURABILITY;
	isActive = true;
	width = 120;
	height = 120;
	x = GAME_WIDTH / 2 - width / 2;
	y = GAME_HEIHGT / 2 - height / 2;

}


void Castle::Update(EnemyManager* enemy)
{
	for (int num = 0; num < enemy->Get_enemyNum(); num++)
	{
		if (enemy->Get_ActiveFlg(num) == true)
		{
			ClisionHit(enemy->Get_x(num), enemy->Get_y(num), enemy->Get_width(num),
				       enemy->Get_height(num), enemy->Get_Power(num),num,
				       enemy->Get_AttackFlg(num),enemy->Get_ActiveFlg(num),enemy);
		}
	}
}

//拠点の描画
void Castle::Draw()
{
	//プレイヤーの移動範囲
	DrawBox(x - 60.0f, y - 60.0f, x + width + 60.0f, y + height + 60.0f, GetColor(25, 25, 25), true);
	//拠点の画像を読み込んで描画させます今は四角を表示
	DrawBox(x, y, x + width, y + height, GetColor(255, 255, 255), true);
}

//拠点がダメージを受けたときの処理
bool Castle::ClisionHit(float ox, float oy, float ow, float oh,
	                     int pow, int num, bool attackFlg, bool activeFlg,
	                     EnemyManager*enemy)
{
	if (x + width >= ox && x <= ox + ow &&
		y + height >= oy && y <= oy + oh &&
		attackFlg==true && activeFlg == true)
	{
		durability -= pow;
		enemy->Set_IsActive(num,false);
		enemy->Set_IsAttack(num, false);
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
	return isActive;
}