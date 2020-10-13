#include <DxLib.h>
#include "OperationExp.h"

#include "Define.h"
#include "FontHandle.h"
#include "Input.h"
#include "SE.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="_sceneChanger">シーン切り替えクラス</param>
/// <param name="_parameter">パラメータ</param>
OperationExp::OperationExp(ISceneChanger* _sceneChanger, Parameter* _parameter) :
	BaseScene(_sceneChanger, _parameter) {

}

/// <summary>
/// 更新処理
/// </summary>
void OperationExp::Update() {
	//xキーが入力されたとき
	if (Input::Instance()->GetPressCount(KEY_INPUT_X) == 1) {
		//キャンセルSEを鳴らす
		SE::Instance()->PlaySE(SE_Cancel);

		//メニューシーンに戻る
		sceneChanger->SceneChange(eScene_MENU, parameter, false, true);
	}
}

/// <summary>
/// 描画処理
/// </summary>
void OperationExp::Draw() {
	//説明を描画する領域の描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 / 2);
	DrawBoxAA(100, 100, GAME_WIDTH - 100, GAME_HEIHGT - 100, GetColor(255, 255, 255), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//◆操作説明◆
	DrawStringToHandle(100, 100, text[0], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_100_3());

	//・移動 / カーソル移動
	DrawStringToHandle(100, 200, text[1], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_64_8());

	//・攻撃 / 決定
	DrawStringToHandle(100, 456, text[6], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_64_8());

	//・キャラスキル / 戻る
	DrawStringToHandle(100, 520, text[8], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_64_8());

	//・ポーズメニュー(ゲーム中)
	DrawStringToHandle(100, 584, text[10], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_64_8());

	//移動 / カーソル移動のキーを描画
	for (int i = 2; i <= 5; i++) {
		DrawStringToHandle(1000, 200 + ((i - 2) * 64), text[i], GetColor(0, 0, 0),
			FontHandle::Instance()->Get_natumemozi_64_8());
	}

	//攻撃 / 決定のキーを描画
	DrawStringToHandle(1000, 456, text[7], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_64_8());

	//キャラスキル / 戻るのキーを描画
	DrawStringToHandle(1000, 520, text[9], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_64_8());

	//ポーズメニューのキーを描画
	DrawStringToHandle(1000, 584, text[11], GetColor(0, 0, 0),
		FontHandle::Instance()->Get_natumemozi_64_8());
}