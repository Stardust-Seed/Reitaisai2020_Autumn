#include "DxLib.h"
#include "GameOver.h"
#include "Parameter.h"
#include "SceneManager.h"


const int GameOver::GAME_X = GAME_WIDTH / 5 + 32;    //コンティニューすると表示するテキストのY座標
const int GameOver::MENU_X = GAME_WIDTH / 2 - 23;    //コンティニューしないと表示するテキストのY座標
//コンストラクタ
GameOver::GameOver()
{

}

void GameOver::Init(GameResource* _gameRes) {
	nowCursor = Cursor::Cursor_0;
	x = 0;
	alpha = 0;
	waitTimer = 0;
	charaType = _gameRes->parameter->Get("CharaSelect");
	BGM::Instance()->PlayBGM(BGM_result, DX_PLAYTYPE_LOOP);
}

//更新
void GameOver::Update(GameResource* _gameRes)
{
	if (waitTimer < 150)
	{
		waitTimer++;
	}
	Move();
	Select(_gameRes);
}

//描画
void GameOver::Draw(GameResource* _gameRes)
{
	//キャラの表示
	switch (charaType)
	{
	case 0:
		DrawGraph(GAME_WIDTH  - 600, GAME_HEIHGT / 9, Image::Instance()->GetGraph(eImageType::Spicture_Sakuya, 2), TRUE);
		break;

	case 1:
		DrawGraph(GAME_WIDTH  - 600, GAME_HEIHGT / 9, Image::Instance()->GetGraph(eImageType::Spicture_Fran, 2), TRUE);
		break;

	default:
		break;
	}

	//メッセージウインドウ表示
	DrawGraph(0, GAME_HEIHGT - 450, Image::Instance()->GetGraph(eImageType::UI_MessageBox), TRUE);

	//ブレンドモードを乗算済みα用のαブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, alpha);
	DrawStringToHandle(GAME_WIDTH / 20+3, GAME_HEIHGT / 10+3, text1, GetColor(0, 0, 0), FontHandle::Instance()->Get_weakForce_222_16());
	DrawStringToHandle(GAME_WIDTH / 20, GAME_HEIHGT / 10 , text1, GetColor(255, 255, 255), FontHandle::Instance()->Get_weakForce_222_16());
	
	//ブレンドモードを通常に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, alpha);

	//カーソルフレームの表示
	if (x != GAME_X)
	{
		DrawRotaGraph(GAME_X, GAME_HEIHGT / 2 + 75, 0.6f, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);
	}
	else
	{
		DrawRotaGraph(MENU_X, GAME_HEIHGT / 2 + 75, 0.6f, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 0), TRUE);
	}

	//選択されてるカーソルフレームの表示
	DrawRotaGraph(x, GAME_HEIHGT / 2 + 75, 0.6f, 0, Image::Instance()->GetGraph(eImageType::UI_CursorFrame, 3), TRUE);

	//テキスト表示
	if (x != GAME_X)
	{
		DrawStringToHandle(GAME_WIDTH / 7 - 13+2, GAME_HEIHGT / 2 + 55+2, text2, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8());
		DrawStringToHandle(GAME_WIDTH / 2 - 192+2, GAME_HEIHGT / 2 + 55+2, text3, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8());
		DrawStringToHandle(GAME_WIDTH / 7 - 13, GAME_HEIHGT / 2 + 55, text2, GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_38_8());
		DrawStringToHandle(GAME_WIDTH / 2 - 192, GAME_HEIHGT / 2 + 55, text3, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8());
	}
	else
	{
		DrawStringToHandle(GAME_WIDTH / 7 - 13 + 2, GAME_HEIHGT / 2 + 55 + 2, text2, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8());
		DrawStringToHandle(GAME_WIDTH / 2 - 192 + 2, GAME_HEIHGT / 2 + 55 + 2, text3, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_38_8());
		DrawStringToHandle(GAME_WIDTH / 7 - 13, GAME_HEIHGT / 2 + 55, text2, GetColor(255, 255, 255), FontHandle::Instance()->Get_natumemozi_38_8());
		DrawStringToHandle(GAME_WIDTH / 2 - 192, GAME_HEIHGT / 2 + 55, text3, GetColor(128, 128, 128), FontHandle::Instance()->Get_natumemozi_38_8());
	}

	//キャラ名とセリフ表示
	switch (charaType)
	{
	case 0:
		DrawStringToHandle(GAME_WIDTH - 500+1, GAME_HEIHGT - 340+1, text4, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
		DrawStringToHandle(GAME_WIDTH - 500, GAME_HEIHGT - 340, text4, GetColor(255, 64, 0), FontHandle::Instance()->Get_natumemozi_48_8());

		DrawStringToHandle(GAME_WIDTH / 13+1, GAME_HEIHGT - 235+1, text5, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_64_8());
		DrawStringToHandle(GAME_WIDTH / 13, GAME_HEIHGT - 235, text5, GetColor(255, 64, 0), FontHandle::Instance()->Get_natumemozi_64_8());
		break;

	case 1:
		DrawStringToHandle(GAME_WIDTH - 520+1 , GAME_HEIHGT - 340+1, text6, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_48_8());
		DrawStringToHandle(GAME_WIDTH - 520, GAME_HEIHGT - 340, text6, GetColor(255, 64, 0), FontHandle::Instance()->Get_natumemozi_48_8());

		DrawStringToHandle(GAME_WIDTH / 13+1, GAME_HEIHGT - 235+1, text7, GetColor(0, 0, 0), FontHandle::Instance()->Get_natumemozi_64_8());
		DrawStringToHandle(GAME_WIDTH / 13, GAME_HEIHGT - 235, text7, GetColor(255, 64, 0), FontHandle::Instance()->Get_natumemozi_64_8());
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
void GameOver::Select(GameResource* _gameRes)
{
	//nowCursorの番号をx座標と合わせる
	{
		switch (nowCursor)
		{
		case Cursor::Cursor_0:
			x = GAME_X;
			break;

		case Cursor::Cursor_1:
			x = MENU_X;
			break;

		default:
			break;
		}
	}

	//左キーが押された時の処理
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_LEFT) % 16 == 1)
		{
			SE::Instance()->PlaySE(SE_cursor);
			if (nowCursor == Cursor::Cursor_1)
			{
				nowCursor = Cursor::Cursor_0;
			}
			else
			{
				nowCursor = Cursor::Cursor_1;
			}
		}
	}

	//右キーが押された時の処理
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) % 16 == 1 )
		{
			SE::Instance()->PlaySE(SE_cursor);
			if (nowCursor == Cursor::Cursor_0)
			{
				nowCursor = Cursor::Cursor_1;
			}
			else
			{
				nowCursor = Cursor::Cursor_0;
			}
		}
	}

	//Zキーが押された時の処理
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_Z) == 1 && waitTimer >= 150)
		{
			SE::Instance()->PlaySE(SE_Enter);
			BGM::Instance()->StopBGM(BGM_result);
			//カーソルの場所によって行うシーン変更処理を決める
			switch (nowCursor)
			{
			case Cursor::Cursor_0:    //コンティニューする
				_gameRes->sceneManager->SceneChange("InGame", false, false, _gameRes);
				break;

			case Cursor::Cursor_1:    //コンティニューしない
				_gameRes->sceneManager->SceneChange("Menu", false, false, _gameRes);
				break;

			default:
				break;
			}
		}
	}
}