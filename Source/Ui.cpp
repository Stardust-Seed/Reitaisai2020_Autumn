#include <DxLib.h>
#include "Ui.h"

//HPバーの表示と中身の処理
void UI::Set_CastleDurability()
{
	CastleDurability = Get_durability();		//拠点の体力を受け取る

	DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200, HPBAR_Y1 + 20, Color = GetColor(255, 255, 255), FALSE);		//HPバーの枠線(白)

	percent = MAX_DURABILTY / 3;				//ピンチ時にHPゲージを赤色にするための割合(３割)　＊要調整
	 
	if (CastleDurability <= percent)			//３割以下でHPゲージが赤になる	
	{
		DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200 * CastleDurability / MAX_DURABILTY, HPBAR_Y1 + 20, Color = GetColor(255, 0, 0), TRUE);		//ピンチ用HPゲージ(赤）
	}
	else
	{
		DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200 * CastleDurability / MAX_DURABILTY, HPBAR_Y1 + 20, Color = GetColor(0, 255, 0), TRUE);		//通常用HPゲージ(緑)
	}

	/*DrawFormatString(150,500, GetColor(255, 255, 255), "%d", percent);//確認用　＊後で消す
	DrawFormatString(150, 600, GetColor(255, 255, 255), "%d", MAX_DURABILTY);//確認用　＊後で消す
	DrawFormatString(150,700, GetColor(255, 255, 255), "%d", CastleDurability);//確認用　＊後で消す*/
}

//敵の数とかそういう関連の処理を書く　＊コメント変える
void UI::Set_EnemyiesRest(int) 
{

}

//操作説明
void UI::PlayGuide()
{
	//追加があるかもしれないけど思いつくのはこの二つ  ＊コメント消す
	DrawString(500, 0, "十字キーで上下左右に移動", GetColor(255, 255, 255));
	DrawString(500, 100, "スペースキーでポーズメニュー表示", GetColor(255, 255, 255));
}

//更新
void UI::Update(Castle* _castle)
{
	Set_durability(_castle->Get_durability());		//現在の拠点の体力
}

//描画処理
void UI::Draw()
{
	Set_CastleDurability();
	PlayGuide();
}
