#include <DxLib.h>
#include "GameScene.h"
#include "Input.h"
#include "SE.h"
#include "BGM.h"

//�R���X�g���N�^
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

	//�e�Ǘ��̃A�h���X���擾
	player->SetBulletManager(bulletManager);

	BGM::Instance()->PlayBGM(BGM_gameScene, DX_PLAYTYPE_LOOP);
}

//�X�V
void GameScene::Update()
{

	//�\������̂����̕��̓z��
	castleManager->Update(enemyManager);

	//�\������̂����Ԃ̓z��
	enemyManager->Update(castleManager, player, bulletManager, itemManager);
	player->Update(enemyManager,buffManager);
	bulletManager->Update(enemyManager);

	//�\������̂��O�̕��̓z��
	itemManager->Update(player, buffManager);
	eventManager->Update(enemyManager,player);
	buffManager->Update(itemManager,enemyManager);
	timeLimit->Update();
	ui->Update(castleManager, itemManager, buffManager,player,timeLimit);

	//�Q�[���V�[���̃V�[������
	ChangeScene();
}

//�`��
void GameScene::Draw()
{
	//�\������̂����̕��̓z��
	castleManager->Draw();

	//�\������̂����Ԃ̓z��
	player->Draw();
	enemyManager->Draw();
	bulletManager->Draw();


	//�\������̂��O�̕��̓z��
	itemManager->Draw();

	//�X�\��
	DrawTurnGraph(-55, GAME_HEIHGT / 2 - 250, Image::Instance()->GetGraph(eImageType::Gpicture_Forest), TRUE);
	DrawGraph(GAME_WIDTH - 500, GAME_HEIHGT / 2 - 250, Image::Instance()->GetGraph(eImageType::Gpicture_Forest), TRUE);

	eventManager->Draw();
	timeLimit->Draw();
	ui->Draw();
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
			sceneChanger->SceneChange(eScene_PAUSEMENU, parameter, true, false);
		}
	}
}