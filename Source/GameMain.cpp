#include <DxLib.h>
#include "GameMain.h"
#include "Input.h"
#include "SE.h"
#include "BGM.h"
#include "Image.h"

GameMain::GameMain() {
	Image::Instance()->Load();
}

GameMain::~GameMain() {

}

void GameMain::Init() {
	FILE* fp;						//ファイルポインタ
	int savebuf[2];	//バッファから数値に変換した要素仮置きする配列変数
	char buf[256];				//バッファ
	int count = 0;					//fgetsに使う変数
	fadeCnt = 0;

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
	nowScene = sManager.GetNowScene();

	if (nowScene == eScene_TITLE && fadeCnt != 0) {
		fadeCnt = 0;
	}

	sManager.Update();

	if (nowScene == eScene_TITLE || nowScene == eScene_MENU || nowScene == eScene_CHARASELECT ||
		nowScene == eScene_LEVELSELECT || nowScene == eScene_PAUSEMENU ||
		nowScene == eScene_CLAER || nowScene == eScene_GAMEOVER || nowScene == eScene_OPTION) {
		DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Title), TRUE);
	}

	if (nowScene == eScene_MENU || nowScene == eScene_CHARASELECT ||
		nowScene == eScene_LEVELSELECT || nowScene == eScene_PAUSEMENU ||
		nowScene == eScene_CLAER || nowScene == eScene_GAMEOVER || nowScene == eScene_OPTION) {
		//シーンに入った際だけフェードイン処理を行う
		if (fadeCnt != 60 + 1) {
			fadeCnt = Image::Instance()->FadeInGraph(0.0f, 0.0f,
				Image::Instance()->GetGraph(eImageType::Background_Filter), fadeCnt, 60);
		}
		else {
			DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Filter), TRUE);
		}
	}

	if (nowScene == eScene_GAME) {
		DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Game), TRUE);
	}

	sManager.Draw();

	return true;
}