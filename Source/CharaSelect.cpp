#include <DxLib.h>
#include "Input.h"
#include "Charaselect.h"

/*�R���X�g���N�^*/
CharaSelect::CharaSelect(ISceneChanger* _sceneChanger, Parameter* _parameter) :BaseScene(_sceneChanger, _parameter) {

	//�ŏ��͍�邪�I������Ă�����
	charaSelect = select_SAKUYA;

	selectChara = SelectCharacter::select_SAKUYA;

	//�F
	color = GetColor(0, 0, 255);

	//UI�t���[���̐F�������ݒ�
	charaCursor[static_cast<int>(SelectCharacter::select_SAKUYA)] = Cursor::Cursor_3;
	charaCursor[static_cast<int>(SelectCharacter::select_FRAN)] = Cursor::Cursor_0;


}

/*�X�V����*/
void CharaSelect::Update()
{
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1))
	{
		Select_Push(CURSOR_DOWN); //�I������

	}
	if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1))
	{
		Select_Push(CURSOR_UP); //�I������
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
	//�ߋ��֖߂�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_X) == 1))
	{
		sceneChanger->SceneChange(eScene_MENU, parameter, false, true);
	}
}
void CharaSelect::Select_Push(int _changeType)
{

		//SE��炷
		SE::Instance()->PlaySE(SE_cursor);

		//���ݑI������Ă鍀�ڂ̃J�[�\���t���[�����D�F��
		charaCursor[static_cast<int>(selectChara)] = Cursor::Cursor_0;

		//�؂�ւ����[�h��DOWN�̏ꍇ
		if (_changeType == CURSOR_DOWN) {
			//��ԉ��̍��ڂ̂Ƃ��A��ԏ�̍��ڂ�
			if (selectChara == SelectCharacter::select_FRAN) {
				selectChara = SelectCharacter::select_SAKUYA;
			}
			//��L�����O�̂Ƃ��A����̍��ڂ�
			else {
				selectChara = static_cast<SelectCharacter>(static_cast<int>(selectChara) + 1);
			}
		}
		//�؂�ւ����[�h��UP�̏ꍇ
		else if (_changeType == CURSOR_UP) {
			//��ԏ�̍��ڂ̂Ƃ��A��ԉ��̍��ڂ�
			if (selectChara == SelectCharacter::select_SAKUYA) {
				selectChara = SelectCharacter::select_FRAN;
			}
			//��L�����O�̂Ƃ��A���̍��ڂ�
			else {
				selectChara = static_cast<SelectCharacter>(static_cast<int>(selectChara) - 1);
			}
	
		}

		//���ݑI������Ă鍀�ڂ̃J�[�\���t���[����F��
		charaCursor[static_cast<int>(selectChara)] = Cursor::Cursor_3;

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
	//�ߋ��֖߂�
	if ((Input::Instance()->GetPressCount(KEY_INPUT_X) == 1))
	{
		sceneChanger->SceneChange(eScene_MENU, parameter, false, true);
	}

}

/*�`�揈��*/
void CharaSelect::Draw()
{
	Draw_CharaWaku();    //�L�����摜�̘g
	Draw_CharaGraph();   //�L�����摜
	Draw_CharaName();    //�L�����l�[���ƃl�[���̘g
	Draw_CharaAbility(); //�L�����N�^�[�̃X�L������
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
	DrawRotaGraph(690,725,0.6,0.0,Image::Instance()->GetGraph(eImageType::UI_CursorFrame, static_cast<int>(charaCursor[static_cast<int>(SelectCharacter::select_SAKUYA)])),TRUE);
	//�X�L���g
	DrawBox(95, 200, 450, 700, GetColor(0, 0, 0), TRUE);
	//�t�����g
	DrawRotaGraph(1250, 725, 0.6, 0.0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, static_cast<int>(charaCursor[static_cast<int>(SelectCharacter::select_FRAN)])), TRUE);
	//�X�L���g
	DrawBox(1490,200,1845, 700, GetColor(0, 0, 0), TRUE);

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