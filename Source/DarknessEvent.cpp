#include "DarknessEvent.h"

DarknessEvent::DarknessEvent() {
	isActive = true;		//�J�n
	nowPhase = PHASE_START;	//�J�n�t�F�[�Y
	darkCount = 0;			//�J�E���g������
	opacity = 0;			//�����x������
	darkImage = LoadGraph("./res/Image/darkness.png");	//�摜�i�[
}

DarknessEvent::~DarknessEvent() {
	DeleteGraph(darkImage);	//�摜�������J��
}

void DarknessEvent::Update() {

	if (nowPhase == PHASE_START && opacity <= MAX_OPACITY) {	//�J�n�t�F�[�Y�@�s�����x���グ��
		opacity += 2;	//�s�����x���Z
	}
	else if (nowPhase == PHASE_START && opacity >= MAX_OPACITY) {
		opacity = MAX_OPACITY;	//���߂��ĂĂ������ō��킹��
		nowPhase = PHASE_DARK;		//���̃t�F�[�Y
	}

	if (nowPhase == PHASE_DARK) {								//�ێ��t�F�[�Y
		if (darkCount <= MAX_DARKNESSTIME) {
			darkCount++;									//�J�E���g���Z
		}
		else if (darkCount > MAX_DARKNESSTIME) {
			nowPhase = PHASE_END;								//���̃t�F�[�Y
		}
	}

	if (nowPhase == PHASE_END && opacity > 0) {
		opacity -= 2;		//�s�����x���Z
	}
	else if (nowPhase == PHASE_END && opacity <= 0) {
		opacity = 0;		//���킹��
		isActive = false;
	}

}

void DarknessEvent::Draw() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, opacity);		//�u�����h���[�h��ύX

	DrawGraph(0, 0, darkImage, TRUE);					//�摜��`��

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);			//�u�����h���[�h���I�t

}