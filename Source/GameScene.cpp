#include <DxLib.h>
#include "GameScene.h"
#include "Input.h"
#include "SE.h"
#include "BGM.h"

//�R���X�g���N�^
GameScene::GameScene(ISceneChanger* _sceneChanger) :BaseScene(_sceneChanger)
{
	timeLimit = new TimeLimit();
	player = new BasePlayer;
	bulletManager = new BulletManager();
	castle = new Castle();
	enemyManager = new EnemyManager(2);
	ui = new UI();

	//�e�Ǘ��̃A�h���X���擾
	player->SetBulletManager(bulletManager);
}

//�X�V
void GameScene::Update()
{
	//�\������̂����̕��̓z��
	castle->Update(enemyManager);

	//�\������̂����Ԃ̓z��
	enemyManager->Update(castle,player, bulletManager);
	player->Update(enemyManager);
	bulletManager->Update(enemyManager);

	//�\������̂��O�̕��̓z��
	timeLimit->Update();
	ui->Update(castle);

	//�Q�[���V�[���̃V�[������
	ChangeScene();
}

//�`��
void GameScene::Draw()
{
	//�\������̂����̕��̓z��
	castle->Draw();

	//�\������̂����Ԃ̓z��
	enemyManager->Draw();
	player->Draw();
	bulletManager->Draw();

	//�\������̂��O�̕��̓z��
	timeLimit->Draw();
	ui->Draw();
}

//�V�[���ύX
void GameScene::ChangeScene()
{
	//�Q�[���N���A
	{
		//�������ԂɒB����
		if (timeLimit->Get_finishTime() == true && castle->Get_IsActive() == true)
		{
			sceneChanger->SceneChange(eScene_CLAER, false, false);
			return;
		}
	}
	
	//�Q�[���I�[�o�[
	{
		//�������ԂɒB����O�ɋ��_���󂳂ꂽ
		if (timeLimit->Get_finishTime() == false && castle->Get_IsActive() == false)
		{
			sceneChanger->SceneChange(eScene_GAMEOVER, false, false);
			return;
		}
	}

	//ESC�L�[��������
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_ESCAPE) == 1)
		{
			sceneChanger->SceneChange(eScene_PAUSEMENU, true, false);
		}
	}
}