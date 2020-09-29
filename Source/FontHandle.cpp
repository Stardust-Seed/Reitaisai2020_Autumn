#include "FontHandle.h"
#include "DxLib.h"
//�R���X�g���N�^
FontHandle::FontHandle() {
	//�R���X�g���N�^��Init�̏������e�𒼐ړ����ƂȂ񂩎��s����Ȃ��A
	//Init�ɏ��������ăR���X�g���N�^�ɓ����ƂȂ񂩎��s����܂�
	Init();
	snoutCrayon = "./res/Font/crayon_1-1.ttf";             //�ǂݍ��ރt�H���g�t�@�C���̃p�X
	natumemozi = "./res/Font/natumemozi.ttf";              //�ǂݍ��ރt�H���g�t�@�C���̃p�X
	weakForce = "./res/Font/851CHIKARA-YOWAKU_002.ttf";   //�ǂݍ��ރt�H���g�t�@�C���̃p�X
	AddFontResourceEx(snoutCrayon, FR_PRIVATE, NULL);      //�t�H���g��ǂݍ���
	AddFontResourceEx(natumemozi, FR_PRIVATE, NULL);       //�t�H���g��ǂݍ���
	AddFontResourceEx(weakForce, FR_PRIVATE, NULL);      //�t�H���g��ǂݍ���
}

//�f�X�g���N�^
FontHandle::~FontHandle() {
	RemoveFontResource(snoutCrayon);                      //�ǂݍ��񂾃t�H���g���폜
	RemoveFontResource(natumemozi);                       //�ǂݍ��񂾃t�H���g���폜
	RemoveFontResource(weakForce);                        //�ǂݍ��񂾃t�H���g���폜
	//�쐬�����t�H���g�n���h���������Ă����֗��ȓz
	InitFontToHandle();
}

//������
void FontHandle::Init()
{
	//CreateFontToHandle("�w�肷��t�H���g��", �����̃T�C�Y, �����̑���);
	//�w��̃t�H���g�f�[�^��������Ȃ��Ƃ��̓f�t�H���g�̃t�H���g�ɂ���܂�
	//�t�H���g����NULL�ɂ���΃f�t�H���g�t�H���g�ɂȂ�

	//�o�^
	snoutCrayon_48_3 = CreateFontToHandle("���菑���N������", 48, 3);
	natumemozi_48_3 = CreateFontToHandle("�Ȃ߂���", 48, 3);
	natumemozi_100_3 = CreateFontToHandle("�Ȃ߂���", 100, 3, DX_FONTTYPE_ANTIALIASING);
	weakForce_48_8 = CreateFontToHandle("851�`�J�������N", 48, 8, DX_FONTTYPE_ANTIALIASING);
	weakForce_222_16 = CreateFontToHandle("851�`�J�������N", 222, 16, DX_FONTTYPE_ANTIALIASING);
}

