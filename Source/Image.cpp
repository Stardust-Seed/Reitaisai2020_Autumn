#include <DxLib.h>
#include "Image.h"

Image::Image() {
	//�摜�̓ǂݍ���
	MyLoadGraph("./res/Image/title_rogo.png");
	MyLoadGraph("./res/Image/darkness.png");
	MyLoadGraph("./res/Image/koumakan.png");

	//�摜�𕪊����ēǂݍ���
	MyLoadDivGraph("./res/Image/tatie_Sakuya.png", 3, 3, 1, 486, 864);
	MyLoadDivGraph("./res/Image/tatie_Fran.png", 3, 3, 1, 486, 864);
	MyLoadDivGraph("./res/Image/player.png", 4, 2, 2, 48, 48);
	MyLoadDivGraph("./res/Image/enemy.png", 6, 2, 3, 48, 48);
	MyLoadDivGraph("./res/Image/SubCastle.png", 2, 2, 1, 55, 55);
	MyLoadDivGraph("./res/Image/sukima.png", 4, 4, 1, 48, 48);
	MyLoadDivGraph("./res/Image/ex.png", 6, 6, 1, 100, 100);
}

void Image::Release() {
	//�ǂݍ��񂾉摜���N���A����
	for (auto release : images) {
		DeleteGraph(release);
	}
	images.clear();
}

int Image::GetGraph(eImageType _imageType, int _num) {
	//�w�肳�ꂽ�摜���Ăяo��
	return images[static_cast<int>(_imageType) + _num];
}

void Image::MyLoadGraph(const char* _filePath) {
	//DX���C�u�����̋@�\�ŉ摜��ǂݍ���
	int tmp = LoadGraph(_filePath);

	//�摜��images�ɉ�����
	images.push_back(tmp);
}

void Image::MyLoadDivGraph(const char* _filePath, int _allNum, int _xNum, int _yNum,
	int _xSize, int _ySize) {
	int tmp[100];	//�摜�o�b�t�@

	//�o�b�t�@��������
	memset(tmp, 0, sizeof(tmp) / sizeof(int));

	//DX���C�u�����̋@�\�ŉ摜�𕪊����ăo�b�t�@�ɓǂݍ���
	LoadDivGraph(_filePath, _allNum, _xNum, _yNum, _xSize, _ySize, tmp);

	//�摜��images�ɉ�����
	for (int i = 0; i < _allNum; i++) {
		images.push_back(tmp[i]);
	}
}

void Image::TransparentGraph(float _x, float _y, int _gHandle, int _pal,
	bool _isTurn, int _transFlag) {
	//�`�惂�[�h ���u�����h���Z�b�g����
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, _pal);

	//���]�`��t���O��true�̂Ƃ����]�`��������Ȃ�
	if (_isTurn == true) {
		DrawTurnGraphF(_x, _y, _gHandle, _transFlag);
	}
	//else�̏ꍇ�ʏ�`��������Ȃ�
	else {
		DrawGraphF(_x, _y, _gHandle, _transFlag);
	}

	//�`�惂�[�h �m�[�u�����h���Z�b�g����
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

int Image::FadeOutGraph(float _x, float _y, int _gHandle, int _fadeCnt, int _fadeMaxCnt,
	bool _isTurn, int _transFlag) {

	//�ő�J�E���g��蒴����ꍇ�����͍s���Ȃ�
	if (_fadeCnt > _fadeMaxCnt) {
		return _fadeCnt;
	}

	//�t�F�C�h�J�E���g�����Z���遦1�`n+1�͈̔͂ɂ��邽��
	_fadeCnt++;

	//�`�惂�[�h ���u�����h���Z�b�g����
	//�p�����[�^�̒l�̌v�Z�� : �ő� - ���݂̃J�E���g * (�ő� / �ő�J�E���g + 1);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - _fadeCnt * (255 / (_fadeMaxCnt + 1)));

	//���]�`��t���O��true�̂Ƃ����]�`��������Ȃ�
	if (_isTurn == true) {
		DrawTurnGraphF(_x, _y, _gHandle, _transFlag);
	}
	//else�̏ꍇ�ʏ�`��������Ȃ�
	else {
		DrawGraphF(_x, _y, _gHandle, _transFlag);
	}

	//�`�惂�[�h �m�[�u�����h���Z�b�g����
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//���̃J�E���g��Ԃ�
	return _fadeCnt;
}