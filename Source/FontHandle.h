#ifndef _FONTHANDLE_H
#define _FONTHANDLE_H

#include "Singleton.h"
#include <Windows.h>
/*********************************************************************************************************************

CreateFontToHandle("�w�肷��t�H���g��", �����̃T�C�Y, �����̑���);
�w��̃t�H���g�f�[�^��������Ȃ��Ƃ��̓f�t�H���g�̃t�H���g�ɂ���܂�
�t�H���g����NULL�ɂ���΃f�t�H���g�t�H���g�ɂȂ�

��������o�^�ł����40�炵���ł�(�m�F�͂��ĂȂ�)

*����*
���܂ł�DrawString�ADrawFormatString���g���ĕ�����\�����Ă�Ǝv���܂��B
���̃n���h�����g�p����ɂ�
DrawStringToHandle(x,y,"����",GetColor(255,255,255),FontHandle�̕ϐ���);
DrawFormatStringToHandle(x,y,GetColor(255,255,255),FontHandle�̕ϐ���,"%d",%d�Ŏg��int�^�̕ϐ���);
��L��DrawStringToHandle�ADrawFormatStringToHandle�ɂ��L�q�Ŏg�p�ł��܂��B

�o�^��)
FontHandle.h��
LPCSTR urabe;
int urabeFont;
int Get_urabe(){ return urabeFont; }
��L�̂悤�Ȃ���̒ǉ������Ă��炢�A

FontHandle.cpp��
urabeFont = CreateFontToHandle("urabe�t�H���g�̖��O(MS �S�V�b�N�Ƃ�)",32(�t�H���g�T�C�Y),3(�t�H���g�̑���));
�Ɠ����Βǉ��o���܂��B

�g�p��)
	�����\��
	DrawStringToHandle(0,0,"�V���E�̉Y���N", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_16_3());

	�ϐ��\��
	int test = 1919;
	DrawFormatStringToHandle(0,0,GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_16_3(),"%d",test);
*********************************************************************************************************************/

class FontHandle :public Singleton <FontHandle> {

	friend Singleton < FontHandle >;

private:
	LPCSTR natumemozi;       //�ǂݍ��ރt�H���g�ϐ�
	LPCSTR weakForce;        //�ǂݍ��ރt�H���g�ϐ�

	int natumemozi_38_8;     //�Ȃ߂����t�H���g
	int natumemozi_48_8;     //�Ȃ߂����t�H���g
	int natumemozi_64_8;     //�Ȃ߂����t�H���g
	int natumemozi_100_3;    //�Ȃ߂����t�H���g
	int weakForce_222_16;    //851�`�J�������N

public:

	FontHandle();     //�R���X�g���N�^
	~FontHandle();    //�f�X�g���N�^

	void Init();      //������

	//�Q�b�^�[

	int Get_natumemozi_38_8() { return natumemozi_38_8; }
	int Get_natumemozi_48_8() { return natumemozi_48_8; }
	int Get_natumemozi_64_8() { return natumemozi_64_8; }
	int Get_natumemozi_100_3() { return natumemozi_100_3; }

	int Get_weakForce_222_16() { return weakForce_222_16; }


};

#endif //FONTHANDLE_H_