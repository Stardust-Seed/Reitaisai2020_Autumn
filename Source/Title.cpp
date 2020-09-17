#include "Dxlib.h"
#include "Title.h"

/*�R���X�g���N�^*/
Title::Title(ISceneChanger* _sceneChanger) :BaseScene(_sceneChanger) {
	SRand;					//����������
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
	//�^�C�g���\��(�R�����g�A�E�g��)
	//DrawGraph(GAME_WIDTH / 8, GAME_HEIHGT/16, Image::Instance()->GetGraph(eImageType_Title), TRUE);

	//�L�����\��(�R�����g�A�E�g��)
	//GetGraph��eImageType�̖��O�͊m�肵�ĂȂ��̂ł�����ۂ��̂����Ă�
	int type = GetRand(3);
	switch (type)
	{
	case 0:
		//DrawGraph(1300, 300, Image::Instance()->GetGraph(eImageType_Sakuya01), TRUE);
		break;

	case 1:
		//DrawGraph(1300, 300, Image::Instance()->GetGraph(eImageType_Sakuya02), TRUE);
		break;

	case 2:
		//DrawGraph(1300, 300, Image::Instance()->GetGraph(eImageType_Fran01), TRUE);
		break;

	case 3:
		//DrawGraph(1300, 300, Image::Instance()->GetGraph(eImageType_Fran02), TRUE);
		break;


	default:
		break;
	}

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