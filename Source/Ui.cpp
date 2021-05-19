#include <DxLib.h>
#include "Ui.h"

//HP�o�[�̕\���ƒ��g�̏���(MainCastle)
void UI::Get_CastleDurability()
{
	DrawBox(10, 5, 470, 200, GetColor(200, 200, 200), TRUE);		//���ɕ~���p

	DrawFormatStringToHandle(HPMOJI_X, HPMOJI_Y, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "HP");						//HP�Ƃ���������\�����邽��

	DrawFormatStringToHandle(HP_X, HP_Y, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(),
		"%d/%d", CastleDurability, MAX_DURABILTY);

	DrawBox(HPBAR_X - 1, HPBAR_Y - 1, HPBAR_X1 + 1, HPBAR_Y1 + 1, GetColor(0, 0, 0), FALSE);				//HP�o�[�̘g��(��)
	DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1, HPBAR_Y1, GetColor(190, 255, 190), TRUE);							//HP�o�[�̘g��(�h��Ԃ�)

	percent = MAX_DURABILTY / 3;				//�s���`����HP�Q�[�W��ԐF�ɂ��邽�߂̊���(�R��)

	if (CastleDurability <= 0)					//HP�Q�[�W��0�ȉ��ɂȂ��Ă��Q�[�W��0�Ŏ~�߂�
	{
		CastleDurability = 0;
	}

	if (CastleDurability <= percent)			//�R���ȉ���HP�Q�[�W���ԂɂȂ�	
	{
		DrawBox(HPGAUGE_X, HPGAUGE_Y, HPGAUGE_X1 + 270 * CastleDurability / MAX_DURABILTY, HPGAUGE_Y1, GetColor(255, 0, 0), TRUE);		//�s���`�pHP�Q�[�W(�ԁj
	}
	else
	{
		DrawBox(HPGAUGE_X, HPGAUGE_Y, HPGAUGE_X1 + 270 * CastleDurability / MAX_DURABILTY, HPGAUGE_Y1, GetColor(0, 255, 0), TRUE);		//�ʏ�pHP�Q�[�W(��)
	}
}

//HP�o�[�̕\���ƒ��g�̏���(SubCastle)
void UI::Get_SubCastleDurability()
{
	DrawFormatStringToHandle(10, 85, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "�ݒu�\�T�u���_���@�F%d", castleNum);
	DrawFormatStringToHandle(12, 125, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "�I�𒆂̃T�u���_�ԍ��F%d", castleNumber);

	//���W�␳
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
		if (SubCastleDurability[i] <= 0)					//HP�Q�[�W��0�ȉ��ɂȂ��Ă��Q�[�W��0�Ŏ~�߂�
		{
			SubCastleDurability[i] = 0;
		}

		//�T�u���_HP
		if (isActive[i] == true)
		{
			DrawBox(castleX[i] - 1, castleY[i] - 16, castleX[i] + 56, castleY[i] - 4, GetColor(0, 0, 0), FALSE);		//�g
			DrawBox(castleX[i], castleY[i] - 15, castleX[i] + 55, castleY[i] - 5, GetColor(190, 255, 190), TRUE);		//HP�o�[�̘g��(�h��ׂ�)

			if (SubCastleDurability[i] <= REDGAUGE)			//HP�Q�[�W���ԂɂȂ�	
			{
				DrawBox(castleX[i], castleY[i] - 15, castleX[i] + 55 * SubCastleDurability[i] / MAX_SABDURABILTY, castleY[i] - 5, GetColor(255, 0, 0), TRUE);		//�ʏ�pHP�Q�[�W(��)
			}
			else
			{
				DrawBox(castleX[i], castleY[i] - 15, castleX[i] + 55 * SubCastleDurability[i] / MAX_SABDURABILTY, castleY[i] - 5, GetColor(0, 255, 0), TRUE);		//�ʏ�pHP�Q�[�W(��)
			}
		}
	}
}

