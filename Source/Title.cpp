#include "Dxlib.h"
#include "Title.h"

/*�R���X�g���N�^*/
Title::Title(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	deg = 0;
	rad = 0;
	cnt = 0;
	alpha = 0;

	type = GetRand(3);
	BGM::Instance()->PlayBGM(BGM_title);
}

void Title::Update()
{
	Move();
	if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1)
	{
		SE::Instance()->PlaySE(SE_cursor);
		BGM::Instance()->StopBGM(BGM_title);
		sceneChanger->SceneChange(eScene_MENU, parameter, false, false);
	}
	if (Input::Instance()->GetPressCount(KEY_INPUT_ESCAPE) == 1) 
	{
		//�Q�[�����I������
		exit(EXIT_SUCCESS);
	}
}

void Title::Draw()
{
	//�^�C�g���\��
	DrawGraph(GAME_WIDTH / 4 - 25, GAME_HEIHGT / 13, Image::Instance()->GetGraph(eImageType::Title_Logo, 0), TRUE);

	//�v���X�X�y�[�X�̕\��
	//�u�����h���[�h����Z�ς݃��p�̃��u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);

	//�e�̃e�L�X�g
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 6+2, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 5) * 11+2), "P                   ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 6+2, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 4.5f) * 11+2), "  R                 ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 6+2, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 4) * 11+2), "    E               ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 6+2, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 3.5f) * 11+2), "      S             ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 6+2, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 3) * 11+2), "        S           ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 10+2, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 2.5f) * 11+2), "           S        ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 10+2, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 2) * 11+2), "             P      ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 10+2, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 1.5f) * 11+2), "               A    ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 10+2, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 1) * 11+2), "                 C  ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 10+2, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 0.5f) * 11+2), "                   E", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	//�{��
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 6, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 5) * 11), "P                   ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 6, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 4.5f) * 11), "  R                 ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 6, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 4) * 11), "    E               ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 6, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 3.5f) * 11), "      S             ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 6, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 3) * 11), "        S           ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 10, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 2.5f) * 11), "           S        ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 10, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 2) * 11), "             P      ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 10, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 1.5f) * 11), "               A    ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 10, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 1) * 11), "                 C  ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringFToHandle(GAME_WIDTH / 2 - 19 * 9 - 10, static_cast<float>(GAME_HEIHGT / 2 + 175 - sin(rad + 0.5f) * 11), "                   E", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	//�u�����h���[�h��ʏ�ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, alpha);
	//DrawLine(GAME_WIDTH / 2, 0, GAME_WIDTH / 2, GAME_HEIHGT, GetColor(0,0,0));    // ����`��
}

//�����̓����̏���
void Title::Move()
{
	//�p�x�v�Z
	if (deg >= 360)deg = 0;
	rad = deg * 3.14 / 180;

	//�����҂�
	if (cnt < 60)
	{
		cnt++;
	}
	else
	{
		deg += 0.5f;
		//�����������яオ��悤�ɂ���
		if (alpha < 255)
		{
			alpha++;
		}
	}

}