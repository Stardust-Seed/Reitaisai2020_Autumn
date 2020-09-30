#include <DxLib.h>
#include "Ui.h"

//HP�o�[�̕\���ƒ��g�̏���(MainCastle)
void UI::Get_CastleDurability()
{
	DrawBox(HPMOJI_X + 10, HPMOJI_Y, HPMOJI_X + HPBAR_X, HPMOJI_Y + 20, GetColor(255, 255, 255), FALSE);		//HP�Ƃ���������\�����邽�߂̘g

	DrawString(HPMOJI_X + 20, HPMOJI_Y + 2, "HP", GetColor(255, 255, 255));						//HP�Ƃ���������\�����邽��

	DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200, HPBAR_Y1 + 20, GetColor(255, 255, 255), FALSE);		//HP�o�[�̘g��(��)

	percent = MAX_DURABILTY / 3;				//�s���`����HP�Q�[�W��ԐF�ɂ��邽�߂̊���(�R��)�@���v����

	if (CastleDurability <= 0)					//HP�Q�[�W��0�ȉ��ɂȂ��Ă��Q�[�W��0�Ŏ~�߂�
	{
		CastleDurability = 0;
	}

	if (CastleDurability <= percent)			//�R���ȉ���HP�Q�[�W���ԂɂȂ�	
	{
		//SE::Instance()->PlaySE(SE_warning);
		DrawBox(HPGAUGE_X, HPGAUGE_Y, HPGAUGE_X1 + 200 * CastleDurability / MAX_DURABILTY, HPGAUGE_Y1 + 20, GetColor(255, 0, 0), TRUE);		//�s���`�pHP�Q�[�W(�ԁj
	}
	else
	{
		DrawBox(HPGAUGE_X, HPGAUGE_Y, HPGAUGE_X1 + 200 * CastleDurability / MAX_DURABILTY, HPGAUGE_Y1 + 20, GetColor(0, 255, 0), TRUE);		//�ʏ�pHP�Q�[�W(��)
	}
}

//HP�o�[�̕\���ƒ��g�̏���(SubCastle)
void UI::Get_SubCastleDurability()
{
	for (i = 1; i < 5; i++)
	{
		if (SubCastleDurability[i] <= 0)					//HP�Q�[�W��0�ȉ��ɂȂ��Ă��Q�[�W��0�Ŏ~�߂�
		{
			SubCastleDurability[i] = 0;
		}
	}

	//�T�u���_1(���j
	if (isActive[1] == true)
	{
		DrawBox(HPMOJI_X + 10, HPMOJI_Y + 200, HPMOJI_X + HPBAR_X, HPMOJI_Y + 15 + 200, GetColor(255, 255, 255), FALSE);		//HP�Ƃ���������\�����邽�߂̘g

		DrawString(HPMOJI_X + 20, HPMOJI_Y + 200, "HP1", GetColor(255, 255, 255));						//HP�Ƃ���������\�����邽��

		DrawBox(HPBAR_X, HPBAR_Y + 200, (HPBAR_X1 + 200) / 2, HPBAR_Y1 + 15 + 200, GetColor(255, 255, 255), FALSE);		//HP�o�[�̘g��(��)

		DrawBox(HPGAUGE_X, HPGAUGE_Y + 200, HPGAUGE_X1 + 75 * SubCastleDurability[1] / MAX_SABDURABILTY, HPGAUGE_Y1 + 15 + 200, GetColor(0, 255, 0), TRUE);		//�ʏ�pHP�Q�[�W(��)
	}

	//�T�u���_2(�E)
	if (isActive[2] == true)
	{
		DrawBox(HPMOJI_X + 10, HPMOJI_Y + 250, HPMOJI_X + HPBAR_X, HPMOJI_Y + 15 + 250, GetColor(255, 255, 255), FALSE);		//HP�Ƃ���������\�����邽�߂̘g

		DrawString(HPMOJI_X + 20, HPMOJI_Y + 250, "HP2", GetColor(255, 255, 255));						//HP�Ƃ���������\�����邽��

		DrawBox(HPBAR_X, HPBAR_Y + 250, (HPBAR_X1 + 200) / 2, HPBAR_Y1 + 15 + 250, GetColor(255, 255, 255), FALSE);		//HP�o�[�̘g��(��)

		DrawBox(HPGAUGE_X, HPGAUGE_Y + 250, HPGAUGE_X1 + 75 * SubCastleDurability[2] / MAX_SABDURABILTY, HPGAUGE_Y1 + 15 + 250, GetColor(0, 255, 0), TRUE);		//�ʏ�pHP�Q�[�W(��)
	}

	//�T�u���_3(��)
	if (isActive[3] == true)
	{
		DrawBox(HPMOJI_X + 10, HPMOJI_Y + 300, HPMOJI_X + HPBAR_X, HPMOJI_Y + 15 + 300, GetColor(255, 255, 255), FALSE);		//HP�Ƃ���������\�����邽�߂̘g

		DrawString(HPMOJI_X + 20, HPMOJI_Y + 300, "HP3", GetColor(255, 255, 255));						//HP�Ƃ���������\�����邽��

		DrawBox(HPBAR_X, HPBAR_Y + 300, (HPBAR_X1 + 200) / 2, HPBAR_Y1 + 15 + 300, GetColor(255, 255, 255), FALSE);		//HP�o�[�̘g��(��)

		DrawBox(HPGAUGE_X, HPGAUGE_Y + 300, HPGAUGE_X1 + 75 * SubCastleDurability[3] / MAX_SABDURABILTY, HPGAUGE_Y1 + 15 + 300, GetColor(0, 255, 0), TRUE);		//�ʏ�pHP�Q�[�W(��)
	}

	//�T�u���_4(��)
	if (isActive[4] == true)
	{
		DrawBox(HPMOJI_X + 10, HPMOJI_Y + 350, HPMOJI_X + HPBAR_X, HPMOJI_Y + 15 + 350, GetColor(255, 255, 255), FALSE);		//HP�Ƃ���������\�����邽�߂̘g

		DrawString(HPMOJI_X + 20, HPMOJI_Y + 350, "HP4", GetColor(255, 255, 255));						//HP�Ƃ���������\�����邽��

		DrawBox(HPBAR_X, HPBAR_Y + 350, (HPBAR_X1 + 200) / 2, HPBAR_Y1 + 15 + 350, GetColor(255, 255, 255), FALSE);		//HP�o�[�̘g��(��)

		DrawBox(HPGAUGE_X, HPGAUGE_Y + 350, HPGAUGE_X1 + 75 * SubCastleDurability[4] / MAX_SABDURABILTY, HPGAUGE_Y1 + 15 + 350, GetColor(0, 255, 0), TRUE);		//�ʏ�pHP�Q�[�W(��)
	}
}

