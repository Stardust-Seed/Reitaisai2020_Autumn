#include <DxLib.h>
#include "Input.h"
#include "Menu.h"

//�I������Ă���
void Menu::SelectMenu()
{
	NowSelect = eMenutype_Num;		//���ݑI������Ă��鍀��
}

//�X�V
void Menu::Update()
{
	Input::Instance()->UpdateKey();

	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1)			//���L�[��������Ă�����
	{
		NowSelect = (NowSelect + 1) % eMenutype_Num;					//�I����Ԃ�������
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1)			//��L�[��������Ă�����
	{
		NowSelect = (NowSelect+(eMenutype_Num-1))% eMenutype_Num;		//�I����Ԃ��グ��
	}
	
	if (Input::Instance()->GetPressCount(KEY_INPUT_RETURN) == 1)		//Enter�L�[�������ꂽ�ꏊ�̏���
	{
		switch (NowSelect)
		{
		case eMenutype_Game:
			DrawString(100, 0, "�Q�[�����", GetColor(255, 255, 255));
			break;

		case eMenutype_Option:
			DrawString(100, 0, "�I�v�V����", GetColor(255, 255, 255));
			break;

		case eMenutype_Title:
			DrawString(100, 0, "�^�C�g��", GetColor(255, 255, 255));
		}
	}
}

//�`��
void Menu::Draw()
{
	DrawString(500, GAME_Y, "�Q�[�����", GetColor(255, 255, 255));
	DrawString(500, OPTOIN_Y, "�I�v�V����", GetColor(255, 255, 255));
	DrawString(500, END_Y, "�Q�[���I��", GetColor(255, 255, 255));
	
	switch (NowSelect) {									//���݂̑I����Ԃɏ]���ď����𕪊�
	case eMenutype_Game:									//�Q�[���I�𒆂Ȃ�
		y = GAME_Y;											//�Q�[���̍��W���i�[
		break;

	case eMenutype_Option:									//�ݒ�I�𒆂Ȃ�
		y = OPTOIN_Y;										//�ݒ�̍��W���i�[
		break;

	case eMenutype_Title:
		y = END_Y;
		break;
	}
	DrawString(450, y, "��", GetColor(255, 255, 255));		//�I���J�[�\��
}