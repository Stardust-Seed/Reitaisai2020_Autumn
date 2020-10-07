#include <DxLib.h>
#include "GameClear.h"

const int GameClear::GAME_X = GAME_WIDTH / 5 + 30;   //�u������x����v�e�L�X�g�\����X���W
const int GameClear::TITLE_X = GAME_WIDTH / 2 - 20;     //�u���j���[�ɖ߂�v�e�L�X�g�\����X���W

GameClear::GameClear(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {

	nowCursor = Cursor::Cursor_0;
	x = 0;
	alpha = 0;
	waitTimer = 0;
	charaType = _parameter->Get(BaseScene::CharaSelectTag);
	BGM::Instance()->PlayBGM(BGM_result, DX_PLAYTYPE_LOOP);
}

/*�X�V����*/
void GameClear::Update() {
	if (waitTimer < 150)
	{
		waitTimer++;
	}
	Move();
	Select();
}

/*�`�揈��*/
void GameClear::Draw() {

	//�L�����̕\��
	switch (charaType)
	{
	case 0:
		DrawGraph(GAME_WIDTH - 600, GAME_HEIHGT / 9, Image::Instance()->GetGraph(eImageType::Spicture_Sakuya, 1), TRUE);
		break;

	case 1:
		DrawGraph(GAME_WIDTH - 600, GAME_HEIHGT / 9, Image::Instance()->GetGraph(eImageType::Spicture_Fran, 1), TRUE);
		break;

	default:
		break;
	}

	//���b�Z�[�W�E�C���h�E�\��
	DrawGraph(0, GAME_HEIHGT - 450, Image::Instance()->GetGraph(eImageType::UI_MessageBox), TRUE);

	//�u�����h���[�h����Z�ς݃��p�̃��u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, alpha);

	//�Q�[���N���A�\��
	DrawStringToHandle(GAME_WIDTH / 20 + 75 + 3, GAME_HEIHGT / 10 + 3, text1, GetColor(0, 0, 0), FontHandle::Instance()->Get_weakForce_222_16());
	DrawStringToHandle(GAME_WIDTH / 20+75, GAME_HEIHGT / 10, text1, GetColor(255, 255, 255), FontHandle::Instance()->Get_weakForce_222_16());

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

	if (x != GAME_X)
	{
		DrawStringToHandle(GAME_WIDTH / 7 - 5 + 2, GAME_HEIHGT / 2 + 50+2, text2, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
		DrawStringToHandle(GAME_WIDTH / 7 - 5, GAME_HEIHGT / 2 + 50, text2, GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_48_8());

		DrawStringToHandle(GAME_WIDTH / 3 + 150 + 2, GAME_HEIHGT / 2 + 50 + 2, text3, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
		DrawStringToHandle(GAME_WIDTH / 3 + 150, GAME_HEIHGT / 2 + 50, text3, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	}
	else
	{
		DrawStringToHandle(GAME_WIDTH / 7 - 5 + 2, GAME_HEIHGT / 2 + 50+2, text2, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
		DrawStringToHandle(GAME_WIDTH / 7 - 5, GAME_HEIHGT / 2 + 50, text2, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());

		DrawStringToHandle(GAME_WIDTH / 3 + 150 + 2, GAME_HEIHGT / 2 + 50 + 2, text3, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
		DrawStringToHandle(GAME_WIDTH / 3 + 150, GAME_HEIHGT / 2 + 50, text3, GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_48_8());
	}

	//�L�������ƃZ���t�\��
	switch (charaType)
	{
	case 0:

		DrawStringToHandle(GAME_WIDTH - 500, GAME_HEIHGT - 340, text4, GetColor(255, 64, 0), FontHandle::Instance()->Get_natumemozi_48_8());

		DrawStringToHandle(GAME_WIDTH / 13+2, GAME_HEIHGT - 260+2, text5, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_64_8());
		DrawStringToHandle(GAME_WIDTH / 13, GAME_HEIHGT - 260, text5, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_64_8());

		
		break;

	case 1:

		DrawStringToHandle(GAME_WIDTH -630, GAME_HEIHGT - 340,text6, GetColor(255, 64, 0), FontHandle::Instance()->Get_natumemozi_48_8());

		DrawStringToHandle(GAME_WIDTH / 13+2, GAME_HEIHGT - 260+2, text7, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_64_8());
		DrawStringToHandle(GAME_WIDTH / 13, GAME_HEIHGT - 260, text7, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_64_8());
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
		if (Input::Instance()->GetPressCount(KEY_INPUT_LEFT) % 16 == 1)
		{
			SE::Instance()->PlaySE(SE_cursor);
			if (nowCursor == Cursor::Cursor_0)
			{
				nowCursor = Cursor::Cursor_1;
			}
			else
			{
				nowCursor = Cursor::Cursor_0;
			}
		}
	}

	//�E�L�[�������ꂽ���̏���
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) % 16  == 1)
		{
			SE::Instance()->PlaySE(SE_cursor);
			if (nowCursor == Cursor::Cursor_1)
			{
				nowCursor = Cursor::Cursor_0;
			}
			else
			{
				nowCursor = Cursor::Cursor_1;
			}
		}
	}

	//Enter�L�[�������ꂽ���̏���
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1 && waitTimer == 150)
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