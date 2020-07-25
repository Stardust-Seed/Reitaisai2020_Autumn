#include <DxLib.h>
#include"TimeLimit.h"

TimeLimit::TimeLimit() {
	timer = MAX_LIMITTIME;						//�������Ԃ̃Z�b�g

	color = GetColor(255, 255, 255);			//�����̐F�@��

	finishTime = false;							//�������
}

void TimeLimit::Update() {
	Draw();											//�`��
	if (timer <= 100) {								//�c���b�ȉ���0�ɂȂ邽�߁A�\���^�C�~���O�̒���
		DrawFormatString(20, 40, color, "Time Up");	//�^�C���A�b�v�̕����\��
		finishTime = true;							//�t���O�ؑ�
	}
	if(timer >= 0){									//�\������Ă���^�C�}�[��0�ɂ������̂ŃJ�E���g�_�E�����̂�0�ɂȂ�܂œ�����
		CountDown();								//�J�E���g�_�E��
	}
}

void TimeLimit::Draw() {
	DrawFormatString(20, 20,color, "��������%d",timer/100);	//�\��
} 

void TimeLimit::CountDown() {
	timer -= 1;												//�J�E���g�_�E��
}