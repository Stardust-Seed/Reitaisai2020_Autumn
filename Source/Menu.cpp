#include <DxLib.h>
#include "BGM.h"

#include "FontHandle.h"
#include "KuronekoLib.h"
#include "Image.h"
#include "Input.h"
#include "Menu.h"
#include "SE.h"
#include "SceneManager.h"

//コンストラクタ
Menu::Menu() {

}

//初期化処理
void Menu::Init(GameResource* _gameRes) {
	//BGMを再生する
	BGM::Instance()->PlayBGM(BGM_menu, DX_PLAYTYPE_LOOP);

	//初期選択をプレイに設定
	selectMenu = eMenuType::Game;

	//UIフレームの色を初期設定
	cursor[static_cast<int>(eMenuType::Game)] = Cursor::Cursor_3;
	cursor[static_cast<int>(eMenuType::Option)] = Cursor::Cursor_0;
	cursor[static_cast<int>(eMenuType::OperationExp)] = Cursor::Cursor_0;
	cursor[static_cast<int>(eMenuType::Title)] = Cursor::Cursor_0;
	cursor[static_cast<int>(eMenuType::GameExit)] = Cursor::Cursor_0;

	//文字の色を初期設定
	color[static_cast<int>(eMenuType::Game)] = GetColor(255, 255, 255);
	color[static_cast<int>(eMenuType::Option)] = GetColor(125, 125, 125);
	color[static_cast<int>(eMenuType::OperationExp)] = GetColor(125, 125, 125);
	color[static_cast<int>(eMenuType::Title)] = GetColor(125, 125, 125);
	color[static_cast<int>(eMenuType::GameExit)] = GetColor(125, 125, 125);
}


//更新処理
void Menu::Update(GameResource* _gameRes) {
	//↓キーが入力された場合
	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) % 16 == 1 &&
		Input::Instance()->GetPressCount(KEY_INPUT_UP) == 0) {
		SelectMenu(CURSOR_DOWN);
	}

	//↑キーが入力された場合
	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) % 16 == 1 &&
		Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 0) {
		SelectMenu(CURSOR_UP);
	}

	//zキーを入力された場合
	if (Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1) {
		//シーンを切り替える
		switch (selectMenu) {
		case eMenuType::Game:
			//決定SEを鳴らす
			SE::Instance()->PlaySE(SE_Enter);

			//キャラ選択画面へ
			_gameRes->sceneManager->SceneChange("CharaSelect", true, false, _gameRes);
			break;
		case eMenuType::Option:
			//決定SEを鳴らす
			SE::Instance()->PlaySE(SE_Enter);

			//オプション画面へ
			_gameRes->sceneManager->SceneChange("Option", true, false, _gameRes);
			break;
		case eMenuType::OperationExp:
			//決定SEを鳴らす
			SE::Instance()->PlaySE(SE_Enter);

			//操作説明画面へ
			_gameRes->sceneManager->SceneChange("OperationExp", true, false, _gameRes);
			break;
		case eMenuType::Title:
			//BGMを止める
			BGM::Instance()->StopBGM(BGM_menu);

			//キャンセルSEを鳴らす
			SE::Instance()->PlaySE(SE_Cancel);

			//タイトル画面へ
			_gameRes->sceneManager->SceneChange("Title", false, false, _gameRes);
			break;
		case eMenuType::GameExit:
			//ゲームを終了する
			exit(EXIT_SUCCESS);
			break;
		}
	}
}

// 描画処理
void Menu::Draw(GameResource* _gameRes) {
/*------------------------------------------------------------------------------
UIの描画
------------------------------------------------------------------------------*/

	//プレイ
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eMenuType::Game)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT[0], UI_EXT[1], 0, UI_PAL, color[static_cast<int>(eMenuType::Game)],
		static_cast<int>(cursor[static_cast<int>(eMenuType::Game)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "プレイ");

	//オプション
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eMenuType::Option)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT[0], UI_EXT[1], 0, UI_PAL, color[static_cast<int>(eMenuType::Option)],
		static_cast<int>(cursor[static_cast<int>(eMenuType::Option)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "オプション");

	//操作説明
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eMenuType::OperationExp)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT[0], UI_EXT[1], 0, UI_PAL, color[static_cast<int>(eMenuType::OperationExp)],
		static_cast<int>(cursor[static_cast<int>(eMenuType::OperationExp)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "操作説明");

	//タイトルへ戻る
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eMenuType::Title)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT[0], UI_EXT[1], 0, UI_PAL, color[static_cast<int>(eMenuType::Title)],
		static_cast<int>(cursor[static_cast<int>(eMenuType::Title)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "タイトルへ戻る");

	//ゲーム終了
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eMenuType::GameExit)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT[0], UI_EXT[1], 0, UI_PAL, color[static_cast<int>(eMenuType::GameExit)],
		static_cast<int>(cursor[static_cast<int>(eMenuType::GameExit)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "ゲーム終了");
}

//選択メニューを切り替える
void Menu::SelectMenu(int _changeMode) {

	//SEを鳴らす
	SE::Instance()->PlaySE(SE_cursor);

	//現在選択されてる項目のカーソルフレームを灰色に
	cursor[static_cast<int>(selectMenu)] = Cursor::Cursor_0;
	color[static_cast<int>(selectMenu)] = GetColor(125, 125, 125);

	//切り替えモードがDOWNの場合
	if (_changeMode == CURSOR_DOWN) {
		//一番下の項目のとき、一番上の項目へ
		if (selectMenu == eMenuType::GameExit) {
			selectMenu = eMenuType::Game;
		}
		//上記条件外のとき、一つ下の項目へ
		else {
			selectMenu = static_cast<eMenuType>(static_cast<int>(selectMenu) + 1);
		}
	}
	//切り替えモードがUPの場合
	else if (_changeMode == CURSOR_UP) {
		//一番上の項目のとき、一番下の項目へ
		if (selectMenu == eMenuType::Game) {
			selectMenu = eMenuType::GameExit;
		}
		//上記条件外のとき、一つ上の項目へ
		else {
			selectMenu = static_cast<eMenuType>(static_cast<int>(selectMenu) - 1);
		}
	}

	//現在選択されてる項目のカーソルフレームを青色に
	cursor[static_cast<int>(selectMenu)] = Cursor::Cursor_3;
	color[static_cast<int>(selectMenu)] = GetColor(255, 255, 255);
}