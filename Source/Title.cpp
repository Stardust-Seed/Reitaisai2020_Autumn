#include "Dxlib.h"
#include "Define.h"
#include "FontHandle.h"
#include "Input.h"
#include "math.h"
#include "SE.h"
#include "Title.h"

/*�R���X�g���N�^*/
Title::Title(ISceneChanger* _sceneChanger) :BaseScene(_sceneChanger) {

	textPosition = 875;
	deg = 0;
	rad = 0;
	cnt = 0;
	r = 0;
	g = 0;
	b = 0;
}

void Title::Update()
{
	if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1)
	{
		sceneChanger->SceneChange(eScene_MENU, false, false);
	}

	Move();
}

void Title::Draw()
{
	//�^�C�g���\��
	DrawStringToHandle(GAME_WIDTH / 2 - 56 * 5 - sin(rad) * 0.5f + textPosition, GAME_HEIHGT / 2 - 200 - cos(rad) * 16, "��        ", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 56 * 5 - sin(rad) * 0.5f + textPosition, GAME_HEIHGT / 2 - 200 - sin(rad) * 18, "  ��      ", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 56 * 5 - sin(rad) * 0.5f + textPosition, GAME_HEIHGT / 2 - 200 - cos(rad) * 10, "    ��    ", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 56 * 5 - sin(rad) * 0.5f + textPosition, GAME_HEIHGT / 2 - 200 - sin(rad) * 18, "      �{  ", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 56 * 5 - sin(rad) * 0.5f + textPosition, GAME_HEIHGT / 2 - 200 - cos(rad) * 25, "        �^", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());

	//�v���X�X�y�[�X�̕\������
	if(cnt == 250)
	{
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.2f, "P          ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.4f, " R         ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.6f, "  E        ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.8f, "   S       ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 2,    "    S      ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 2,    "      S    ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.8f, "       P   ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.6f, "        A  ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.4f, "         C ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.5f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.2f, "          E", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
	}

	//�摜�\�����͎l�p�\��
	DrawBox(GAME_WIDTH -250, GAME_HEIHGT - 400, GAME_WIDTH, GAME_HEIHGT, GetColor(255, 255, 255), true);
}

//�����̓����̏���
void Title::Move()
{
	//�p�x�v�Z
	if (deg >= 360)deg = 0;
	rad = deg * 3.14 / 180;

	//��ʒ����܂ŉ��ړ�������
	if (cnt < 250)
	{
		cnt++;
		deg += 1.75f;
		textPosition -= 3.5f;
	}
	else
	{
		deg += 1.25f;
		//�����������яオ��悤�Ȋ����ɂ���
		if (r < 255 && b < 255 && g < 255)
		{
			r++;
			b++;
			g++;
		}
		else
		{
			r = 255;
			b = 255;
			g = 255;
		}
	}
}