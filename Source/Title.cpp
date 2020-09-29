#include "Dxlib.h"
#include "Title.h"

/*�R���X�g���N�^*/
Title::Title(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	SRand;					//����������
	deg = 0;
	rad = 0;
	cnt = 0;
	alpha = 0;

	type = GetRand(3);
	BGM::Instance()->PlayBGM(BGM_title);
}

void Title::Update()
{
	if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1)
	{
		SE::Instance()->PlaySE(SE_cursor);
		BGM::Instance()->StopBGM(BGM_title);
		sceneChanger->SceneChange(eScene_MENU, parameter, false, false);
	}

	Move();
}

void Title::Draw()
{
	//�w�i�\��
	DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Title), TRUE);

	//�^�C�g���\��
	DrawGraph(GAME_WIDTH / 4.25f, GAME_HEIHGT / 13, Image::Instance()->GetGraph(eImageType::Title_Logo, 0), TRUE);

	//�v���X�X�y�[�X�̕\��
	//�u�����h���[�h����Z�ς݃��p�̃��u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, alpha);

	DrawStringToHandle(GAME_WIDTH / 2 - 16 * 6.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 3,    "P          ", GetColor(255, 255, 255), FontHandle::Instance()->Get_SnoutCrayon_48_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 16 * 6.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 3.2f, " R         ", GetColor(255, 255, 255), FontHandle::Instance()->Get_SnoutCrayon_48_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 16 * 6.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 3.4f, "  E        ", GetColor(255, 255, 255), FontHandle::Instance()->Get_SnoutCrayon_48_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 16 * 6.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 3.6f, "   S       ", GetColor(255, 255, 255), FontHandle::Instance()->Get_SnoutCrayon_48_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 16 * 6.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 3.8f, "    S      ", GetColor(255, 255, 255), FontHandle::Instance()->Get_SnoutCrayon_48_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 16 * 6.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 3.8f, "      S    ", GetColor(255, 255, 255), FontHandle::Instance()->Get_SnoutCrayon_48_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 16 * 6.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 3.6f, "       P   ", GetColor(255, 255, 255), FontHandle::Instance()->Get_SnoutCrayon_48_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 16 * 6.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 3.4f, "        A  ", GetColor(255, 255, 255), FontHandle::Instance()->Get_SnoutCrayon_48_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 16 * 6.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 3.2f, "         C ", GetColor(255, 255, 255), FontHandle::Instance()->Get_SnoutCrayon_48_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 16 * 6.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 3,    "          E", GetColor(255, 255, 255), FontHandle::Instance()->Get_SnoutCrayon_48_3());

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
	if (cnt < 130)
	{
		cnt++;
	}
	else
	{
		deg += 1;
		//�����������яオ��悤�ɂ���
		if (alpha < 255)
		{
			alpha++;
		}
	}
}