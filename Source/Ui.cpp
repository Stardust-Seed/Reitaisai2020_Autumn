#include <DxLib.h>
#include "Ui.h"

//HPバーの表示と中身の処理(MainCastle)
void UI::Get_CastleDurability()
{
	DrawBox(10, 5, 380, 120, GetColor(200, 200, 200), TRUE);		//後ろに敷く用

	DrawFormatStringToHandle(HPMOJI_X + 20, HPMOJI_Y + 15, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "HP");						//HPという文字を表示するため

	DrawFormatStringToHandle(HPMOJI_X + 250, HPMOJI_Y + 5, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), 
							 "%d/%d", CastleDurability, MAX_DURABILTY);

	DrawBox(HPBAR_X + 19, HPBAR_Y + 39, HPBAR_X1 + 321, HPBAR_Y1 + 61, GetColor(0, 0, 0), FALSE);				//HPバーの枠線(白)
	DrawBox(HPBAR_X + 20, HPBAR_Y + 40, HPBAR_X1 + 320, HPBAR_Y1 + 60, GetColor(190, 255, 190), TRUE);			//HPバーの枠線(塗りつぶし)

	percent = MAX_DURABILTY / 3;				//ピンチ時にHPゲージを赤色にするための割合(３割)

	if (CastleDurability <= 0)					//HPゲージが0以下になってもゲージは0で止める
	{
		CastleDurability = 0;
	}

	if (CastleDurability <= percent)			//３割以下でHPゲージが赤になる	
	{
		DrawBox(HPGAUGE_X + 20, HPGAUGE_Y + 40, HPGAUGE_X1 + 320 * CastleDurability / MAX_DURABILTY, HPGAUGE_Y1 + 60, GetColor(255, 0, 0), TRUE);		//ピンチ用HPゲージ(赤）
	}
	else
	{
		DrawBox(HPGAUGE_X + 20, HPGAUGE_Y + 40, HPGAUGE_X1 + 320 * CastleDurability / MAX_DURABILTY, HPGAUGE_Y1 + 60, GetColor(0, 255, 0), TRUE);		//通常用HPゲージ(緑)
	}
}

