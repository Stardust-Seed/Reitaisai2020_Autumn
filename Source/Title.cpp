#include "Dxlib.h"
#include "Title.h"

/*コンストラクタ*/
Title::Title(ISceneChanger* _sceneChanger) :BaseScene(_sceneChanger) {
	SRand;					//乱数初期化
	textPosition = 875;
	deg = 0;
	rad = 0;
	cnt = 0;
	r = 0;
	g = 0;
	b = 0;

	type = GetRand(3);
}

void Title::Update()
{
	if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1)
	{
		sceneChanger->SceneChange(eScene_MENU, false, false);
	}

	Move();
}

void Title::Draw()
{
	//タイトル表示
	DrawGraph(GAME_WIDTH / 4.25f, GAME_HEIHGT / 13, Image::Instance()->GetGraph(eImageType::Title_Logo, 0), TRUE);

	switch (type)
	{
	case 0:
		DrawGraph(1300, 300, Image::Instance()->GetGraph(eImageType::Spicture_Sakuya, 0), TRUE);
		break;

	case 1:
		DrawGraph(1300, 300, Image::Instance()->GetGraph(eImageType::Spicture_Sakuya, 1), TRUE);
		break;

	case 2:
		DrawGraph(1300, 300, Image::Instance()->GetGraph(eImageType::Spicture_Fran, 0), TRUE);
		break;

	case 3:
		DrawGraph(1300, 300, Image::Instance()->GetGraph(eImageType::Spicture_Fran, 1), TRUE);
		break;

	default:
		break;
	}

	//プレススペースの表示処理
	if (cnt == 250)
	{
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.75f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.2f, "P          ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.75f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.4f, " R         ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.75f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.6f, "  E        ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.75f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.8f, "   S       ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.75f, GAME_HEIHGT / 2 + 175 - sin(rad) * 2,    "    S      ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.75f, GAME_HEIHGT / 2 + 175 - sin(rad) * 2,    "      S    ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.75f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.8f, "       P   ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.75f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.6f, "        A  ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.75f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.4f, "         C ", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 16 * 5.75f, GAME_HEIHGT / 2 + 175 - sin(rad) * 1.2f, "          E", GetColor(r, b, g), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
	}
}

//文字の動きの処理
void Title::Move()
{
	//角度計算
	if (deg >= 360)deg = 0;
	rad = deg * 3.14 / 180;

	//画面中央まで横移動させる
	if (cnt < 250)
	{
		cnt++;
		deg += 1.75f;
		textPosition -= 3.5f;
	}
	else
	{
		deg += 1.25f;
		//文字が浮かび上がるような感じにする
		if (r < 255 && b < 255 && g < 255)
		{
			r++;
			b++;
			g++;
		}
		else
		{
			r = 255;
			b = 255;
			g = 255;
		}
	}
}