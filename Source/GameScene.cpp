#include <DxLib.h>
#include "Input.h"
#include "GameScene.h"

//コンストラクタ
GameScene::GameScene()
{
	nowScene = GAME;
}

//更新
void GameScene::Update()
{
	Input::Instance()->UpdateKey();
	//ゲーム画面なのでここでプレイヤーとか動かすのかもしれない

	//何をもってクリアなのかまだ知らん
	if (Input::Instance()->GetPressCount(KEY_INPUT_1) == 1)			//1が押されたらクリアとしておく
	{
		nowScene = CLAER;
		//SceneChange->onSceneChanged(Scene::CLAER);みたいな感じかもしれないきっと
	}

	//if(Castle.Get_IsActive()==false)みたいなif文...たぶん
	if (Input::Instance()->GetPressCount(KEY_INPUT_2) == 1)			//2が押されたらがめおヴぇｒとしておく
	{
		nowScene = GAMEOVER;
		//SceneChange->onSceneChanged(Scene::GAMEOVER);みたいな感じかもしれないきっと
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_ESCAPE) == 1)    //ESCキーがポーズとしておく
	{
		nowScene = PAUSEMENU;
		//SceneChange->onSceneChanged(Scene::PAUSEMENU);みたいな感じかもしれないきっと
	}
}

//描画
void GameScene::Draw()
{
	DrawFormatString(10, 100, GetColor(255, 255, 255), "現在のシーン番号%d", nowScene);
	DrawFormatString(10, 120, GetColor(255, 255, 255), "今反応するキー:ESC,1,2");

	if (nowScene == CLAER)
	{
		DrawFormatString(10, 150, GetColor(255, 255, 255), "ｃぁえｒ");
	}

	if (nowScene == GAMEOVER)
	{
		DrawFormatString(10, 150, GetColor(255, 255, 255), "がめおヴぇｒ");
	}

	if (nowScene == PAUSEMENU)
	{
		DrawFormatString(10, 150, GetColor(255, 255, 255), "ぽうせ");
	}
}