#include <DxLib.h>
#include "KuronekoLib.h"

#include "Define.h"
#include "Image.h"

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
	float _angle, int _pal, unsigned int _color, int _cursor, eDrawType _drawType,
	int _font, int _fontSize, string _text) {
	int textSize;				//�e�L�X�g�T�C�Y
	int textMiddleSize;			//�e�L�X�g�̔����̐��l
	bool isOdd = false;			//��t���O
	bool isHalfSize = false;	//���p�t���O

	int textX;							//�\�����镶����x���W
	int textY = _y - (_fontSize / 2);	//�\�����镶����y���W

	/*
	�S�p���菈��
	�S�p�̏ꍇ _text�̔������i�[���� ���S�p��2�o�C�g�̈�
	���p�̏ꍇ _text���i�[����
	*/
	if (IsDBCSLeadByte(_text[0]) == 0) {
		//�e�L�X�g�T�C�Y���i�[����
		textSize = _text.size();
		isHalfSize = true;
	}
	else {
		//�e�L�X�g�T�C�Y���i�[����
		textSize = _text.size() / 2;
	}

	//�e�L�X�g�̔����̐��l���i�[����
	textMiddleSize = textSize / 2;

	//�e�L�X�g�T�C�Y����̏ꍇ��t���O��true�ɐ؂�ւ���
	if (textSize % 2 != 0) {
		isOdd = true;
	}

	if (isHalfSize == true) {
		//��̏ꍇ
		if (isOdd == true) {
			textX = _x - (((_fontSize / 2) * textMiddleSize) + (_fontSize / 4));
		}
		//�����̏ꍇ
		else {
			textX = _x - ((_fontSize / 2) * textMiddleSize);
		}
	}
	else {
		//��̏ꍇ
		if (isOdd == true) {
			textX = _x - ((_fontSize * textMiddleSize) + (_fontSize / 2));
		}
		//�����̏ꍇ
		else {
			textX = _x - (_fontSize * textMiddleSize);
		}
	}

	//���W��␳
	if (_drawType == eDrawType::Front) {
		_x += ((_width / 2) * _extX);
		_y += ((_height / 2) * _extY);
	}

	//�u�����h���[�h���A���t�@�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);

	//UI�t���[���̕`��
	DrawRotaGraph3F(_x, _y, _width / 2, _height / 2, _extX, _extY, (_angle * PAI) / 180,
		Image::Instance()->GetGraph(eImageType::UI_CursorFrame, _cursor), TRUE);

	//�e�̕`��
	DrawStringToHandle(textX, textY + 2, _text.c_str(), GetColor(0, 0, 0), _font);

	//�����̕`��
	DrawStringToHandle(textX, textY, _text.c_str(), _color, _font);

	//�u�����h���[�h���m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	return 0;
}