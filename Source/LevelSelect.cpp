#include <DxLib.h>
#include "LevelSelect.h"

#include "Define.h"
#include "FontHandle.h"
#include "Input.h"
#include "SE.h"

LevelSelect::LevelSelect(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	//初期化処理
	selectLevel = eLevelType::Easy;

	//Easyの初期座標
	easyX1 = (GAME_WIDTH / 2) - 300;
	easyX2 = (GAME_WIDTH / 2) + 300;
	easyY1 = (GAME_HEIHGT / 2) - 400;
	easyY2 = (GAME_HEIHGT / 2) - 200;

	//Normalの初期座標
	normalX1 = (GAME_WIDTH / 2) - 300;
	normalX2 = (GAME_WIDTH / 2) + 300;
	normalY1 = (GAME_HEIHGT / 2) - 100;
	normalY2 = (GAME_HEIHGT / 2) + 100;

	//Hardの初期座標
	hardX1 = (GAME_WIDTH / 2) - 300;
	hardX2 = (GAME_WIDTH / 2) + 300;
	hardY1 = (GAME_HEIHGT / 2) + 200;
	hardY2 = (GAME_HEIHGT / 2) + 400;

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
		/*--------------------------------------
		現在選択中のレベルの下の項目に切り替える
		※Hardの場合一番上のEasyに移動する
		--------------------------------------*/
		switch (selectLevel) {
		case eLevelType::Easy:
			selectLevel = eLevelType::Normal;
			break;
		case eLevelType::Normal:
			selectLevel = eLevelType::Hard;
			break;
		case eLevelType::Hard:
			selectLevel = eLevelType::Easy;
			break;
		}

		//フラグを切り替える
		isChange = true;

		//SEを鳴らす
		SE::Instance()->PlaySE(SE_cursor);
	}

	/*------------------------------------------
	↑キーが押されたとき
	※↓キーが入力されている場合は処理を行わない
	------------------------------------------*/
	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) % 16 == 1 &&
		Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 0) {
		/*--------------------------------------
		現在選択中のレベルの上の項目に切り替える
		※Easyの場合一番下のHardに移動する
		--------------------------------------*/
		switch (selectLevel) {
		case eLevelType::Easy:
			selectLevel = eLevelType::Hard;
			break;
		case eLevelType::Normal:
			selectLevel = eLevelType::Easy;
			break;
		case eLevelType::Hard:
			selectLevel = eLevelType::Normal;
			break;
		}

		//フラグを切り替える
		isChange = true;

		//SEを鳴らす
		SE::Instance()->PlaySE(SE_cursor);
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
	DrawUIBox(easyX1, easyY1, easyX2, easyY2, GetColor(0, 255, 0),
		"Easy", eLevelType::Easy);

	//Normal
	DrawUIBox(normalX1, normalY1, normalX2, normalY2, GetColor(0, 0, 255),
		"Normal", eLevelType::Normal);

	//Hard
	DrawUIBox(hardX1, hardY1, hardX2, hardY2, GetColor(255, 0, 0),
		"Hard", eLevelType::Hard);
}

void LevelSelect::ChangeLevel() {

}

//UIの描画処理
void LevelSelect::DrawUIBox(float _x1, float _y1, float _x2, float _y2, unsigned int _color,
	const char* _text, eLevelType _levelType) {

	//選択されていないレベルだったら灰色にする
	if (selectLevel != _levelType) {
		_color = GetColor(125, 125, 125);
	}

	//ブレンドモードをアルファブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 125);

	//四角形の描画
	DrawBoxAA(_x1, _y1, _x2, _y2, _color, TRUE);

	//文字の描画
	DrawStringToHandle(_x1, _y1, _text, GetColor(255, 255, 255),
		FontHandle::Instance()->Get_natumemozi_100_3());

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