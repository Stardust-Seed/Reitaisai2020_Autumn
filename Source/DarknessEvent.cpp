#include "DarknessEvent.h"
#include "Image.h"
#include "SE.h"

DarknessEvent::DarknessEvent() {
	isActive = true;		//�J�n
	nowPhase = PHASE_START;	//�J�n�t�F�[�Y
	darkCount = 0;			//�J�E���g������
	opacity = 0;			//�����x������
}

DarknessEvent::~DarknessEvent() {

}

void DarknessEvent::Update() {

	if (nowPhase == PHASE_START && opacity <= MAX_OPACITY) {	//�J�n�t�F�[�Y�@�s�����x���グ��
		if (opacity == 0) {
			SE::Instance()->PlaySE(SE_DarknessStart);
		}
		opacity += 2;	//�s�����x���Z
	}
	else if (nowPhase == PHASE_START && opacity >= MAX_OPACITY) {
		opacity = MAX_OPACITY;	//���߂��ĂĂ������ō��킹��
		nowPhase = PHASE_DARK;		//���̃t�F�[�Y
	}

	if (nowPhase == PHASE_DARK) {								//�ێ��t�F�[�Y
		if (darkCount <= MAX_DARKNESSTIME) {
			darkCount++;									//�J�E���g���Z

			if (darkCount == MAX_DARKNESSTIME - FRAME) {	//�ێ��t�F�[�Y�I����b�O��SE����悤��(SE�̃^�C�~���O����)
				SE::Instance()->PlaySE(SE_DarknessEnd);
			}
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

	DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Event_Darkness), TRUE);		//�摜��`��

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);			//�u�����h���[�h���I�t

}