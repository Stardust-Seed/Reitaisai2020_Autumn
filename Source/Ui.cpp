#include <DxLib.h>
#include "Ui.h"

//HPバーの表示と中身の処理
void UI::Get_CastleDurability()
{
	DrawBox(HPMOJI_X + 10, HPMOJI_Y, HPMOJI_X + HPBAR_X, HPMOJI_Y + 20, GetColor(255, 255, 255), FALSE);		//HPという文字を表示するための枠

	DrawString(HPMOJI_X	+ 20, HPMOJI_Y + 2, "HP", GetColor(255, 255, 255));						//HPという文字を表示するため

	DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200, HPBAR_Y1 + 20, GetColor(255, 255, 255), FALSE);		//HPバーの枠線(白)

	percent = MAX_DURABILTY / 3;				//ピンチ時にHPゲージを赤色にするための割合(３割)　＊要調整

	if (CastleDurability <= 0)					//HPゲージが0以下になってもゲージは0で止める
	{
		CastleDurability = 0;
	}

	if (CastleDurability <= percent)			//３割以下でHPゲージが赤になる	
	{
		DrawBox(HPGAUGE_X, HPGAUGE_Y, HPGAUGE_X1 + 200 * CastleDurability / MAX_DURABILTY, HPGAUGE_Y1 + 20, GetColor(255, 0, 0), TRUE);		//ピンチ用HPゲージ(赤）
	}
	else
	{
		DrawBox(HPGAUGE_X, HPGAUGE_Y, HPGAUGE_X1 + 200 * CastleDurability / MAX_DURABILTY, HPGAUGE_Y1 + 20, GetColor(0, 255, 0), TRUE);		//通常用HPゲージ(緑)
	}
}

void UI::Get_BuffPoint() 
{
	//Pアイテム
	DrawBox(PMOJI_X, PMOJI_Y, PBAR_X1, PMOJI_Y + 20, GetColor(255, 255, 255), FALSE);										//文字
	DrawFormatString(PMOJI_X + 10, PMOJI_Y + 2, GetColor(255, 255, 255), "PLv%d", pBuffLevel);

	DrawBox(PBAR_X, PBAR_Y, PBAR_X1 + 200, PBAR_Y1 + 20, GetColor(255, 255, 255), FALSE);									//枠
	
	DrawBox(PGAUGE_X, PGAUGE_Y, PGAUGE_X1 + 200 * pBuffPoint / MAX_BUFF, PGAUGE_Y1 + 20, GetColor(0, 255, 0), TRUE);	//ゲージ
	
	//Sアイテム
	DrawBox(SMOJI_X, SMOJI_Y, SBAR_X1, SMOJI_Y + 20, GetColor(255, 255, 255), FALSE);										//文字
	DrawFormatString(SMOJI_X + 10, SMOJI_Y + 2, GetColor(255, 255, 255), "SLv%d", sBuffLevel);

	DrawBox(SBAR_X, SBAR_Y, SBAR_X1 + 200, SBAR_Y1 + 20, GetColor(255, 255, 255), FALSE);									//枠

	DrawBox(SGAUGE_X, SGAUGE_Y, SGAUGE_X1 + 200 * sBuffPoint / MAX_BUFF, SGAUGE_Y1 + 20, GetColor(0, 255, 0), TRUE);	//ゲージ

}

//操作説明
void UI::PlayGuide()
{
	DrawString(700, 10, "十字キーで上下左右に移動", GetColor(255, 255, 255));
	DrawString(700, 60, "〇〇でポーズメニュー表示", GetColor(255, 255, 255));
	DrawString(700, 110, "Zキーで弾発射", GetColor(255, 255, 255));
}

//更新
void UI::Update(CastleManager* _castlemanager, ItemManager* _itemmanager, BuffManager* _buffmanager)
{
	pBuffPoint = _itemmanager->Get_P_Count();
	sBuffPoint = _itemmanager->Get_S_Count();
	pBuffLevel = _buffmanager->GetPowerLevel();
	sBuffLevel = _buffmanager->GetSpeedLevel();
	CastleDurability = _castlemanager->Get_Durability(0);		//拠点の体力をセットする
}

//描画処理
void UI::Draw()
{
	Get_CastleDurability();
	Get_BuffPoint();
	PlayGuide();
}
