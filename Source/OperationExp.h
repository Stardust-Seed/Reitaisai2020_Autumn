#ifndef _OPERATIONEXP_H
#define _OPERATIONEXP_H

#include "Scene.h"

class OperationExp final :public Scene {
private:
	const char* text[12]{			//�\������e�L�X�g
		"�����������",
		"�E�ړ� / �J�[�\���ړ�",
		"��:���L�[",
		"��:���L�[",
		"��:���L�[",
		"�E:���L�[",
		"�E�U�� / ����",
		"�@:�y�L�[",
		"�E�L�����X�L�� / �߂�",
		"�@:�w�L�[",
		"�E�|�[�Y���j���[(�Q�[����)",
		"�@:�d�r�b�L�["
	};
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="_sceneChanger">�V�[���؂�ւ��N���X</param>
	/// <param name="_parameter">�p�����[�^</param>
	OperationExp();

	~OperationExp() = default;

	//�X�V����
	void Update(GameResource* _gameRes);

	//�`�揈��
	void Draw(GameResource* _gameRes);
};

#endif // !_OPERATIONEXP_H