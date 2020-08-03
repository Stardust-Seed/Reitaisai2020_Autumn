#include "Castle.h"
#include "DxLib.h"
#include "Fairy_Speed.h"
//#include"EnemyManager.h"

//拠点の耐久力を設定
const int Castle::MAX_DURABILITY = 100;

//コンストラクタ
Castle::Castle(){

	durability = MAX_DURABILITY;
	isActive = true;

	width = 120;
	height = 120;
	x = GAME_WIDTH  / 2 - width  / 2;
	y = GAME_HEIHGT / 2 - height / 2;

}

//void Castle::Update(Enemy& enemy)constになる予定
//今はスピード型の奴参照してテストしてます
//void Castle::Update(EnemyManager* enemy)
void Castle::Update(Fairy_Speed* enemy)
{
	ClisionHit(enemy->Get_X(), enemy->Get_Y(), enemy->Get_Width(), enemy->Get_Height(),enemy->GetPower());
}

//拠点の描画
void Castle::Draw()
{
	DrawFormatString(10, 100, GetColor(255, 255, 255), "%d", durability);
	if (isActive == false)
	{
		DrawFormatString(10, 130, GetColor(255, 255, 255), "クラムボンは死んだよ");
	}
	else
	{
		DrawFormatString(10, 130, GetColor(255, 255, 255), "クラムボンはいきてる");
	}

	//プレイヤーの移動範囲
	DrawBox(x-60.0f, y-60.0f, x+width+60.0f, y+height+60.0f, GetColor(25, 25, 25), true);
	//拠点の画像を読み込んで描画させます今は四角を表示
	DrawBox(x, y, x+width, y+height, GetColor(255, 255, 255), true);
}

//拠点がダメージを受けたときの処理
bool Castle::ClisionHit(float ox, float oy, float ow, float oh,int pow)
{
	DrawFormatString(10, 500, GetColor(255, 255, 255), "%f", ox);
	DrawFormatString(10, 520, GetColor(255, 255, 255), "%f", oy);
	DrawFormatString(10, 540, GetColor(255, 255, 255), "%f", ow);
	DrawFormatString(10, 560, GetColor(255, 255, 255), "%f", oh);
	DrawFormatString(10, 580, GetColor(255, 255, 255), "%d", pow);
	//ソーシャルディスタンスを保てない屑野郎が来たら
	//星屑野郎の攻撃力分、自分のHPを減らすことが出来る！
	if (x + width >= ox && x <= ox + ow &&
		y + height >= oy && y <= oy + oh)
	{
		durability -= pow;
	}

	//俺死んでしまう時の処理
	if (durability >= 0)
	{
		isActive = true;
	}
	else
	{
		isActive = false;
	}

	return isActive;
}