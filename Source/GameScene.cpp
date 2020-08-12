#include <DxLib.h>
#include "Input.h"
#include "GameScene.h"

//�R���X�g���N�^
GameScene::GameScene(ISceneChanger* _sceneChanger) :BaseScene(_sceneChanger)
{

}

//�X�V
void GameScene::Update()
{
	ChangeScene();
	//�Q�[����ʂȂ̂ł����Ńv���C���[�Ƃ��������̂�������Ȃ�

}

//�`��
void GameScene::Draw()
{
	DrawFormatString(10, 120, GetColor(255, 255, 255), "����������L�[:ESC,1,2");
}

//�V�[���ύX
void GameScene::ChangeScene()
{
	//�Q�[���N���A�Ȃ�
	{
		//���������ăN���A�Ȃ̂��܂��m���
		if (Input::Instance()->GetPressCount(KEY_INPUT_1) == 1)			//1�������ꂽ��N���A�Ƃ��Ă���
		{
			sceneChanger->SceneChange(eScene_CLAER, false, false);
		}
	}
	
	//�Q�[���I�[�o�[�Ȃ�
	{
		if(Input::Instance()->GetPressCount(KEY_INPUT_2) == 1)
		//if (_castle->Get_IsActive() == false)			//2�������ꂽ�炪�߂��������Ƃ��Ă���
		{
			sceneChanger->SceneChange(eScene_GAMEOVER, false, false);
		}
	}

	//ESC�L�[��������
	{
		if (Input::Instance()->GetPressCount(KEY_INPUT_ESCAPE) == 1)    //ESC�L�[���|�[�Y�Ƃ��Ă���
		{
			sceneChanger->SceneChange(eScene_PAUSEMENU, true, false);
		}
	}
}