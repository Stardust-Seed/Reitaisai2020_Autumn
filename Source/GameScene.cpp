#include <DxLib.h>
#include "Input.h"
#include "GameScene.h"

//�R���X�g���N�^
GameScene::GameScene()
{
	nowScene = GAME;
}

//�X�V
void GameScene::Update()
{
	Input::Instance()->UpdateKey();
	//�Q�[����ʂȂ̂ł����Ńv���C���[�Ƃ��������̂�������Ȃ�

	//���������ăN���A�Ȃ̂��܂��m���
	if (Input::Instance()->GetPressCount(KEY_INPUT_1) == 1)			//1�������ꂽ��N���A�Ƃ��Ă���
	{
		nowScene = CLAER;
		//SceneChange->onSceneChanged(Scene::CLAER);�݂����Ȋ�����������Ȃ�������
	}

	//if(Castle.Get_IsActive()==false)�݂�����if��...���Ԃ�
	if (Input::Instance()->GetPressCount(KEY_INPUT_2) == 1)			//2�������ꂽ�炪�߂��������Ƃ��Ă���
	{
		nowScene = GAMEOVER;
		//SceneChange->onSceneChanged(Scene::GAMEOVER);�݂����Ȋ�����������Ȃ�������
	}

	if (Input::Instance()->GetPressCount(KEY_INPUT_ESCAPE) == 1)    //ESC�L�[���|�[�Y�Ƃ��Ă���
	{
		nowScene = PAUSEMENU;
		//SceneChange->onSceneChanged(Scene::PAUSEMENU);�݂����Ȋ�����������Ȃ�������
	}
}

//�`��
void GameScene::Draw()
{
	DrawFormatString(10, 100, GetColor(255, 255, 255), "���݂̃V�[���ԍ�%d", nowScene);
	DrawFormatString(10, 120, GetColor(255, 255, 255), "����������L�[:ESC,1,2");

	if (nowScene == CLAER)
	{
		DrawFormatString(10, 150, GetColor(255, 255, 255), "��������");
	}

	if (nowScene == GAMEOVER)
	{
		DrawFormatString(10, 150, GetColor(255, 255, 255), "���߂�������");
	}

	if (nowScene == PAUSEMENU)
	{
		DrawFormatString(10, 150, GetColor(255, 255, 255), "�ۂ���");
	}
}