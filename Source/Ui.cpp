#include <DxLib.h>
#include "Ui.h"

//HPバーの表示と中身の処理(MainCastle)
void UI::Get_CastleDurability()
{
	DrawBox(10, 5, 470, 200, GetColor(200, 200, 200), TRUE);		//後ろに敷く用

	DrawFormatStringToHandle(HPMOJI_X, HPMOJI_Y, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "HP");						//HPという文字を表示するため

	DrawFormatStringToHandle(HP_X, HP_Y, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(),
		"%d/%d", CastleDurability, MAX_DURABILTY);

	DrawBox(HPBAR_X - 1, HPBAR_Y - 1, HPBAR_X1 + 1, HPBAR_Y1 + 1, GetColor(0, 0, 0), FALSE);				//HPバーの枠線(白)
	DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1, HPBAR_Y1, GetColor(190, 255, 190), TRUE);							//HPバーの枠線(塗りつぶし)

	percent = MAX_DURABILTY / 3;				//ピンチ時にHPゲージを赤色にするための割合(３割)

	if (CastleDurability <= 0)					//HPゲージが0以下になってもゲージは0で止める
	{
		CastleDurability = 0;
	}

	if (CastleDurability <= percent)			//３割以下でHPゲージが赤になる	
	{
		DrawBox(HPGAUGE_X, HPGAUGE_Y, HPGAUGE_X1 + 270 * CastleDurability / MAX_DURABILTY, HPGAUGE_Y1, GetColor(255, 0, 0), TRUE);		//ピンチ用HPゲージ(赤）
	}
	else
	{
		DrawBox(HPGAUGE_X, HPGAUGE_Y, HPGAUGE_X1 + 270 * CastleDurability / MAX_DURABILTY, HPGAUGE_Y1, GetColor(0, 255, 0), TRUE);		//通常用HPゲージ(緑)
	}
}

//HPバーの表示と中身の処理(SubCastle)
void UI::Get_SubCastleDurability()
{
	DrawFormatStringToHandle(10, 85, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "設置可能サブ拠点数　：%d", castleNum);
	DrawFormatStringToHandle(12, 125, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "選択中のサブ拠点番号：%d", castleNumber);

	//座標補正
	int xa = 12, yb = 38;

	if (castleNum != 0)
	{
		DrawString(SubCastle::COORDINATE_X_ONE - 48 - 4 + xa, SubCastle::COORDINATE_Y_ONE - 80 - 4 + yb, "1", GetColor(0, 0, 0));
		DrawString(SubCastle::COORDINATE_X_TWO - 48 - 4 + xa, SubCastle::COORDINATE_Y_TWO + 32 - 4 + yb, "2", GetColor(0, 0, 0));
		DrawString(SubCastle::COORDINATE_X_THREE + 32 - 4 + xa, SubCastle::COORDINATE_Y_THREE - 48 - 4 + yb, "3", GetColor(0, 0, 0));
		DrawString(SubCastle::COORDINATE_X_FOUR - 80 - 4 + xa, SubCastle::COORDINATE_Y_FOUR - 48 - 4 + yb, "4", GetColor(0, 0, 0));
		DrawString(SubCastle::COORDINATE_X_FIVE + 48 - 4 + xa, SubCastle::COORDINATE_Y_FIVE + 32 - 4 + yb, "5", GetColor(0, 0, 0));
		DrawString(SubCastle::COORDINATE_X_SIX + 48 - 4 + xa, SubCastle::COORDINATE_Y_SIX - 80 - 4 + yb, "6", GetColor(0, 0, 0));
		DrawString(SubCastle::COORDINATE_X_SEVEN - 80 - 4 + xa, SubCastle::COORDINATE_Y_SEVEN + 48 - 4 + yb, "7", GetColor(0, 0, 0));
		DrawString(SubCastle::COORDINATE_X_EIGHT + 32 - 4 + xa, SubCastle::COORDINATE_Y_EIGHT + 48 - 4 + yb, "8", GetColor(0, 0, 0));
	}

	for (i = 1; i < 5; i++)
	{
		if (SubCastleDurability[i] <= 0)					//HPゲージが0以下になってもゲージは0で止める
		{
			SubCastleDurability[i] = 0;
		}

		//サブ拠点HP
		if (isActive[i] == true)
		{
			DrawBox(castleX[i] - 1, castleY[i] - 16, castleX[i] + 56, castleY[i] - 4, GetColor(0, 0, 0), FALSE);		//枠
			DrawBox(castleX[i], castleY[i] - 15, castleX[i] + 55, castleY[i] - 5, GetColor(190, 255, 190), TRUE);		//HPバーの枠線(塗り潰し)

			if (SubCastleDurability[i] <= REDGAUGE)			//HPゲージが赤になる	
			{
				DrawBox(castleX[i], castleY[i] - 15, castleX[i] + 55 * SubCastleDurability[i] / MAX_SABDURABILTY, castleY[i] - 5, GetColor(255, 0, 0), TRUE);		//通常用HPゲージ(緑)
			}
			else
			{
				DrawBox(castleX[i], castleY[i] - 15, castleX[i] + 55 * SubCastleDurability[i] / MAX_SABDURABILTY, castleY[i] - 5, GetColor(0, 255, 0), TRUE);		//通常用HPゲージ(緑)
			}
		}
	}
}