//�o�t�֘A��UI
void UI::Get_BuffPoint()
{
	//P�A�C�e��
	DrawBox(PMOJI_X, PMOJI_Y + 5, PMOJI_X1, PMOJI_Y1, GetColor(0, 0, 0), FALSE);										//����

	DrawFormatStringToHandle(PMOJI_X + 5, PMOJI_Y - 45, GetColor(255, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "P");

	DrawBox(PBAR_X, PBAR_Y + 1, PBAR_X1, PBAR_Y1, GetColor(0, 0, 0), FALSE);							//�g
	DrawBox(PBAR_X, PBAR_Y, PBAR_X1, PBAR_Y1, GetColor(190, 255, 190), TRUE);

	if (pBuffLevel == 3)
	{
		pBuffPoint = 15;
		DrawBox(PGAUGE_X, PGAUGE_Y, PGAUGE_X1, PGAUGE_Y1 - 250 * pBuffPoint / MAX_BUFF, GetColor(255, 0, 0), TRUE);		//�Q�[�W
		DrawFormatStringToHandle(1500, 900, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "Power LvMAX");
	}
	else
	{
		DrawBox(PGAUGE_X, PGAUGE_Y, PGAUGE_X1, PGAUGE_Y1 - 250 * pBuffPoint / MAX_BUFF, GetColor(255, 0, 0), TRUE);		//�Q�[�W
		DrawFormatStringToHandle(1500, 900, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "Power Lv%d", pBuffLevel);
	}

	//S�A�C�e��
	DrawBox(SMOJI_X, SMOJI_Y + 5, SMOJI_X1, SMOJI_Y1, GetColor(0, 0, 0), FALSE);										//����

	DrawFormatStringToHandle(SMOJI_X + 5, SMOJI_Y - 45, GetColor(0, 0, 255), FontHandle::Instance()->Get_natumemozi_38_8(), "S");

	DrawBox(SBAR_X, SBAR_Y + 1, SBAR_X1, SBAR_Y1, GetColor(0, 0, 0), FALSE);											//�g
	DrawBox(SBAR_X, SBAR_Y, SBAR_X1, SBAR_Y1, GetColor(190, 255, 190), TRUE);											//�h��Ԃ�

	if (sBuffLevel == 3)
	{
		sBuffPoint = 15;
		DrawBox(SGAUGE_X, SGAUGE_Y, SGAUGE_X1, SGAUGE_Y1 - 250 * sBuffPoint / MAX_BUFF, GetColor(0, 0, 255), TRUE);		//�Q�[�W
		DrawFormatStringToHandle(1500, 1000, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "Speed LvMAX");
	}
	else
	{
		DrawBox(SGAUGE_X, SGAUGE_Y, SGAUGE_X1, SGAUGE_Y1 - 250 * sBuffPoint / MAX_BUFF, GetColor(0, 0, 255), TRUE);		//�Q�[�W
		DrawFormatStringToHandle(1500, 1000, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "Speed Lv%d", sBuffLevel);
	}
}

//�X�L���֘A��UI 
void UI::AbilityUi()
{
	DrawFormatStringToHandle(1500, 800, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "Skill��%d", skillCount);

	//��邳��̎��~��
	if (skillType == SAKUYA_Ability && skillActive == true)
	{
		DrawBox(pX - 1, pY + 1, pX + 51, pY - 6, GetColor(255, 255, 255), FALSE);									    //�g
		DrawBox(pX, pY, pX + 50 * skillClock / MAX_SAKUYATIME, pY - 5, GetColor(0, 255, 255), TRUE);			//�Q�[�W
	}

	//�t��������̟r��
	if (skillType == FRAN_Ability && skillFran == true)
	{
		DrawBox(pX, pY, pX + 50, pY - 5, GetColor(255, 255, 255), FALSE);									    //�g
		DrawBox(pX, pY, pX + 50 * skillClock / MAX_FRANTIME, pY - 5, GetColor(255, 100, 100), TRUE);			//�Q�[�W
	}
}

//�������Ԃ�UI
void UI::TimeLimitUi()
{
	DrawFormatStringToHandle(10, 160, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "TIME %d%d%d", hundredsTime, tensTime, onesTime);
}

void UI::ChargeGage()
{
	DrawBox(10, 950, 380, 1050, GetColor(200, 200, 200), TRUE);		//���ɕ~��
	DrawFormatStringToHandle(15, 950, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8(), "�`���[�W�Q�[�W");
	//�`���[�W�Q�[�W�̘g
	DrawBox(CHARGEGAUGE_X-1, CHARGEGAUGE_Y-1,CHARGEGAUGE_X2+1, CHARGEGAUGE_Y2+1, GetColor(0, 0, 0), FALSE);	

	//�`���[�W�Q�[�W
	DrawBox(CHARGEGAUGE_X, CHARGEGAUGE_Y,
		CHARGEGAUGE_X + 325 * ((float)chageGauge / maxGauge),
		CHARGEGAUGE_Y2, GetColor(0, 255, 255), TRUE);
}

//�X�V
void UI::Update(GameResource* _gameRes)
{
	//�o�t�֘A
	pBuffPoint = _gameRes->itemManager->Get_P_Count();
	sBuffPoint = _gameRes->itemManager->Get_S_Count();
	pBuffLevel = _gameRes->buffManager->GetPowerLevel();
	sBuffLevel = _gameRes->buffManager->GetSpeedLevel();

	//���_�֘A
	CastleDurability = _gameRes->castleManager->Get_Durability(0);		//���_�̗̑͂��Z�b�g����
	castleNum = _gameRes->castleManager->Get_installCastle();
	castleNumber = _gameRes->castleManager->Get_installNum();

	for (i = 1; i < 5; i++)
	{
		SubCastleDurability[i] = _gameRes->castleManager->Get_Durability(i);
		isActive[i] = _gameRes->castleManager->Get_IsActive(i);
		castleX[i] = _gameRes->castleManager->Get_DrawPosX(i);		
		castleY[i] = _gameRes->castleManager->Get_DrawPosY(i);			
	}
	//�`���[�W�Q�[�W�֘A
	maxGauge = _gameRes->player->Get_maxChage();
	chageGauge = _gameRes->player->Get_chageGauge();
	
	//�X�L���֘A
	skillCount = _gameRes->player->Get_AbilityCount();
	skillClock = _gameRes->player->Get_AbilityClock();
	skillActive = _gameRes->player->Get_isAbility();
	skillType = _gameRes->player->Get_AbilityType();
	skillFran = _gameRes->player->Get_FranAbility();

	pX = _gameRes->player->Get_x();
	pY = _gameRes->player->Get_y();

	//�^�C���֘A
	hundredsTime = _gameRes->timeLimit->Get_hundredsPlace();
	tensTime = _gameRes->timeLimit->Get_tensPlace();
	onesTime = _gameRes->timeLimit->Get_onesPlace();
}

//�`�揈��
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


