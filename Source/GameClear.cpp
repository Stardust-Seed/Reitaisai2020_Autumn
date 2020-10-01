#include <DxLib.h>
#include "GameClear.h"

GameClear::GameClear(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	nowCursor = Cursor::Cursor_0;
	x = 0;
	alpha = 0;
	alpha = 0;
	charaType = _parameter->Get(BaseScene::CharaSelectTag);
	BGM::Instance()->PlayBGM(BGM_result, DX_PLAYTYPE_LOOP);
}

/*�X�V����*/
void GameClear::Update() {
	Select();
	Move();
}

/*�`�揈��*/
void GameClear::Draw() {

	//�w�i�\��
	DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Title), TRUE);

	//�w�i�\��
	DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Filter), TRUE);

	//�L�����̕\��
	switch (charaType)
	{
	case 0:
		DrawGraph(GAME_WIDTH / 1.45f, GAME_HEIHGT / 9, Image::Instance()->GetGraph(eImageType::Spicture_Sakuya, 1), TRUE);
		break;

	case 1:
		DrawGraph(GAME_WIDTH / 1.45f, GAME_HEIHGT / 9, Image::Instance()->GetGraph(eImageType::Spicture_Fran, 1), TRUE);
		break;

	default:
		break;
	}

	//���b�Z�[�W�E�C���h�E�\��
	DrawGraph(0, GAME_HEIHGT - 450, Image::Instance()->GetGraph(eImageType::UI_MessageBox), TRUE);

	//�u�����h���[�h����Z�ς݃��p�̃��u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, alpha);

	//�Q�[���N���A�\��
	DrawStringToHandle(GAME_WIDTH / 20+75, GAME_HEIHGT / 10, "�Q�[���N���A!", GetColor(255, 255, 255), FontHandle::Instance()->Get_weakForce_222_16());

	//�u�����h���[�h��ʏ�ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, alpha);

	//�J�[�\���t���[���̕\��
	if (x != GAME_X)
	{
		DrawRotaGraph(GAME_X, GAME_HEIHGT / 2 + 75, 0.6f, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);
	}
	else
	{
		DrawRotaGraph(TITLE_X, GAME_HEIHGT / 2 + 75, 0.6f, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);
	}

	//�I������Ă�J�[�\���t���[���̕\��
	DrawRotaGraph(x, GAME_HEIHGT / 2 + 75, 0.6f, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 3), TRUE);

	//�e�L�X�g�\��
	DrawStringToHandle(GAME_WIDTH / 7 - 5, GAME_HEIHGT / 2 + 50, "������x����", GetColor(255, 64, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(GAME_WIDTH / 2.5+25, GAME_HEIHGT / 2 + 50, "�^�C�g���ɖ߂�", GetColor(255, 64, 0), FontHandle::Instance()->Get_natumemozi_48_8());

	//�L�������ƃZ���t�\��
	switch (charaType)
	{
	case 0:
		DrawStringToHandle(GAME_WIDTH - 500, GAME_HEIHGT - 340, "�\�Z�� ���", GetColor(255, 64, 0), FontHandle::Instance()->Get_natumemozi_48_8());
		
		DrawStringToHandle(GAME_WIDTH / 13, GAME_HEIHGT - 260, "�Ђ�����f�o�b�O\n�Ђ�����f�o�b�O\n�Ђ�����f�o�b�O", GetColor(255, 64, 0), FontHandle::Instance()->Get_natumemozi_64_8());
		break;

	case 1:
		DrawStringToHandle(GAME_WIDTH /1.5f + 10, GAME_HEIHGT - 340, "�t�����h�[���E�X�J�[���b�g", GetColor(255, 64, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	
		DrawStringToHandle(GAME_WIDTH / 13, GAME_HEIHGT - 260, "�Ђ�����f�o�b�O\n�Ђ�����f�o�b�O\n�Ђ�����f�o�b�O", GetColor(255, 64, 0), FontHandle::Instance()->Get_natumemozi_64_8());
		break;

	default:
		break;
	}
}

//�����̓���
void GameClear::Move()
{
	if (alpha < 255)
	{
		alpha++;
	}
}

//�I��
void GameClear::Select()
{
	//nowCursor�̔ԍ���x���W�ƍ��킹��
	{
		switch (nowCursor)
		{
		case Cursor::Cursor_0:
			x = GAME_X;
			break;

		case Cursor::Cursor_1:
			x = TITLE_X;
			break;

		default:
			break;
		}
	}

	//���L�[�������ꂽ���̏���
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1)
		{
			SE::Instance()->PlaySE(SE_cursor);
			nowCursor = Cursor::Cursor_0;
		}
	}

	//�E�L�[�������ꂽ���̏���
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1)
		{
			SE::Instance()->PlaySE(SE_cursor);
			nowCursor = Cursor::Cursor_1;
		}
	}

	//Enter�L�[�������ꂽ���̏���
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1)
		{
			BGM::Instance()->StopBGM(BGM_result);
			//�J�[�\���̏ꏊ�ɂ���čs���V�[���ύX���������߂�
			switch (nowCursor)
			{
			case Cursor::Cursor_0:    //�R���e�B�j���[����
				sceneChanger->SceneChange(eScene_GAME, parameter, false, false);
				break;

			case Cursor::Cursor_1:    //�^�C�g���ɖ߂�
				sceneChanger->SceneChange(eScene_MENU, parameter, false, false);
				break;

			default:
				break;
			}
		}
	}
}