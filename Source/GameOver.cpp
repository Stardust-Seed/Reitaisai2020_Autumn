#include <DxLib.h>
#include "Input.h"
#include "GameOver.h"

const int GameOver::GAME_Y = 440;
const int GameOver::MENU_Y = 460;

//コンストラクタ
GameOver::GameOver(ISceneChanger* _sceneChanger) :BaseScene(_sceneChanger)
{
	nowCursor = Continuity_Yes;
	y = GAME_Y;
}

//更新
void GameOver::Update()
{
	Select();
	//ゲームオーバー画面なのでここでそれ用の画像とか出すのかもしれない
}

//描画
void GameOver::Draw()
{
	//DrawFormatString(10, 600, GetColor(255, 255, 255), "nowCursor:%d", nowCursor);
	DrawFormatString(5, y, GetColor(255, 255, 255), "(首)->");
	DrawFormatString(65, GAME_Y, GetColor(255, 255, 255), ":コンティニューする  ");
	DrawFormatString(65, MENU_Y, GetColor(255, 255, 255), ":コンティニューしない");
}

//選択
void GameOver::Select()
{
	//{}だけの部分があるけどそれは左にある
    //Visual Studioの表示機能を使うためだよ

	//nowCursorの番号をy座標と合わせる
	{
		switch (nowCursor)
		{
		case Continuity_Yes:
			y = GAME_Y;
			break;

		case Continuity_No:
			y = MENU_Y;
			break;
		}
	}
	//↑キーが押された時の処理
	{
		//長押し時はワンテンポ置いてから
		if (Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1 ||
			Input::Instance()->GetPressCount(KEY_INPUT_UP) >= 60)
		{
			nowCursor -= 1;
		}
		//nowCursorの番号が最低値含め下なら実行
		if (Continuity_Min >= nowCursor)nowCursor = Continuity_Max - 1;
	}
	//↓キーが押された時の処理
	{
		//長押し時はワンテンポ置いてから
		if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1 ||
			Input::Instance()->GetPressCount(KEY_INPUT_DOWN) >= 60)
		{
			nowCursor += 1;
		}
		//nowCursorの番号が最大値含め上なら実行
		if (Continuity_Max <= nowCursor)nowCursor = Continuity_Min + 1;
	}
	//Enterキーが押された時の処理
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_RETURN) == 1)
		{
			//カーソルの場所によって処理を変える
			switch (nowCursor)
			{
			case Continuity_Yes:    //コンティニューします！！！！！！！！！！！！！！
				sceneChanger->SceneChange(eScene_GAME, false, false);
				break;

			case Continuity_No:   	//付加価値の高い俺は撤退戦略を持つぜ
				sceneChanger->SceneChange(eScene_MENU, false, false);
				break;
			}
		}
	}
}