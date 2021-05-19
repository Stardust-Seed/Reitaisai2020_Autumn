#ifndef _SCENE_H
#define _SCENE_H

#include "GameResource.h"

//�V�[���N���X
class Scene {
public:
	Scene() {}											//�R���X�g���N�^
	virtual ~Scene() {}									//�f�X�g���N�^
	virtual void Init(GameResource* _gameRes) {}		//����������
	virtual void Final() {}								//�I������
	virtual void Update(GameResource* _gameRes) {}		//�X�V����
	virtual void Draw(GameResource* _gameRes) {}		//�`�揈��
};

#endif // !_SCENE_H

