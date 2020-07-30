#include<DxLib.h>
#include "Pausemenu.h"
#include "Input.h"

void Pausemenu::Update()
{
	Input::Instance()->UpdateKey();
	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1)					//���L�[��������Ă�����
	{
	    NowSelect = (NowSelect + 1) % ePausetype_Num;							//�I����Ԃ�������
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1)					//��L�[��������Ă�����
	{
		NowSelect = (NowSelect + (ePausetype_Num - 1)) % ePausetype_Num;		//�I����Ԃ��グ��
	}
	if (Input::Instance()->GetPressCount(KEY_INPUT_RETURN) == 1)				//Enter�L�[�������ꂽ�ꏊ�̏���
	{
		switch (NowSelect)
		{
		case ePausetype_Game:
			DrawString(100, 0, "�Q�[�����", GetColor(255, 255, 255));
			break;

		case ePausetype_Menu:
			DrawString(100, 0, "���j���[���", GetColor(255, 255, 255));
			break;
		}
	}
}

//�`��
void Pausemenu::Draw()
{
	DrawString(500, PGAME_Y, "�Q�[����ʂɖ߂�", GetColor(255, 255, 255));
	DrawString(500, PEND_Y, "�Q�[���I��", GetColor(255, 255, 255));

	switch (NowSelect) {									//���݂̑I����Ԃɏ]���ď����𕪊�
	case ePausetype_Game:									//�Q�[����ʂɖ߂��I�𒆂Ȃ�
		y = PGAME_Y;										//�Q�[����ʂɖ߂�̍��W���i�[
		break;

	case ePausetype_Menu:									//�Q�[�����I����I�𒆂Ȃ�
		y = PEND_Y;											//�Q�[���I���̍��W���i�[
		break;
	}
	DrawString(450, y, "��", GetColor(255, 255, 255));		//�I���J�[�\��
}
