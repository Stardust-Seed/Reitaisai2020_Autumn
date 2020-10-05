#include <DxLib.h>
#include "Ui.h"

//HPバーの表示と中身の処理(MainCastle)
void UI::Get_CastleDurability()
{
	DrawBox(HPMOJI_X + 10, HPMOJI_Y, HPMOJI_X + HPBAR_X, HPMOJI_Y + 20, GetColor(255, 255, 255), FALSE);		//HPという文字を表示するための枠

	DrawString(HPMOJI_X + 20, HPMOJI_Y + 2, "HP", GetColor(255, 255, 255));							//HPという文字を表示するため

	DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200, HPBAR_Y1 + 20, GetColor(255, 255, 255), FALSE);		//HPバーの枠線(白)
	DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200, HPBAR_Y1 + 20, GetColor(190, 255, 190), TRUE);		//HPバーの枠線(白)

	percent = MAX_DURABILTY / 3;				//ピンチ時にHPゲージを赤色にするための割合(３割)

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

	DrawString(HPMOJI_X + 20, HPMOJI_Y + 200, "HP1", GetColor(255, 255, 255));						//HPという文字を表示するため

	DrawBox(HPBAR_X, HPBAR_Y + 200, (HPBAR_X1 + 200) / 2, HPBAR_Y1 + 15 + 200, GetColor(255, 255, 255), FALSE);		//HPバーの枠線(白)

	DrawBox(HPBAR_X, HPBAR_Y + 200, (HPBAR_X1 + 200) / 2, HPBAR_Y1 + 15 + 200, GetColor(190, 255, 190), TRUE);		//HPバーの枠線(白)

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

	DrawBox(HPBAR_X + 180, HPBAR_Y + 200, (HPBAR_X1 + 180 + 400) / 2, HPBAR_Y1 + 15 + 200, GetColor(190, 255, 190), TRUE);		//HPバーの枠線(白)

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

	DrawBox(HPBAR_X, HPBAR_Y + 250, (HPBAR_X1 + 200) / 2, HPBAR_Y1 + 15 + 250, GetColor(190, 255, 190), TRUE);		//HPバーの枠線(白)

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

	DrawBox(HPBAR_X + 180, HPBAR_Y + 250, (HPBAR_X1 + 180 + 400) / 2, HPBAR_Y1 + 15 + 250, GetColor(190, 255, 190), TRUE);		//HPバーの枠線(白)

	if (isActive[4] == true)
	{
		DrawBox(HPGAUGE_X + 180, HPGAUGE_Y + 250, HPGAUGE_X1 + 180 + 85 * SubCastleDurability[4] / MAX_SABDURABILTY, HPGAUGE_Y1 + 15 + 250, GetColor(0, 255, 0), TRUE);		//通常用HPゲージ(緑)
	}
	else
	{
		DrawString(HPGAUGE_X + 200, HPGAUGE_Y + 250, "破壊", GetColor(0, 0, 0));						//破壊という文字を表示するため
	}
}

void UI::Get_BuffPoint()
{
	//Pアイテム
	DrawBox(PMOJI_X, PMOJI_Y, PBAR_X1, PMOJI_Y + 20, GetColor(255, 255, 255), FALSE);										//文字
	DrawFormatString(PMOJI_X + 10, PMOJI_Y + 2, GetColor(255, 255, 255), "PLv%d", pBuffLevel);

	DrawBox(PBAR_X, PBAR_Y, PBAR_X1 + 300, PBAR_Y1 + 20, GetColor(255, 255, 255), FALSE);									//枠

	DrawBox(PGAUGE_X, PGAUGE_Y, PGAUGE_X1 + 300 * pBuffPoint / MAX_BUFF, PGAUGE_Y1 + 20, GetColor(0, 255, 0), TRUE);		//ゲージ

	if (pBuffLevel == 3)
	{
		DrawString(PGAUGE_X + 130, PGAUGE_Y + 2, "MAX", GetColor(255, 255, 255));
	}

	//Sアイテム
	DrawBox(SMOJI_X, SMOJI_Y, SBAR_X1, SMOJI_Y + 20, GetColor(255, 255, 255), FALSE);										//文字
	DrawFormatString(SMOJI_X + 10, SMOJI_Y + 2, GetColor(255, 255, 255), "SLv%d", sBuffLevel);

	DrawBox(SBAR_X, SBAR_Y, SBAR_X1 + 300, SBAR_Y1 + 20, GetColor(255, 255, 255), FALSE);									//枠

	DrawBox(SGAUGE_X, SGAUGE_Y, SGAUGE_X1 + 300 * sBuffPoint / MAX_BUFF, SGAUGE_Y1 + 20, GetColor(0, 255, 0), TRUE);		//ゲージ

	if (sBuffLevel == 3)
	{
		DrawString(SGAUGE_X + 130, SGAUGE_Y + 2, "MAX", GetColor(255, 255, 255));
	}
}

void UI::AbilityUi()
{
	//DrawFormatStringToHandle(0, 140, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "Skill回数%d", skillCount);
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Skill回数%d", skillCount);
	if (skillType == SAKUYA_Ability)
	{
		if (skillActive == true)
		{
			//DrawFormatStringToHandle(100, 140, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "SkillTime");
			DrawString(0, 140, "SkillTime", GetColor(255, 255, 255));
			DrawBox(SKILLBAR_X, SKILLBAR_Y, SKILLBAR_X1 + 200, SKILLBAR_Y1 + 10, GetColor(255, 255, 255), FALSE);									//枠
			DrawBox(SKILLGAUGE_X, SKILLGAUGE_Y, SKILLGAUGE_X1 + 200 * skillClock / MAX_STOPTIME, SKILLGAUGE_Y1 + 10, GetColor(0, 255, 255), TRUE);	//ゲージ
		}
    }
}

void UI::TimeLimitUi()
{
	DrawFormatStringToHandle(0, 30, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "TIME %d", hundredsTime);
	DrawFormatStringToHandle(110, 30, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "%d", tensTime);
	DrawFormatStringToHandle(130, 30, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "%d", onesTime);
}

//更新
void UI::Update(CastleManager* _castlemanager, ItemManager* _itemmanager, BuffManager* _buffmanager, BasePlayer* _baseplayer, TimeLimit* _timelimit)
{
	//バフ関連
	pBuffPoint = _itemmanager->Get_P_Count();
	sBuffPoint = _itemmanager->Get_S_Count();
	pBuffLevel = _buffmanager->GetPowerLevel();
	sBuffLevel = _buffmanager->GetSpeedLevel();
	CastleDurability = _castlemanager->Get_Durability(0);		//拠点の体力をセットする
	 
	//拠点関連
	for (i = 1; i < 5; i++)
	{	
		SubCastleDurability[i] = _castlemanager->Get_Durability(i);	
		isActive[i] = _castlemanager->Get_IsActive(i);
	}

	//スキル関連
	skillCount = _baseplayer->Get_AbilityCount();
	skillClock = _baseplayer->Get_abilityClock();
	skillActive = _baseplayer->Get_isAbility();
	skillType = _baseplayer->Get_AbilityType();

	//タイム関連
	hundredsTime = _timelimit->Get_hundredsPlace();
	tensTime = _timelimit->Get_tensPlace();
	onesTime = _timelimit->Get_onesPlace();
}

//描画処理
void UI::Draw()
{
	//DrawBox(0, 0, 400, 300, GetColor(50, 50, 50), TRUE);
	Get_CastleDurability();
	Get_SubCastleDurability();
	Get_BuffPoint();
	AbilityUi();
	TimeLimitUi();
}
