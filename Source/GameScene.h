#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "BaseScene.h"

class GameScene :public virtual BaseScene{

private:
	int nowScene;               //���ݑI�𒆂̃V�[��

public:
	GameScene();

	void Update();				//�X�V����
	void Draw();				//�`�揈��
	void ChangeScene();         //�V�[���ύX����
};

#endif //GAMESCENE_H_