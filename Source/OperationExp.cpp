#include <DxLib.h>
#include "OperationExp.h"

#include "Define.h"
#include "FontHandle.h"
#include "Input.h"
#include "SE.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="_sceneChanger">�V�[���؂�ւ��N���X</param>
/// <param name="_parameter">�p�����[�^</param>
OperationExp::OperationExp(ISceneChanger* _sceneChanger, Parameter* _parameter) :
	BaseScene(_sceneChanger, _parameter) {

}

/// <summary>
/// �X�V����
/// </summary>
void OperationExp::Update() {
	//x�L�[�����͂��ꂽ�Ƃ�
	if (Input::Instance()->GetPressCount(KEY_INPUT_X) == 1) {
		//�L�����Z��SE��炷
		SE::Instance()->PlaySE(SE_Cancel);

		//���j���[�V�[���ɖ߂�
		sceneChanger->SceneChange(eScene_MENU, parameter, false, true);
	}
}

/// <summary>
/// �`�揈��
/// </summary>
void OperationExp::Draw() {
	//������`�悷��̈�̕`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 / 2);
	DrawBoxAA(100, 100, GAME_WIDTH - 100, GAME_HEIHGT - 100, GetColor(255, 255, 255), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//�����������
	DrawStringToHandle(100, 100, text[0], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_100_3());

	//�E�ړ� / �J�[�\���ړ�
	DrawStringToHandle(100, 200, text[1], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_64_8());

	//�E�U�� / ����
	DrawStringToHandle(100, 456, text[6], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_64_8());

	//�E�L�����X�L�� / �߂�
	DrawStringToHandle(100, 520, text[8], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_64_8());

	//�E�|�[�Y���j���[(�Q�[����)
	DrawStringToHandle(100, 584, text[10], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_64_8());

	//�ړ� / �J�[�\���ړ��̃L�[��`��
	for (int i = 2; i <= 5; i++) {
		DrawStringToHandle(1000, 200 + ((i - 2) * 64), text[i], GetColor(0, 0, 0),
			FontHandle::Instance()->Get_natumemozi_64_8());
	}

	//�U�� / ����̃L�[��`��
	DrawStringToHandle(1000, 456, text[7], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_64_8());

	//�L�����X�L�� / �߂�̃L�[��`��
	DrawStringToHandle(1000, 520, text[9], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_64_8());

	//�|�[�Y���j���[�̃L�[��`��
	DrawStringToHandle(1000, 584, text[11], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_64_8());
}