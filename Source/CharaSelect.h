#ifndef _CHARASELECT_H
#define _CHARASELECT_H

#include"BaseScene.h"

//キャラクタータイプ
enum SelectCharacter {
	select_SAKUYA,     //咲夜
	select_FRAN,       //フラン
	select_BACK,       //戻る
	select_NUM         //項目数
};

//選択項目の描画の為の構造体
struct SelectMenu {
	int x, y;    //表示座標
	char isMenu[128]; //項目名
};

class CharaSelect :public BaseScene {
private:

	int charaSelect;         //選択したキャラタイプ
	//SelectCharacter charaType;	//選択したキャラタイプ

	SelectMenu selectMenu[2] = {
		{660,700,"十六夜 咲夜"},
		{1200,700,"フランドール・S"},
	};

public:
	CharaSelect(ISceneChanger* _sceneChanger, Parameter* _parameter);
	void Update();
	void Draw();

	int Get_selectChara() { return charaSelect; }

};



#endif //CHARAselect_H_