//バフ関連のUI
void UI::Get_BuffPoint()
{
	//Pアイテム
	DrawBox(PMOJI_X, PMOJI_Y + 5, PMOJI_X1, PMOJI_Y1, GetColor(0, 0, 0), FALSE);										//文字

	DrawFormatStringToHandle(PMOJI_X + 5, PMOJI_Y - 45, GetColor(255, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "P");

	DrawBox(PBAR_X, PBAR_Y + 1, PBAR_X1, PBAR_Y1, GetColor(0, 0, 0), FALSE);							//枠
	DrawBox(PBAR_X, PBAR_Y, PBAR_X1, PBAR_Y1, GetColor(190, 255, 190), TRUE);

	if (pBuffLevel == 3)
	{
		pBuffPoint = 15;
		DrawBox(PGAUGE_X, PGAUGE_Y, PGAUGE_X1, PGAUGE_Y1 - 250 * pBuffPoint / MAX_BUFF, GetColor(255, 0, 0), TRUE);		//ゲージ
		DrawFormatStringToHandle(1500, 900, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "Power LvMAX");
	}
	else
	{
		DrawBox(PGAUGE_X, PGAUGE_Y, PGAUGE_X1, PGAUGE_Y1 - 250 * pBuffPoint / MAX_BUFF, GetColor(255, 0, 0), TRUE);		//ゲージ
		DrawFormatStringToHandle(1500, 900, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "Power Lv%d", pBuffLevel);
	}

	//Sアイテム
	DrawBox(SMOJI_X, SMOJI_Y + 5, SMOJI_X1, SMOJI_Y1, GetColor(0, 0, 0), FALSE);										//文字

	DrawFormatStringToHandle(SMOJI_X + 5, SMOJI_Y - 45, GetColor(0, 0, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "S");

	DrawBox(SBAR_X, SBAR_Y + 1, SBAR_X1, SBAR_Y1, GetColor(0, 0, 0), FALSE);											//枠
	DrawBox(SBAR_X, SBAR_Y, SBAR_X1, SBAR_Y1, GetColor(190, 255, 190), TRUE);											//塗りつぶし

	if (sBuffLevel == 3)
	{
		sBuffPoint = 15;
		DrawBox(SGAUGE_X, SGAUGE_Y, SGAUGE_X1, SGAUGE_Y1 - 250 * sBuffPoint / MAX_BUFF, GetColor(0, 0, 255), TRUE);		//ゲージ
		DrawFormatStringToHandle(1500, 1000, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "Speed LvMAX");
	}
	else
	{
		DrawBox(SGAUGE_X, SGAUGE_Y, SGAUGE_X1, SGAUGE_Y1 - 250 * sBuffPoint / MAX_BUFF, GetColor(0, 0, 255), TRUE);		//ゲージ
		DrawFormatStringToHandle(1500, 1000, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "Speed Lv%d", sBuffLevel);
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
		DrawBox(pX, pY, pX + 50 * skillClock / MAX_SAKUYATIME, pY - 5, GetColor(0, 255, 255), TRUE);			//ゲージ
	}

	//フランさんの殲滅
	if (skillType == FRAN_Ability && skillFran == true)
	{
		DrawBox(pX, pY, pX + 50, pY - 5, GetColor(255, 255, 255), FALSE);									    //枠
		DrawBox(pX, pY, pX + 50 * skillClock / MAX_FRANTIME, pY - 5, GetColor(255, 100, 100), TRUE);			//ゲージ
	}
}

//制限時間のUI
void UI::TimeLimitUi()
{
	DrawFormatStringToHandle(10, 160, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "TIME %d%d%d", hundredsTime, tensTime, onesTime);
}

void UI::ChargeGage()
{
	DrawBox(10, 950, 380, 1050, GetColor(200, 200, 200), TRUE);		//後ろに敷く
	DrawFormatStringToHandle(15, 950, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "チャージゲージ");
	//チャージゲージの枠
	DrawBox(CHARGEGAUGE_X-1, CHARGEGAUGE_Y-1,CHARGEGAUGE_X2+1, CHARGEGAUGE_Y2+1, GetColor(0, 0, 0), FALSE);	

	//チャージゲージ
	DrawBox(CHARGEGAUGE_X, CHARGEGAUGE_Y,
		CHARGEGAUGE_X + 325 * ((float)chageGauge / maxGauge),
		CHARGEGAUGE_Y2, GetColor(0, 255, 255), TRUE);
}

//更新
void UI::Update(GameResource* _gameRes)
{
	//バフ関連
	pBuffPoint = _gameRes->itemManager->Get_P_Count();
	sBuffPoint = _gameRes->itemManager->Get_S_Count();
	pBuffLevel = _gameRes->buffManager->GetPowerLevel();
	sBuffLevel = _gameRes->buffManager->GetSpeedLevel();

	//拠点関連
	CastleDurability = _gameRes->castleManager->Get_Durability(0);		//拠点の体力をセットする
	castleNum = _gameRes->castleManager->Get_installCastle();
	castleNumber = _gameRes->castleManager->Get_installNum();

	for (i = 1; i < 5; i++)
	{
		SubCastleDurability[i] = _gameRes->castleManager->Get_Durability(i);
		isActive[i] = _gameRes->castleManager->Get_IsActive(i);
		castleX[i] = _gameRes->castleManager->Get_DrawPosX(i);		
		castleY[i] = _gameRes->castleManager->Get_DrawPosY(i);			
	}
	//チャージゲージ関連
	maxGauge = _gameRes->player->Get_maxChage();
	chageGauge = _gameRes->player->Get_chageGauge();
	
	//スキル関連
	skillCount = _gameRes->player->Get_AbilityCount();
	skillClock = _gameRes->player->Get_AbilityClock();
	skillActive = _gameRes->player->Get_isAbility();
	skillType = _gameRes->player->Get_AbilityType();
	skillFran = _gameRes->player->Get_FranAbility();

	pX = _gameRes->player->Get_x();
	pY = _gameRes->player->Get_y();

	//タイム関連
	hundredsTime = _gameRes->timeLimit->Get_hundredsPlace();
	tensTime = _gameRes->timeLimit->Get_tensPlace();
	onesTime = _gameRes->timeLimit->Get_onesPlace();
}

//描画処理
void UI::Draw(GameResource* _gameRes)
{
	DrawBox(1450, 730, 1920, 1080, GetColor(200, 200, 200), TRUE);
	Get_CastleDurability();
	Get_SubCastleDurability();
	Get_BuffPoint();
	AbilityUi();
	ChargeGage();
	TimeLimitUi();
}


