#include <DxLib.h>
#include"TimeLimit.h"

TimeLimit::TimeLimit() {
	const int MAX_LIMITTIME = 100 * 10;	// 一秒 * 指定した秒数

	timer = MAX_LIMITTIME;					//制限時間のセット

	color = GetColor(255, 255, 255);

	finishTime = false;						//初期状態

}

void TimeLimit::Update() {
	Draw();				//描画
	if (timer <= 0) {
		DrawFormatString(20, 40, color, "Time Up", timer);//
		finishTime = true;
	}
	else {
		CountDown();	//カウントダウン
	}
}

void TimeLimit::Draw() {
	DrawFormatString(20, 20,color, "制限時間%d",timer);//表示
} 

void TimeLimit::CountDown() {
	timer -= 1;								//カウントダウン
}