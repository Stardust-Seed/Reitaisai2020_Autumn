#ifndef _CHARASELECT_H
#define _CHARASELECT_H

#include"BaseScene.h"

//キャラクタータイプ
enum SelectCharacter {
	select_NOON,       //なし
	select_SAKUYA,     //咲夜
	select_FRAN        //フラン
};

class Charaselect :public BaseScene {
private:

	SelectCharacter charaType;	//選択したキャラタイプ

public:
	Charaselect(ISceneChanger* _sceneChanger);
	void Update();
	void Draw();

	SelectCharacter Get_selectChara() { return charaType; }

};



#endif //CHARAselect_H_