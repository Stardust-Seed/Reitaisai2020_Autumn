#include <DxLib.h>
#include "Ui.h"

//HP�o�[�̕\���ƒ��g�̏���
void UI::Set_CastleDurability()
{
	CastleDurability = Get_durability();		//���_�̗̑͂��󂯎��

	DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200, HPBAR_Y1 + 20, Color = GetColor(255, 255, 255), FALSE);		//HP�o�[�̘g��(��)

	percent = MAX_DURABILTY / 3;				//�s���`����HP�Q�[�W��ԐF�ɂ��邽�߂̊���(�R��)�@���v����
	 
	if (CastleDurability <= percent)			//�R���ȉ���HP�Q�[�W���ԂɂȂ�	
	{
		DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200 * CastleDurability / MAX_DURABILTY, HPBAR_Y1 + 20, Color = GetColor(255, 0, 0), TRUE);		//�s���`�pHP�Q�[�W(�ԁj
	}
	else
	{
		DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200 * CastleDurability / MAX_DURABILTY, HPBAR_Y1 + 20, Color = GetColor(0, 255, 0), TRUE);		//�ʏ�pHP�Q�[�W(��)
	}

	/*DrawFormatString(150,500, GetColor(255, 255, 255), "%d", percent);//�m�F�p�@����ŏ���
	DrawFormatString(150, 600, GetColor(255, 255, 255), "%d", MAX_DURABILTY);//�m�F�p�@����ŏ���
	DrawFormatString(150,700, GetColor(255, 255, 255), "%d", CastleDurability);//�m�F�p�@����ŏ���*/
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
}

//�X�V
void UI::Update(Castle* _castle)
{
	Set_durability(_castle->Get_durability());		//���݂̋��_�̗̑�
}

//�`�揈��
void UI::Draw()
{
	Set_CastleDurability();
	PlayGuide();
}
