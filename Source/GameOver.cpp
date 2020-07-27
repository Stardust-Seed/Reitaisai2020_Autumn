#include <DxLib.h>
#include "Input.h"
#include "GameOver.h"

const int GameOver::GAME_Y = 440;
const int GameOver::MENU_Y = 460;

//コンストラクタ
GameOver::GameOver()
{
	nowScene = GAME;
	nowCursor = Continuity_Yes;
	y = GAME_Y;
}

//更新
void GameOver::Update()
{
	Input::Instance()->UpdateKey();
	//ゲームオーバー画面なのでここでそれ用の画像とか出すのかもしれない

	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1)        //↑キーが押されたよ
	{
		//nowCursorの番号が最低値より上なら実行
		if(Continuity_Yes < nowCursor) nowCursor -= 1;
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1)      //↓キーが押されたよ
	{
		//nowCursorの番号が最大値-1より下なら実行
		if (Continuity_NULL - 1 > nowCursor) nowCursor += 1;
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_RETURN) == 1)    //Enterキーが押されたよ
	{
		switch (nowCursor)
		{
		case Continuity_Yes:    //コンティニューします！！！！！！！！！！！！！！
			                    //仕様書ではメニューに移動になってます
			nowScene = MENU;
			//SceneChange->onSceneChanged(Scene::MENU);みたいな感じかもしれないきっと
			break;

		case Continuity_No:   	//付加価値の高い俺は撤退戦略を持つぜ
			                    //仕様書ではゲーム画面に移動になってます？？？？？？？？？？？？？
			                    //コンティニューしないのにゲーム画面に戻されるのか...
			nowScene = GAME;
			//SceneChange->onSceneChanged(Scene::GAME);みたいな感じかもしれないきっと
			break;
		}
	}
}

//描画
void GameOver::Draw()
{
	DrawFormatString(10, 100, GetColor(255, 255, 255), "現在のシーン番号%d", nowScene);
	DrawFormatString(10, 600, GetColor(255, 255, 255), "nowCursor:%d", nowCursor);
	DrawFormatString(5, y, GetColor(255, 255, 255), "(首)->");
	DrawFormatString(65, GAME_Y, GetColor(255, 255, 255), ":コンティニューする  ");
	DrawFormatString(65, MENU_Y, GetColor(255, 255, 255), ":コンティニューしない");

	//nowCursorの番号をy座標と合わせる
	switch (nowCursor)
	{
	case Continuity_Yes:
		y = GAME_Y;
		break;

	case Continuity_No:
		y = MENU_Y;
		break;
	}

	if (nowScene == MENU)
	{
		DrawFormatString(10, 150, GetColor(255, 255, 255), "めぬ");
	}
	if (nowScene == GAME)
	{
		DrawFormatString(10, 150, GetColor(255, 255, 255), "がめ");
	}
}