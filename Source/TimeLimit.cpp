#include <DxLib.h>
#include"TimeLimit.h"
#include "FontHandle.h"

TimeLimit::TimeLimit() {
	timer = MAX_LIMITTIME;						//�������Ԃ̃Z�b�g
	time = timer / FRAME;						//������

	color = GetColor(255, 255, 255);			//�����̐F�@��

	hundredsPlace = 0;							//������
	tensPlace = 0;								//������
	onesPlace = 0;								//������

	finishTime = false;							//�������
}

void TimeLimit::Update() {
	Draw();											//�`��
	time = timer / FRAME;							//�l�ԗp�^�C�}�[�X�V
	if (timer <= FRAME) {								//�c���b�ȉ��͊���Z�̌���0�ɂȂ邽��
		finishTime = true;							//�t���O�ؑ�
	}
	if(timer >= 0){									//�\������Ă���^�C�}�[��0�ɂ������̂ŃJ�E���g�_�E�����̂�0�ɂȂ�܂œ�����
		CountDown();								//�J�E���g�_�E��
	}
}

void TimeLimit::Draw() {
	DrawFormatStringToHandle(10, 60, color, FontHandle::Instance()->Get_natumemozi_38_8(), "TIME :%d", timer / FRAME);
	//DrawFormatStringToHandle(150, 60, color, FontHandle::Instance()->Get_natumemozi_38_8(), "100:%d", Get_hundredsPlace());
	//DrawFormatStringToHandle(250, 60, color, FontHandle::Instance()->Get_natumemozi_38_8(), "10:%d", Get_tensPlace());
	//DrawFormatStringToHandle(350, 60, color, FontHandle::Instance()->Get_natumemozi_38_8(), "1:%d", Get_onesPlace());
} 

void TimeLimit::CountDown() {
	timer -= 1;						//�J�E���g�_�E��
}

int TimeLimit::Get_hundredsPlace() {
	hundredsPlace = time / 100;				
	return hundredsPlace;			//�S�̈�
}

int TimeLimit::Get_tensPlace() {
	tensPlace = time - (Get_hundredsPlace() * 100);	//�S�̈ʂ�����
	tensPlace = tensPlace / 10;				//�\�̈ʂ̂�
	return tensPlace;
}

int TimeLimit::Get_onesPlace() {
	onesPlace = time - (Get_hundredsPlace() * 100);	//�S�̈ʂ�����
	onesPlace = onesPlace - (Get_tensPlace() * 10);//�\�̈ʂ�����
	return onesPlace;
}

bool TimeLimit::Get_finishTime() {
	return finishTime;
}