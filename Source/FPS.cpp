#include <DxLib.h>
#include "FPS.h"

/*******************************************************************************
参考サイト→https://dixq.net/s/2.html
*******************************************************************************/

FPS::FPS() {
    fpsTime_i = 0;
    nowFps = 0;
    refreshTime = 0;
    memset(fpsTime, 0, sizeof(fpsTime));
}

void FPS::Update() {
    if (fpsTime_i == 0) {
        fpsTime[0] = GetNowCount();
    }

    if (fpsTime_i == 59) {
        fpsTime[1] = GetNowCount();
        nowFps = 1000.0f / ((fpsTime[1] - fpsTime[0]) / 60.0f);
        fpsTime_i = 0;
    }
    else {
        fpsTime_i++;
    }

    if (nowFps != 0)return;
}

void FPS::Draw()const {
    DrawFormatString(0, 25, GetColor(255, 255, 255), "FPS:%.1f", nowFps);
}

void FPS::Wait() {
    refreshTime = GetNowCount();

    while (static_cast<float>(GetNowCount() - refreshTime) < 16.7f);
}