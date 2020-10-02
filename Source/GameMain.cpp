#include <DxLib.h>
#include "GameMain.h"
#include "Input.h"
#include "SE.h"
#include "BGM.h"

GameMain::GameMain() {

}

GameMain::~GameMain() {

}

void GameMain::Init() {
	FILE* fp;						//ファイルポインタ
	int savebuf[2];	//バッファから数値に変換した要素仮置きする配列変数
	char buf[256];				//バッファ
	int count = 0;					//fgetsに使う変数

	//savebufを0で初期化
	memset(savebuf, 0, sizeof(savebuf));

	//ファイルを開く
	fopen_s(&fp, "./res/File/ConfigFile.txt", "r");
	if (fp == NULL) {
		exit(EXIT_FAILURE);
	}

	//ファイルを1行ごとにsavebufに格納する
	while (fgets(buf, 256, fp) != NULL) {
		savebuf[count] = atoi(buf);
		count++;
	}

	BGM::Instance()->VolumeBGM(savebuf[0]);
	SE::Instance()->VolumeSE(savebuf[1]);
	BGM::Instance()->Set_Volume(savebuf[0]);
	SE::Instance()->Set_Volume(savebuf[1]);

	fclose(fp);
}

bool GameMain::GameLoop() {

	Input::Instance()->UpdateKey();

	sManager.Update();
	sManager.Draw();

	return true;
}