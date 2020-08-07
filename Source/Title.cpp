#include "Dxlib.h"
#include "Title.h"
#include "Input.h"
#include "math.h"

//�R���X�g���N�^
Title::Title(){

	//�p�������Ώ���
	textSpeed[0] = 0;
	textSpeed[1] = 1;
	textSpeed[2] = 2;
	deg = 0;
	rad = 0;
	cnt = 0;
	o = 1000;

	//�摜�Ƃ��ǂݍ��݂�����

}

void Title::Update()
{
	if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1)
	{
		SE::Instance()->PlaySE(SE_00,No);
		// �`�悷�镶����̃T�C�Y��ݒ�
		SetFontSize(16);
		DrawFormatString(0,40, GetColor(255, 255, 255), "�X�y�[�X�������ꂽ�̂ŃV�[���؂�ւ����ꂽ��");
		//SceneChange->onSceneChanged(Scene::MENU);�݂����Ȋ�����������Ȃ�������
	}

	Move();
}

void Title::Draw()
{
	//�^�C�g���\��
	DrawStringToHandle(GAME_WIDTH / 2 - 64 - textSpeed[2] + o, GAME_HEIHGT / 2 - 200 - sin(rad) * 64 * 0.25f, "��", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 64 - textSpeed[1] + o, GAME_HEIHGT / 2 - 200 - cos(rad) * 64 * 0.5f , "��", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 64 + textSpeed[0] + o, GAME_HEIHGT / 2 - 200 - sin(rad) * 64 * 0.05f, "��", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 64 + textSpeed[1] + o, GAME_HEIHGT / 2 - 200 - cos(rad) * 64 * 0.5f , "�{", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 64 + textSpeed[2] + o, GAME_HEIHGT / 2 - 200 - sin(rad) * 64 * 0.75f, "�^", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());

	//�摜�\�����͎l�p�\��
	DrawBox(GAME_WIDTH -250, GAME_HEIHGT - 400, GAME_WIDTH, GAME_HEIHGT, GetColor(255, 255, 255), true);
}

void Title::Move()
{
	cnt++;
	//�^�C�g���̈ړ�����
	{
		//if���̒��Ƃ��}�W�b�N�i���o�[���肠�胍�W�J��������
		if (deg >= 360)deg = 0;
		rad = deg * 3.14 / 180;

		if (cnt < 112)
		{
			textSpeed[1] += 1;
			textSpeed[2] += 2;
		}
		else
		{
			deg += 0.15f;
		}

		if (cnt < 500)
		{
			o -= 2;
		}
		else
		{
			deg += 0.15f;
			o = deg * 3.14 / 720;
			cnt = 500;
		}
	}
	//�v���X�X�y�[�X�̕\������
	{
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 1.25f, "P"          , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 1.5f,  " R"         , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 1.75f, "  E"        , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 2,     "   S"       , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 2.5f,  "    S"      , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 2.5f,  "      S"    , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 2,     "       P"   , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 1.75,  "        A"  , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 1.5f,  "         C" , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 1.25f, "          E", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
	}
}