void UI::Get_BuffPoint()
{
	//P�A�C�e��
	DrawBox(PMOJI_X, PMOJI_Y, PBAR_X1, PMOJI_Y + 20, GetColor(255, 255, 255), FALSE);										//����
	DrawFormatString(PMOJI_X + 10, PMOJI_Y + 2, GetColor(255, 255, 255), "PLv%d", pBuffLevel);

	DrawBox(PBAR_X, PBAR_Y, PBAR_X1 + 300, PBAR_Y1 + 20, GetColor(255, 255, 255), FALSE);									//�g

	DrawBox(PGAUGE_X, PGAUGE_Y, PGAUGE_X1 + 300 * pBuffPoint / MAX_BUFF, PGAUGE_Y1 + 20, GetColor(0, 255, 0), TRUE);		//�Q�[�W

	if (pBuffLevel == 3)
	{
		DrawString(PGAUGE_X + 130, PGAUGE_Y + 2, "MAX", GetColor(255, 255, 255));
	}

	//S�A�C�e��
	DrawBox(SMOJI_X, SMOJI_Y, SBAR_X1, SMOJI_Y + 20, GetColor(255, 255, 255), FALSE);										//����
	DrawFormatString(SMOJI_X + 10, SMOJI_Y + 2, GetColor(255, 255, 255), "SLv%d", sBuffLevel);

	DrawBox(SBAR_X, SBAR_Y, SBAR_X1 + 300, SBAR_Y1 + 20, GetColor(255, 255, 255), FALSE);									//�g

	DrawBox(SGAUGE_X, SGAUGE_Y, SGAUGE_X1 + 300 * sBuffPoint / MAX_BUFF, SGAUGE_Y1 + 20, GetColor(0, 255, 0), TRUE);		//�Q�[�W

	if (sBuffLevel == 3)
	{
		DrawString(SGAUGE_X + 130, SGAUGE_Y + 2, "MAX", GetColor(255, 255, 255));
	}
}

void UI::AbilityUi()
{
	DrawFormatString(0, 100, GetColor(255, 255, 255), "Skill��%d", skillcount);

	if (skilltype == SAKUYA_Ability)
	{
		if (skillactive == true)
		{
			DrawString(0, 150, "SkillTime", GetColor(255, 255, 255));
			DrawBox(SKILLBAR_X, SKILLBAR_Y, SKILLBAR_X1 + 200, SKILLBAR_Y1 + 10, GetColor(255, 255, 255), FALSE);									//�g
			DrawBox(SKILLGAUGE_X, SKILLGAUGE_Y, SKILLGAUGE_X1 + 200 * skillclock / MAX_STOPTIME, SKILLGAUGE_Y1 + 10, GetColor(0, 255, 255), TRUE);	//�Q�[�W
		}
    }
}

//�X�V
void UI::Update(CastleManager* _castlemanager, ItemManager* _itemmanager, BuffManager* _buffmanager, BasePlayer* _baseplayer)
{
	pBuffPoint = _itemmanager->Get_P_Count();
	sBuffPoint = _itemmanager->Get_S_Count();
	pBuffLevel = _buffmanager->GetPowerLevel();
	sBuffLevel = _buffmanager->GetSpeedLevel();
	CastleDurability = _castlemanager->Get_Durability(0);		//���_�̗̑͂��Z�b�g����

	for (i = 1; i < 5; i++)
	{	
		SubCastleDurability[i] = _castlemanager->Get_Durability(i);	
		isActive[i] = _castlemanager->Get_IsActive(i);
	}

	skillcount = _baseplayer->Get_AbilityCount();
	skillclock = _baseplayer->Get_abilityClock();
	skillactive = _baseplayer->Get_isAbility();
	skilltype = _baseplayer->Get_AbilityType();
}

//�`�揈��
void UI::Draw()
{
	Get_CastleDurability();
	Get_SubCastleDurability();
	Get_BuffPoint();
	AbilityUi();
}
