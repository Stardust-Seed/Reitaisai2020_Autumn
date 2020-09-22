#ifndef _CHARASELECT_H
#define _CHARASELECT_H

#include"BaseScene.h"

//�L�����N�^�[�^�C�v
enum SelectCharacter {
	select_NOON,       //�Ȃ�
	select_SAKUYA,     //���
	select_FRAN        //�t����
};

class Charaselect :public BaseScene {
private:

	SelectCharacter charaType;	//�I�������L�����^�C�v

public:
	Charaselect(ISceneChanger* _sceneChanger);
	void Update();
	void Draw();

	SelectCharacter Get_selectChara() { return charaType; }

};



#endif //CHARAselect_H_