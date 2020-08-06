#include <DxLib.h>
#include "Ui.h"
#include "Castle.h"

//��قǋ��_�̗̑͊֘A���󂯎��@���R�����g�ς���
void UI::Set_CastleDurability(int CastleDurability, int MAX_DURABILITY)
{
	MAX_DURABILITY = 10;
	CastleDurability = 3;
	DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200, HPBAR_Y1 + 20, Color = GetColor(255, 255, 255), FALSE);		//HP�o�[�̘g��

	percent = MAX_DURABILITY / 3;
	 
	if (CastleDurability <= percent)
	{
		DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200 * CastleDurability / MAX_DURABILITY, HPBAR_Y1 + 20, Color = GetColor(255, 0, 0), TRUE);		//�s���`�pHP�Q�[�W(�ԁj
	}
	else
	{
		DrawBox(HPBAR_X, HPBAR_Y, HPBAR_X1 + 200 * CastleDurability / MAX_DURABILITY, HPBAR_Y1 + 20, Color = GetColor(0, 255, 0), TRUE);		//�ʏ�pHP�Q�[�W(��)
	}
	//DrawFormatString(10, 500, GetColor(255, 255, 255), "%f", percent);		//�m�F�p�@����ŏ���
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