//HPバーの表示と中身の処理(SubCastle)
void UI::Get_SubCastleDurability()
{
	for (i = 1; i < 5; i++)
	{
		if (SubCastleDurability[i] <= 0)					//HPゲージが0以下になってもゲージは0で止める
		{
			SubCastleDurability[i] = 0;
		}
	}

	//サブ拠点1(左）
	DrawBox(HPMOJI_X + 10, HPMOJI_Y + 200, HPMOJI_X + HPBAR_X, HPMOJI_Y + 15 + 200, GetColor(255, 255, 255), FALSE);		//HPという文字を表示するための枠

	DrawString(HPMOJI_X + 20, HPMOJI_Y + 200, "HP1", GetColor(255, 255, 255));							//HPという文字を表示するため

	
	DrawBox(HPBAR_X, HPBAR_Y + 200, (HPBAR_X1 + 200) / 2, HPBAR_Y1 + 15 + 200, GetColor(190, 255, 190), FALSE);
	DrawBox(HPBAR_X, HPBAR_Y + 200, (HPBAR_X1 + 200) / 2, HPBAR_Y1 + 15 + 200, GetColor(190, 255, 190), TRUE);		//HPバーの枠線(塗り潰し)

	if (isActive[1] == true)
	{
		DrawBox(HPGAUGE_X, HPGAUGE_Y + 200, HPGAUGE_X1 + 75 * SubCastleDurability[1] / MAX_SABDURABILTY, HPGAUGE_Y1 + 15 + 200, GetColor(0, 255, 0), TRUE);		//通常用HPゲージ(緑)
	}
	else
	{
		DrawString(HPGAUGE_X + 20, HPGAUGE_Y + 200, "破壊", GetColor(0, 0, 0));						//破壊という文字を表示するため
	}

	//サブ拠点2(右)
	DrawBox(HPMOJI_X + 190, HPMOJI_Y + 200, HPMOJI_X + 180 + HPBAR_X, HPMOJI_Y + 15 + 200, GetColor(255, 255, 255), FALSE);		//HPという文字を表示するための枠

	DrawString(HPMOJI_X + 200, HPMOJI_Y + 200, "HP2", GetColor(255, 255, 255));						//HPという文字を表示するため

	DrawBox(HPBAR_X + 180, HPBAR_Y + 200, (HPBAR_X1 + 180 + 400) / 2, HPBAR_Y1 + 15 + 200, GetColor(255, 255, 255), FALSE);		//HPバーの枠線(白)

	DrawBox(HPBAR_X + 180, HPBAR_Y + 200, (HPBAR_X1 + 180 + 400) / 2, HPBAR_Y1 + 15 + 200, GetColor(190, 255, 190), TRUE);		//HPバーの枠線(塗りつぶし)

	if (isActive[2] == true)
	{
		DrawBox(HPGAUGE_X + 180, HPGAUGE_Y + 200, HPGAUGE_X1 + 180 + 85 * SubCastleDurability[2] / MAX_SABDURABILTY, HPGAUGE_Y1 + 15 + 200, GetColor(0, 255, 0), TRUE);		//通常用HPゲージ(緑)
	}
	else
	{
		DrawString(HPGAUGE_X + 200, HPGAUGE_Y + 200, "破壊", GetColor(0, 0, 0));						//破壊という文字を表示するため
	}

	//サブ拠点3(上)
	DrawBox(HPMOJI_X + 10, HPMOJI_Y + 250, HPMOJI_X + HPBAR_X, HPMOJI_Y + 15 + 250, GetColor(255, 255, 255), FALSE);		//HPという文字を表示するための枠

	DrawString(HPMOJI_X + 20, HPMOJI_Y + 250, "HP3", GetColor(255, 255, 255));						//HPという文字を表示するため

	DrawBox(HPBAR_X, HPBAR_Y + 250, (HPBAR_X1 + 200) / 2, HPBAR_Y1 + 15 + 250, GetColor(255, 255, 255), FALSE);		//HPバーの枠線(白)

	DrawBox(HPBAR_X, HPBAR_Y + 250, (HPBAR_X1 + 200) / 2, HPBAR_Y1 + 15 + 250, GetColor(190, 255, 190), TRUE);		//HPバーの枠線(塗りつぶし)

	if (isActive[3] == true)
	{
		DrawBox(HPGAUGE_X, HPGAUGE_Y + 250, HPGAUGE_X1 + 75 * SubCastleDurability[3] / MAX_SABDURABILTY, HPGAUGE_Y1 + 15 + 250, GetColor(0, 255, 0), TRUE);		    //通常用HPゲージ(緑)
	}
	else
	{
		DrawString(HPGAUGE_X + 20, HPGAUGE_Y + 250, "破壊", GetColor(0, 0, 0));						//HPという文字を表示するため
	}

	//サブ拠点4(下)
	DrawBox(HPMOJI_X + 190, HPMOJI_Y + 250, HPMOJI_X + 180 + HPBAR_X, HPMOJI_Y + 15 + 250, GetColor(255, 255, 255), FALSE);		//HPという文字を表示するための枠

	DrawString(HPMOJI_X + 200, HPMOJI_Y + 250, "HP4", GetColor(255, 255, 255));						//HPという文字を表示するため

	DrawBox(HPBAR_X + 180, HPBAR_Y + 250, (HPBAR_X1 + 180 + 400) / 2, HPBAR_Y1 + 15 + 250, GetColor(255, 255, 255), FALSE);		//HPバーの枠線(白)

	DrawBox(HPBAR_X + 180, HPBAR_Y + 250, (HPBAR_X1 + 180 + 400) / 2, HPBAR_Y1 + 15 + 250, GetColor(190, 255, 190), TRUE);		//HPバーの枠線(塗りつぶし)

	if (isActive[4] == true)
	{
		DrawBox(HPGAUGE_X + 180, HPGAUGE_Y + 250, HPGAUGE_X1 + 180 + 85 * SubCastleDurability[4] / MAX_SABDURABILTY, HPGAUGE_Y1 + 15 + 250, GetColor(0, 255, 0), TRUE);		//通常用HPゲージ(緑)
	}
	else
	{
		DrawString(HPGAUGE_X + 200, HPGAUGE_Y + 250, "破壊", GetColor(0, 0, 0));						//破壊という文字を表示するため
	}
}

