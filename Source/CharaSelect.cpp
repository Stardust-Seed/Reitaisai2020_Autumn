#include <DxLib.h>
#include "Input.h"
#include "Charaselect.h"

/*�R���X�g���N�^*/
CharaSelect::CharaSelect(ISceneChanger* _sceneChanger, Parameter* _parameter) :BaseScene(_sceneChanger, _parameter) {

	//�ŏ��͍�邪�I������Ă�����
	charaSelect = select_SAKUYA;

	//�ŏ��͍�邪�I������Ă�����
	select_Sakuya= 0;
	select_Fran = 0;

	//�F
	color = GetColor(0, 0, 255);

}

/*�X�V����*/
void CharaSelect::Update()
{
	/****�I��****/
	/************/
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1))
	{
		//�I�����ڂ�����炷(�E��)
		charaSelect = (charaSelect + 1) % select_NUM;
		SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_NORMAL);
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1))
	{
		//�I�����ڂ���グ��(����)
		charaSelect = (charaSelect - 1) % select_NUM;
		SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_NORMAL);
	}


	/****����****/
	/************/
	if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1))
	{
		switch (charaSelect) {
		case select_SAKUYA:   //����I��
			SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_NORMAL);
			parameter->Set(BaseScene::CharaSelectTag, charaSelect);
			sceneChanger->SceneChange(eScene_LEVELSELECT, parameter, true, false);
			break;
		case select_FRAN:     //�t������I��
			SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_NORMAL);
			parameter->Set(BaseScene::CharaSelectTag, charaSelect);
			sceneChanger->SceneChange(eScene_LEVELSELECT, parameter, true, false);
			break;
		}
	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_X) == 1))
	{
		BGM::Instance()->StopBGM(BGM_menu);
		sceneChanger->SceneChange(eScene_MENU, parameter, true, false);
	}

	if (charaSelect == select_SAKUYA)
	{
		select_Sakuya = 3;
		select_Fran = 0;
	}
	else if (charaSelect == select_FRAN)
	{
		select_Fran = 1;
		select_Sakuya = 0;
	}
	else
	{
		select_Sakuya = 0;
		select_Fran = 0;
	}

}


/*�`�揈��*/
void CharaSelect::Draw()
{
	Draw_CharaBack();    //�w�i
	Draw_CharaWaku();    //�L�����摜�̘g
	Draw_CharaGraph();   //�L�����摜
	Draw_CharaName();    //�L�����l�[���ƃl�[���̘g
	Draw_CharaAbility(); //�L�����N�^�[�̃X�L������

}
void CharaSelect::Draw_CharaBack()
{
	DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Title, 0), true);   //�w�i
	DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Filter, 0), true); //�t�B���^�[
}
void CharaSelect::Draw_CharaWaku()
{
	/**�`�� ��**/
	//�L�����N�^�[�摜�̘g�g��
	DrawBox(535, 180, 850, 620, GetColor(0, 0, 255), true);      //�F
	DrawBox(1085, 180, 1400, 620, GetColor(255, 0, 0), true);    //�ԐF

	DrawBox(555, 200, 830, 599, GetColor(0, 255, 255), true);    //���F
	DrawBox(1105, 200, 1380, 599, GetColor(255, 255, 0), true);  //���F

}
void CharaSelect::Draw_CharaGraph()
{
	/**�`�� ��**/
	//�L�����N�^�[�摜�̕\��
	DrawGraph(555, 200, Image::Instance()->GetGraph(eImageType::Spicture_SelectPlayer, 0), true);
	DrawGraph(1105, 200, Image::Instance()->GetGraph(eImageType::Spicture_SelectPlayer, 1), true);
}
void CharaSelect::Draw_CharaName()
{
	//���g
	DrawRotaGraph(690,725,0.6,0.0,Image::Instance()->GetGraph(eImageType::UI_CursorFrame, select_Sakuya),TRUE);
	//�X�L���g
	DrawBox(95, 200, 450, 700, GetColor(0, 0, 0), TRUE);
	//DrawExtendGraph(125, 200, 500, 600, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);

	//�t�����g
	DrawRotaGraph(1250, 725, 0.6, 0.0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, select_Fran), TRUE);
	//�X�L���g
	DrawBox(1490,200,1845, 700, GetColor(0, 0, 0), TRUE);
	//DrawExtendGraph(1440, 200, 1800, 600, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);

	/**�`�� �O**/
	//�L�����N�^�[���̕\��
	DrawStringToHandle(560, 700, "�\�Z�� ���", GetColor(0, 0,0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1100, 700, "�t�����h�[���E�r", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
}
void CharaSelect::Draw_CharaAbility()
{
	//���X�L������
	DrawStringToHandle(160, 250, "�@�X�L��", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(160, 325, "�G�̓�����", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(100, 375, "5�b�Ԓ�~������", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(120, 450, "�g�p�񐔁F�R��", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());

	//���X�e�[�^�X
	DrawStringToHandle(120, 530, "power  ��", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(120, 580, "speed  ������", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());

	//�t�����X�L������
	DrawStringToHandle(1550, 250, "�@�X�L��", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1515, 325, "��ʏ�̓G��", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1515, 375, "�S�Ĕj�󂷂�", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1515, 450, "�g�p�񐔁F�Q��", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());

	//�t�����X�e�[�^�X
	DrawStringToHandle(1515, 530, "power  ������", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1515, 580, "speed  ��", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
}