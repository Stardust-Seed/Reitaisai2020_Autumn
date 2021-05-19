#include <DxLib.h>
#include "GameScene.h"
#include "Input.h"
#include "SE.h"
#include "BGM.h"
#include "Parameter.h"
#include "SceneManager.h"

//コンストラクタ
GameScene::GameScene()
{
	timeLimit = nullptr;
	player = nullptr;
	bulletManager = nullptr;
	itemManager = nullptr;
	buffManager = nullptr;
	castleManager = nullptr;
	eventManager = nullptr;
	enemyManager = nullptr;
	ui = nullptr;
}

GameScene::~GameScene() {
	Final();
}

void GameScene::Init(GameResource* _gameRes) {
	timeLimit = new TimeLimit();
	player = new BasePlayer(_gameRes->parameter->Get("CharaSelect"));
	bulletManager = new BulletManager();
	itemManager = new ItemManager();
	buffManager = new BuffManager();
	castleManager = new CastleManager();
	eventManager = new EventManager(_gameRes->parameter->Get("LevelSelect"));
	enemyManager = new EnemyManager(_gameRes->parameter->Get("LevelSelect"));
	ui = new UI();

	//弾管理のアドレスを取得
	player->SetBulletManager(bulletManager);

	//ゲームリソースに各オブジェクトを追加
	_gameRes->buffManager = buffManager;
	_gameRes->bulletManager = bulletManager;
	_gameRes->castleManager = castleManager;
	_gameRes->eventManager = eventManager;
	_gameRes->enemyManager = enemyManager;
	_gameRes->itemManager = itemManager;
	_gameRes->player = player;
	_gameRes->timeLimit = timeLimit;

	BGM::Instance()->PlayBGM(BGM_gameScene, DX_PLAYTYPE_LOOP);
} 

//終了処理
void GameScene::Final() {
	delete timeLimit;
	delete player;
	delete bulletManager;
	delete itemManager;
	delete buffManager;
	delete castleManager;
	delete eventManager;
	delete enemyManager;
	delete ui;
}

//更新
void GameScene::Update(GameResource* _gameRes)
{
	//表示するのが奥の方の奴ら
	castleManager->Update(_gameRes);

	//表示するのが中間の奴ら
	enemyManager->Update(_gameRes);
	player->Update(_gameRes);
	bulletManager->Update(_gameRes);

	//表示するのが前の方の奴ら
	itemManager->Update(_gameRes);
	eventManager->Update(_gameRes);
	buffManager->Update(_gameRes);
	timeLimit->Update();
	ui->Update(_gameRes);

	//ゲームシーンのシーン処理
	ChangeScene(_gameRes);
}

//描画
void GameScene::Draw(GameResource* _gameRes)
{
	//表示するのが奥の方の奴ら
	castleManager->Draw(_gameRes);

	//表示するのが中間の奴ら
	player->Draw(_gameRes);
	enemyManager->Draw(_gameRes);
	bulletManager->Draw(_gameRes);


	//表示するのが前の方の奴ら
	itemManager->Draw(_gameRes);

	//森表示
	DrawTurnGraph(0, GAME_HEIHGT / 2 - 220, Image::Instance()->GetGraph(eImageType::Gpicture_Forest), TRUE);
	DrawGraph(GAME_WIDTH - 465, GAME_HEIHGT / 2 - 220, Image::Instance()->GetGraph(eImageType::Gpicture_Forest), TRUE);

	eventManager->Draw(_gameRes);
	ui->Draw(_gameRes);
}

//シーン変更
void GameScene::ChangeScene(GameResource* _gameRes)
{
	//ゲームクリア
	{
		//制限時間に達した
		if (timeLimit->Get_finishTime() == true && castleManager->Get_IsActive(0) == true)
		{
			BGM::Instance()->StopBGM(BGM_gameScene);
			_gameRes->sceneManager->SceneChange("Clear", false, false, _gameRes);
			return;
		}
	}
	
	//ゲームオーバー
	{
		//制限時間に達する前に拠点が壊された
		if (timeLimit->Get_finishTime() == false && castleManager->Get_IsActive(0) == false)
		{
			BGM::Instance()->StopBGM(BGM_gameScene);
			_gameRes->sceneManager->SceneChange("GameOver", false, false, _gameRes);
			return;
		}
	}

	//ESCキー押したら
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_ESCAPE) == 1)
		{
			SE::Instance()->PlaySE(SE_Enter);
			_gameRes->sceneManager->SceneChange("PauseMenu", true, false, _gameRes);
		}
	}
}