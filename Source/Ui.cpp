#include <DxLib.h>
#include "Ui.h"

//HP�o�[�̕\���ƒ��g�̏���
void UI::Get_CastleDurability()
{
	DrawBox(HPMOJI_X + 10, HPMOJI_Y, HPMOJI_X + HPBAR_X, HPMOJI_Y + 20, GetColor(255, 255, 255), FALSE);		//HP�Ƃ���������\�����邽�߂̘g

	DrawString(HPMOJI_X	+ 20, HPMOJI_Y + 2, "HP", GetColor(255, 255, 255));						//HP�Ƃ���������\�����邽��

	DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200, HPBAR_Y1 + 20, GetColor(255, 255, 255), FALSE);		//HP�o�[�̘g��(��)

	percent = MAX_DURABILTY / 3;				//�s���`����HP�Q�[�W��ԐF�ɂ��邽�߂̊���(�R��)�@���v����

	if (CastleDurability <= 0)					//HP�Q�[�W��0�ȉ��ɂȂ��Ă��Q�[�W��0�Ŏ~�߂�
	{
		CastleDurability = 0;
	}

	if (CastleDurability <= percent)			//�R���ȉ���HP�Q�[�W���ԂɂȂ�	
	{
		DrawBox(HPGAUGE_X, HPGAUGE_Y, HPGAUGE_X1 + 200 * CastleDurability / MAX_DURABILTY, HPGAUGE_Y1 + 20, GetColor(255, 0, 0), TRUE);		//�s���`�pHP�Q�[�W(�ԁj
	}
	else
	{
		DrawBox(HPGAUGE_X, HPGAUGE_Y, HPGAUGE_X1 + 200 * CastleDurability / MAX_DURABILTY, HPGAUGE_Y1 + 20, GetColor(0, 255, 0), TRUE);		//�ʏ�pHP�Q�[�W(��)
	}
}

void UI::Get_BuffPoint() 
{
	//P�A�C�e��
	DrawBox(PMOJI_X, PMOJI_Y, PBAR_X1, PMOJI_Y + 20, GetColor(255, 255, 255), FALSE);										//����
	DrawFormatString(PMOJI_X + 10, PMOJI_Y + 2, GetColor(255, 255, 255), "PLv%d", pBuffLevel);

	DrawBox(PBAR_X, PBAR_Y, PBAR_X1 + 200, PBAR_Y1 + 20, GetColor(255, 255, 255), FALSE);									//�g
	
	DrawBox(PGAUGE_X, PGAUGE_Y, PGAUGE_X1 + 200 * pBuffPoint / MAX_BUFF, PGAUGE_Y1 + 20, GetColor(0, 255, 0), TRUE);	//�Q�[�W
	
	//S�A�C�e��
	DrawBox(SMOJI_X, SMOJI_Y, SBAR_X1, SMOJI_Y + 20, GetColor(255, 255, 255), FALSE);										//����
	DrawFormatString(SMOJI_X + 10, SMOJI_Y + 2, GetColor(255, 255, 255), "SLv%d", sBuffLevel);

	DrawBox(SBAR_X, SBAR_Y, SBAR_X1 + 200, SBAR_Y1 + 20, GetColor(255, 255, 255), FALSE);									//�g

	DrawBox(SGAUGE_X, SGAUGE_Y, SGAUGE_X1 + 200 * sBuffPoint / MAX_BUFF, SGAUGE_Y1 + 20, GetColor(0, 255, 0), TRUE);	//�Q�[�W

}

//�������
void UI::PlayGuide()
{
	DrawString(700, 10, "�\���L�[�ŏ㉺���E�Ɉړ�", GetColor(255, 255, 255));
	DrawString(700, 60, "�Z�Z�Ń|�[�Y���j���[�\��", GetColor(255, 255, 255));
	DrawString(700, 110, "Z�L�[�Œe����", GetColor(255, 255, 255));
}

//�X�V
void UI::Update(CastleManager* _castlemanager, ItemManager* _itemmanager, BuffManager* _buffmanager)
{
	pBuffPoint = _itemmanager->Get_P_Count();
	sBuffPoint = _itemmanager->Get_S_Count();
	pBuffLevel = _buffmanager->GetPowerLevel();
	sBuffLevel = _buffmanager->GetSpeedLevel();
	CastleDurability = _castlemanager->Get_Durability(0);		//���_�̗̑͂��Z�b�g����
}

//�`�揈��
void UI::Draw()
{
	Get_CastleDurability();
	Get_BuffPoint();
	PlayGuide();
}
