#include <DxLib.h>
#include "Pausemenu.h"
#include "Input.h"

Pausemenu::Pausemenu(ISceneChanger* _sceneChanger) :BaseScene(_sceneChanger) {

}

//�摜�Ƃ��w�i�H(������)
/*void Pausemenu::Pause()
{
	
}*/

//�|�[�Y��ʂ̏���
void Pausemenu::PauseAll()
{
	if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE))			//�X�y�[�X�L�[�������ꂽ��
	{
		if (!pauseState)											//�|�[�Y��Ԃł͂Ȃ��Ƃ�
		{
			pauseFlg = true;										//�|�[�Y��Ԃɂ���t���O
		}
		pauseState = true;											//�|�[�Y��ԂɂȂ��Ă���
	}
	else															//�X�y�[�X�L�[��������ĂȂ��Ƃ�
	{
		pauseState = false;											//�|�[�Y��Ԃł͂Ȃ�
	}

	if (pauseFlg == true) 
	{
		if (ePausetype_Game)										// Pause��Ԓ��ɃQ�[����ʂɖ߂邪�����ꂽ�Ƃ�
		{
			if (!pauseReset)										//�|�[�Y��Ԃ����Z�b�g����ĂȂ��Ȃ�
			{
				pauseFlg = false;									//�|�[�Y��Ԃ�����
			}
			pauseReset = true;										//�|�[�Y������Ԃւ̈ڍs����
		}
		else 
		{
			pauseReset = false;										// �Q�[����ʂɖ߂邪������ĂȂ����Pause�����ɂȂ��Ă��Ȃ�

			DrawString(300, 0, "�|�[�Y���", GetColor(255, 255, 255));				//�m�F
			DrawString(500, PGAME_Y, "�Q�[����ʂɖ߂�", GetColor(255, 255, 255));
			DrawString(500, PEND_Y, "�Q�[���I��", GetColor(255, 255, 255));

			switch (NowSelect)														//���݂̑I����Ԃɏ]���ď����𕪊�
			{													
			case ePausetype_Game:													//�Q�[����ʂɖ߂��I�𒆂Ȃ�
				y = PGAME_Y;														//�Q�[����ʂɖ߂�̍��W���i�[
				break;

			case ePausetype_Menu:													//�Q�[�����I����I�𒆂Ȃ�
				y = PEND_Y;															//�Q�[���I���̍��W���i�[
				break;
			}
			DrawString(450, y, "��", GetColor(255, 255, 255));						//�I���J�[�\��
		}
	}
}	

//�X�V
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
		case ePausetype_Game:															//�Q�[����ʂɖ߂鍀��
			DrawString(100, 0, "�Q�[�����", GetColor(255, 255, 255));
			
				if (!pauseReset)														// Pause��Ԃ���x�����Z�b�g����Ă��Ȃ��Ȃ�
				{
					pauseFlg = false;													// Pause������ԂɂȂ�Ƃ����t���O
					DrawString(300, 0, "�|�[�Y��ʉ���", GetColor(255, 255, 255));
				}
				pauseReset = true;														// ��xPause������Ԃւ̈ڍs���������
				break;

		case ePausetype_Menu:															//�Q�[���I���̍���
			DrawString(100, 0, "���j���[���", GetColor(255, 255, 255));
			break;
		}
	}
}

//�`��
void Pausemenu::Draw()
{
	PauseAll();
}
