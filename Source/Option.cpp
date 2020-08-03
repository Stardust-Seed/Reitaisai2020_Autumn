#include <DxLib.h>
#include "Input.h"
#include "Option.h"

const float Option::BGMBAR_WIDTH = 76.9f;
const float Option::BGMBAR_HEIGHT = 17.9f;
const float Option::BGMBAR_INTERVAL = 5.0f;
const int Option::BGM_MAXVOLUME = 10;

const float Option::SEBAR_WIDTH = 76.9f;
const float Option::SEBAR_HEIGHT = 17.9f;
const float Option::SEBAR_INTERVAL = 5.0f;
const int Option::SE_MAXVOLUME = 10;

const float Option::SELECTBAR_X1 = 105.0f;
const float Option::SELECTBAR_X2 = 195.0f;
const float Option::SELECTBAR_YBGM = 120.0f;
const float Option::SELECTBAR_YSE = 454.0f;

const float Option::UIAREA_X1 = 100.0f;
const float Option::UIAREA_X2 = 924.0f;
const float Option::UIAREA_Y1BGM = 100.0f;
const float Option::UIAREA_Y2BGM = 334.0f;
const float Option::UIAREA_Y1SE = 434.0f;
const float Option::UIAREA_Y2SE = 668.0f;

const int Option::STRING_XBGM = 105;
const int Option::STRING_YBGM = 105;
const int Option::STRING_XSE = 105;
const int Option::STRING_YSE = 439;

Option::Option() {
	bgmVolume = 5;
	seVolume = 5;

	selectType = select_BGM;
}

void Option::Update() {
	//変更項目の変更処理
	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1) {
		if (selectType == select_BGM) {
			selectType = select_SE;
			return;
		}

		if (selectType == select_SE) {
			selectType = select_BGM;
		}
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1) {
		if (selectType == select_BGM) {
			selectType = select_SE;
			return;
		}

		if (selectType == select_SE) {
			selectType = select_BGM;
		}
	}

	//ボリュームの設定処理
	if (Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1) {
		//BGM音量を上昇
		if (selectType == select_BGM) {
			if (bgmVolume >= BGM_MAXVOLUME) {
				return;
			}
			bgmVolume++;
		}
		//SE音量を上昇
		if (selectType == select_SE) {
			if (seVolume >= SE_MAXVOLUME) {
				return;
			}
			seVolume++;
		}
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1) {
		//BGM音量を減少
		if (selectType == select_BGM) {
			if (bgmVolume <= 0) {
				return;
			}
			bgmVolume--;
		}
		//SE音量を減少
		if (selectType == select_SE) {
			if (seVolume <= 0) {
				return;
			}
			seVolume--;
		}
	}
}

void Option::Draw() {
	//BGM関連のUIの表示
	DrawBoxAA(UIAREA_X1, UIAREA_Y1BGM, UIAREA_X2, UIAREA_Y2BGM, GetColor(255, 255, 255), TRUE);
	DrawString(STRING_XBGM, STRING_YBGM, "BGM Volume", GetColor(0, 0, 0));

	for (int i = 0; i < bgmVolume; i++) {
		DrawBoxAA(100 + (i * BGMBAR_WIDTH) + ((i + 1) * BGMBAR_INTERVAL), 329, (100 + BGMBAR_WIDTH) + (i * BGMBAR_WIDTH) + ((i + 1) * BGMBAR_INTERVAL),
			329 - BGMBAR_HEIGHT - (BGMBAR_HEIGHT * i), GetColor(0, 0, 0), TRUE);
	}

	DrawBoxAA(UIAREA_X1, UIAREA_Y1SE, UIAREA_X2, UIAREA_Y2SE, GetColor(255, 255, 255), TRUE);
	DrawString(STRING_XSE, STRING_YSE, "SE Volume", GetColor(0, 0, 0));

	for (int i = 0; i < seVolume; i++) {
		DrawBoxAA(100 + (i * SEBAR_WIDTH) + ((i + 1) * SEBAR_INTERVAL), 663, (100 + SEBAR_WIDTH) + (i * SEBAR_WIDTH) + ((i + 1) * SEBAR_INTERVAL),
			663 - SEBAR_HEIGHT - (SEBAR_HEIGHT * i), GetColor(0, 0, 0), TRUE);
	}

	//選択してる項目のUIの表示
	if (selectType == select_BGM) {
		DrawLineAA(SELECTBAR_X1, SELECTBAR_YBGM, SELECTBAR_X2, SELECTBAR_YBGM, GetColor(0, 0, 0));
	}

	if (selectType == select_SE) {
		DrawLineAA(SELECTBAR_X1, SELECTBAR_YSE, SELECTBAR_X2, SELECTBAR_YSE, GetColor(0, 0, 0));
	}
}