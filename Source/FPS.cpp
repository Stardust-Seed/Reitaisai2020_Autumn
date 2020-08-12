#include <DxLib.h>
#include "FPS.h"

FPS::FPS() {
	mStartTime = 0;
	mCount = 0;
	mFps = 0;
}

void FPS::Update() {
	if (mCount == 0) { //1フレーム目なら時刻を記憶
		mStartTime = GetNowCount();
	}
	if (mCount == N) { //60フレーム目なら平均を計算する
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;

		return;
	}
	mCount++;
}

void FPS::Wait() {
	int tookTime = GetNowCount() - mStartTime;	//かかった時間
	int waitTime = mCount * 1000 / AVG_FPS - tookTime;	//待つべき時間
	if (waitTime > 0) {
		Sleep(waitTime);	//待機
	}
}

void FPS::Draw() {
	DrawFormatString(1024-75, 768-15, GetColor(255, 255, 255), "FPS:%.1f", mFps);
}