#include <DxLib.h>
#include"TimeLimit.h"
#include "FontHandle.h"

TimeLimit::TimeLimit() {
	timer = MAX_LIMITTIME;						//制限時間のセット

	color = GetColor(255, 255, 255);			//文字の色　白

	finishTime = false;							//初期状態
}

void TimeLimit::Update() {
	Draw();											//描画
	if (timer <= FRAME) {								//残り一秒以下は割り算の結果0になるため
		finishTime = true;							//フラグ切替
	}
	if(timer >= 0){									//表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
		CountDown();								//カウントダウン
	}
}

void TimeLimit::Draw() {
	//DrawFormatString(10, 60,color, "制限時間%d",timer/FRAME);	//表示
	DrawFormatStringToHandle(10, 60, color, FontHandle::Instance()->Get_natumemozi_38_8(), "TIME :%d", timer / FRAME);
} 

void TimeLimit::CountDown() {
	timer -= 1;												//カウントダウン
}

bool TimeLimit::Get_finishTime() {
	return finishTime;
}