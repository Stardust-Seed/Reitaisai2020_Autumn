#include "DarknessEvent.h"

DarknessEvent::DarknessEvent() {
	isActive = true;		//開始
	nowPhase = PHASE_START;	//開始フェーズ
	darkCount = 0;			//カウント初期化
	opacity = 0;			//透明度初期化
	darkImage = LoadGraph("./res/Image/darkness.png");	//画像格納
}

DarknessEvent::~DarknessEvent() {
	DeleteGraph(darkImage);	//画像メモリ開放
}

void DarknessEvent::Update() {

	if (nowPhase == PHASE_START && opacity <= MAX_OPACITY) {	//開始フェーズ　不透明度を上げる
		opacity += 2;	//不透明度加算
	}
	else if (nowPhase == PHASE_START && opacity >= MAX_OPACITY) {
		opacity = MAX_OPACITY;	//超過しててもここで合わせる
		nowPhase = PHASE_DARK;		//次のフェーズ
	}

	if (nowPhase == PHASE_DARK) {								//維持フェーズ
		if (darkCount <= MAX_DARKNESSTIME) {
			darkCount++;									//カウント加算
		}
		else if (darkCount > MAX_DARKNESSTIME) {
			nowPhase = PHASE_END;								//次のフェーズ
		}
	}

	if (nowPhase == PHASE_END && opacity > 0) {
		opacity -= 2;		//不透明度減算
	}
	else if (nowPhase == PHASE_END && opacity <= 0) {
		opacity = 0;		//合わせる
		isActive = false;
	}

}

void DarknessEvent::Draw() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, opacity);		//ブレンドモードを変更

	DrawGraph(0, 0, darkImage, TRUE);					//画像を描画

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);			//ブレンドモードをオフ

}