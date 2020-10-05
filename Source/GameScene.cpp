#include <DxLib.h>
#include "GameScene.h"
#include "Input.h"
#include "SE.h"
#include "BGM.h"

//コンストラクタ
GameScene::GameScene(ISceneChanger* _sceneChanger, Parameter* _parameter) :BaseScene(_sceneChanger, _parameter)
{
	timeLimit = new TimeLimit();
	player = new BasePlayer(_parameter->Get(BaseScene::CharaSelectTag));
	bulletManager = new BulletManager();
	itemManager = new ItemManager();
	buffManager = new BuffManager();
	castleManager = new CastleManager();
	eventManager = new EventManager(_parameter->Get(BaseScene::LevelSelectTag));
	enemyManager = new EnemyManager(_parameter->Get(BaseScene::LevelSelectTag));
	ui = new UI();

	//弾管理のアドレスを取得
	player->SetBulletManager(bulletManager);

	BGM::Instance()->PlayBGM(BGM_gameScene, DX_PLAYTYPE_LOOP);
}

//更新
void GameScene::Update()
{

	//表示するのが奥の方の奴ら
	castleManager->Update(enemyManager);

	//表示するのが中間の奴ら
	enemyManager->Update(castleManager, player, bulletManager, itemManager);
	player->Update(enemyManager,buffManager);
	bulletManager->Update(enemyManager);

	//表示するのが前の方の奴ら
	itemManager->Update(player, buffManager);
	eventManager->Update(enemyManager,player);
	buffManager->Update(itemManager,enemyManager);
	timeLimit->Update();
	ui->Update(castleManager, itemManager, buffManager,player,timeLimit);

	//ゲームシーンのシーン処理
	ChangeScene();
}

//描画
void GameScene::Draw()
{
	//表示するのが奥の方の奴ら
	castleManager->Draw();

	//表示するのが中間の奴ら
	player->Draw();
	enemyManager->Draw();
	bulletManager->Draw();


	//表示するのが前の方の奴ら
	itemManager->Draw();

	//森表示
	DrawTurnGraph(-55, GAME_HEIHGT / 2 - 250, Image::Instance()->GetGraph(eImageType::Gpicture_Forest), TRUE);
	DrawGraph(GAME_WIDTH - 500, GAME_HEIHGT / 2 - 250, Image::Instance()->GetGraph(eImageType::Gpicture_Forest), TRUE);

	eventManager->Draw();
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
			BGM::Instance()->StopBGM(BGM_gameScene);
			sceneChanger->SceneChange(eScene_CLAER, parameter, false, false);
			return;
		}
	}
	
	//ゲームオーバー
	{
		//制限時間に達する前に拠点が壊された
		if (timeLimit->Get_finishTime() == false && castleManager->Get_IsActive(0) == false)
		{
			BGM::Instance()->StopBGM(BGM_gameScene);
			sceneChanger->SceneChange(eScene_GAMEOVER, parameter, false, false);
			return;
		}
	}

	//ESCキー押したら
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_ESCAPE) == 1)
		{
			sceneChanger->SceneChange(eScene_PAUSEMENU, parameter, true, false);
		}
	}
}