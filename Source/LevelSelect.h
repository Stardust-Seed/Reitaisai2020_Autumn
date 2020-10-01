#ifndef _LEVELSELECT_H
#define _LEVELSELECT_H

#include <string>
#include "BaseScene.h"
#include "Cursor.h"
#include "Define.h"
using namespace std;

/// <summary>
/// �I�𒆂̃��x��
/// </summary>
enum class eLevelType {
	Easy,		//�ȒP
	Normal,		//����
	Hard,		//���
};

/// <summary>
/// ��Փx�I���N���X
/// </summary>
class LevelSelect final :public BaseScene {
private:
	const float UI_X = (GAME_WIDTH / 2);	//UI��x���W
	const float UI_Y[3] = {					//UI��y���W
		(GAME_HEIHGT / 2) - 300,	//Easy
		(GAME_HEIHGT / 2),			//Normal
		(GAME_HEIHGT / 2) + 300		//Hard
	};
	const double UI_EXT = 1.0;				//UI�̊g�嗦
	const int UI_PAL = 255;					//UI�̃u�����h�̃p�����[�^
	const int UI_FONTSIZE = 100;			//UI�̃t�H���g�T�C�Y

	eLevelType selectLevel;	//�I�����ꂽ���x��
	Cursor cursor[3];		//�J�[�\���̐F
	bool isChange;			//�؂�ւ��t���O

	/// <summary>
	/// �I�����x����؂�ւ���
	/// </summary>
	/// <param name="_changeMode"></param>
	void ChangeLevel(int _changeMode);
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