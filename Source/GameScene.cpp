#include <DxLib.h>
#include "GameScene.h"
#include "Input.h"
#include "SE.h"
#include "BGM.h"

//コンストラクタ
GameScene::GameScene(ISceneChanger* _sceneChanger, Parameter* _parameter,
	GameResource* _gameRes)
	:BaseScene(_sceneChanger, _parameter)
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
	ChangeScene();
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
			SE::Instance()->PlaySE(SE_Enter);
			sceneChanger->SceneChange(eScene_PAUSEMENU, parameter, true, false);
		}
	}
}