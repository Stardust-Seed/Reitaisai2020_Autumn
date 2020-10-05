#include <DxLib.h>
#include "Pausemenu.h"
#include "Input.h"
#include "BGM.h"
#include "SE.h"
#include "KuronekoLib.h"
#include "FontHandle.h"
#include "Define.h"
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

	case ePausetype_Menu:													//�Q�[�����I����I�𒆂Ȃ�
		y = PEND_Y;															//�Q�[���I���̍��W���i�[
		break;
	}
}

//�X�V
void Pausemenu::Update()
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
	if (Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1)				        //Z�L�[�������ꂽ�ꏊ�̏���
	{
		BGM::Instance()->VolumeBGM(BGM::Instance()->Get_Volume());
		switch (NowSelect)
		{
		case ePausetype_Game:													//�Q�[����ʂɖ߂鍀��
			sceneChanger->SceneChange(eScene_GAME, parameter, false, true);
			break;

		case ePausetype_Menu:													//�Q�[���I���̍���
			BGM::Instance()->StopBGM(BGM_gameScene);
			sceneChanger->SceneChange(eScene_MENU, parameter, false, false);
			break;
		}
	}
}

//�`��
void Pausemenu::Draw()
{
	PauseAll();

	if (NowSelect == ePausetype_Game)
	{
		DrawUIGraph(1300, 400, 1300, 350, 1, 1,
			0, 255, GetColor(255, 255, 255), 3, eDrawType::Center,
			FontHandle::Instance()->Get_natumemozi_100_3(), 205, "�Q�[���ɖ߂�");

		DrawUIGraph(1300, 750, 1300, 350, 1, 1,
			0, 255, GetColor(255, 255, 255), 0, eDrawType::Center,
			FontHandle::Instance()->Get_natumemozi_100_3(), 180, "���j���[�ɖ߂�");
	}
	else
	{
		DrawUIGraph(1300, 400, 1300, 350, 1, 1,
			0, 255, GetColor(255, 255, 255), 0, eDrawType::Center,
			FontHandle::Instance()->Get_natumemozi_100_3(), 205, "�Q�[���ɖ߂�");

		DrawUIGraph(1300, 750, 1300, 350, 1, 1,
			0, 255, GetColor(255, 255, 255), 3, eDrawType::Center,
			FontHandle::Instance()->Get_natumemozi_100_3(), 180, "���j���[�ɖ߂�");
	}

}
