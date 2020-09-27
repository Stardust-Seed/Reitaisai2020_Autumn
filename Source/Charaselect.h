#ifndef _CHARASELECT_H
#define _CHARASELECT_H

#include"BaseScene.h"

//�L�����N�^�[�^�C�v
enum SelectCharacter {
	select_SAKUYA,     //���
	select_FRAN,       //�t����
	select_BACK,       //�߂�
	select_NUM         //���ڐ�
};

//�I�����ڂ̕`��ׂ̈̍\����
struct SelectMenu {
	int x, y;    //�\�����W
	char isMenu[128]; //���ږ�
};

class Charaselect :public BaseScene {
private:

	int charaSelect;         //�I�������L�����^�C�v
	//SelectCharacter charaType;	//�I�������L�����^�C�v

	SelectMenu selectMenu[2] = {
		{660,700,"�\�Z�� ���"},
		{1200,700,"�t�����h�[���ES"},
	};

public:
	Charaselect(ISceneChanger* _sceneChanger);
	void Update();
	void Draw();

	int Get_selectChara() { return charaSelect; }

};



#endif //CHARAselect_H_