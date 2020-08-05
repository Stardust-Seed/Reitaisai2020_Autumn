#include "Dxlib.h"
#include "Title.h"
#include "Input.h"
#include "math.h"

//�^�C�g���e�L�X�g�����傱���Ɠ����������̏����Ɏg��
//�^�C�g���������̂��͌��߂ĂȂ�����p�������Ώ���
float deg, rad;
float o;
int textSpeed[3];
int cnt;
float w;
//�R���X�g���N�^
Title::Title(){

	//�p�������Ώ���
	textSpeed[0] = 0;
	textSpeed[1] = 1;
	textSpeed[2] = 2;
	cnt = 0;
	o = 1000;
	w = 0;
	//�摜�Ƃ��ǂݍ��݂�����

}

void Title::Update()
{
	if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1)
	{
		// �`�悷�镶����̃T�C�Y��ݒ�
		SetFontSize(16);
		DrawFormatString(0,40, GetColor(255, 255, 255), "�X�y�[�X�������ꂽ�̂ŃV�[���؂�ւ����ꂽ��");
		//SceneChange->onSceneChanged(Scene::MENU);�݂����Ȋ�����������Ȃ�������
	}
	//�p�������Ώ���
	Move();
}

void Title::Draw()
{
	//���ʂɕ`�悷�邾��
	//DrawFormatString(GAME_WIDTH / 2 - 112*2.5f, GAME_HEIHGT / 2 , GetColor(255, 255, 255), "�����͖{�^");
	// �`�悷�镶����̃T�C�Y��ݒ�
	SetFontSize(112);
	//�������Ȃ�
	DrawFormatString(GAME_WIDTH / 2 - 64 - textSpeed[2] + o, GAME_HEIHGT / 2-200 - sin(rad) * 64 * 0.25f, GetColor(255, 255, 255), "��");
	DrawFormatString(GAME_WIDTH / 2 - 64 - textSpeed[1] + o, GAME_HEIHGT / 2-200 - cos(rad) * 64 * 0.5f, GetColor(255, 255, 255), "��");
	DrawFormatString(GAME_WIDTH / 2 - 64 + textSpeed[0] + o, GAME_HEIHGT / 2-200 - sin(rad) * 64 * 0.05f, GetColor(255, 255, 255), "��");
	DrawFormatString(GAME_WIDTH / 2 - 64 + textSpeed[1] + o, GAME_HEIHGT / 2-200 - cos(rad) * 64 * 0.5f, GetColor(255, 255, 255), "�{");
	DrawFormatString(GAME_WIDTH / 2 - 64 + textSpeed[2] + o, GAME_HEIHGT / 2-200 - sin(rad) * 64 * 0.75f, GetColor(255, 255, 255), "�^");

	//���V�ۂ����݊�����߂��Ȃ̂ŗ}�����Ă���
	// �`�悷�镶����̃T�C�Y��ݒ�
	SetFontSize(4);

	//���ʂɕ`�悷�邾��
	//DrawFormatString(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f, GetColor(255, 255, 255), "PRESS SPACE");

	//�摜�\�����͎l�p�\��
	DrawBox(GAME_WIDTH -250, GAME_HEIHGT - 400, GAME_WIDTH, GAME_HEIHGT, GetColor(255, 255, 255), true);

}

//�p�������Ώ���
void Title::Move()
{
	cnt++;
	//�^�C�g���̈ړ�����
	{
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
		if(cnt>=500)w+=0.5f;
		if (w >= 450)w = 50;
		// �`�悷�镶����̃T�C�Y��ݒ�
		SetFontSize(32);
		DrawFormatString(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f, GetColor(255, 255, 255), "PRESS SPACE");
		DrawBox(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.4f, GAME_WIDTH / 2 - 32 * 3.5f + 200, GAME_HEIHGT / 1.75f + w, GetColor(0, 0, 0), true);
		DrawBox(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.4f-350, GAME_WIDTH / 2 - 32 * 3.5f + 200, GAME_HEIHGT / 1.75f + w-350, GetColor(0,0, 0), true);
	}
}