//バフ関連のUI
void UI::Get_BuffPoint()
{
	//Pアイテム
	DrawBox(PMOJI_X, PMOJI_Y + 5, PMOJI_X1, PMOJI_Y1, GetColor(0, 0, 0), FALSE);										//文字

	DrawFormatStringToHandle(PMOJI_X + 5, PMOJI_Y - 45, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "P");

	DrawBox(PBAR_X, PBAR_Y + 1, PBAR_X1, PBAR_Y1, GetColor(0, 0, 0), FALSE);							//枠
	DrawBox(PBAR_X, PBAR_Y, PBAR_X1, PBAR_Y1, GetColor(190, 255, 190), TRUE);

	if (pBuffLevel == 3)
	{
		pBuffPoint = 15;
		DrawBox(PGAUGE_X, PGAUGE_Y, PGAUGE_X1, PGAUGE_Y1 - 250 * pBuffPoint / MAX_BUFF, GetColor(255, 0, 0), TRUE);		//ゲージ
		DrawFormatStringToHandle(1500, 900, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "PLvMAX");
	}
	else
	{
		DrawBox(PGAUGE_X, PGAUGE_Y, PGAUGE_X1, PGAUGE_Y1 - 250 * pBuffPoint / MAX_BUFF, GetColor(255, 0, 0), TRUE);		//ゲージ
		DrawFormatStringToHandle(1500, 900, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "PLv%d", pBuffLevel);
	}

	//Sアイテム
	DrawBox(SMOJI_X, SMOJI_Y + 5, SMOJI_X1, SMOJI_Y1, GetColor(0, 0, 0), FALSE);										//文字

	DrawFormatStringToHandle(SMOJI_X + 5, SMOJI_Y - 45, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "S");

	DrawBox(SBAR_X, SBAR_Y + 1, SBAR_X1, SBAR_Y1, GetColor(0, 0, 0), FALSE);											//枠
	DrawBox(SBAR_X, SBAR_Y, SBAR_X1, SBAR_Y1, GetColor(190, 255, 190), TRUE);											//塗りつぶし

	if (sBuffLevel == 3)
	{
		sBuffPoint = 15;
		DrawBox(SGAUGE_X, SGAUGE_Y, SGAUGE_X1, SGAUGE_Y1 - 250 * sBuffPoint / MAX_BUFF, GetColor(0, 0, 255), TRUE);		//ゲージ
		DrawFormatStringToHandle(1500, 1000, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "SLvMAX");
	}
	else
	{
		DrawBox(SGAUGE_X, SGAUGE_Y, SGAUGE_X1, SGAUGE_Y1 - 250 * sBuffPoint / MAX_BUFF, GetColor(0, 0, 255), TRUE);		//ゲージ
		DrawFormatStringToHandle(1500, 1000, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "SLv%d", sBuffLevel);
	}
}

//スキル関連のUI 
void UI::AbilityUi()
{
	DrawFormatStringToHandle(1500, 800, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "Skill回数%d", skillCount);

	//咲夜さんの時止め
	if (skillType == SAKUYA_Ability && skillActive == true)
	{
		DrawBox(pX - 1, pY + 1, pX + 51, pY - 6, GetColor(255, 255, 255), FALSE);									    //枠
		DrawBox(pX, pY, pX + 50 * skillClock / MAX_STOPTIME, pY - 5, GetColor(0, 255, 255), TRUE);			//ゲージ
	}

	//フランさんの殲滅(追加用）
	/*if ()
	{
		DrawBox(pX, pY, pX + 50, pY - 5, GetColor(255, 255, 255), FALSE);									    //枠
		DrawBox(pX, pY, pX + 50 * skillClock / MAX_STOPTIME, pY - 5, GetColor(255, 100, 100), TRUE);			//ゲージ
	}*/
}

//制限時間のUI
void UI::TimeLimitUi()
{
	DrawFormatStringToHandle(10, 80, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "TIME %d%d%d", hundredsTime, tensTime, onesTime);
}

//更新
void UI::Update(CastleManager* _castlemanager, ItemManager* _itemmanager, BuffManager* _buffmanager, BasePlayer* _baseplayer, TimeLimit* _timelimit)
{
	//バフ関連
	pBuffPoint = _itemmanager->Get_P_Count();
	sBuffPoint = _itemmanager->Get_S_Count();
	pBuffLevel = _buffmanager->GetPowerLevel();
	sBuffLevel = _buffmanager->GetSpeedLevel();

	//拠点関連
	CastleDurability = _castlemanager->Get_Durability(0);		//拠点の体力をセットする

	for (i = 1; i < 5; i++)
	{
		SubCastleDurability[i] = _castlemanager->Get_Durability(i);
		isActive[i] = _castlemanager->Get_IsActive(i);
		//castleX[i] = _castlemanager->Get_DrawPosX(i);		
		//castleY[i] = _castlemanager->Get_DrawPosY(i);			
	}

	//スキル関連
	skillCount = _baseplayer->Get_AbilityCount();
	skillClock = _baseplayer->Get_AbilityClock();  //コメント化だったらミス
	skillActive = _baseplayer->Get_isAbility();
	skillType = _baseplayer->Get_AbilityType();

	pX = _baseplayer->Get_x();
	pY = _baseplayer->Get_y();

	//タイム関連
	hundredsTime = _timelimit->Get_hundredsPlace();
	tensTime = _timelimit->Get_tensPlace();
	onesTime = _timelimit->Get_onesPlace();
}

//描画処理
void UI::Draw()
{
	DrawBox(1450, 730, 1900, 1060, GetColor(200, 200, 200), TRUE);
	Get_CastleDurability();
	Get_SubCastleDurability();
	Get_BuffPoint();
	AbilityUi();
	TimeLimitUi();
}


