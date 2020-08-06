#include <DxLib.h>
#include "Ui.h"
#include "Castle.h"

//後ほど拠点の体力関連を受け取る　＊コメント変える
void UI::Set_CastleDurability(int CastleDurability, int MAX_DURABILITY)
{
	MAX_DURABILITY = 10;
	CastleDurability = 3;
	DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200, HPBAR_Y1 + 20, Color = GetColor(255, 255, 255), FALSE);		//HPバーの枠線

	percent = MAX_DURABILITY / 3;
	 
	if (CastleDurability <= percent)
	{
		DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200 * CastleDurability / MAX_DURABILITY, HPBAR_Y1 + 20, Color = GetColor(255, 0, 0), TRUE);		//ピンチ用HPゲージ(赤）
	}
	else
	{
		DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200 * CastleDurability / MAX_DURABILITY, HPBAR_Y1 + 20, Color = GetColor(0, 255, 0), TRUE);		//通常用HPゲージ(緑)
	}
	//DrawFormatString(10, 500, GetColor(255, 255, 255), "%f", percent);		//確認用　＊後で消す
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
