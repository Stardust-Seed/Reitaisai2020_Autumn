#ifndef KURONEKO_KURONEKOLIB_H
#define KURONEKO_KURONEKOLIB_H

#include <string>
#include "Cursor.h"

using namespace std;

//�`��^�C�v
enum class eDrawType {
	Front,	//��
	Center,	//����
	Back	//�E
};

/// <summary>
/// UI�摜��`�悷��
/// </summary>
/// <param name="_x">x���W</param>
/// <param name="_y">y���W</param>
/// <param name="_width">����</param>
/// <param name="_height">����</param>
/// <param name="_extX">�g�嗦x</param>
/// <param name="_extY">�g�嗦y</param>
/// <param name="_angle">��](��)</param>
/// <param name="_pal">�u�����h���[�h�̃p�����[�^</param>
/// <param name="_color">�F</param>
/// <param name="_cursor">�J�[�\��</param>
/// <param name="_drawType">�`��^�C�v</param>
/// <param name="_font">�t�H���g</param>
/// <param name="_fontSize">�t�H���g�̃T�C�Y</param>
/// <param name="_text">�\������e�L�X�g</param>
/// <returns></returns>
int DrawUIGraph(float _x, float _y, float _width, float _height, double _extX, double _extY,
	float _angle, int _pal, unsigned int _color, int _cursor,eDrawType _drawType,
	int _font, int _fontSize, string _text);

#endif // !KURONEKO_KURONEKOLIB_H