#ifndef _MENU_H_
#define _MENU_H_

#include "BaseScene.h"

#include "Define.h"

/// <summary>
/// ���j���[�^�C�v
/// </summary>
enum class  eMenuType {
	Game,		//�Q�[�����
	Option,		//�I�v�V�������
	Title,		//�^�C�g�����
	GameExit	//�Q�[���I��
};

/// <summary>
/// ���j���[�N���X
/// </summary>
class Menu :public BaseScene {
private:
	const float UI_X = (GAME_WIDTH / 2);	//UI��x���W
	const float UI_Y[4]{					//UI��y���W
		(GAME_HEIHGT / 2) - 300,	//�v���C
		(GAME_HEIHGT / 2) - 100,	//�I�v�V����
		(GAME_HEIHGT / 2) + 100,	//�^�C�g���֖߂�
		(GAME_HEIHGT / 2) + 300		//�Q�[���I��
	};
	const double UI_EXT[2]{					//UI�̊g�嗦
		1.5,	//x
		0.7		//y
	};
	const int UI_PAL		= 255;			//UI�̃u�����h�̃p�����[�^
	const int UI_FONTSIZE	= 100;			//UI�̃t�H���g�T�C�Y

	eMenuType selectMenu;	//�I�����ꂽ����
	Cursor cursor[4];		//�J�[�\���̐F
	unsigned int color[4];	//�����̐F
	int fadeCnt;			//�t�F�[�h�J�E���g

	/// <summary>
	/// �I�����j���[��؂�ւ���
	/// </summary>
	/// <param name="_changeMode">�؂�ւ����[�h</param>
	void SelectMenu(int _changeMode);
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_sceneChanger">�V�[���`�F���W���[</param>
	/// <param name="_parameter">�p�����[�^</param>
	Menu(ISceneChanger* _sceneChanger, Parameter* _parameter);

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();
};

#endif