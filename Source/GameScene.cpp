#include <DxLib.h>
#include "GameScene.h"
#include "Input.h"
#include "SE.h"
#include "BGM.h"
#include "Parameter.h"
#include "SceneManager.h"

//�R���X�g���N�^
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

	//�e�Ǘ��̃A�h���X���擾
	player->SetBulletManager(bulletManager);

	//�Q�[�����\�[�X�Ɋe�I�u�W�F�N�g��ǉ�
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

//�I������
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

//�X�V
void GameScene::Update(GameResource* _gameRes)
{
	//�\������̂����̕��̓z��
	castleManager->Update(_gameRes);

	//�\������̂����Ԃ̓z��
	enemyManager->Update(_gameRes);
	player->Update(_gameRes);
	bulletManager->Update(_gameRes);

	//�\������̂��O�̕��̓z��
	itemManager->Update(_gameRes);
	eventManager->Update(_gameRes);
	buffManager->Update(_gameRes);
	timeLimit->Update();
	ui->Update(_gameRes);

	//�Q�[���V�[���̃V�[������
	ChangeScene(_gameRes);
}

//�`��
void GameScene::Draw(GameResource* _gameRes)
{
	//�\������̂����̕��̓z��
	castleManager->Draw(_gameRes);

	//�\������̂����Ԃ̓z��
	player->Draw(_gameRes);
	enemyManager->Draw(_gameRes);
	bulletManager->Draw(_gameRes);


	//�\������̂��O�̕��̓z��
	itemManager->Draw(_gameRes);

	//�X�\��
	DrawTurnGraph(0, GAME_HEIHGT / 2 - 220, Image::Instance()->GetGraph(eImageType::Gpicture_Forest), TRUE);
	DrawGraph(GAME_WIDTH - 465, GAME_HEIHGT / 2 - 220, Image::Instance()->GetGraph(eImageType::Gpicture_Forest), TRUE);

	eventManager->Draw(_gameRes);
	ui->Draw(_gameRes);
}

//�V�[���ύX
void GameScene::ChangeScene(GameResource* _gameRes)
{
	//�Q�[���N���A
	{
		//�������ԂɒB����
		if (timeLimit->Get_finishTime() == true && castleManager->Get_IsActive(0) == true)
		{
			BGM::Instance()->StopBGM(BGM_gameScene);
			_gameRes->sceneManager->SceneChange("Clear", false, false, _gameRes);
			return;
		}
	}
	
	//�Q�[���I�[�o�[
	{
		//�������ԂɒB����O�ɋ��_���󂳂ꂽ
		if (timeLimit->Get_finishTime() == false && castleManager->Get_IsActive(0) == false)
		{
			BGM::Instance()->StopBGM(BGM_gameScene);
			_gameRes->sceneManager->SceneChange("GameOver", false, false, _gameRes);
			return;
		}
	}

	//ESC�L�[��������
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_ESCAPE) == 1)
		{
			SE::Instance()->PlaySE(SE_Enter);
			_gameRes->sceneManager->SceneChange("PauseMenu", true, false, _gameRes);
		}
	}
}