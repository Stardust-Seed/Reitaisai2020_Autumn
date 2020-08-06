#include "Dxlib.h"
#include "Title.h"
#include "Input.h"
#include "math.h"

//タイトルテキストをちょこっと動かすだけの処理に使う
//タイトル動かすのかは決めてないから却下されれば消す
float deg, rad;
float o;
int textSpeed[3];
int cnt;
float w;
//コンストラクタ
Title::Title(){

	//却下されれば消す
	textSpeed[0] = 0;
	textSpeed[1] = 1;
	textSpeed[2] = 2;
	cnt = 0;
	o = 1000;
	//画像とか読み込みたいね

}

void Title::Update()
{
	if (Input::Instance()->GetPressCount(KEY_INPUT_SPACE) == 1)
	{
		// 描画する文字列のサイズを設定
		SetFontSize(16);
		DrawFormatString(0,40, GetColor(255, 255, 255), "スペースが押されたのでシーン切り替えされたい");
		//SceneChange->onSceneChanged(Scene::MENU);みたいな感じかもしれないきっと
	}

	//却下されれば消す
	Move();
}

void Title::Draw()
{
	//普通に描画するだけ
	//DrawFormatString(GAME_WIDTH / 2 - 112*2.5f, GAME_HEIHGT / 2 , GetColor(255, 255, 255), "東方河本録");

	//動かすなら
	DrawStringToHandle(GAME_WIDTH / 2 - 64 - textSpeed[2] + o, GAME_HEIHGT / 2 - 200 - sin(rad) * 64 * 0.25f, "東", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 64 - textSpeed[1] + o, GAME_HEIHGT / 2 - 200 - cos(rad) * 64 * 0.5f , "方", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 64 + textSpeed[0] + o, GAME_HEIHGT / 2 - 200 - sin(rad) * 64 * 0.05f, "河", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 64 + textSpeed[1] + o, GAME_HEIHGT / 2 - 200 - cos(rad) * 64 * 0.5f , "本", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());
	DrawStringToHandle(GAME_WIDTH / 2 - 64 + textSpeed[2] + o, GAME_HEIHGT / 2 - 200 - sin(rad) * 64 * 0.75f, "録", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_112_3());

	//普通に描画するだけ
	//DrawFormatString(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f, GetColor(255, 255, 255), "PRESS SPACE");

	//画像表示今は四角表示
	DrawBox(GAME_WIDTH -250, GAME_HEIHGT - 400, GAME_WIDTH, GAME_HEIHGT, GetColor(255, 255, 255), true);

}

//却下されれば消す
void Title::Move()
{
	cnt++;
	//タイトルの移動処理
	{
		//if文の中とかマジックナンバーありありロジカル許して
		if (deg >= 360)deg = 0;
		rad = deg * 3.14 / 180;

		if (cnt < 112)
		{
			textSpeed[1] += 1;
			textSpeed[2] += 2;
		}
		else
		{
			deg += 0.15f;
		}

		if (cnt < 500)
		{
			o -= 2;
		}
		else
		{
			deg += 0.15f;
			o = deg * 3.14 / 720;
			cnt = 500;
		}
	}
	//プレススペースの表示処理
	{
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 1.25f, "P"          , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 1.5f,  " R"         , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 1.75f, "  E"        , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 2,     "   S"       , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 2.5f,  "    S"      , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 2.5f,  "      S"    , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 2,     "       P"   , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 1.75,  "        A"  , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 1.5f,  "         C" , GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
		DrawStringToHandle(GAME_WIDTH / 2 - 32 * 3.5f, GAME_HEIHGT / 1.5f - sin(rad) * 1.25f, "          E", GetColor(255, 255, 255), FontHandle::Instance()->Get_MS_GOTHIC_32_3());
	}
}