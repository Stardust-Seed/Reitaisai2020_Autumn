#ifndef _FONTHANDLE_H
#define _FONTHANDLE_H

#include "Singleton.h"

/********************************************************************************************

CreateFontToHandle("�w�肷��t�H���g��", �����̃T�C�Y, �����̑���);
�w��̃t�H���g�f�[�^��������Ȃ��Ƃ��̓f�t�H���g�̃t�H���g�ɂ���܂�
�t�H���g����NULL�ɂ���΃f�t�H���g�t�H���g�ɂȂ�

�R���X�g���N�^��CreateFontToHandle�̐��������������Ă��������Ȃ������[���E�n�������Ȃ̂�
�킴�킴�킴�킴�킴�킴�킴�킴�킴�킴�킴�킴�킴
Init����������܂�
�R���X�g���N�^�Ȃ񂩕K�v�˂��񂾂�I�n�Q�I�I�I�I�I�I�I�I�I�I�I�I�I
��������o�^�ł����40�炵���ł�(�m�F�͂��ĂȂ�)

*����*
���܂ł�DrawString�ADrawFormatString���g���ĕ�����\�����Ă�Ǝv���܂��B
���̃n���h�����g�p����ɂ͏�L�̓z�ł͂Ȃ�
DrawStringToHandle(x,y,"����",GetColor(255,255,255),FontHandle�̕ϐ���);
�̂悤�ȋL�q�ɂȂ�܂��B

��)
int urabe;
urabe = CreateFontToHandle("�l�r �S�V�b�N",32,3);
DrawStringToHandle(0,0,"��꒬������",GetColor(255,255,255),urabe);

********************************************************************************************/

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

	//�R���X�g���N�^����񂪎g���Ȃ��̂�
	//Init�N��錾���Ă���܂�
	void Init();

	int Get_MS_GOTHIC_112_3() { return MS_GOTHIC_112_3; }
	int Get_MS_GOTHIC_64_3() { return MS_GOTHIC_64_3; }
	int Get_MS_GOTHIC_32_3() { return MS_GOTHIC_32_3; }
	int Get_MS_GOTHIC_16_3() { return MS_GOTHIC_16_3; }

	int Get_MS_MINCHO_64_3() { return MS_MINCHO_64_3; }
	int Get_MS_MINCHO_32_3() { return MS_MINCHO_32_3; }
	int Get_MS_MINCHO_16_3() { return MS_MINCHO_16_3; }
};

#endif //FONTHANDLE_H_