#include <DxLib.h>
#include "GameMain.h"
#include "Input.h"
#include "SE.h"
#include "BGM.h"
#include "Image.h"
#include "File.h"

GameMain::GameMain() {
	Image::Instance()->Load();
	File::Instance()->Load();
}

GameMain::~GameMain() {

}

void GameMain::Init() {
	int count = 0;					//fgetsに使う変数
	fadeCnt = 0;

	BGM::Instance()->VolumeBGM(File::Instance()->GetFileData(eFileType::Config, 0));
	SE::Instance()->VolumeSE(File::Instance()->GetFileData(eFileType::Config, 1));
	BGM::Instance()->Set_Volume(File::Instance()->GetFileData(eFileType::Config, 0));
	SE::Instance()->Set_Volume(File::Instance()->GetFileData(eFileType::Config, 1));

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