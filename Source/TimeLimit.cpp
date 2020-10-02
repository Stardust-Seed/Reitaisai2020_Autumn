#include <DxLib.h>
#include"TimeLimit.h"
#include "FontHandle.h"

TimeLimit::TimeLimit() {
	timer = MAX_LIMITTIME;						//�������Ԃ̃Z�b�g

	color = GetColor(255, 255, 255);			//�����̐F�@��

	finishTime = false;							//�������
}

void TimeLimit::Update() {
	Draw();											//�`��
	if (timer <= FRAME) {								//�c���b�ȉ��͊���Z�̌���0�ɂȂ邽��
		finishTime = true;							//�t���O�ؑ�
	}
	if(timer >= 0){									//�\������Ă���^�C�}�[��0�ɂ������̂ŃJ�E���g�_�E�����̂�0�ɂȂ�܂œ�����
		CountDown();								//�J�E���g�_�E��
	}
}

void TimeLimit::Draw() {
	//DrawFormatString(10, 60,color, "��������%d",timer/FRAME);	//�\��
	DrawFormatStringToHandle(10, 60, color, FontHandle::Instance()->Get_natumemozi_38_8(), "TIME :%d", timer / FRAME);
} 

void TimeLimit::CountDown() {
	timer -= 1;												//�J�E���g�_�E��
}

bool TimeLimit::Get_finishTime() {
	return finishTime;
}