#include <DxLib.h>
#include "Input.h"
#include "Charaselect.h"

/*�R���X�g���N�^*/
CharaSelect::CharaSelect(ISceneChanger* _sceneChanger, Parameter* _parameter) :BaseScene(_sceneChanger, _parameter) {

	//�ŏ��͍�邪�I������Ă�����
	charaSelect = select_SAKUYA;

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
	if (charaSelect != select_SAKUYA) {
		if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1))
		{
			//�I�����ڂ���グ��(����)
			charaSelect = (charaSelect - 1) % select_NUM;
			SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_NORMAL);
		}
	}

	/****����****/
	/************/
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RETURN) == 1))
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
		case select_BACK:
			SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_NORMAL);
			//�O�̃V�[��(���)�ɖ߂�
			sceneChanger->SceneChange(eScene_MENU, parameter, false, true); //�V
			break;
		}
	}

}

/*�`�揈��*/
void CharaSelect::Draw()
{

	Draw_Waku();
	Draw_CharaGraph();
	Draw_CharaName();

}
void CharaSelect::Draw_CharaGraph()
{
	/**�`�� ��**/
	//�L�����N�^�[�摜�̕\��
	DrawGraph(555, 200, Image::Instance()->GetGraph(eImageType::Spicture_SelectPlayer, 0), true);
	DrawGraph(1105, 200, Image::Instance()->GetGraph(eImageType::Spicture_SelectPlayer, 1), true);
}
void CharaSelect::Draw_Waku()
{
	/**�`�� ��**/
	//�L�����N�^�[�摜�̘g�g��
	DrawBox(535, 180, 850, 620, GetColor(0, 0, 255), true);      //�F
	DrawBox(1085, 180, 1400, 620, GetColor(255, 0, 0), true);    //�ԐF

	DrawBox(555, 200, 830, 599, GetColor(0, 255, 255), true);    //���F
	DrawBox(1105, 200, 1380, 599, GetColor(255, 255, 0), true);  //���F

	//�I�����Ă鍀�ڂ̘g
	DrawOvalAA(selectMenu[charaSelect].x, selectMenu[charaSelect].y,
		selectMenu[charaSelect].rx, selectMenu[charaSelect].ry, 100, color, false, 5.0f);
}
void CharaSelect::Draw_CharaName()
{

	/**�`�� �O**/
	//�L�����N�^�[���̕\��
	DrawStringToHandle(560, 700, "�\�Z�� ���", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_3());
	DrawStringToHandle(1100, 700, "�t�����h�[���E�r", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_3());
	DrawStringToHandle(830, 900, "���j���[�ɖ߂�", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_3());
}