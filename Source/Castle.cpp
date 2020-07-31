#include "Castle.h"
#include "DxLib.h"
#include "Fairy_Speed.h"
//拠点の耐久力を設定
const int Castle::MAX_DURABILITY = 100;

//コンストラクタ
Castle::Castle(){

	durability = MAX_DURABILITY;
	isActive = true;
	//テスト用に少しずらしてある
	x = 1024 / 2 - 60+80;
	y = 768 / 2 - 60+80;
	width = 120;
	height = 120;
}

//void Castle::Update(Enemy& enemy)constになる予定
//今はスピード型の奴参照してテストしてます
void Castle::Update(Fairy_Speed* enemy)
{
	Draw();
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
	DrawBox(x-60, y-60, x+width+60, y+height+60, GetColor(25, 25, 25), true);
	//拠点の画像を読み込んで描画させます今は四角を表示
	DrawBox(x, y, x+width, y+height, GetColor(255, 255, 255), true);
}
/*
//ClisionHitが使えるなら必要なし？
//拠点が存在しているか判定する処理
void Castle::JudgeActive()
{
	if (durability <= 0)
	{
		isActive = false;
	}
	else
	{
		isActive = true;
	}
}

//ClisionHitが使えるなら必要なし？
//拠点がダメージを受けたときの処理
void Castle::HitDamage()
{
	durability -= 1;
	//エネミー側待ちなので仮の処理
	//Durability -= Enemy->GetPower();
}
*/

//拠点がダメージを受けたときの処理
bool Castle::ClisionHit(float ox, float oy, float ow, float oh,int pow)
{
	DrawFormatString(10, 500, GetColor(255, 255, 255), "%f", ox);
	DrawFormatString(10, 520, GetColor(255, 255, 255), "%f", oy);
	DrawFormatString(10, 540, GetColor(255, 255, 255), "%f", ow);
	DrawFormatString(10, 560, GetColor(255, 255, 255), "%f", oh);
	DrawFormatString(10, 580, GetColor(255, 255, 255), "%d", pow);

	if (x + width >= ox && x <= ox + ow &&
		y + height >= oy && y <= oy + oh)
	{
		//durability -= 10;    //とりあえずの記述
		durability -= pow;
	}

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