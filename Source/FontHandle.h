#ifndef _FONTHANDLE_H
#define _FONTHANDLE_H

#include "Singleton.h"

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
int urabeFont;
int Get_urabe(){ return urabeFont; }

FontHandle.cpp��
urabeFont = CreateFontToHandle("�l�r �S�V�b�N",32,3);

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

	//�ϐ������������ƂȂ񂩋C����������������啶���A���_�[�o�[�I�����[
	/*-MS �S�V�b�N �t�H���g��`��-*/
	int MS_GOTHIC_112_3;
	int MS_GOTHIC_64_3;
	int MS_GOTHIC_32_3;
	int MS_GOTHIC_16_3;
	/*----------------------------*/

	/*-MS ���� �t�H���g��`��-----*/
	int MS_MINCHO_64_3;
	int MS_MINCHO_32_3;
	int MS_MINCHO_16_3;
	/*----------------------------*/
public:

	FontHandle();     //�R���X�g���N�^
	~FontHandle();    //�f�X�g���N�^

	void Init();      //������

	//�Q�b�^�[
	int Get_MS_GOTHIC_112_3() { return MS_GOTHIC_112_3; }
	int Get_MS_GOTHIC_64_3() { return MS_GOTHIC_64_3; }
	int Get_MS_GOTHIC_32_3() { return MS_GOTHIC_32_3; }
	int Get_MS_GOTHIC_16_3() { return MS_GOTHIC_16_3; }

	int Get_MS_MINCHO_64_3() { return MS_MINCHO_64_3; }
	int Get_MS_MINCHO_32_3() { return MS_MINCHO_32_3; }
	int Get_MS_MINCHO_16_3() { return MS_MINCHO_16_3; }
};

#endif //FONTHANDLE_H_