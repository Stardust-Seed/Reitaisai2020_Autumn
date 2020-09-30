#include <DxLib.h>
#include "LevelSelect.h"

#include "Define.h"
#include "FontHandle.h"
#include "Image.h"
#include "Input.h"
#include "SE.h"

LevelSelect::LevelSelect(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	//初期化処理
	selectLevel = eLevelType::Easy;

	//Easyの初期座標
	easyX = (GAME_WIDTH / 2);
	easyY = (GAME_HEIHGT / 2) - 300;

	//Normalの初期座標
	normalX = (GAME_WIDTH / 2);
	normalY = (GAME_HEIHGT / 2);

	//Hardの初期座標
	hardX = (GAME_WIDTH / 2);
	hardY = (GAME_HEIHGT / 2) + 300;

	//アニメーションカウントの初期化
	animationCnt = 0;

	//切り替えフラグの初期化
	isChange = false;
}

void LevelSelect::Update() {
	/*------------------------------------------
	↓キーが押されたとき
	※↑キーが入力されている場合は処理を行わない
	------------------------------------------*/
	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) % 16 == 1 &&
		Input::Instance()->GetPressCount(KEY_INPUT_UP) == 0) {
		ChangeLevel(CURSOR_DOWN);
	}

	/*------------------------------------------
	↑キーが押されたとき
	※↓キーが入力されている場合は処理を行わない
	------------------------------------------*/
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

		//シーンをゲームシーンに切り替える
		sceneChanger->SceneChange(eScene_GAME, parameter, false, false);
	}

	//切り替えのアニメーション処理
	if (isChange == true) {
		Animation();
	}
}

//描画処理
void LevelSelect::Draw() {
	/*-----------------------------------------------------------------------
	UIの描画
	-----------------------------------------------------------------------*/
	//Easy
	DrawUIBox(easyX, easyY, EASY, eLevelType::Easy, Cursor::Cursor_2);

	//Normal
	DrawUIBox(normalX, normalY, NORMAL, eLevelType::Normal, Cursor::Cursor_3);

	//Hard
	DrawUIBox(hardX, hardY, HARD, eLevelType::Hard, Cursor::Cursor_1);
}

void LevelSelect::ChangeLevel(int _changeMode) {
	//フラグを切り替える
	isChange = true;

	//SEを鳴らす
	SE::Instance()->PlaySE(SE_cursor);

	//選択されたレベルを返す
	switch (selectLevel) {
	case eLevelType::Easy:
		//カーソルUPのとき
		if (_changeMode == CURSOR_UP) {
			selectLevel = eLevelType::Hard;
		}
		//カーソルDOWNのとき
		else if (_changeMode == CURSOR_DOWN) {
			selectLevel = eLevelType::Normal;
		}
		break;
	case eLevelType::Normal:
		//カーソルUPのとき
		if (_changeMode == CURSOR_UP) {
			selectLevel = eLevelType::Easy;
		}
		//カーソルDOWNのとき
		else if (_changeMode == CURSOR_DOWN) {
			selectLevel = eLevelType::Hard;
		}
		break;
	case eLevelType::Hard:
		//カーソルUPのとき
		if (_changeMode == CURSOR_UP) {
			selectLevel = eLevelType::Normal;
		}
		//カーソルDOWNのとき
		else if (_changeMode == CURSOR_DOWN) {
			selectLevel = eLevelType::Easy;
		}
		break;
	}
}

//UIの描画処理
void LevelSelect::DrawUIBox(float _x, float _y, string _text,
	eLevelType _levelType, Cursor _cursor) {

	int textSize = _text.size();

	//選択されていないレベルだったら灰色にする
	if (selectLevel != _levelType) {
		_cursor = Cursor::Cursor_0;
	}

	//ブレンドモードをアルファブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);

	//四角形の描画
	DrawRotaGraph3F(_x, _y, 650 / 2, 250 / 2, 1.0, 1.0, (0 * PAI) / 180,
		Image::Instance()->GetGraph(eImageType::UI_CursorFrame, static_cast<int>(_cursor)),
		FALSE);

	//文字の描画
	DrawStringToHandle(_x - ((100 / 2) * (textSize / 2)), _y - (100 / 2),
		_text.c_str(), GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_100_3());

	//ブレンドモードをノーブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//切り替えアニメーションの処理
void LevelSelect::Animation() {
	if (animationCnt >= 16) {
		animationCnt = 0;
		isChange = false;
	}

	animationCnt++;
}