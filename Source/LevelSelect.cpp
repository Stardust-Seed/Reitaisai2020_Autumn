#include <DxLib.h>
#include "LevelSelect.h"

#include "BGM.h"
#include "File.h"
#include "FontHandle.h"
#include "KuronekoLib.h"
#include "Image.h"
#include "Input.h"
#include "SE.h"
#include "Parameter.h"
#include "SceneManager.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="_sceneChanger">シーン切り替えクラス</param>
/// <param name="_parameter">パラメータ</param>
LevelSelect::LevelSelect() {

}

void LevelSelect::Init(GameResource* _gameRes) {
	//初期化処理
	selectLevel = eLevelType::Easy;

	//UIフレームの色を初期設定
	SetCursor(Cursor::Cursor_2, Cursor::Cursor_0, Cursor::Cursor_0);

	SetColor(GetColor(255, 255, 255), GetColor(125, 125, 125), GetColor(125, 125, 125));

	//切り替えるフラグを初期化
	isChange = false;

	//クリアフラグをセットする
	SetIsClear(File::Instance()->GetFileData(eFileType::Clear, static_cast<int>(eLevelType::Easy)),
		static_cast<int>(eLevelType::Easy));

	SetIsClear(File::Instance()->GetFileData(eFileType::Clear, static_cast<int>(eLevelType::Normal)),
		static_cast<int>(eLevelType::Normal));

	SetIsClear(File::Instance()->GetFileData(eFileType::Clear, static_cast<int>(eLevelType::Hard)),
		static_cast<int>(eLevelType::Hard));
}

/// <summary>
/// 更新処理
/// </summary>
void LevelSelect::Update(GameResource* _gameRes) {
	//選択された項目に色を付けて、それ以外は灰色に設定する
	if (isChange == true) {
		switch (selectLevel) {
		case eLevelType::Easy:
			SetCursor(Cursor::Cursor_2, Cursor::Cursor_0, Cursor::Cursor_0);
			SetColor(GetColor(255, 255, 255), GetColor(125, 125, 125), GetColor(125, 125, 125));
			break;
		case eLevelType::Normal:
			SetCursor(Cursor::Cursor_0, Cursor::Cursor_3, Cursor::Cursor_0);
			SetColor(GetColor(125, 125, 125), GetColor(255, 255, 255), GetColor(125, 125, 125));
			break;
		case eLevelType::Hard:
			SetCursor(Cursor::Cursor_0, Cursor::Cursor_0, Cursor::Cursor_1);
			SetColor(GetColor(125, 125, 125), GetColor(125, 125, 125), GetColor(255, 255, 255));
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
			_gameRes->parameter->Set("LevelSelect", 0);
			break;
		case eLevelType::Normal:
			_gameRes->parameter->Set("LevelSelect", 1);
			break;
		case eLevelType::Hard:
			_gameRes->parameter->Set("LevelSelect", 2);
			break;
		}

		//メニューのBGMを止める
		BGM::Instance()->StopBGM(BGM_menu);

		//決定SEを鳴らす
		SE::Instance()->PlaySE(SE_Enter);

		//シーンをゲームシーンに切り替える
		_gameRes->sceneManager->SceneChange("InGame", false, false, _gameRes);
	}

	//xキーが押されたとき
	if (Input::Instance()->GetPressCount(KEY_INPUT_X) == 1) {

		//キャンセルSEを鳴らす
		SE::Instance()->PlaySE(SE_Cancel);

		//シーンをキャラセレクトに切り替える
		_gameRes->sceneManager->SceneChange("CharaSelect", false, true, _gameRes);
	}
}

/// <summary>
/// 描画処理
/// </summary>
void LevelSelect::Draw(GameResource* _gameRes) {
/*------------------------------------------------------------------------------
UIの描画
------------------------------------------------------------------------------*/
	//Easy
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eLevelType::Easy)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT, UI_EXT, 0, UI_PAL, color[static_cast<int>(eLevelType::Easy)],
		static_cast<int>(cursor[static_cast<int>(eLevelType::Easy)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "Easy");

	ClearDraw(eLevelType::Easy);

	//Normal
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eLevelType::Normal)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT, UI_EXT, 0, UI_PAL, color[static_cast<int>(eLevelType::Normal)],
		static_cast<int>(cursor[static_cast<int>(eLevelType::Normal)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "Normal");

	ClearDraw(eLevelType::Normal);

	//Hard
	DrawUIGraph(UI_X, UI_Y[static_cast<int>(eLevelType::Hard)], UIFRAME_WIDTH, UIFRAME_HEIGHT,
		UI_EXT, UI_EXT, 0, UI_PAL, color[static_cast<int>(eLevelType::Hard)],
		static_cast<int>(cursor[static_cast<int>(eLevelType::Hard)]), eDrawType::Center,
		FontHandle::Instance()->Get_natumemozi_100_3(), UI_FONTSIZE, "Hard");

	ClearDraw(eLevelType::Hard);
}

