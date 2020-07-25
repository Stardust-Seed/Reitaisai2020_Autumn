#include <DxLib.h>
#include"TimeLimit.h"

TimeLimit::TimeLimit() {
	timer = MAX_LIMITTIME;						//制限時間のセット

	color = GetColor(255, 255, 255);			//文字の色　白

	finishTime = false;							//初期状態
}

void TimeLimit::Update() {
	Draw();											//描画
	if (timer <= 100) {								//残り一秒以下は0になるため、表示タイミングの調整
		DrawFormatString(20, 40, color, "Time Up");	//タイムアップの文字表示
		finishTime = true;							//フラグ切替
	}
	if(timer >= 0){									//表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
		CountDown();								//カウントダウン
	}
}

void TimeLimit::Draw() {
	DrawFormatString(20, 20,color, "制限時間%d",timer/100);	//表示
} 

void TimeLimit::CountDown() {
	timer -= 1;												//カウントダウン
}