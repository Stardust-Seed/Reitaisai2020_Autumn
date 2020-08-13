#include <DxLib.h>
#include "Pausemenu.h"
#include "Input.h"

Pausemenu::Pausemenu(ISceneChanger* _sceneChanger) :BaseScene(_sceneChanger) {

}

//画像とか背景？(未実装)
/*void Pausemenu::Pause()
{
	
}*/

//ポーズ画面の処理
void Pausemenu::PauseAll()
{
	if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE))			//スペースキーが押されたら
	{
		if (!pauseState)											//ポーズ状態ではないとき
		{
			pauseFlg = true;										//ポーズ状態にするフラグ
		}
		pauseState = true;											//ポーズ状態になっている
	}
	else															//スペースキーが押されてないとき
	{
		pauseState = false;											//ポーズ状態ではない
	}

	if (pauseFlg == true) 
	{
		if (ePausetype_Game)										// Pause状態中にゲーム画面に戻るが押されたとき
		{
			if (!pauseReset)										//ポーズ状態がリセットされてないなら
			{
				pauseFlg = false;									//ポーズ状態が解除
			}
			pauseReset = true;										//ポーズ解除状態への移行判定
		}
		else 
		{
			pauseReset = false;										// ゲーム画面に戻るが押されてなければPause解除になっていない

			DrawString(300, 0, "ポーズ画面", GetColor(255, 255, 255));				//確認
			DrawString(500, PGAME_Y, "ゲーム画面に戻る", GetColor(255, 255, 255));
			DrawString(500, PEND_Y, "ゲーム終了", GetColor(255, 255, 255));

			switch (NowSelect)														//現在の選択状態に従って処理を分岐
			{													
			case ePausetype_Game:													//ゲーム画面に戻るを選択中なら
				y = PGAME_Y;														//ゲーム画面に戻るの座標を格納
				break;

			case ePausetype_Menu:													//ゲームを終了を選択中なら
				y = PEND_Y;															//ゲーム終了の座標を格納
				break;
			}
			DrawString(450, y, "■", GetColor(255, 255, 255));						//選択カーソル
		}
	}
}	

//更新
void Pausemenu::Update()
{
	Input::Instance()->UpdateKey();

	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) == 1)					//下キーが押されていたら
	{
	    NowSelect = (NowSelect + 1) % ePausetype_Num;							//選択状態を下げる
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) == 1)					//上キーが押されていたら
	{
		NowSelect = (NowSelect + (ePausetype_Num - 1)) % ePausetype_Num;		//選択状態を上げる
	}
	if (Input::Instance()->GetPressCount(KEY_INPUT_RETURN) == 1)				//Enterキーが押された場所の処理
	{
		switch (NowSelect)
		{
		case ePausetype_Game:															//ゲーム画面に戻る項目
			DrawString(100, 0, "ゲーム画面", GetColor(255, 255, 255));
			
				if (!pauseReset)														// Pause状態が一度もリセットされていないなら
				{
					pauseFlg = false;													// Pause解除状態になるというフラグ
					DrawString(300, 0, "ポーズ画面解除", GetColor(255, 255, 255));
				}
				pauseReset = true;														// 一度Pause解除状態への移行判定をした
				break;

		case ePausetype_Menu:															//ゲーム終了の項目
			DrawString(100, 0, "メニュー画面", GetColor(255, 255, 255));
			break;
		}
	}
}

//描画
void Pausemenu::Draw()
{
	PauseAll();
}
