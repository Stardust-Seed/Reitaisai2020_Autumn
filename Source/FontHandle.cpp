#include "FontHandle.h"
#include "DxLib.h"

void FontHandle::Init()
{
	//CreateFontToHandle("�w�肷��t�H���g��", �����̃T�C�Y, �����̑���);
	//�w��̃t�H���g�f�[�^��������Ȃ��Ƃ��̓f�t�H���g�̃t�H���g�ɂ���܂�
	//�t�H���g����NULL�ɂ���΃f�t�H���g�t�H���g�ɂȂ�

	//�o�^���Ă���`
	MS_GOTHIC_112_3 = CreateFontToHandle("�l�r �S�V�b�N", 112, 3);
	MS_GOTHIC_64_3 = CreateFontToHandle("�l�r �S�V�b�N", 64, 3);
	MS_GOTHIC_32_3 = CreateFontToHandle("�l�r �S�V�b�N", 32, 3);
	MS_GOTHIC_16_3 = CreateFontToHandle("�l�r �S�V�b�N", 16, 3);

	MS_MINCHO_64_3 = CreateFontToHandle("�l�r ����", 64, 3);
	MS_MINCHO_32_3 = CreateFontToHandle("�l�r ����", 32, 3);
	MS_MINCHO_16_3 = CreateFontToHandle("�l�r ����", 16, 3);
}

