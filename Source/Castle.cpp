#include "Castle.h"
#include "DxLib.h"

//拠点の耐久力を設定
const int Castle::MAX_DURABILITY = 100;

//コンストラクタ
Castle::Castle(){

	durability = MAX_DURABILITY;
	isActive = true;

}
//void Castle::Update(Enemy& enemy)constになる予定
void Castle::Update()
{
	Draw();
	JudgeActive();
	HitDamage();
	//後々こんな感じの記述になる？
	//ClisionHit(x,y,width,height, enemy.x, enemy.y, enemy.width, enemy.height);
}
//拠点の描画
void Castle::Draw()
{
	//拠点の画像を読み込んで描画させます今は四角を表示
	DrawBox(1024/2-120, 768/2-120, 1024/2+120, 768/2+120, GetColor(255, 255, 255), true);
}

//ClisionHitが使えるなら必要なし？
//拠点が存在しているか判定する処理
void Castle::JudgeActive()
{
	DrawFormatString(10, 100, GetColor(255, 255, 255), "%d",durability);
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

//拠点がダメージを受けたときの処理
bool Castle::ClisionHit(float mx, float my, float mw, float mh,
	float ox, float oy, float ow, float oh)
{
	if (mx + mw >= ox && mx <= ox + ow &&
		my + mh >= oy && my <= oy + oh)
	{
		durability -= 10;    //とりあえずの記述
		//Durability -= Enemy.GetPower();
	}

	if (durability <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}