#include <DxLib.h>
#include "GameScene.h"
#include "Input.h"
#include "SE.h"
#include "BGM.h"

//コンストラクタ
GameScene::GameScene(ISceneChanger* _sceneChanger) :BaseScene(_sceneChanger)
{
	timeLimit = new TimeLimit();
	player = new BasePlayer;
	bulletManager = new BulletManager();
	itemManager = new ItemManager();
	buffManager = new BuffManager();
	castleManager = new CastleManager();
	enemyManager = new EnemyManager(2);
	ui = new UI();

	//弾管理のアドレスを取得
	player->SetBulletManager(bulletManager);

}

//更新
void GameScene::Update()
{
	//表示するのが奥の方の奴ら
	castleManager->Update(enemyManager);

	//表示するのが中間の奴ら
	enemyManager->Update(castleManager, player, bulletManager, itemManager);
	player->Update(enemyManager);
	bulletManager->Update(enemyManager);

	//表示するのが前の方の奴ら
	timeLimit->Update();
	ui->Update(castleManager);

	//ゲームシーンのシーン処理
	ChangeScene();
}

//描画
void GameScene::Draw()
{
	//表示するのが奥の方の奴ら
	castleManager->Draw();

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
		if (timeLimit->Get_finishTime() == true && castleManager->Get_IsActive(0) == true)
		{
			sceneChanger->SceneChange(eScene_CLAER, false, false);
			return;
		}
	}
	
	//ゲームオーバー
	{
		//制限時間に達する前に拠点が壊された
		if (timeLimit->Get_finishTime() == false && castleManager->Get_IsActive(0) == false)
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