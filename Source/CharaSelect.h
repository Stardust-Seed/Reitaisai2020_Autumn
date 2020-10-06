#ifndef _CHARASELECT_H
#define _CHARASELECT_H

#include <DxLib.h>
#include"BaseScene.h"
#include "FontHandle.h"
#include"Image.h"
#include"SE.h"
#include"BGM.h"
#include "Cursor.h"
#include "Define.h"

//�L�����N�^�[�^�C�v
enum SelectCharacter {
	select_SAKUYA,     //���
	select_FRAN      //�t����
};

//�I������
struct SelectMenu{
	float x, y;   //�`��ʒu
	float rx, ry; //�~�̑傫��
};

class CharaSelect :public BaseScene {
private:

	int charaSelect;                    //�I�������L�����^�C�v
	int select_Sakuya;                  //���ژg�F���
	int select_Fran;                    //���ژg�F�t����

	SelectCharacter selectChara;        //�I���L����
	Cursor charaCursor[2];              //���ڃJ�[�\��

	int color;    //�F

	SelectMenu selectMenu[3] = {
		{685.0f,725.0f,160.0f,80.0f},    //���
		{1250.0f,725.0f,190.0f,80.0f},   //�t����
	};

public:
	CharaSelect(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update();
	void Select_Push(int _changeType);
	void Draw();
	void Draw_CharaWaku();
	void Draw_CharaName();
	void Draw_CharaAbility();
	void Draw_CharaGraph();

	int Get_selectChara() { return charaSelect; }

};

#endif //CHARAselect_H_