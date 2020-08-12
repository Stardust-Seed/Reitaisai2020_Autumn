#include <DxLib.h>
#include "Input.h"
#include "GameScene.h"

//コンストラクタ
GameScene::GameScene(ISceneChanger* _sceneChanger) :BaseScene(_sceneChanger)
{

}

//更新
void GameScene::Update()
{
	ChangeScene();
	//ゲーム画面なのでここでプレイヤーとか動かすのかもしれない

}

//描画
void GameScene::Draw()
{
	DrawFormatString(10, 120, GetColor(255, 255, 255), "今反応するキー:ESC,1,2");
}

//シーン変更
void GameScene::ChangeScene()
{
	//ゲームクリアなら
	{
		//何をもってクリアなのかまだ知らん
		if (Input::Instance()->GetPressCount(KEY_INPUT_1) == 1)			//1が押されたらクリアとしておく
		{
			sceneChanger->SceneChange(eScene_CLAER, false, false);
		}
	}
	
	//ゲームオーバーなら
	{
		if(Input::Instance()->GetPressCount(KEY_INPUT_2) == 1)
		//if (_castle->Get_IsActive() == false)			//2が押されたらがめおヴぇｒとしておく
		{
			sceneChanger->SceneChange(eScene_GAMEOVER, false, false);
		}
	}

	//ESCキー押したら
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_ESCAPE) == 1)    //ESCキーがポーズとしておく
		{
			sceneChanger->SceneChange(eScene_PAUSEMENU, true, false);
		}
	}
}