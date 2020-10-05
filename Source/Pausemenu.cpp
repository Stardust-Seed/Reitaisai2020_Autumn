#include <DxLib.h>
#include "Pausemenu.h"
#include "Input.h"
#include "BGM.h"
#include "SE.h"
#include "KuronekoLib.h"
#include "FontHandle.h"
#include "Define.h"
#include "Image.h"
Pausemenu::Pausemenu(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {

	if (BGM::Instance()->Get_Volume() >= 5)
	{
		BGM::Instance()->VolumeBGM(4);
	}
	else
	{
		if (BGM::Instance()->Get_Volume() != 0)
		{
			BGM::Instance()->VolumeBGM(BGM::Instance()->Get_Volume() - 1);
		}
	}
}

//画像とか背景？(未実装)
/*void Pausemenu::Pause()
{

}*/

//ポーズ画面の処理
void Pausemenu::PauseAll()
{
	switch (NowSelect)														//現在の選択状態に従って処理を分岐
	{
	case ePausetype_Game:													//ゲーム画面に戻るを選択中なら
		y = PGAME_Y;														//ゲーム画面に戻るの座標を格納
		break;

	case ePausetype_Menu:													//ゲームを終了を選択中なら
		y = PEND_Y;															//ゲーム終了の座標を格納
		break;
	}
}

//更新
void Pausemenu::Update()
{

	if (Input::Instance()->GetPressCount(KEY_INPUT_DOWN) % 16 == 1)		        //下キーが押されていたら
	{
		SE::Instance()->PlaySE(SE_cursor);
		NowSelect = (NowSelect + 1) % ePausetype_Num;							//選択状態を下げる
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_UP) % 16 == 1)			    //上キーが押されていたら
	{
		SE::Instance()->PlaySE(SE_cursor);
		NowSelect = (NowSelect + (ePausetype_Num - 1)) % ePausetype_Num;		//選択状態を上げる
	}
	if (Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1)				        //Zキーが押された場所の処理
	{
		BGM::Instance()->VolumeBGM(BGM::Instance()->Get_Volume());
		switch (NowSelect)
		{
		case ePausetype_Game:													//ゲーム画面に戻る項目
			sceneChanger->SceneChange(eScene_GAME, parameter, false, true);
			break;

		case ePausetype_Menu:													//ゲーム終了の項目
			BGM::Instance()->StopBGM(BGM_gameScene);
			sceneChanger->SceneChange(eScene_MENU, parameter, false, false);
			break;
		}
	}
}

//描画
void Pausemenu::Draw()
{
	PauseAll();

	if (NowSelect == ePausetype_Game)
	{
		DrawUIGraph(1300, 400, 1300, 350, 1, 1,
			0, 255, GetColor(255, 255, 255), 3, eDrawType::Center,
			FontHandle::Instance()->Get_natumemozi_100_3(), 205, "ゲームに戻る");

		DrawUIGraph(1300, 750, 1300, 350, 1, 1,
			0, 255, GetColor(255, 255, 255), 0, eDrawType::Center,
			FontHandle::Instance()->Get_natumemozi_100_3(), 180, "メニューに戻る");
	}
	else
	{
		DrawUIGraph(1300, 400, 1300, 350, 1, 1,
			0, 255, GetColor(255, 255, 255), 0, eDrawType::Center,
			FontHandle::Instance()->Get_natumemozi_100_3(), 205, "ゲームに戻る");

		DrawUIGraph(1300, 750, 1300, 350, 1, 1,
			0, 255, GetColor(255, 255, 255), 3, eDrawType::Center,
			FontHandle::Instance()->Get_natumemozi_100_3(), 180, "メニューに戻る");
	}

}
