#ifndef _LEVELSELECT_H
#define _LEVELSELECT_H

#include "BaseScene.h"
#include "Background.h"

/// <summary>
/// �I�𒆂̃��x��
/// </summary>
enum class eSelectLevel {
	Easy,
	Normal,
	Hard,
};

/// <summary>
/// ��Փx�I���N���X
/// </summary>
class LevelSelect final :public BaseScene {
private:
	Background background;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_sceneChanger">�V�[���؂�ւ��N���X���</param>
	LevelSelect(ISceneChanger* _sceneChanger, Parameter* _parameter);

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>	
	~LevelSelect() = default;

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();
};

#endif // !_LEVELSELECT_H