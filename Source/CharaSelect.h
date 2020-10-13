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

//キャラクタータイプ
enum SelectCharacter {
	select_SAKUYA,     //咲夜
	select_FRAN      //フラン
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
	int colorNo;                        //色番号

	Cursor charaCursor[2];              //選択キャラカーソル
	SelectCharacter selectChara;        //選択キャラ

	int color;        //カラー
	int color_Sakuya; //咲夜カラー
	int color_Fran;   //フランカラー

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