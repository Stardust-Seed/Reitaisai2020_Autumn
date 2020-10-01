#include <DxLib.h>
#include "LevelSelect.h"

#include "BGM.h"
#include "FontHandle.h"
#include "KuronekoLib.h"
#include "Image.h"
#include "Input.h"
#include "SE.h"

LevelSelect::LevelSelect(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	//初期化処理
	selectLevel = eLevelType::Easy;

	//UIフレームの色を初期設定
	cursor[static_cast<int>(eLevelType::Easy)] = Cursor::Cursor_2;
	cursor[static_cast<int>(eLevelType::Normal)] = Cursor::Cursor_0;
	cursor[static_cast<int>(eLevelType::Hard)] = Cursor::Cursor_0;

	//切り替えるフラグを初期化
	isChange = false;
}

void LevelSelect::Update() {

	//選択された項目に色を付けて、それ以外は灰色に設定する
	if (isChange == true) {
		switch (selectLevel) {
		case eLevelType::Easy:
			cursor[static_cast<int>(eLevelType::Easy)] = Cursor::Cursor_2;
			cursor[static_cast<int>(eLevelType::Normal)] = Cursor::Cursor_0;
			cursor[static_cast<int>(eLevelType::Hard)] = Cursor::Cursor_0;
			break;
		case eLevelType::Normal:
			cursor[static_cast<int>(eLevelType::Easy)] = Cursor::Cursor_0;
			cursor[static_cast<int>(eLevelType::Normal)] = Cursor::Cursor_3;
			cursor[static_cast<int>(eLevelType::Hard)] = Cursor::Cursor_0;
			break;
		case eLevelType::Hard:
			cursor[static_cast<int>(eLevelType::Easy)] = Cursor::Cursor_0;
			cursor[static_cast<int>(eLevelType::Normal)] = Cursor::Cursor_0;
			cursor[static_cast<int>(eLevelType::Hard)] = Cursor::Cursor_1;
			break;
		}

		//切り替えフラグをfalseにする
		isChange = false;
	}

	//↓キーが押されたとき
	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) % 16 == 1 &&
		Input::Instance()->GetPressCount(KEY_INPUT_UP) == 0) {
		ChangeLevel(CURSOR_DOWN);
	}

	//↑キーが押されたとき
	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) % 16 == 1 &&
		Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 0) {
		ChangeLevel(CURSOR_UP);
	}

	//zキーが押されたとき
	if (Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1) {
		//選択されたレベルに従ってパラメータに数値をセット
		switch (selectLevel) {
		case eLevelType::Easy:
			parameter->Set(BaseScene::LevelSelectTag, 0);
			break;
		case eLevelType::Normal:
			parameter->Set(BaseScene::LevelSelectTag, 1);
			break;
		case eLevelType::Hard:
			parameter->Set(BaseScene::LevelSelectTag, 2);
			break;
		}

		//メニューのBGMを止める
		BGM::Instance()->StopBGM(BGM_menu);

		//シーンをゲームシーンに切り替える
		sceneChanger->SceneChange(eScene_GAME, parameter, false, false);
	}

	//xキーが押されたとき
	if (Input::Instance()->GetPressCount(KEY_INPUT_X) == 1) {
		sceneChanger->SceneChange(eScene_CHARASELECT, parameter, true, false);
	}
}

//描画処理
void LevelSelect::Draw() {
/*------------------------------------------------------------------------------
背景の描画
------------------------------------------------------------------------------*/
	DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Title), TRUE);
	DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Filter), TRUE);
/*------------------------------------------------------------------------------
UIの描画
------------------------------------------------------------------------------*/
	//Easy
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eLevelType::Easy)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT, UI_EXT, 0, UI_PAL, GetColor(255, 255, 255),
		static_cast<int>(cursor[static_cast<int>(eLevelType::Easy)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "Easy");

	//Normal
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eLevelType::Normal)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT, UI_EXT, 0, UI_PAL, GetColor(255, 255, 255),
		static_cast<int>(cursor[static_cast<int>(eLevelType::Normal)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "Normal");

	//Hard
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eLevelType::Hard)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT, UI_EXT, 0, UI_PAL, GetColor(255, 255, 255),
		static_cast<int>(cursor[static_cast<int>(eLevelType::Hard)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "Hard");
}

void LevelSelect::ChangeLevel(int _changeMode) {
	//SEを鳴らす
	SE::Instance()->PlaySE(SE_cursor);

	//切り替えフラグをtrueにする
	isChange = true;

	//切り替えモードがDOWNの場合
	if (_changeMode == CURSOR_DOWN) {
		//一番下の項目のとき、一番上の項目へ
		if (selectLevel == eLevelType::Hard) {
			selectLevel = eLevelType::Easy;
		}
		//上記条件外のとき、一つ下の項目へ
		else {
			selectLevel = static_cast<eLevelType>(static_cast<int>(selectLevel) + 1);
		}
	}
	//切り替えモードがUPの場合
	else if (_changeMode == CURSOR_UP) {
		//一番上の項目のとき、一番下の項目へ
		if (selectLevel == eLevelType::Easy) {
			selectLevel = eLevelType::Hard;
		}
		//上記条件外のとき、一つ上の項目へ
		else {
			selectLevel = static_cast<eLevelType>(static_cast<int>(selectLevel) - 1);
		}
	}
}