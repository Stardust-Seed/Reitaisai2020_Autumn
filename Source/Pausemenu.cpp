#include <DxLib.h>
#include "Pausemenu.h"
#include "Input.h"
#include "BGM.h"
#include "SE.h"
#include "FontHandle.h"
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

	case ePausetype_Guide:
		y = PGUIDE_Y;
		break;

	case ePausetype_Menu:													//ゲームを終了を選択中なら
		y = PEND_Y;															//ゲーム終了の座標を格納
		break;
	}
}

//更新
void Pausemenu::Update(GameResource* _gameRes)
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

	if (Input::Instance()->GetPressCount(KEY_INPUT_X) == 1)				        //Xキーが押された場所の処理
	{
		SE::Instance()->PlaySE(SE_Cancel);
		BGM::Instance()->VolumeBGM(BGM::Instance()->Get_Volume());
		sceneChanger->SceneChange(eScene_GAME, parameter, false, true);
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1)				        //Zキーが押された場所の処理
	{
		SE::Instance()->PlaySE(SE_Enter);
		BGM::Instance()->VolumeBGM(BGM::Instance()->Get_Volume());
		switch (NowSelect)
		{
		case 0:													//ゲーム画面に戻る項目
			sceneChanger->SceneChange(eScene_GAME, parameter, false, true);
			break;

		case 1:													//操作説明の項目
			sceneChanger->SceneChange(eScene_OPERATIONEXP, parameter, true, false);
			break;

		case 2:													//ゲーム終了の項目
			BGM::Instance()->StopBGM(BGM_gameScene);
			sceneChanger->SceneChange(eScene_MENU, parameter, false, false);
		}
	}
}

//描画
void Pausemenu::Draw(GameResource* _gameRes)
{
	PauseAll();

	if (NowSelect == ePausetype_Game)
	{
		DrawRotaGraph(GAME_WIDTH / 2, 225, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 3), TRUE);
		DrawRotaGraph(GAME_WIDTH / 2, 525, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);
		DrawRotaGraph(GAME_WIDTH / 2, 825, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);

		DrawStringToHandle(GAME_WIDTH / 2 - 287, 225 - 50, "ゲームに戻る", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 300, 525 - 50, "　操作説明　", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 280, 825 - 50, " ゲーム終了 ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());

		DrawStringToHandle(GAME_WIDTH / 2 - 287-2, 225 - 50-2, "ゲームに戻る", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 300-2, 525 - 50-2, "　操作説明　", GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 280-2, 825 - 50-2, " ゲーム終了 ", GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_100_3());
	}

	if(NowSelect == ePausetype_Menu)
	{
		DrawRotaGraph(GAME_WIDTH / 2, 225, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);
		DrawRotaGraph(GAME_WIDTH / 2, 525, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 3), TRUE);
		DrawRotaGraph(GAME_WIDTH / 2, 825, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);

		DrawStringToHandle(GAME_WIDTH / 2 - 287, 225 - 50, "ゲームに戻る", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 300, 525 - 50, "　操作説明　", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 280, 825 - 50, " ゲーム終了 ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());

		DrawStringToHandle(GAME_WIDTH / 2 - 287 - 2, 225 - 50 - 2, "ゲームに戻る", GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 300 - 2, 525 - 50 - 2, "　操作説明　", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 280 - 2, 825 - 50 - 2, " ゲーム終了 ", GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_100_3());

	}

	if (NowSelect == ePausetype_Guide)
	{
		DrawRotaGraph(GAME_WIDTH / 2, 225, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);
		DrawRotaGraph(GAME_WIDTH / 2, 525, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);
		DrawRotaGraph(GAME_WIDTH / 2, 825, 1, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 3), TRUE);

		DrawStringToHandle(GAME_WIDTH / 2 - 287, 225 - 50, "ゲームに戻る", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 300, 525 - 50, "　操作説明　", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 280, 825 - 50, " ゲーム終了 ", GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_100_3());

		DrawStringToHandle(GAME_WIDTH / 2 - 287 - 2, 225 - 50 - 2, "ゲームに戻る", GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 300 - 2, 525 - 50 - 2, "　操作説明　", GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_100_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 280 - 2, 825 - 50 - 2, " ゲーム終了 ", GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_100_3());

	}

}
