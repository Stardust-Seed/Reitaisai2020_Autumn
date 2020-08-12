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

	//DrawFormatString(150,500, GetColor(255, 255, 255), "%d", percent);//�m�F�p�@����ŏ���
	//DrawFormatString(150, 600, GetColor(255, 255, 255), "%d", MAX_DURABILTY);//�m�F�p�@����ŏ���
	DrawFormatString(150,700, GetColor(255, 255, 255), "HP%d", CastleDurability);//�m�F�p�@����ŏ���*/
}

//�G�̐��Ƃ����������֘A�̏����������@���R�����g�ς���
void UI::Set_EnemyiesRest(int) 
{

}

//�������
void UI::PlayGuide()
{
	//�ǉ������邩������Ȃ����ǎv�����̂͂��̓��  ���R�����g����
	DrawString(500, 0, "�\���L�[�ŏ㉺���E�Ɉړ�", GetColor(255, 255, 255));
	DrawString(500, 100, "�X�y�[�X�L�[�Ń|�[�Y���j���[�\��", GetColor(255, 255, 255));
	DrawString(500, 200, "�Z�Z�L�[�Œe����", GetColor(255, 255, 255));
}

//�X�V
void UI::Update(Castle* _castle)
{
	CastleDurability = _castle->Get_durability();		//���_�̗̑͂��Z�b�g����
}

//�`�揈��
void UI::Draw()
{
	Get_CastleDurability();
	PlayGuide();
}
