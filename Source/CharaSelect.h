#ifndef _CHARASELECT_H
#define _CHARASELECT_H

#include <DxLib.h>
#include"BaseScene.h"
#include "FontHandle.h"
#include"Image.h"
#include"SE.h"

//キャラクタータイプ
enum SelectCharacter {
	select_SAKUYA,     //咲夜
	select_FRAN,       //フラン
	select_BACK,       //戻る
	select_NUM         //項目数
};

//選択項目
struct SelectMenu{
	float x, y;   //描画位置
	float rx, ry; //円の大きさ
};

class CharaSelect :public BaseScene {
private:

	int charaSelect;                    //選択したキャラタイプ
	int select_Sakuya;                  //項目枠：咲夜
	int select_Fran;                    //項目枠：フラン
	int select_Menu;                    //項目枠：メニュー

	int color;    //色

	SelectMenu selectMenu[3] = {
		{685.0f,725.0f,160.0f,80.0f},    //咲夜
		{1250.0f,725.0f,190.0f,80.0f},   //フラン
		{970.0f,920.0f,180.0f,80.0f},    //戻る
	};

public:
	CharaSelect(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update();
	void Draw();
	void Draw_CharaName();
	void Draw_CharaAbility();
	void Draw_CharaGraph();
	void Draw_Waku();

	int Get_selectChara() { return charaSelect; }

};

#endif //CHARAselect_H_