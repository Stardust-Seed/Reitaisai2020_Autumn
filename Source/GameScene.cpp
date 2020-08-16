#include <DxLib.h>
#include "GameScene.h"

//コンストラクタ
GameScene::GameScene(ISceneChanger* _sceneChanger) :BaseScene(_sceneChanger)
{
	timeLimit = new TimeLimit();
	player = new BasePlayer;
	bulletManager = new BulletManager();
	castle = new Castle();
	enemyManager = new EnemyManager(0);
	ui = new UI();

	//弾管理のアドレスを取得
	player->SetBulletManager(bulletManager);
}

//更新
void GameScene::Update()
{
	//表示するのが奥の方の奴ら
	castle->Update(enemyManager);

	//表示するのが中間の奴ら
	enemyManager->Update(castle,player);
	player->Update(enemyManager, enemyManager);
	bulletManager->Update();

	//表示するのが前の方の奴ら
	timeLimit->Update();
	ui->Update(castle);

	//ゲームシーンのシーン処理
	ChangeScene();
}

//描画
void GameScene::Draw()
{
	//表示するのが奥の方の奴ら
	castle->Draw();

	//表示するのが中間の奴ら
	enemyManager->Draw();
	player->Draw();
	bulletManager->Draw();

	//表示するのが前の方の奴ら
	timeLimit->Draw();
	ui->Draw();
}

//シーン変更
void GameScene::ChangeScene()
{
	//ゲームクリア
	{
		//制限時間に達した
		if (timeLimit->Get_FinishFlg() == true && castle->Get_IsActive() == true)
		{
			sceneChanger->SceneChange(eScene_CLAER, false, false);
			return;
		}
	}
	
	//ゲームオーバー
	{
		//制限時間に達する前に拠点が壊された
		if (timeLimit->Get_FinishFlg() == false && castle->Get_IsActive() == false)
		{
			sceneChanger->SceneChange(eScene_GAMEOVER, false, false);
			return;
		}
	}

	//ESCキー押したら
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_ESCAPE) == 1)
		{
			sceneChanger->SceneChange(eScene_PAUSEMENU, true, false);
		}
	}
}