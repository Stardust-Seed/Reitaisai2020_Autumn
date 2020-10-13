#include <DxLib.h>
#include"TimeLimit.h"
#include "FontHandle.h"

TimeLimit::TimeLimit() {
	timer = MAX_LIMITTIME;						//制限時間のセット
	time = timer / FRAME;						//初期化

	color = GetColor(255, 255, 255);			//文字の色　白

	hundredsPlace = 0;							//初期化
	tensPlace = 0;								//初期化
	onesPlace = 0;								//初期化

	finishTime = false;							//初期状態
}

void TimeLimit::Update() {
	Draw();											//描画
	time = timer / FRAME;							//人間用タイマー更新
	if (timer <= FRAME) {								//残り一秒以下は割り算の結果0になるため
		finishTime = true;							//フラグ切替
	}
	if(timer >= 0){									//表示されているタイマーを0にしたいのでカウントダウン自体は0になるまで動かす
		CountDown();								//カウントダウン
	}
}

void TimeLimit::Draw() {
	DrawFormatStringToHandle(10, 60, color, FontHandle::Instance()->Get_natumemozi_38_8(), "TIME :%d", timer / FRAME);
	//DrawFormatStringToHandle(150, 60, color, FontHandle::Instance()->Get_natumemozi_38_8(), "100:%d", Get_hundredsPlace());
	//DrawFormatStringToHandle(250, 60, color, FontHandle::Instance()->Get_natumemozi_38_8(), "10:%d", Get_tensPlace());
	//DrawFormatStringToHandle(350, 60, color, FontHandle::Instance()->Get_natumemozi_38_8(), "1:%d", Get_onesPlace());
} 

void TimeLimit::CountDown() {
	timer -= 1;						//カウントダウン
}

int TimeLimit::Get_hundredsPlace() {
	hundredsPlace = time / 100;				
	return hundredsPlace;			//百の位
}

int TimeLimit::Get_tensPlace() {
	tensPlace = time - (Get_hundredsPlace() * 100);	//百の位を引く
	tensPlace = tensPlace / 10;				//十の位のみ
	return tensPlace;
}

int TimeLimit::Get_onesPlace() {
	onesPlace = time - (Get_hundredsPlace() * 100);	//百の位を引く
	onesPlace = onesPlace - (Get_tensPlace() * 10);//十の位を引く
	return onesPlace;
}

bool TimeLimit::Get_finishTime() {
	return finishTime;
}