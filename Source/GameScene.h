#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "BaseScene.h"
#include "Castle.h"

class GameScene :public virtual BaseScene{

private:
	int nowScene;               //���ݑI�𒆂̃V�[��

public:
	GameScene();
	void Update() {};				//�X�V����
	void Update(Castle* _castle);
	void Draw();				//�`�揈��
	void ChangeScene(Castle* _castle);         //�V�[���ύX����
};

#endif //GAMESCENE_H_