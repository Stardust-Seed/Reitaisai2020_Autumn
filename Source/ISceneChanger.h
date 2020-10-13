#ifndef _ISCENECHANGER_H
#define _ISCENECHANGER_H

#include "BaseScene.h"
#include "Parameter.h"

enum eScene;

//�V�[���؂�ւ��̃C���^�[�t�F�C�X�N���X
class ISceneChanger {
public:
	ISceneChanger() = default;
	virtual ~ISceneChanger() = default;
	virtual void SceneChange(eScene _nextScene, Parameter* _parameter,
		const bool _isStack, const bool _isBack) = 0;
};

#endif // !_ISCENECHANGER_H