/// <summary>
/// 選択レベルを切り替える
/// </summary>
/// <param name="_changeMode">切り替えモード</param>
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

/// <summary>
/// 引数のカーソルを各カーソルにセットする
/// </summary>
/// <param name="_easy">Easyのカーソル</param>
/// <param name="_normal">Normalのカーソル</param>
/// <param name="_hard">Hardのカーソル</param>
void LevelSelect::SetCursor(Cursor _easy, Cursor _normal, Cursor _hard) {
	//Easyのカーソルをセットする
	cursor[static_cast<int>(eLevelType::Easy)] = _easy;

	//Normalのカーソルをセットする
	cursor[static_cast<int>(eLevelType::Normal)] = _normal;

	//Hardのカーソルをセットする
	cursor[static_cast<int>(eLevelType::Hard)] = _hard;
}

/// <summary>
/// 引数に対応する色をセットする
/// </summary>
/// <param name="_easy">Easyのカーソル</param>
/// <param name="_normal">Normalのカーソル</param>
/// <param name="_hard">Hardのカーソル</param>
void LevelSelect::SetColor(unsigned int _easy, unsigned int _normal, unsigned int _hard) {
	//Easyの色をセットする
	color[static_cast<int>(eLevelType::Easy)] = _easy;

	//Normalの色をセットする
	color[static_cast<int>(eLevelType::Normal)] = _normal;

	//Hardの色をセットする
	color[static_cast<int>(eLevelType::Hard)] = _hard;
}

/// <summary>
/// クリアフラグをセットする
/// </summary>
/// <param name="_isClear">クリアフラグ</param>
/// <param name="_level">セットするレベル</param>
void LevelSelect::SetIsClear(int _isClear, int _level) {
	//_isClearが0の場合 false / 1の場合 true
	if (_isClear == 0) {
		isClear[_level] = false;
	}
	else {
		isClear[_level] = true;
	}
}

/// <summary>
/// クリア表示する
/// </summary>
/// <param name="_level">表示するレベル</param>
void LevelSelect::ClearDraw(eLevelType _level) {
	//isClearがtrueの場合
	if (isClear[static_cast<int>(_level)] == true) {
		switch (_level) {
		case eLevelType::Easy:
			//影の描画
			DrawStringFToHandle((UI_X - (UIFRAME_WIDTH / 2)) + 3,
				(UI_Y[static_cast<int>(eLevelType::Easy)] - (UIFRAME_HEIGHT / 2)) + 3,
				"Clear", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_64_8());

			//文字の描画
			DrawStringFToHandle((UI_X - UIFRAME_WIDTH / 2),
				UI_Y[static_cast<int>(eLevelType::Easy)] - (UIFRAME_HEIGHT / 2), "Clear",
				GetColor(255, 255, 0), FontHandle::Instance()->Get_natumemozi_64_8());
			break;
		case eLevelType::Normal:
			//影の描画
			DrawStringFToHandle((UI_X - (UIFRAME_WIDTH / 2)) + 3,
				(UI_Y[static_cast<int>(eLevelType::Normal)] - (UIFRAME_HEIGHT / 2)) + 3,
				"Clear", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_64_8());

			//文字の描画
			DrawStringFToHandle((UI_X - (UIFRAME_WIDTH / 2)),
				UI_Y[static_cast<int>(eLevelType::Normal)] - (UIFRAME_HEIGHT / 2), "Clear",
				GetColor(255, 255, 0), FontHandle::Instance()->Get_natumemozi_64_8());
			break;
		case eLevelType::Hard:
			//影の描画
			DrawStringFToHandle((UI_X - (UIFRAME_WIDTH / 2)) + 3,
				(UI_Y[static_cast<int>(eLevelType::Hard)] - (UIFRAME_HEIGHT / 2)) + 3,
				"Clear", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_64_8());

			//文字の描画
			DrawStringFToHandle((UI_X - (UIFRAME_WIDTH / 2)),
				UI_Y[static_cast<int>(eLevelType::Hard)] - (UIFRAME_HEIGHT / 2),
				"Clear", GetColor(255, 255, 0), FontHandle::Instance()->Get_natumemozi_64_8());
			break;
		}
	}
}