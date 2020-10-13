#include <DxLib.h>
#include "FPS.h"

FPS::FPS() {
	mStartTime = 0;
	mCount = 0;
	mFps = 0;
}

void FPS::Update() {
	if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}
	if (mCount == N) { //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;

		return;
	}
	mCount++;
}

void FPS::Wait() {
	int tookTime = GetNowCount() - mStartTime;	//������������
	int waitTime = mCount * 1000 / AVG_FPS - tookTime;	//�҂ׂ�����
	if (waitTime > 0) {
		Sleep(waitTime);	//�ҋ@
	}
}

void FPS::Draw() {
	DrawFormatString(1024-75, 768-15, GetColor(255, 255, 255), "FPS:%.1f", mFps);
}