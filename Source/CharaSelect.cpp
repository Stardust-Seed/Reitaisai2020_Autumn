#include <DxLib.h>
#include "Input.h"
#include "Charaselect.h"

/*コンストラクタ*/
CharaSelect::CharaSelect(ISceneChanger* _sceneChanger, Parameter* _parameter) :BaseScene(_sceneChanger, _parameter) {

	//最初は咲夜が選択されている状態
	charaSelect = select_SAKUYA;

	selectChara = SelectCharacter::select_SAKUYA;

	color = GetColor(128,128,128); //灰色
	color_Sakuya = GetColor(255, 64, 0); //白
	color_Fran = GetColor(128, 128, 128);   //灰色

	//UIフレームの色を初期設定
	charaCursor[static_cast<int>(SelectCharacter::select_SAKUYA)] = Cursor::Cursor_3;
	charaCursor[static_cast<int>(SelectCharacter::select_FRAN)] = Cursor::Cursor_0;

	colorNo = 0;
}

/*更新処理*/
void CharaSelect::Update()
{
	if (Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) % 16 == 1 &&
		Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 0)
	{
		Select_Push(CURSOR_DOWN); //選択決定

	}
	if (Input::Instance()->GetPressCount(KEY_INPUT_LEFT) % 16 == 1 &&
		Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 0)
	{
		Select_Push(CURSOR_UP); //選択決定
	}

	/****決定****/
	/************/
	if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1))
	{
		switch (charaSelect) {
		case select_SAKUYA:   //咲夜を選択
			SE::Instance()->PlaySE(SE_Enter, DX_PLAYTYPE_BACK);
			parameter->Set(BaseScene::CharaSelectTag, selectChara);
			sceneChanger->SceneChange(eScene_LEVELSELECT, parameter, true, false);
			break;
		case select_FRAN:     //フランを選択
			SE::Instance()->PlaySE(SE_Enter, DX_PLAYTYPE_BACK);
			parameter->Set(BaseScene::CharaSelectTag, selectChara);
			sceneChanger->SceneChange(eScene_LEVELSELECT, parameter, true, false);
			break;
		}
	}
	//過去へ戻る
	if ((Input::Instance()->GetPressCount(KEY_INPUT_X) == 1))
	{
		SE::Instance()->PlaySE(SE_Cancel, DX_PLAYTYPE_BACK);
		sceneChanger->SceneChange(eScene_MENU, parameter, false, true);
	}
}
void CharaSelect::Select_Push(int _changeType)
{
	//現在選択されてる項目のカーソルフレームを灰色に
	charaCursor[static_cast<int>(selectChara)] = Cursor::Cursor_0;

	//切り替えモードがDOWNの場合
	if (_changeType == CURSOR_DOWN) {
		//SEを鳴らす
		SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_BACK);
		//一番下の項目のとき、一番上の項目へ
		if (selectChara == SelectCharacter::select_FRAN) {
			selectChara = SelectCharacter::select_SAKUYA;
			color_Sakuya = color_Fran; //灰色
			color_Fran = color;        //白色
		}
		//上記条件外のとき、一つ下の項目へ
		else {
			selectChara = static_cast<SelectCharacter>(static_cast<int>(selectChara) + 1);
			color_Fran = color_Sakuya; //白
			color_Sakuya = color;      //灰色
		}
	}
	//切り替えモードがUPの場合
	else if (_changeType == CURSOR_UP) {
		//SEを鳴らす
		SE::Instance()->PlaySE(SE_cursor, DX_PLAYTYPE_BACK);
		//一番上の項目のとき、一番下の項目へ
		if (selectChara == SelectCharacter::select_SAKUYA) {
			selectChara = SelectCharacter::select_FRAN;
			color_Fran = color_Sakuya; //白
			color_Sakuya = color;      //灰色
		}
		//上記条件外のとき、一つ上の項目へ
		else {
			selectChara = static_cast<SelectCharacter>(static_cast<int>(selectChara) - 1);
			color_Sakuya = color_Fran; //白
			color_Fran = color;        //灰色
		}

	}

	//現在選択されてる項目のカーソルフレームを青色に
	charaCursor[static_cast<int>(selectChara)] = Cursor::Cursor_3;

	/****決定****/
