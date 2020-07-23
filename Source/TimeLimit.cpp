#include <DxLib.h>
#include"TimeLimit.h"

TimeLimit::TimeLimit() {
	const int MAX_LIMITTIME = 100 * 10;	// ��b * �w�肵���b��

	timer = MAX_LIMITTIME;					//�������Ԃ̃Z�b�g

	color = GetColor(255, 255, 255);

	finishTime = false;						//�������

}

void TimeLimit::Update() {
	Draw();				//�`��
	if (timer <= 0) {
		DrawFormatString(20, 40, color, "Time Up", timer);//
		finishTime = true;
	}
	else {
		CountDown();	//�J�E���g�_�E��
	}
}

void TimeLimit::Draw() {
	DrawFormatString(20, 20,color, "��������%d",timer);//�\��
} 

void TimeLimit::CountDown() {
	timer -= 1;								//�J�E���g�_�E��
}