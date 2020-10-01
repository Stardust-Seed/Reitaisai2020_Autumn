#include "Dxlib.h"
#include "Title.h"

/*コンストラクタ*/
Title::Title(ISceneChanger* _sceneChanger, Parameter* _parameter)
	:BaseScene(_sceneChanger, _parameter) {
	SRand;					//乱数初期化
	deg = 0;
	rad = 0;
	cnt = 0;
	alpha = 0;

	type = GetRand(3);
	BGM::Instance()->PlayBGM(BGM_title);
}

void Title::Update()
{
	Move();
	if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1)
	{
		SE::Instance()->PlaySE(SE_cursor);
		BGM::Instance()->StopBGM(BGM_title);
		sceneChanger->SceneChange(eScene_MENU, parameter, false, false);
	}
}

void Title::Draw()
{
	//背景表示
	DrawGraph(0, 0, Image::Instance()->GetGraph(eImageType::Background_Title), TRUE);

	//タイトル表示
	DrawGraph(GAME_WIDTH / 4.25f, GAME_HEIHGT / 13, Image::Instance()->GetGraph(eImageType::Title_Logo, 0), TRUE);

	//プレススペースの表示
	//ブレンドモードを乗算済みα用のαブレンドにする
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);

	DrawStringToHandle(GAME_WIDTH / 2 - 19 * 9 - 6 , GAME_HEIHGT / 2 + 175 - sin(rad) * 3,    "P                   ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(GAME_WIDTH / 2 - 19 * 9 - 6 , GAME_HEIHGT / 2 + 175 - sin(rad) * 3.2f, "  R                 ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(GAME_WIDTH / 2 - 19 * 9 - 6 , GAME_HEIHGT / 2 + 175 - sin(rad) * 3.4f, "    E               ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(GAME_WIDTH / 2 - 19 * 9 - 6 , GAME_HEIHGT / 2 + 175 - sin(rad) * 3.6f, "      S             ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(GAME_WIDTH / 2 - 19 * 9 - 6 , GAME_HEIHGT / 2 + 175 - sin(rad) * 3.8f, "        S           ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(GAME_WIDTH / 2 - 19 * 9 - 10, GAME_HEIHGT / 2 + 175 - sin(rad) * 3.8f, "           S        ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(GAME_WIDTH / 2 - 19 * 9 - 10, GAME_HEIHGT / 2 + 175 - sin(rad) * 3.6f, "             P      ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(GAME_WIDTH / 2 - 19 * 9 - 10, GAME_HEIHGT / 2 + 175 - sin(rad) * 3.4f, "               A    ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(GAME_WIDTH / 2 - 19 * 9 - 10, GAME_HEIHGT / 2 + 175 - sin(rad) * 3.2f, "                 C  ", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());
	DrawStringToHandle(GAME_WIDTH / 2 - 19 * 9 - 10, GAME_HEIHGT / 2 + 175 - sin(rad) * 3,    "                   E", GetColor(255, 128, 0), FontHandle::Instance()->Get_natumemozi_48_8());

	//ブレンドモードを通常に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, alpha);
	//DrawLine(GAME_WIDTH / 2, 0, GAME_WIDTH / 2, GAME_HEIHGT, GetColor(0,0,0));    // 線を描画
}

//文字の動きの処理
void Title::Move()
{
	//角度計算
	if (deg >= 360)deg = 0;
	rad = deg * 3.14 / 180;

	//少し待つ
	if (cnt < 130)
	{
		cnt++;
	}
	else
	{
		deg += 1;
		//文字が浮かび上がるようにする
		if (alpha < 255)
		{
			alpha++;
		}
	}
}