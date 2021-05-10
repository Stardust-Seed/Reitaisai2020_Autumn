#include <DxLib.h>
#include "Pausemenu.h"
#include "Input.h"
#include "BGM.h"
#include "SE.h"
#include "FontHandle.h"
#include "Image.h"
Pausemenu::Pausemenu(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {

	if (BGM::Instance()->Get_Volume() >= 5)
	{
		BGM::Instance()->VolumeBGM(4);
	}
	else
	{
		if (BGM::Instance()->Get_Volume() != 0)
		{
			BGM::Instance()->VolumeBGM(BGM::Instance()->Get_Volume() - 1);
		}
	}
}

//�摜�Ƃ��w�i�H(������)
/*void Pausemenu::Pause()
{

}*/

//�|�[�Y��ʂ̏���
void Pausemenu::PauseAll()
{
	switch (NowSelect)														//���݂̑I����Ԃɏ]���ď����𕪊�
	{
	case ePausetype_Game:													//�Q�[����ʂɖ߂��I�𒆂Ȃ�
		y = PGAME_Y;														//�Q�[����ʂɖ߂�̍��W���i�[
		break;

	case ePausetype_Guide:
		y = PGUIDE_Y;
		break;

	case ePausetype_Menu:													//�Q�[�����I����I�𒆂Ȃ�
		y = PEND_Y;															//�Q�[���I���̍��W���i�[
		break;
	}
}

//�X�V
void Pausemenu::Update(GameResource* _gameRes)
{

	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) % 16 == 1)		        //���L�[��������Ă�����
	{
		SE::Instance()->PlaySE(SE_cursor);
		NowSelect = (NowSelect + 1) % ePausetype_Num;							//�I����Ԃ�������
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) % 16 == 1)			    //��L�[��������Ă�����
	{
		SE::Instance()->PlaySE(SE_cursor);
		NowSelect = (NowSelect + (ePausetype_Num - 1)) % ePausetype_Num;		//�I����Ԃ��グ��
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_X) == 1)				        //X�L�[�������ꂽ�ꏊ�̏���
	{
		SE::Instance()->PlaySE(SE_Cancel);
		BGM::Instance()->VolumeBGM(BGM::Instance()->Get_Volume());
		sceneChanger->SceneChange(eScene_GAME, parameter, false, true);
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1)				        //Z�L�[�������ꂽ�ꏊ�̏���
	{
		SE::Instance()->PlaySE(SE_Enter);
		BGM::Instance()->VolumeBGM(BGM::Instance()->Get_Volume());
		switch (NowSelect)
		{
		case 0:													//�Q�[����ʂɖ߂鍀��
			sceneChanger->SceneChange(eScene_GAME, parameter, false, true);
			break;

		case 1:													//��������̍���
			sceneChanger->SceneChange(eScene_OPERATIONEXP, parameter, true, false);
			break;

		case 2:													//�Q�[���I���̍���
			BGM::Instance()->StopBGM(BGM_gameScene);
			sceneChanger->SceneChange(eScene_MENU, parameter, false, false);
		}
	}
}

//�`��
void Pausemenu::Draw(GameResource* _gameRes)
{
	PauseAll();

	if (NowSelect == ePausetype_Game)
	{
		DrawRotaGraph(GAME_WIDTH / 2, 225, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 3), TRUE);
		DrawRotaGraph(GAME_WIDTH / 2, 525, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);
		DrawRotaGraph(GAME_WIDTH / 2, 825, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);

		DrawStringToHandle(GAME_WIDTH / 2 - 287, 225 - 50, "�Q�[���ɖ߂�", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 300, 525 - 50, "�@��������@", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 280, 825 - 50, " �Q�[���I�� ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());

		DrawStringToHandle(GAME_WIDTH / 2 - 287-2, 225 - 50-2, "�Q�[���ɖ߂�", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 300-2, 525 - 50-2, "�@��������@", GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 280-2, 825 - 50-2, " �Q�[���I�� ", GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_100_3());
	}

	if(NowSelect == ePausetype_Menu)
	{
		DrawRotaGraph(GAME_WIDTH / 2, 225, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);
		DrawRotaGraph(GAME_WIDTH / 2, 525, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 3), TRUE);
		DrawRotaGraph(GAME_WIDTH / 2, 825, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);

		DrawStringToHandle(GAME_WIDTH / 2 - 287, 225 - 50, "�Q�[���ɖ߂�", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 300, 525 - 50, "�@��������@", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 280, 825 - 50, " �Q�[���I�� ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());

		DrawStringToHandle(GAME_WIDTH / 2 - 287 - 2, 225 - 50 - 2, "�Q�[���ɖ߂�", GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 300 - 2, 525 - 50 - 2, "�@��������@", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 280 - 2, 825 - 50 - 2, " �Q�[���I�� ", GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_100_3());

	}

	if (NowSelect == ePausetype_Guide)
	{
		DrawRotaGraph(GAME_WIDTH / 2, 225, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);
		DrawRotaGraph(GAME_WIDTH / 2, 525, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);
		DrawRotaGraph(GAME_WIDTH / 2, 825, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 3), TRUE);

		DrawStringToHandle(GAME_WIDTH / 2 - 287, 225 - 50, "�Q�[���ɖ߂�", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 300, 525 - 50, "�@��������@", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 280, 825 - 50, " �Q�[���I�� ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());

		DrawStringToHandle(GAME_WIDTH / 2 - 287 - 2, 225 - 50 - 2, "�Q�[���ɖ߂�", GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 300 - 2, 525 - 50 - 2, "�@��������@", GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 280 - 2, 825 - 50 - 2, " �Q�[���I�� ", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_100_3());

	}

}
