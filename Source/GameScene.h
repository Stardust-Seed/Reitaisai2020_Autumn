#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "BaseScene.h"
//#include "Castle.h"

class GameScene :public virtual BaseScene {
public:
	GameScene(ISceneChanger* _sceneChanger);
	void Update();				//�X�V����
	void Draw();				//�`�揈��
	void ChangeScene();         //�V�[���ύX����
};

#endif //GAMESCENE_H_