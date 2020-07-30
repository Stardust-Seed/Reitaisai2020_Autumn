#include <DxLib.h>
#include "Option.h"

const float Option::BGMBAR_WIDTH = 76.9f;
const float Option::BGMBAR_HEIGHT = 17.9f;
const float Option::BGMBAR_INTERVAL = 5.0f;
const int Option::BGMBAR_MAXNUM = 10;

const float Option::SEBAR_WIDTH = 76.9f;
const float Option::SEBAR_HEIGHT = 17.9f;
const float Option::SEBAR_INTERVAL = 5.0f;
const int Option::SEBAR_MAXNUM = 10;

Option::Option() {

}

void Option::Update() {

}

void Option::Draw() {
	DrawBoxAA(100, 100, 1024 - 100, (768 / 2) - 50, GetColor(255, 255, 255), TRUE);
	DrawString(105, 105, "BGM Volume", GetColor(0, 0, 0));

	for (int i = 0; i < BGMBAR_MAXNUM; i++) {
		DrawBoxAA(100 + (i * BGMBAR_WIDTH) + ((i + 1) * BGMBAR_INTERVAL), 329, (100 + BGMBAR_WIDTH) + (i * BGMBAR_WIDTH) + ((i + 1) * BGMBAR_INTERVAL),
			329 - BGMBAR_HEIGHT - (BGMBAR_HEIGHT * i), GetColor(0, 0, 0), TRUE);
	}

	DrawBoxAA(100, (768 / 2 + 50), 1024 - 100, 768 - 100, GetColor(255, 255, 255), TRUE);
	DrawString(105, (768 / 2 + 50) + 5, "SE Volume", GetColor(0, 0, 0));

	for (int i = 0; i < SEBAR_MAXNUM; i++) {
		DrawBoxAA(100 + (i * SEBAR_WIDTH) + ((i + 1) * SEBAR_INTERVAL), 663, (100 + SEBAR_WIDTH) + (i * SEBAR_WIDTH) + ((i + 1) * SEBAR_INTERVAL),
			663 - SEBAR_HEIGHT - (SEBAR_HEIGHT * i), GetColor(0, 0, 0), TRUE);
	}
}