/************/
	if ((Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1))
	{
		switch (charaSelect) {
		case select_SAKUYA:   //咲夜を選択
			SE::Instance()->PlaySE(SE_Enter, DX_PLAYTYPE_NORMAL);
			parameter->Set(BaseScene::CharaSelectTag, charaSelect);
			sceneChanger->SceneChange(eScene_LEVELSELECT, parameter, true, false);
			break;
		case select_FRAN:     //フランを選択
			SE::Instance()->PlaySE(SE_Enter, DX_PLAYTYPE_NORMAL);
			parameter->Set(BaseScene::CharaSelectTag, charaSelect);
			sceneChanger->SceneChange(eScene_LEVELSELECT, parameter, true, false);
			break;
		}
	}
	//過去へ戻る
	if ((Input::Instance()->GetPressCount(KEY_INPUT_X) == 1))
	{
		//SEを鳴らす
		SE::Instance()->PlaySE(SE_Cancel, DX_PLAYTYPE_NORMAL);
		sceneChanger->SceneChange(eScene_MENU, parameter, false, true);
	}

}

/*描画処理*/
void CharaSelect::Draw()
{
	Draw_CharaWaku();    //キャラ画像の枠
	Draw_CharaGraph();   //キャラ画像
	Draw_CharaName();    //キャラネームとネームの枠
	Draw_CharaAbility(); //キャラクターのスキル説明
}
void CharaSelect::Draw_CharaWaku()
{
	/**描画 奥**/
	//キャラクター画像の枠組み
	DrawBox(535, 180, 850, 620, GetColor(0, 0, 255), true);      //青色
	DrawBox(1085, 180, 1400, 620, GetColor(255, 0, 0), true);    //赤色

	DrawBox(555, 200, 830, 599, GetColor(0, 255, 255), true);    //水色
	DrawBox(1105, 200, 1380, 599, GetColor(255, 255, 0), true);  //黄色

}
void CharaSelect::Draw_CharaGraph()
{
	/**描画 中**/
	//キャラクター画像の表示
	DrawGraph(555, 200, Image::Instance()->GetGraph(eImageType::Spicture_SelectPlayer, 0), true);
	DrawGraph(1105, 200, Image::Instance()->GetGraph(eImageType::Spicture_SelectPlayer, 1), true);
}
void CharaSelect::Draw_CharaName()
{
	//咲夜枠
	DrawRotaGraph(690,725,0.6,0.0,Image::Instance()->GetGraph(eImageType::UI_CursorFrame, static_cast<int>(charaCursor[static_cast<int>(SelectCharacter::select_SAKUYA)])),TRUE);
	//スキル枠
	DrawBox(95, 200, 450, 700, GetColor(0, 0, 0), TRUE);
	//フラン枠
	DrawRotaGraph(1250, 725, 0.6, 0.0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, static_cast<int>(charaCursor[static_cast<int>(SelectCharacter::select_FRAN)])), TRUE);
	//スキル枠
	DrawBox(1490,200,1845, 700, GetColor(0, 0, 0), TRUE);

	/**描画 前**/
	//キャラクター名の表示

	//影
	DrawStringToHandle(562, 702, "十六夜 咲夜", GetColor(0, 0, 0),FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1092, 702, "フランドール・Ｓ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());

	//真
	DrawStringToHandle(560, 700, "十六夜 咲夜", color_Sakuya, FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1090, 700, "フランドール・Ｓ", color_Fran, FontHandle::Instance()->Get_natumemozi_48_8());
}
void CharaSelect::Draw_CharaAbility()
{
	//咲夜スキル説明
	DrawStringToHandle(160, 250, "　スキル", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(160, 325, "敵の動きを", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(100, 375, "5秒間停止させる", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(120, 450, "使用回数：３回", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());

	//咲夜ステータス
	DrawStringToHandle(120, 530, "power  ★", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(120, 580, "speed  ★★★", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());

	//フランスキル説明
	DrawStringToHandle(1550, 250, "　スキル", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1515, 325, "画面上の敵を", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1515, 375, "全て破壊する", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1515, 450, "使用回数：２回", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());

	//フランステータス
	DrawStringToHandle(1515, 530, "power  ★★★", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(1515, 580, "speed  ★", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_48_8());
}