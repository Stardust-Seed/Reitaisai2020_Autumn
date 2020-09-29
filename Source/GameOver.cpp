#include "DxLib.h"
#include "GameOver.h"
#include "Charaselect.h"

//コンストラクタ
GameOver::GameOver(ISceneChanger* _sceneChanger, Parameter* _parameter) :BaseScene(_sceneChanger, _parameter)
{
	nowCursor = Continuity_Yes;
	x = 0;
	alpha = 0;
	charaType = _parameter->Get(BaseScene::CharaSelectTag);

	BGM::Instance()->PlayBGM(BGM_result, DX_PLAYTYPE_LOOP);
}

//更新
void GameOver::Update()
{
	Select();
	Move();
}

//描画
void GameOver::Draw()
{
	DrawGraph(GAME_WIDTH / 1.45f, GAME_HEIHGT / 9, Image::Instance()->GetGraph(eImageType::Spicture_Fran, 0), TRUE);
	DrawGraph(0, GAME_HEIHGT - 450, Image::Instance()->GetGraph(eImageType::Background_Title), TRUE);
	
	//ブレンドモードを乗算済みα用のαブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, alpha);

	DrawStringToHandle(GAME_WIDTH / 20, GAME_HEIHGT / 10 , "ゲームオーバー", GetColor(255, 255, 255), FontHandle::Instance()->Get_weakForce_222_16());
	
	//ブレンドモードを通常に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, alpha);

	//カーソルフレームの表示
	DrawGraph(x, GAME_HEIHGT / 2 + 25, Image::Instance()->GetGraph(eImageType::Title_Logo), TRUE);

	DrawGraph(GAME_X, GAME_HEIHGT / 2 + 25, Image::Instance()->GetGraph(eImageType::Title_Logo), TRUE);
	DrawGraph(MENU_X, GAME_HEIHGT / 2 + 25, Image::Instance()->GetGraph(eImageType::Title_Logo), TRUE);

	DrawStringToHandle(GAME_WIDTH / 7.5f, GAME_HEIHGT / 2 + 50, "コンティニューする  ", GetColor(128,0,0), FontHandle::Instance()->Get_weakForce_48_8());
	DrawStringToHandle(GAME_WIDTH / 2.5f, GAME_HEIHGT / 2 + 50,  "コンティニューしない", GetColor(128, 0, 0), FontHandle::Instance()->Get_weakForce_48_8());


	//キャラの表示
	switch (charaType)
	{
	//ケース文はenumにするかもしれない
	case 1:
		DrawGraph(GAME_WIDTH / 1.5f, GAME_HEIHGT / 1.75f, Image::Instance()->GetGraph(eImageType::Spicture_Sakuya, 0), TRUE);
		break;

	case 2:
		DrawGraph(GAME_WIDTH / 1.5f, GAME_HEIHGT / 1.75f, Image::Instance()->GetGraph(eImageType::Spicture_Fran, 0), TRUE);
		break;

	default:
		break;
	}
}
//文字の動き
void GameOver::Move()
{
	if (alpha < 255)
	{
		alpha++;
	}
}

//選択
void GameOver::Select()
{
	//nowCursorの番号をx座標と合わせる
	{
		switch (nowCursor)
		{
		case Continuity_Yes:
			x = GAME_X;
			break;

		case Continuity_No:
			x = MENU_X;
			break;
		}
	}

	//左キーが押された時の処理
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1)
		{
			SE::Instance()->PlaySE(SE_cursor);
			nowCursor -= 1;
		}

		//nowCursorの番号が最低値含め下なら実行
		if (Continuity_Min >= nowCursor)nowCursor = Continuity_Max - 1;
	}

	//右キーが押された時の処理
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1 )
		{
			SE::Instance()->PlaySE(SE_cursor);
			nowCursor += 1;
		}

		//nowCursorの番号が最大値含め上なら実行
		if (Continuity_Max <= nowCursor)nowCursor = Continuity_Min + 1;
	}

	//Enterキーが押された時の処理
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_RETURN) == 1)
		{
			BGM::Instance()->StopBGM(BGM_result);
			//カーソルの場所によって行うシーン変更処理を決める
			switch (nowCursor)
			{
			case Continuity_Yes:    //コンティニューする
				sceneChanger->SceneChange(eScene_GAME, parameter, false, false);
				break;

			case Continuity_No:   	//コンティニューしない
				sceneChanger->SceneChange(eScene_MENU, parameter, false, false);
				break;
			}
		}
	}
}