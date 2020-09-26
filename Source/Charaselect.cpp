#include <DxLib.h>
#include "Input.h"
#include "Charaselect.h"

/*�R���X�g���N�^*/
Charaselect::Charaselect(ISceneChanger* _sceneChanger) :BaseScene(_sceneChanger) {


	//�ŏ��͍�邪�I������Ă�����
	charaSelect = select_SAKUYA;
}

/*�X�V����*/
void Charaselect::Update() 
{
	/****�I��****/
	/************/
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RIGHT) == 1))
	{
		//�I�����ڂ��������
		charaSelect = (charaSelect + 1) % select_NUM;
	}
	if (charaSelect != select_SAKUYA) {
		if ((Input::Instance()->GetPressCount(KEY_INPUT_LEFT) == 1))
		{
			//�I�����ڂ���グ��
			charaSelect = (charaSelect - 1) % select_NUM;
		}
	}

	/****����****/
	/************/
	if ((Input::Instance()->GetPressCount(KEY_INPUT_RETURN) == 1))
	{
		switch (charaSelect){
		case select_SAKUYA:   //����I��
			//�m������Փx�I����ʂ����������H
			//sceneChanger->SceneChange(, false, false);
			break;
		case select_FRAN:
			//�m������Փx�I����ʂ����������H
			//sceneChanger->SceneChange(, false, false);
			break;
		case select_BACK:
			//�O�̃V�[��(���)�ɖ߂�
			sceneChanger->SceneChange(eScene_MENU, false, false);
			break;
		}
	}

}

/*�`�揈��*/
void Charaselect::Draw()
{
	DrawFormatString(200, 200, GetColor(255, 255, 255),"�I������:%d",charaSelect );

	DrawBox(575, 200, 850, 600, GetColor(255, 255, 255), false);

	DrawBox(1125, 200, 1400, 600, GetColor(255, 255, 255), false);

	//�L�����N�^�[���ڂ̕`��
	for (int i = 0; i < 2; i++)
	{
		DrawFormatString(selectMenu[i].x, selectMenu[i].y, GetColor(255, 255, 255), selectMenu[i].isMenu);
	}
}