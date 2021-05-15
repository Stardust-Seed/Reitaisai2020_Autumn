#include <DxLib.h>
#include "GameScene.h"
#include "Input.h"
#include "SE.h"
#include "BGM.h"

//�R���X�g���N�^
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
	ChangeScene();
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
void GameScene::ChangeScene()
{
	//�Q�[���N���A
	{
		//�������ԂɒB����
		if (timeLimit->Get_finishTime() == true && castleManager->Get_IsActive(0) == true)
		{
			BGM::Instance()->StopBGM(BGM_gameScene);
			sceneChanger->SceneChange(eScene_CLAER, parameter, false, false);
			return;
		}
	}
	
	//�Q�[���I�[�o�[
	{
		//�������ԂɒB����O�ɋ��_���󂳂ꂽ
		if (timeLimit->Get_finishTime() == false && castleManager->Get_IsActive(0) == false)
		{
			BGM::Instance()->StopBGM(BGM_gameScene);
			sceneChanger->SceneChange(eScene_GAMEOVER, parameter, false, false);
			return;
		}
	}

	//ESC�L�[��������
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_ESCAPE) == 1)
		{
			SE::Instance()->PlaySE(SE_Enter);
			sceneChanger->SceneChange(eScene_PAUSEMENU, parameter, true, false);
		}
	}
}