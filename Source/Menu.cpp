#include <DxLib.h>
#include "Input.h"
#include "Menu.h"

//選択されてる画面
void Menu::SelectMenu()
{
	NowSelect = eMenutype_Num;		//現在選択されている項目
}

//更新
void Menu::Update()
{
	Input::Instance()->UpdateKey();

	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1)			//下キーが押されていたら
	{
		NowSelect = (NowSelect + 1) % eMenutype_Num;					//選択状態を下げる
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1)			//上キーが押されていたら
	{
		NowSelect = (NowSelect+(eMenutype_Num-1))% eMenutype_Num;		//選択状態を上げる
	}
	
	if (Input::Instance()->GetPressCount(KEY_INPUT_RETURN) == 1)		//Enterキーが押された場所の処理
	{
		switch (NowSelect)
		{
		case eMenutype_Game:
			DrawString(100, 0, "ゲーム画面", GetColor(255, 255, 255));
			break;

		case eMenutype_Option:
			DrawString(100, 0, "オプション", GetColor(255, 255, 255));
			break;

		case eMenutype_Title:
			DrawString(100, 0, "タイトル", GetColor(255, 255, 255));
		}
	}
}

//描画
void Menu::Draw()
{
	DrawString(500, GAME_Y, "ゲーム画面", GetColor(255, 255, 255));
	DrawString(500, OPTOIN_Y, "オプション", GetColor(255, 255, 255));
	DrawString(500, END_Y, "ゲーム終了", GetColor(255, 255, 255));
	
	switch (NowSelect) {									//現在の選択状態に従って処理を分岐
	case eMenutype_Game:									//ゲーム選択中なら
		y = GAME_Y;											//ゲームの座標を格納
		break;

	case eMenutype_Option:									//設定選択中なら
		y = OPTOIN_Y;										//設定の座標を格納
		break;

	case eMenutype_Title:
		y = END_Y;
		break;
	}
	DrawString(450, y, "■", GetColor(255, 255, 255));		//選択カーソル
}