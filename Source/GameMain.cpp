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

	sManager = new SceneManager();
	parameter = new Parameter();

	gameRes.sceneManager = sManager;
	gameRes.parameter = parameter;

	//シーンを設定する
	sManager->SetScene("Title", &title);
	sManager->SetScene("Menu", &menu);
	sManager->SetScene("CharaSelect", &cSelect);
	sManager->SetScene("Option", &option);
	sManager->SetScene("OperationExp", &opExp);
	sManager->SetScene("LevelSelect", &levelSelect);
	sManager->SetScene("InGame", &inGame);
	sManager->SetScene("Clear", &gameClear);
	sManager->SetScene("GameOver", &gameOver);
	sManager->SetScene("PauseMenu", &pauseMenu);
	sManager->Init(&gameRes);
	sManager->SceneChange("Title", false, false, &gameRes);
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
	std::string nowScene = sManager->GetNowScene();

	if (nowScene == "Title" && fadeCnt != 0) {
		fadeCnt = 0;
	}

	sManager->Update(&gameRes);

	if (nowScene == "Title" || nowScene == "Menu" || nowScene == "CharaSelect" ||
		nowScene == "LevelSelect" || nowScene == "PauseMenu" ||
		nowScene == "Clear" || nowScene == "GameOver" || nowScene == "Option" ||
		nowScene == "OperationExp") {
		DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Title), TRUE);
	}

	if (nowScene == "Menu" || nowScene == "CharaSelect" ||
		nowScene == "LevelSelect" || nowScene == "PauseMenu" ||
		nowScene == "Clear" || nowScene == "GameOver" || nowScene == "Option" ||
		nowScene == "OperationExp") {
		//シーンに入った際だけフェードイン処理を行う
		if (fadeCnt != 60 + 1) {
			fadeCnt = Image::Instance()->FadeInGraph(0.0f, 0.0f,
				Image::Instance()->GetGraph(eImageType::Background_Filter), fadeCnt, 60);
		}
		else {
			DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Filter), TRUE);
		}
	}

	if (nowScene == "InGame") {
		DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Game), TRUE);
	}

	sManager->Draw(&gameRes);

	return true;
}