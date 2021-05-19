#ifndef _MENU_H_
#define _MENU_H_

#include "Scene.h"
#include "Define.h"
#include "Cursor.h"

/// <summary>
/// ���j���[�^�C�v
/// </summary>
enum class  eMenuType {
	Game,			//�Q�[�����
	Option,			//�I�v�V�������
	OperationExp,	//����������
	Title,			//�^�C�g�����
	GameExit		//�Q�[���I��
};

/// <summary>
/// ���j���[�N���X
/// </summary>
class Menu final :public Scene {
private:
	const float UI_X = (GAME_WIDTH / 2);	//UI��x���W
	const float UI_Y[5]{					//UI��y���W
		(GAME_HEIHGT / 2) - 400,			//�v���C
		(GAME_HEIHGT / 2) - 200,			//�I�v�V����
		(GAME_HEIHGT / 2),
		(GAME_HEIHGT / 2) + 200,			//�^�C�g���֖߂�
		(GAME_HEIHGT / 2) + 400				//�Q�[���I��
	};
	const double UI_EXT[2]{					//UI�̊g�嗦
		1.5,	//x
		0.7		//y
	};
	const int UI_PAL		= 255;			//UI�̃u�����h�̃p�����[�^
	const int UI_FONTSIZE	= 100;			//UI�̃t�H���g�T�C�Y

	eMenuType selectMenu;	//�I�����ꂽ����
	Cursor cursor[5];		//�J�[�\���̐F
	unsigned int color[5];	//�����̐F


	//�I�����j���[��؂�ւ���
	void SelectMenu(int _changeMode);
public:

	//�R���X�g���N�^
	Menu();

	//�f�X�g���N�^
	~Menu() = default;

	//����������
	void Init(GameResource* _gameRes);

	//�X�V����
	void Update(GameResource* _gameRes);

	//�`�揈��
	void Draw(GameResource* _gameRes);
};

#endif